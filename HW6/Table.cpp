#include <fstream>
#include "Table.h"
#include "String.h"

using namespace std;

bool func_asc(String* a, String* b) { return (*a < *b); }
bool func_int_asc(String*a, String* b) { return (stoi(*a) < stoi(*b)); }
void swap_single(String* a, String* b) {
    String temp = *a;
    *a = *b;
    *b = temp;
}
#define addr(at) (((long long) (at) & 0xFFFF) >> 2)
void swap_fields(Field* fieldHead, String* o, String* a, String* b) {
    // cout << "a: " << addr(a) << " b: " << addr(b) << endl;
    long long index_a = ((long long) a - (long long) o) / sizeof(String*);
    long long index_b = ((long long) b - (long long) o) / sizeof(String*);
    // cout << index_a << " " << index_b << endl;
    Field* temp_field = fieldHead;
    String temp;
    for (; temp_field; temp_field = temp_field->next) {
        temp = temp_field->column[index_a];
        temp_field->column[index_a] = temp_field->column[index_b];
        temp_field->column[index_b] = temp;
    }
}


void sort(String* start, String* end, bool (*func)(String*, String*), Field* fieldHead, void (*swap)(Field*, String*, String*, String*)) {
 // insertion sort
    // cout << addr(start) << " " << addr(end) << endl;
    String* tar = start, *elm, temp, *best;
    for (; tar < end; tar++) {
        // cout << "tar: " << addr(tar) << endl;
        best = tar;
        for (elm = tar + 1; elm <= end; elm++) {
            if (!func(best, elm)) {
                best = elm;
            }
        }
        // cout << "best: " << addr(best) << endl;
        if (*best != *tar) { // swap
            swap(fieldHead, start, best, tar);
        }
    }
}

void sort(String* start, String* end, bool (*func)(String*, String*)) {
     // insertion sort
    // cout << addr(start) << " " << addr(end) << endl;
    String* tar = start, *elm, temp, *best;
    for (; tar < end; tar++) {
        // cout << "tar: " << addr(tar) << endl;
        best = tar;
        for (elm = tar + 1; elm <= end; elm++) {
            if (!func(best, elm)) {
                best = elm;
            }
        }
        // cout << "best: " << addr(best) << endl;
        if (*best != *tar) { // swap
            swap_single(best, tar);
        }
    }
}


void sort(String* start, String* end) {
    sort(start, end, func_asc);
}

/*
The constructor. Create a new Table.
Initilaise pointers to nullptr.
Initialise numRows and numCols to 0, and tableSize to 100.
Set table name as provided.
*/
Table::Table(const String &name) { // should be working
    this->primaryKey = nullptr;
    this->fieldHead = nullptr;
    this->numRows = 0;
    this->numCols = 0;
    this->tableSize = 100;
    this->name = name;
}

Table::Table(ifstream &ifs, const String &name) : Table(name) {
    int cols, rows;
    ifs >> cols >> rows;
    String temp, fieldName; char type;
    for (int c = 0; c < cols; c++) {
        if (c == cols - 1) getline(ifs, temp, '\n');
        else { getline(ifs, temp, ','); }  
        type = temp[temp.length() - 1];
        if (temp[0] == '*') {
            fieldName = temp.substr(1, temp.length() - 3);
            // cout << fieldName << endl;
            addField(c, fieldName, (type == '0') ? INT : STRING);
            setPrimaryKey(fieldName); 
        } else {
            fieldName = temp.substr(0, temp.length() - 2);
            // cout << fieldName << endl;
            addField(c, fieldName, (type == '0') ? INT : STRING);
        }
    }
    String* fields = new String[cols];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (c == cols - 1) getline(ifs, fields[c], '\n');
            else { getline(ifs, fields[c], ','); }  
            // cout << fields[c];
        }
        addRecord(r, fields);
    }
    delete [] fields;
    // cout << "done!";
}

