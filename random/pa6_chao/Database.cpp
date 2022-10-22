#include <fstream>
#include <iomanip>
#include <iostream>
#include "Database.h"
#include "String.h"
#include "Table.h"

using namespace std;

void Database::printTable(Table *table) const
{
    if (table == nullptr)
    {
        cout << "No such table exists in the database." << endl;
        return;
    }

    for (Field *cur = table->getFieldHead(); cur != nullptr; cur = cur->next)
    {
        cout << setw(15) << left;
        String curPrintName = (cur == table->getPrimaryKey() ? "*" : "") + cur->name + ' ' + (cur->type == INT ? "0" : "1");
        cout << curPrintName;
    }
    cout << endl;
    for (int i = 0; i < table->getNumRows(); ++i)
    {
        for (int j = 0; j < table->getNumCols(); ++j)
        {
            cout << setw(15) << left;
            cout << (*table)[j][i];
        }
        cout << endl;
    }

    return;
}

Database::Database(const String &name, int numTables): name(name),numTables(numTables) {

    currentTable = nullptr;
    tableHead = nullptr;

    Table* temp_table_pointer = nullptr;

    for(int i = 1; i < numTables+1; i++)
    {
        if(i == 1)
        {
            tableHead = new Table("Table_1");
            temp_table_pointer = tableHead;    
        }
        else
        {
            char s1 = '0' + i%10;
            char s2 = '0' + i/10;
            String template_table = "Table_";
            String thename;
            if(s2 != '0')
                thename = template_table + s2 + s1;
            else
                thename = template_table + s1;
            // cout << "test " << "i = " << i << "numTables "<< numTables << endl;
            temp_table_pointer->next = new Table(thename);
            temp_table_pointer = temp_table_pointer->next;
        };

    }

    //test
    /* char s = '0' + 2;
    String template_table = "Table_";
    String thename = template_table + s;
    tableHead = new Table("Table_1");
    tableHead->next = new Table(thename);
    delete tableHead->next;
    tableHead->next = nullptr; */


}

Database::Database(const String &filename){

    
    ifstream ifs(filename.getStr());
    Table* temp_table_pointer;

    currentTable = nullptr;
    ifs >> name;        //the name for first line
    ifs >> numTables;   //the numTables for second line
    for(int table = 0; table < numTables; table++)  //creating tables
    {
        String table_name;
        ifs >> table_name;

        if(table == 0)
        {
            tableHead = new Table(ifs, table_name);
            temp_table_pointer = tableHead;
        }    
        else
        {
            temp_table_pointer->next = new Table(ifs,table_name);
            temp_table_pointer = temp_table_pointer->next;
        }

        /* if(table == numTables-1)
            temp_table_pointer->next = nullptr; */
    }

    ifs.close();
}

Database::~Database(){

    Table* table_pointer_delete = tableHead; //table_pointer_for_delete
    Table* temp_table_pointer = nullptr;

    if(tableHead != nullptr)
        temp_table_pointer = tableHead->next;

    while(table_pointer_delete != nullptr)
    {
        delete table_pointer_delete;
        table_pointer_delete = temp_table_pointer;
        if(temp_table_pointer != nullptr)                   //prevent error
            temp_table_pointer = temp_table_pointer->next;
    }

}

void Database::addTable(const String &name){

    Table* temp_table_pointer = tableHead;
    Table* new_table = nullptr;       


    while(temp_table_pointer != nullptr)
    {
        if(temp_table_pointer->getName() == name)
            break;
        else
        {
            if(temp_table_pointer->next == nullptr)
                new_table = temp_table_pointer;
            temp_table_pointer = temp_table_pointer->next;
        }
    }

    if(temp_table_pointer != nullptr)
    {
        cout << "Table with given name already exists in the database.\n";
        return;
    }
    
    if(new_table != nullptr)
        new_table->next = new Table(name);
    else
        tableHead = new Table(name);

    numTables++;
    return;

}

