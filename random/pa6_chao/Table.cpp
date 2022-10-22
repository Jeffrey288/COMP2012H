#include <fstream>
#include "Table.h"
#include "String.h"

using namespace std;

bool isInteger(const String &test)
{
    if (!test.length())
        return false;

    if (test[0] != '-' && !isdigit(test[0]))
        return false;

    for (int i = 1; i < test.length(); ++i)
    {
        if (!isdigit(test[i]))
            return false;
    }
    return true;
}

String *Table::operator[](int index) const
{

    if (index >= numCols || index < 0)
    {
        cout << "Table column index is out of bounds." << endl;
        return nullptr;
    }

    Field *cur = fieldHead;
    for (int count = 0; count < index; cur = cur->next, ++count)
        ;
    return cur->column;
}

Table::Table(const String &name) :name(name){

    numCols = numRows = 0;
    primaryKey = nullptr; fieldHead = nullptr; next = nullptr;
    tableSize = 100;

}

Table::Table(ifstream &ifs, const String &name) :name(name){

    Field* temp_field_pointer;// use for creating fields & read the record

    ifs >> numCols; ifs>> numRows;
    primaryKey = nullptr; fieldHead = nullptr; next = nullptr;  //later back
    tableSize = 100;    //later back

    for(int field = 0; field < numCols; field++)    //create fields and link them
    {
        String field_name, field_type;

        getline(ifs,field_name,' '); //the field name is before ' '
        if(field != numCols-1)
            getline(ifs,field_type,',');
        else
            getline(ifs,field_type,'\n');
        
        if(field == 0)
        {
            fieldHead = new Field;
            temp_field_pointer = fieldHead;
        }
        else
        {
            temp_field_pointer->next = new Field;
            temp_field_pointer = temp_field_pointer->next;
        } 

        
        if (field_name[0] == '*')           //set the name of the field //set primary key if found
        {
            primaryKey = temp_field_pointer;
            temp_field_pointer->name = field_name.substr(1,field_name.length()-1);
        }              
        else
            temp_field_pointer->name = field_name;

        if(stoi(field_type.substr(0,1)) == 0)            //set the type
            temp_field_pointer->type = INT;
        else if(stoi(field_type.substr(0,1)) == 1)
            temp_field_pointer->type = STRING;

        temp_field_pointer->column = new String[tableSize];
        
        if(field == numCols-1)  //set last field->next be nullptr //special case
            temp_field_pointer->next = nullptr;
    }

    for(int record = 0; record < numRows; record++) //read the record   //I forgot have [] fuction to use......
    {
        for(int field = 0; field < numCols; field++)
        {
            if(field == 0)
                temp_field_pointer = fieldHead;
            else
                temp_field_pointer = temp_field_pointer->next;
            
            if(field != numCols -1 )   
                getline(ifs,temp_field_pointer->column[record],',');
            else
                getline(ifs,temp_field_pointer->column[record],'\n');
        }
    }



}

Table::~Table(){

    Field* field_pointer_delete = fieldHead; //field_pointer_for_delete
    Field* temp_field_pointer = nullptr;
    if(fieldHead != nullptr)
        temp_field_pointer = field_pointer_delete->next;
        

    while(field_pointer_delete != nullptr)
    {
        delete [] (field_pointer_delete->column);
        delete field_pointer_delete;
        field_pointer_delete = temp_field_pointer;
        if(temp_field_pointer != nullptr)
            temp_field_pointer = temp_field_pointer->next;
    }

}