/*
Deallocate all of the fields in the Table object. 
Remember to deallocate the dynamic array.
*/
Table::~Table() {
    Field* field = this->fieldHead;
    if (field == nullptr) return;
    Field* nextField;
    for (int c = 0; c < numCols; c++) {
        nextField = field->next;
        // cout << this->name << endl;
        delete [] field->column;
        delete field;
        field = nextField;
    }
}

/*
Adds a record to the provided row index of the table, record is an array containing the values of every field (same order as the fields themselves).
Null pointer:
If record is a null pointer, print Record is empty.\n and return.
Dimensions mismatch:
If the target index is greater than the number of rows in the table or smaller than 0, print Table row index is out of bounds.\n and return.
Primary key error:
If primary key stored in record is empty ("") or is the same as another record, print Empty or duplicate primary key.\n and return.
Type mismatch:
If a field has type INT but the corresponding value in record is not an integer, print Cannot insert non-integer in integer field.\n and return.
Do validation according to the order above. For example, if there are both dimension mismatch and primary key error, you print the message of dimension mismatch and return.
Procedure:
If the new record will not be the last row, do some moving to make space for the new record. The relative order of those original records should remain the same.
Insert the data from the record and increase numRows.
If numRows is equal to tableSize then:
Allocate a new dynamic array with 100 more positions and update tableSize.
Copy all the data from the old column to the new column.
Deallocate the old column and make the current field point to the new column.
You may use the == operator to compare two String-type objects. Additionally, you may use the provided isInteger(const String&) function to check whether a particular String object is a number or not.
*/
void Table::addRecord(int index, String *record) { // should be fine?
// written with the assumption that it has at least one field, which is okay according to main.cpp
    if (record == nullptr) { // Null Pointer
        cout << "Record is empty.\n";
        return;
    }
    if (index < 0 || index > this->numRows) { // Dimensions mismatch
        cout << "Table row index is out of bounds.\n";
        return;
    }

    // now we deal with the string
    if (record->length() == 0) { // if the string is empty
        cout << "Empty or duplicate primary key.\n";
        return;
    }

    // checking for primary key errors and mismatch
    Field* field = this->fieldHead;
    int col = 0;
    bool primaryKeyFlag = false, typeMismatchFlag = false;
    for (; field; col++, field = field->next) {
        if (this->primaryKey == field) { // if this is a primary key field
            if (record[col] == "") primaryKeyFlag = true; // disallowing empty key field
            for (int r = 0; r < numRows; r++) { // checking for duplicates
                if (record[col] == field->column[r]) {
                    primaryKeyFlag = true;
                    break;
                }
            }
        } 
        // checking for type mismatch (INT, but record is not integer)
        if (field->type == INT && !isInteger(record[col])) typeMismatchFlag = true;
    }

    if (col != numCols) {
        cerr << "numCols is wrong";
        exit(-1);
    }

    if (primaryKeyFlag) {
        cout << "Empty or duplicate primary key.\n";
        return;
    } else if (typeMismatchFlag) {
        cout << "Cannot insert non-integer in integer field.\n";
        return;
    } else {
        // insert the fields
        if (this->numRows == this->tableSize) { // need to reallocate more space
            this->tableSize += 100; // incrmeent the tableSize (>=100)
            
            for (field = this->fieldHead; field; field = field->next) { 
                String* newColumn = new String[this->tableSize];
                for (int r = 0; r < numRows; r++) { // copy the array contents
                    newColumn[r] = field->column[r];
                } 
                delete [] field->column;
                field->column = newColumn;
            }
        }
        
        // then add the record
        for (field = this->fieldHead, col = 0; field; field = field->next, col++) {
            for (int r = numRows; r > index; r--) {
                field->column[r] = field->column[r - 1];
            }
            field->column[index] = record[col]; // add the records
        }

        this->numRows++;
    }

}