bool Database::addTable(Table *table){

    if(table == nullptr)                        //special case
    {
        cout << "Table is a null pointer.\n";
        return false;
    }

    Table* temp_table_pointer = tableHead;
    Table* new_table = nullptr;


    while(temp_table_pointer != nullptr)
    {
        if(temp_table_pointer->getName() == table->getName())
            break;
        else
        {
            if(temp_table_pointer->next == nullptr)
                new_table = temp_table_pointer;
            temp_table_pointer = temp_table_pointer->next;
        }
    }

    if(temp_table_pointer != nullptr)
    {
        cout << "Table with given name already exists in the database.\n";
        return false;
    }
    
    if(new_table!=nullptr)
    {
        table->next = nullptr; 
        new_table->next = table;
    }
    else
    {
        table->next = nullptr;
        tableHead = table;
    }
    
    numTables++;
    return true;

}

Table* Database::findTable(const String &name) const{

    Table* temp_table_pointer = tableHead;

    while(temp_table_pointer != nullptr)
    {

        if(temp_table_pointer->getName() == name)
            break;
        else 
            temp_table_pointer = temp_table_pointer->next;

    }
    return temp_table_pointer;

}

void Database::listTables() const{

    Table* temp_table_pointer = tableHead;

    cout << "The tables currently existing in the database are:\n";

    while(temp_table_pointer != nullptr)
    {
        cout << temp_table_pointer->getName().getStr() << endl;
        temp_table_pointer = temp_table_pointer->next;
    }

}

void Database::deleteTable(const String &name){ 

    Table* temp_table_pointer = tableHead;
    Table* last_pointer = nullptr;

    // bool found = false;     //can use temp_table_pointer == nullptr ->false instead

    while(temp_table_pointer != nullptr)    //find the table    //not correct coz no prev like deque-> tomorrow sin do zzz
    {
        if(name == temp_table_pointer->getName())
            break;  
        else
        {
            last_pointer = temp_table_pointer;
            temp_table_pointer = temp_table_pointer->next;
        }
    }

    
    if(temp_table_pointer == nullptr)       //not found
    {
        cout << "No such table exists in the database.\n";
        return;
    }
    else if(temp_table_pointer == tableHead) //delete first one;
    {
        tableHead = temp_table_pointer->next;
        delete temp_table_pointer;
        numTables--;
    }
    else 
    {
        cout << "test";
        last_pointer->next = temp_table_pointer->next;
        delete temp_table_pointer;
        numTables--;
    }
    return;

}

void Database::setCurrentTable(const String &name){

    Table* temp_table_pointer = tableHead;

    while(temp_table_pointer != nullptr)    //find the table
    {
        if(name == temp_table_pointer->getName())
            break;
        else
            temp_table_pointer = temp_table_pointer->next;
    }
    if(temp_table_pointer == nullptr)       //not found
    {
        cout << "No such table exists in the database.\n";
        return;
    }
    else
    {
        currentTable = temp_table_pointer;
        return;
    }
}

void Database::saveDatabase(const String &filename) const{

    remove(filename.getStr());          //remove the old one
    ofstream ofs(filename.getStr());     //ofs
    ofs << name << '\n'; ofs << numTables << '\n'; //first two lines

    Table* temp_table_pointer = tableHead;

    while(temp_table_pointer != nullptr)  //store each table respectively
    {
        ofs << temp_table_pointer->getName() << '\n';
        ofs << temp_table_pointer->getNumCols() << '\n';
        ofs << temp_table_pointer->getNumRows() << '\n';

        Field* temp_field_pointer = temp_table_pointer->getFieldHead(); //set head to print field
        while(temp_field_pointer != nullptr)    //store the field info
        {
            if(temp_field_pointer == temp_table_pointer->getPrimaryKey())   //star of key
                ofs << '*';
            ofs << temp_field_pointer->name <<' ';    //name
            ofs << temp_field_pointer->type;    //type
            if(temp_field_pointer->next != nullptr) 
                ofs << ", ";
            else
                ofs << '\n';
            
            temp_field_pointer = temp_field_pointer->next;
        }

        temp_field_pointer = temp_table_pointer->getFieldHead(); //reset to head to print records
        for(int record = 0; record < temp_table_pointer->getNumRows(); record++)
        {
            for(int field = 0; field < temp_table_pointer->getNumCols(); field++)
            {
                ofs << temp_table_pointer->operator[](field)[record];
                if(field != temp_table_pointer->getNumCols()-1)
                    ofs << ", ";
                else
                    ofs << '\n';

            }  
        }
        temp_table_pointer = temp_table_pointer->next;
    }

    ofs.close();
    return;

}

