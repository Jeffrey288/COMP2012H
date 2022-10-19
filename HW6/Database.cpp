#include <fstream>
#include <iomanip>
#include <iostream>
#include "Database.h"
#include "String.h"
#include "Table.h"

using namespace std;

/*
Create a new Database. In this function you can assume 
0 <= numTables && numTables < 100.
Set currentTable to nullptr, this->numTables to be numTables, this->name to be name
Create numTables tables and name them as Table_i where i ranges from 1 to numTables (inclusive). 
The first table in the linked list (pointed by tableHead) should be Table_1, and so on.
 */
Database::Database(const String &name, int numTables) { // should be working
    currentTable = nullptr;
    this->numTables = numTables;
    this->name = name;
    Table* nextTable = nullptr;
    char buff[20] = "Table_";
    for (int n = numTables; n >= 1; n--) {
        sprintf(buff + 6, "%d", n);
        Table* table = new Table(buff);
        table->next = nextTable;
        nextTable = table;
    }
    this->tableHead = nextTable; // links to the first table
}

Database::Database(const String &filename) {
    ifstream ifs(filename.getStr());
    getline(ifs, this->name, '\n');
    this->numTables = 0;
    this->tableHead = nullptr;

    int tables;
    ifs >> tables;
    String tableName;
    for (int t = 0; t < tables; t++) {
        getline(ifs, tableName, '\n'); 
        Table* table = new Table(ifs,  tableName);
        // cout << numTables << endl;
        addTable(table);
        // cout << "done!";
    }
    ifs.close();
}

Database::~Database() {
    cout << "This was not called" << endl;
    Table* table = this->tableHead;
    cout << "Bay" << endl;
    if (table == nullptr) return;
    Table* nextTable = table->next;
    cout << "Hey" << endl;
    // ! assumes that numTable is correct (important)
    for (int n = 0; n < this->numTables; n++) { 
        delete table;
        cout << "Deleted table " << n << endl;
        table = nextTable;
        if (table == nullptr) return;
        nextTable = table->next;
    }
}

/*
Push the provided table to the end of the Table linked-list.
If table is a null pointer, print Table is a null pointer.\n and return false.
If a table with the same name as table already exists in the database, print Table with given name already exists in the database.\n and return false.
Otherwise push the new table to the end of the linked list, increase numTables and return true.
You may use the == operator to compare two String-type objects.
*/
bool Database::addTable(Table *table) { // should be okay
    if (table == nullptr) {
        cout << "Table is a null pointer.\n";
        return false;
    }
    if (findTable(table->getName())) { // assumes work and doesn't cout anything
        cout << "Table with given name already exists in the database.\n";
        return false;
    }
    if (numTables == 0) { // no tables, ! assumes that numTable is correct
        this->tableHead = table;
    } else {
        Table* lastTable = this->tableHead;
        while (lastTable->next) {lastTable = lastTable->next;}
        lastTable->next = table;
    }
    table->next = nullptr; // ! dunno if need this
    numTables++;
    return true;
}

/*
Create a new table with name name.
If a table with the provided name exists in the database, print Table with given name already exists in the database.\n and return.
Otherwise, allocate a new table object, add it to the end of the linked list, and increase numTables.
*/
void Database::addTable(const String &name) { // should be working
    Table* newTable = new Table(name);
    if (!addTable(newTable)) {
        delete newTable;
    } 
}

/*
Return a pointer to the table with the name specified by name. 
Return nullptr if no table with the provided name exists in the database.
*/
Table* Database::findTable(const String &name) const { // should be correct
    Table* currTable = this->tableHead;
    while (currTable) {
        if (currTable->getName() == name) {
            return currTable;
        }
        currTable = currTable->next;
    }
    return nullptr;
}

void Database::listTables() const { // should be working
    cout << "The tables currently existing in the database are:\n";
    Table* currTable = this->tableHead; 
    while (currTable) {// if no tables, immediately returns
        cout << currTable->getName() << "\n";
        currTable = currTable->next;
    }
}