/*
Allocate a new Field struct and place it at position index of the linked list.
Dimensions mismatch:
If the target index is greater than numCols or smaller than 0, print Table column index is out of bounds.\n and return.
Name error:
If a field with the given name already exists in the table, print Field with given name already exists in table.\n and return.
Again, do validation according to the order above.

Procedure
Allocate a new field. 
Additionally, allocate a String array and make Field::column point to it. Increase numCols.
Place the field at the appropriate position in the linked-list. For instance, if the the target index is 1, set the new field's index to be the new second (index 1) column.
If the field is of type INT, initialise all cells to "0", otherwise initialize them to "".
Additionally, if this the first field to be added to the table, set it to be the primary key.
*/
void Table::addField(int index, const String &name, TYPE type) { // i think it works?
    if (index < 0 || index > numCols) { // Dimensions mismatch
        cout << "Table column index is out of bounds.\n";
        return;
    }

    Field* field;
    for (field = this->fieldHead; field && field->name != name; field = field->next);
    if (field) {
        cout << "Field with given name already exists in table.\n";
        return;
    }

    Field* newField = new Field;
    if (index == 0) {
        newField->next = this->fieldHead;
        this->fieldHead = newField;
    } else {
        field = this->fieldHead;
        for (int i = 0; i < index - 1; i++, field = field->next);
        newField->next = field->next;
        field->next = newField;
    }
    newField->name = name;
    newField->type = type;
    newField->column = new String[this->tableSize];
    if (type == INT) {
        for (int r = 0; r < this->tableSize; r++) {
            newField->column[r] = "0";
        }  
    } else {
        for (int r = 0; r < this->tableSize; r++) {
            newField->column[r] = "";
        }
    }
    
    if (numCols == 0) this->primaryKey = newField;
    this->numCols++;
}

/*
Delete a record from the table.
If row is greater than or equal to the number of rows in the table or smaller than 0, print Table row index is out of bounds.\n and return.
Otherwise, delete the row indicated by row. This is done by remove the corresponding value in every field. If the deleted row is not the last row, do some moving to fill the blank. The relative order of the other records should remain the same.
Decrease numRows.
*/
void Table::deleteRecord(int row) {
    if (row < 0 || row >= numRows) {
        cout << "Table row index is out of bounds.\n";
        return;
    }
    for (Field* field = this->fieldHead; field; field = field->next) {
        for (int r = row; r < numRows - 1; r++) {
            field->column[r] = field->column[r + 1];
        }
        field->column[numRows - 1] = (field->type == INT) ? "0" : "";
    }
    numRows--;
}

/*
Modify the cell specified by row and row to hold newVal.
Dimensions mismatch:
If row is greater than or equal to numRows or less than 0, print Table row index is out of bounds.\n and return.
If column is greater than or equal to numCols or less than 0, print Table column index is out of bounds.\n and return.
Primary key error:
If this modification is going to trigger a primary key conflict or if the primary key is going to be empty (""), print Empty or duplicate primary key.\n and return.
Type mismatch:
If strVal is a string but the column that it corresponds to is of type INT, print Cannot insert non-integer in integer field.\n and return.
Again, do validation according to the order above.
Again, you may use the provided isInteger(const String&) function to check whether a particular String object is a number or not.
*/
void Table::modifyRecord(int row, int column, const String &newVal) {
    if (row >= numRows || row < 0) {
        cout << "Table row index is out of bounds.\n";
        return;
    }
    if (column >= numCols || column < 0) {
        cout << "Table column index is out of bounds.\n";
        return;
    }
    Field* field = this->fieldHead;
    for (int c = 0; c < column; c++, field = field->next);
    if (primaryKey == field) { // if it is a primary field
        if (newVal == "") {
            cout << "Empty or duplicate primary key.\n";
            return;
        }
        for (int r = 0; r < numRows; r++) {
            if (field->column[r] == newVal && r != row) {
                cout << "Empty or duplicate primary key.\n";
                return;
            }
        }
    } 
    if (field->type == INT && !isInteger(newVal)) {
        cout << "Cannot insert non-integer in integer field.\n";
        return;
    }
    field->column[row] = newVal;
}