void Database::innerJoin(Table* table1, Table* table2){

    if((table1 == nullptr)||(table2 == nullptr))
    {
        cout << "No such table exists in the database.\n";
        return;
    }
    if(table1->getPrimaryKey()->type != table2->getPrimaryKey()->type)
    {
        cout << "Type mismatch between target fields.\n";
        return;
    }

    String new_table_name = table1->getName() + '+' + table2->getName();
    Table* new_table = new Table(new_table_name);

    String new_key_name = table1->getPrimaryKey()->name + '+' + table2->getPrimaryKey()->name ;
    new_table->addField(0, new_key_name, table1->getPrimaryKey()->type); //add the key1+key2 field //it will be primary field automatically coz addfield()


    //create empty field that combine fields of 2 table
    Field* temp_field = table1->getFieldHead(); 
    int i = 1;  String temp_field_name;
    while(temp_field != nullptr)
    {
        if(temp_field != table1->getPrimaryKey())
        {
            new_table->addField(i, temp_field->name, temp_field->type);
            i++;
        }
        temp_field = temp_field->next;
    }
    temp_field = table2->getFieldHead();
    while(temp_field != nullptr)
    {
        if(temp_field != table2->getPrimaryKey())
        {   
            if(table1->findField(temp_field->name) == nullptr)
                temp_field_name = temp_field->name;
            else    //repeated field name in two table
                temp_field_name = temp_field->name + "(T2)";
            new_table->addField(i, temp_field_name, temp_field->type);
            i++;
        }
        temp_field = temp_field->next;
    }

    //find the key index of 2 table
    int key1 = 0; int key2 = 0;
    
    temp_field = table1->getFieldHead(); 
    while(temp_field != table1->getPrimaryKey())
    {
        temp_field = temp_field->next; 
        key1++;
    }

    temp_field = table2->getFieldHead();
    while(temp_field != table2->getPrimaryKey())
    {
        temp_field = temp_field->next; 
        key2++;
    }

    //add the record
    int new_numCols =  table1->getNumCols() + table2->getNumCols() - 1;
    String* new_temp_record = new String[new_numCols];
    bool found = false; int index_newtable = 0;

    for(int row_1 = 0; row_1 < table1->getNumRows(); row_1++)
    {
        for(int row_2 = 0; row_2 < table2->getNumRows(); row_2++)
        {
            if(table1->operator[](key1)[row_1] == table2->operator[](key2)[row_2])  
            {
                new_temp_record[0] = table1->operator[](key1)[row_1];   //first is for key
                int count = 1;  
                int count_1 = 0;
                while(count_1 < table1->getNumCols())
                {
                    if(count_1 != key1)
                    {   
                        new_temp_record[count] = table1->operator[](count_1)[row_1];
                        count++;
                    }
                    count_1++;
                }
                int count_2 = 0;
                while(count_2 < table2->getNumCols())
                {
                    if(count_2 != key2)
                    {   
                        new_temp_record[count] = table2->operator[](count_2)[row_2];
                        count++;
                    }
                    count_2++;
                }
                for(int i = 0; i < new_numCols; i++)
                    cout << new_temp_record[i] << " ";
                cout << endl;
                new_table->addRecord(index_newtable, new_temp_record);
                index_newtable++;
                break;
            }
        }

    }

    delete [] new_temp_record;

    /* int new_numCols =  table1->getNumCols() + table2->getNumCols() - 1;  //for testing
    String* new_temp_record = new String[new_numCols];
    
    for(int i = 0; i < 7; i++)
        new_temp_record[i] = "1";
    new_table->addRecord(0,new_temp_record);
    
    new_temp_record[0] = "2";
    new_table->addRecord(1,new_temp_record);
    new_temp_record[0] = "3";
    new_table->addRecord(2,new_temp_record);
    delete new_temp_record; */

    addTable(new_table);    //numtable added by the function
    return;

}