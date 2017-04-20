#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
#include "Parse.h"
int main()
{
    std::string metaFile = "xhsql.db";
    vector<vector<string>> db;
    ifstream dbFile(metaFile, ios::in);
    string word;
    while(getline(dbFile, word))
    {
        string oneWord;
        vector<string> record;
        istringstream is(word);
        while(is >> oneWord)
            record.push_back(oneWord);
        db.push_back(record);
    }
    while(1)
    {
        std::string command;
        std::cout << "xhsql >" ;
        std::getline(std::cin, command);
        if(command == "exit;")
            break;
        Parse parse(command, db);
        std::cout << '\n';
        parse.interpret();
    }
    std::cout << "Bye Bye!" << "\n";
}