/*
Set the field specified by name as the new primary key.
Errors:
If there is no field with the name name in the table, print No such field with provided name exists.\n and return.
If there is such a field, check the column.
If the column has any duplicates, print Cannot set field with duplicate elements as primary key.\n and return.
If the column has any empty data (""), print Cannot set field with empty data as primary key.\n and return.
*/
void Table::setPrimaryKey(const String &name) {
    Field* field = this->fieldHead;
    for (; field && field->name != name; field = field->next); // find the corresponding field
    if (field) {
        String* tempCol = new String[numRows];
        for (int r = 0; r < numRows; r++) { // copy to tempCol
            tempCol[r] = field->column[r];
        }
        sort(tempCol, tempCol + (numRows-1)); // sort the array
        for (int r = 0; r < numRows - 1; r++) {
            if (tempCol[r] == tempCol[r+1]) { // contains duplicates
                cout << "Cannot set field with duplicate elements as primary key.\n";
                delete [] tempCol;
                return;
            }
        }
        for (int r = 0; r < numRows; r++) { // copy to tempCol
            if (tempCol[r] == "") {
                cout << "Cannot set field with empty data as primary key.\n";
                delete [] tempCol;
                return;
            }
        }
        delete [] tempCol;
        primaryKey = field;        
    } else {
        cout << "No such field with provided name exists.\n";
        return;
    }
}

/*
Move the field specified by target so that it is at position index.
If no field with the given name exists in the table, print No such field with provided name exists.\n and return.
If index is greater than or equal to numCols or less than 0, print Table column index is out of bounds.\n and return.
Again, do validation according to the order above.
*/
void Table::setColumnIndex(int index, const String &target) {
    Field* prevField = nullptr;
    Field* field = this->fieldHead;
    for (; field && field->name != target; prevField = field, field = field->next);
    if (field) {
        if (index < 0 || index >= numCols) {
            cout << "Table column index is out of bounds.\n";
            return;
        }
        // first, rerout the field before the moved field
        if (prevField) {
            prevField->next = field->next;
        } else {
            this->fieldHead = field->next;
        }
        // then, in the new position, point the previous field at the moved field
        if (index == 0) {
            field->next = this->fieldHead;
            this->fieldHead = field;
        } else {
            Field* prevNew = this->fieldHead;
            for (int i = 0; i < index - 1; i++, prevNew = prevNew->next);
            field->next = prevNew->next;
            prevNew->next = field;
        }
    } else {
        cout << "No such field with provided name exists.\n";
        return;
    }
}

/*
Delete the field specified by name.
If no field with the given name exists in the table, print No such field with provided name exists.\n and return.
If the target field to be deleted is the primary key, print Cannot delete primary key field.\n and return.
Otherwise, deallocate the field and the dynamic array, decrease numCols.
*/
void Table::deleteField(const String &name) { // should be okay?
    Field* prevField = nullptr;
    Field* field = this->fieldHead;
    for (; field && field->name != name; prevField = field, field = field->next);
    if (field) {
        if (primaryKey == field) {
            cout << "Cannot delete primary key field.\n";
            return;
        }
        if (prevField) { // is not the first field
            prevField->next = field->next;
        } else { // is the first field
            this->fieldHead = field->next;
        }
        delete [] field->column;
        delete field;
        numCols--;
    } else {
        cout << "No such field with provided name exists.\n";
        return;
    }
}

Field* Table::findField(const String &name) const {
    Field* field = this->fieldHead;
    for (; field && field->name != name; field = field->next);
    if (field == nullptr) {
        cout << "No such field with provided name exists.\n";
    }
    return field;    
}


void Table::sortTable(Field* field) { // wronglly implemented
 
    if (field) {
        if (field->type == INT) {
            sort(field->column, field->column+(numRows-1), func_int_asc, fieldHead, swap_fields);
        } else {
            sort(field->column, field->column+(numRows-1), func_asc, fieldHead, swap_fields);
        }
    } else {
        cout << "Invalid field provided.\n";
        return;
    }
}

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