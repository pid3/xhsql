#include "Parse.h"
#include <sstream>
Parse::Parse(string acommand, vector<vector<string>> db)
    : command(acommand), dbData(db)
{
    for(auto &record : dbData)
    {
        dbFile.insert(record.front());
    }
}

enum Action {SELECT, CREATE, INSERT};
struct Entry{
    Action  action;
    string table;
};
struct Select : Entry
{
    vector<string> property;
};

struct Insert :Entry
{
    vector<int> value;
};

struct Create :Entry
{
    Entry entry;
    vector<string> property;
};
Entry *lex(string command)
{
    istringstream is(command);
    string word;
    is >> word;
    if(word == "select")
    {
        Select *select = new Select;
        select->action = SELECT;
        is >> word;
        while(word != "from")
        {
            select->property.push_back(word);
        }
        is >> select->table;
        return select;
    }
    else if (word == "insert")
    {
        Insert *insert = new Insert;
        insert->action = INSERT;
        is >> word;
        is >> word;
        insert->table = word;
        int i;
        while(is >> i)
            insert->value.push_back(i);
        return insert;
    }
    return nullptr;
}
void Parse::interpret()
{
    Entry *entry = lex(command);
    if(entry->action == SELECT)
    {
        Select *select = reinterpret_cast<Select *>(entry);
        std::cout << select->property.front() << endl;
        ifstream it(select->table);
        int id;
        while(it >> id)
        {
            cout <<  "| " << select->table << " |";
            cout <<  "\n| " << id << " |";
        }
    }
    else if (entry->action == INSERT)
    {
        Insert *insert = reinterpret_cast<Insert *>(entry);
        ofstream ot(insert->table, ios::app);
        ot << "\n" << insert->value.front();
        cout << "insert ok" ;
    }
}
/*        string command;*/
        //vector<vector<string>> dbData;
        //vector<fstream> dbFile;
// select ---->action
// create ----->action
// insert ----->action
//


