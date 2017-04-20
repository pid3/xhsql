#ifndef PARSE_H_
#define PARSE_H_
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
 using namespace std;
// select pro from table; ----> 1 shu table
// create table name (p1 int , .....);2 name p1 int p2 double p3 char;
// insert into table name ; 3 table v1 v2 v3;
class Parse{
    public:
        Parse(string acommand, vector<vector<string>> db);
        void interpret();
    private:
        string command;
        vector<vector<string>> dbData;
        set<string> dbFile;
};


#endif