void Table::addRecord(int index, String *record){

    if(record == nullptr)
    {
        cout << "Record is empty.\n";
        return;
    }
    if((index < 0)||(index>numRows))
    {
        cout << "Table row index is out of bounds.\n";
        return;
    }

    int key_index = 0; //find index of primary field
    Field* temp_field_pointer = fieldHead;
    while(temp_field_pointer != nullptr)            
    {
        if(temp_field_pointer == primaryKey)        //assuming there always are key
            break;
        temp_field_pointer = temp_field_pointer->next;
        key_index++;
    }

    if(record[key_index]=="")           //Primary key error
    {
        cout << "Empty or duplicate primary key.\n";
        return;
    }
    for(int i = 0; i < numRows; i++)
    {
        if(operator[](key_index)[i]==record[key_index])
        {
            cout << "Empty or duplicate primary key.\n";
            return;
        }
    }

    temp_field_pointer = fieldHead; int count = 0;
    while (temp_field_pointer != nullptr)
    {
        if(temp_field_pointer->type == INT)
            if(!isInteger(record[count]))
            {
                cout << "Cannot insert non-integer in integer field.\n";
                return;
            }
        count++;
        temp_field_pointer = temp_field_pointer->next;
    }

    //Procedure

    if(numRows == tableSize) //Allocate a new dynamic array with 100 more positions and update tableSize.
    {
        temp_field_pointer = fieldHead;
        while (temp_field_pointer != nullptr)
        {
            String* temp_record = new String[tableSize+100];
            for(count = 0; count < tableSize; count++)
                temp_record[count] = temp_field_pointer->column[count];
            delete [] (temp_field_pointer->column);
            temp_field_pointer->column = temp_record;

            temp_field_pointer = temp_field_pointer->next;
        }
        tableSize += 100;
    }

    temp_field_pointer = fieldHead; count = 0;              //forgot have operator[] fuction......
    while (temp_field_pointer != nullptr)
    {
        for(int count_copy = numRows; count_copy > index; count_copy--)
            temp_field_pointer->column[count_copy] = temp_field_pointer->column[count_copy-1];
        temp_field_pointer->column[index] = record[count];
        count++;
        temp_field_pointer = temp_field_pointer->next;
    }
    numRows++;

    return;
}

void Table::addField(int index, const String &name, TYPE type){

    if(index > numCols)
    {
        cout << "Table column index is out of bounds.\n";
        return;
    }
    Field* temp_field_pointer = fieldHead;
    while (temp_field_pointer != nullptr)
    {
        if(name == temp_field_pointer->name)
        {
            cout << "Field with given name already exists in table.\n";
            return;
        }
        else
            temp_field_pointer = temp_field_pointer->next;
    }

    //Procedure
    Field* new_field_pointer = new Field;

    new_field_pointer->name = name;
    new_field_pointer->type = type;

    String inti_value = (type == INT) ? "0" : "";
    new_field_pointer->column = new String [tableSize];
    for(int i = 0; i < tableSize; i++)
        new_field_pointer->column[i] = inti_value;
    

    //start link them               //forgot have operator[] again...

    if(fieldHead == nullptr)
        primaryKey = new_field_pointer;

    temp_field_pointer = fieldHead;
    Field* last_field = nullptr;
    for(int i = 0; i < index; i++)
    {
        last_field = temp_field_pointer;
        if(temp_field_pointer != nullptr)
            temp_field_pointer = temp_field_pointer->next;
    }

    if(index==0)
    {
        new_field_pointer->next = fieldHead;
        fieldHead = new_field_pointer;
    }
    else
    {
        new_field_pointer->next = temp_field_pointer;
        last_field->next = new_field_pointer;
    }

    
    numCols++;

    return;
}

void Table::deleteRecord(int row){      //idk need no need set the row deleted to init value

    if(row >= numRows)
    {
        cout << "Table row index is out of bounds.\n";
        return;
    }
    for(int field_index = 0; field_index < numCols; field_index++)
    {
        for(int i = row; i < numRows-1; i++)
            operator[](field_index)[i] = operator[](field_index)[i+1];
        operator[](field_index)[numRows-1] = "";
    }

    numRows--;
    return;
}