void Database::deleteTable(const String &name) { // should be working
    Table* prevTable = nullptr;
    Table* table = this->tableHead;
    while (table && table->getName() != name) {
        prevTable = table;
        table = table->next;
    }
    if (table) {
        if (prevTable == nullptr) { // i.e. this table is the first one
            this->tableHead = table->next;
        } else {
            prevTable->next = table->next;
        }
        delete table;
        numTables--;
    } else {
        cout << "No such table exists in the database.\n";
    }
}

void Database::setCurrentTable(const String &name) {
    this->currentTable = findTable(name);
    if (this->currentTable == nullptr)
        cout << "No such table exists in the database.\n";
}

void Database::saveDatabase(const String &filename) const {
    ofstream ofs(filename.getStr());
    ofs << this->name << endl;
    Table* table = tableHead;
    Field* field;
    ofs << this->numTables << endl;
    for (; table; table = table->next) {
        int rows = table->getNumRows(), cols = table->getNumCols();
        ofs << table->getName() << endl;
        ofs << cols << endl;
        ofs << rows << endl;
        field = table->getFieldHead();
        for (int c = 0; c < cols; c++, field = field->next) {
            if (field == table->getPrimaryKey()) ofs << "*";
            ofs << field->name << " " << ((field->type == INT) ? 0 : 1);
            if (c == cols - 1) {
                ofs << endl;
            } else {
                ofs << ", ";
            }
        }
        for (int r = 0; r < rows; r++) {
            field = table->getFieldHead();
            for (int c = 0; c < cols; c++, field = field->next) {
                ofs << field->column[r];
                if (c == cols - 1) {
                    ofs << endl;
                } else {
                    ofs << ", ";
                }
            }
        }
    }
    ofs.close();
    
}

void Database::innerJoin(Table *table1, Table *table2) {
    if (table1 == nullptr || table2 == nullptr) {
        cout << "No such table exists in the database.\n";
        return;
    }

    Field* keyField1 = table1->getPrimaryKey();
    Field* keyField2 = table2->getPrimaryKey();
    if (keyField1->type != keyField2->type) {
        cout << "Type mismatch between target fields.\n";
        return;
    }

    int row1 = table1->getNumRows(), row2 = table2->getNumCols();
    int cols = 0;
    Table* table = new Table(table1->getName() + "+" + table2->getName());
    Field* field = table->getFieldHead();
    Field* field1 = table1->getFieldHead();
    Field* field2 = table2->getFieldHead();

    table->addField(cols++, keyField1->name + "+" + keyField2->name, keyField1->type);
    for (field1 = table1->getFieldHead(); field1; field1 = field1->next) {
        if (field1 == keyField1) continue;
        table->addField(cols++, field1->name, field1->type);
    }
    for (field2 = table2->getFieldHead(); field2; field2 = field2->next) {
        if (field2 == keyField2) continue;
        bool dupFlag = false;
        String temp;
        for (field1 = table1->getFieldHead(); field1; field1 = field1->next) {
            if (field1->name == field2->name) {dupFlag = true; break;}
        }
        if (dupFlag) {
            temp = field2->name + "(T2)";
        } else {
            temp = field2->name;
        }
        table->addField(cols++, temp, field2->type);
    }

    // this->addTable(table);
    // return;

    String* fields = new String[cols];
    int col = 0;
    int row = 0;
    bool matchFlag = false;
    int r1, r2;
    for (r1 = 0; r1 < row1; r1++) {
        matchFlag = false;
        for (r2 = 0; r2 < row2; r2++) {
            if (keyField1->column[r1] == keyField2->column[r2]) {
                matchFlag = true;
                break;
            }
        }
        if (!matchFlag) continue;
        col = 0;
        field = table->getFieldHead();
        fields[col++] = keyField1->column[r1];
        for (field1 = table1->getFieldHead(); field1; field1 = field1->next) {
            if (field1 == keyField1) continue;
            fields[col++] = field1->column[r1];
        }
        for (field2 = table2->getFieldHead(); field2; field2 = field2->next) {
            if (field2 == keyField2) continue;
            fields[col++] = field2->column[r2];
        }
        table->addRecord(row++, fields);
    }
    
    this->addTable(table);
    delete [] fields;

}

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