void Table::modifyRecord(int row, int column, const String &newVal){

    if(row >= numRows)
    {
        cout << "Table row index is out of bounds.\n";
        return;
    }
    if(column >= numCols)
    {
        cout << "Table column index is out of bounds.\n";
        return;
    }

    int key_index = 0;                              //find index of primary field
    Field* temp_field_pointer = fieldHead;
    while(temp_field_pointer != nullptr)            
    {
        if(temp_field_pointer == primaryKey)        //assuming there always are key
            break;
        temp_field_pointer = temp_field_pointer->next;
        key_index++;
    }

    if((column == key_index) && (newVal == ""))
    {
        cout << "Empty or duplicate primary key.\n";
        return;
    }

    if(column == key_index)
        for(int i = 0; i < numRows; i++)
        {
            if(i != row)
                if(operator[](key_index)[i]== newVal)
                {
                    cout << "Empty or duplicate primary key.\n";
                    return;
                }
        }

    temp_field_pointer = fieldHead;         //find the type
    for (int i = 0; i < column; i++)
        temp_field_pointer = temp_field_pointer->next;
    
    if((temp_field_pointer->type == INT)&&(!isInteger(newVal)))
    {
        cout << "Cannot insert non-integer in integer field.\n";
        return;
    }
    
    operator[](column)[row] = newVal;
    return;
}

void Table::setPrimaryKey(const String &name){

    Field* temp_field_pointer = findField(name);
    if(temp_field_pointer == nullptr)
        return;

    for(int i = 0; i < numRows; i++)
        for(int j = i+1; j < numRows; j++)
            if(temp_field_pointer->column[i]==temp_field_pointer->column[j])
            {
                cout << "Cannot set field with duplicate elements as primary key.\n";
                return;
            }
    for(int row = 0; row < numRows; row++)
        if(temp_field_pointer->column[row]=="")
        {
            cout << "Cannot set field with empty data as primary key.\n";
            return;
        }

    primaryKey = temp_field_pointer;
    return;
}

void Table::setColumnIndex(int index, const String &target){

    Field* target_field = fieldHead;
    Field* target_field_prev = nullptr;
    int target_index = 0;

    while(target_field != nullptr)
    {
        if(target_field->name == target)
            break;
        else
        {
            target_field_prev = target_field;
            target_field = target_field->next;
            target_index++;
        }
    }

    if(target_field == nullptr)
    {
        cout << "No such field with provided name exists.\n";
        return;
    }
    if(index >= numCols)
    {
        cout << "Table column index is out of bounds.\n";
        return;
    }

    Field* index_field = fieldHead;
    //Field* index_field_next = fieldHead->next;
    Field* index_field_prev = nullptr;
    for(int count = 0; count < index; count++)
    {
        index_field_prev = index_field;
        index_field = index_field->next;
        // if(index_field_next!=nullptr)
        //     index_field_next = index_field_next->next;
    }
    
    if(target_field != fieldHead)
    {
        if(index_field != fieldHead)
        {
            if(target_index > index)
            {
                target_field_prev->next = target_field->next;
                index_field_prev->next = target_field;
                target_field->next = index_field;
            }
            else if(target_index < index)
            {
                target_field_prev->next = target_field->next;
                target_field->next = index_field->next;
                index_field->next = target_field;

            }   
        }
        else    //this no prob
        {
            target_field_prev->next = target_field->next;
            fieldHead = target_field;
            target_field->next = index_field;
        }
    }
    else    //(target_field == fieldHead)
    {
        if(index_field != fieldHead)
        {
            fieldHead = fieldHead->next;
            target_field->next = index_field->next;
            index_field->next = target_field;
        }
        else    //this no prob
        {
            return;
        }
    }

    return;
}

void Table::deleteField(const String &name){

    Field* target_field = fieldHead;
    Field* target_field_prev = nullptr;
    while(target_field != nullptr)
    {
        if(target_field->name == name)
            break;
        else
        {
            target_field_prev = target_field;
            target_field = target_field->next;
        }
    }
    if(target_field == nullptr)
    {
        cout << "No such field with provided name exists.\n";
        return;
    }
    if(target_field == primaryKey)
    {
        cout << "Cannot delete primary key field.\n";
        return;
    }

    if(target_field == fieldHead)
    {
        fieldHead = target_field->next;
        delete [] (target_field->column);
        delete target_field;
    }
    else
    {
        target_field_prev->next = target_field->next;
        delete [] (target_field->column);
        delete target_field;
    }

    numCols--;
    return;

}

Field* Table::findField(const String &name) const{

    Field* temp_field_pointer = fieldHead;
    while(temp_field_pointer != nullptr)
    {
        if(temp_field_pointer->name == name)
            return temp_field_pointer;
        else
            temp_field_pointer = temp_field_pointer->next;
    }

    cout << "No such field with provided name exists.\n";
    return nullptr;
}

void Table::sortTable(Field* field){    

    if(field == nullptr)
    {
        cout << "Invalid field provided.\n";
        return;
    }

    Table* sorted_table = new Table(this->name);  //numRows,numCols,tableSize,name set  //next set to nullptr 
    sorted_table->numCols = 0; sorted_table->numRows = 0; 
    sorted_table->tableSize = this->tableSize;

    Field* temp_field = this->fieldHead;
    for(int index = 0; index < numCols; index++)
    {
        sorted_table->addField(index, temp_field->name, temp_field->type);  
       //Headfield is automatically setted when call the addField() fucntion when index = 0
        if(temp_field == this->primaryKey)                  //set the primary key of new table
            sorted_table->setPrimaryKey(temp_field->name);
        temp_field = temp_field->next;
    }
    sorted_table->numCols = this->numCols; sorted_table->numRows = this->numRows;
    
    //find the index of the field
    Field* temp_field_2 = this->fieldHead; int sorting_index = 0;    
    while(temp_field_2 != nullptr)
    {
        if(temp_field_2 == field)
            break;
        else
            sorting_index++;
    }

    //A new empty with same info created 
    // Start sorting    (insertion sert with linear search (coz easier for implement :) ))    //assume distinct value in that field

    for(int col = 0; col < numCols; col++)                              //set the first row of the new table
        sorted_table->operator[](col)[0] = this->operator[](col)[0];
    
    bool smaller;
    
    for(int row_compare = 1; row_compare < numRows; row_compare++)
    {
        for(int row_sorted = 0; row_sorted < row_compare; row_sorted++)
        {
            if(field->type == INT)
            {   
                if(stoi(this->operator[](sorting_index)[row_compare]) < stoi(sorted_table->operator[](sorting_index)[row_sorted]))
                    smaller = true;
                else
                    smaller = false;
            }
            else //(field->type == STRING)
            {
                if(this->operator[](sorting_index)[row_compare] < sorted_table->operator[](sorting_index)[row_sorted])
                    smaller = true;
                else
                    smaller = false;
            }
            
            if(smaller) //sth like if(this->operator[](sorting_index)[row_compare] < sorted_table->operator[](sorting_index)[row_sorted]) //coz hv integer
            {
                for(int i = row_compare; i > row_sorted; i--)                                   //move the value before it 後一格
                {
                    for(int col = 0; col < numCols; col++)
                        sorted_table->operator[](col)[i] = sorted_table->operator[](col)[i-1];
                }

                for(int col = 0; col < numCols; col++)                                           //insert the new value
                    sorted_table->operator[](col)[row_sorted] = this->operator[](col)[row_compare];

                break;
            }
            else if(row_sorted + 1 == row_compare) //larger than last one
            {
                for(int col = 0; col < numCols; col++)
                    sorted_table->operator[](col)[row_compare] = this->operator[](col)[row_compare];
                
                break;
            }
        }
    }

    //copy the sorted element to this table
    for(int row = 0; row < numRows; row++)
        for(int col = 0; col < numCols; col++)
            this->operator[](col)[row] = sorted_table->operator[](col)[row];
    
    //then delete the old sorted one 
    
    delete sorted_table;

    //actually can let this table point to new field, and delete the old one for effieiency

    return;
}