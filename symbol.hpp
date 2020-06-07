#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum{
    TT_OBJ,
    TT_INT,
    TT_STRING,
    TT_FLOAT,
    TT_BOOL,
    TT_FUNC,
    TT_NONE
};

struct symbolTable_data{
    string name;
    int type;

    int data_type;
    int intVal;
    float floatVal;
    bool boolVal;
    string stringVal;
    bool isInit = false;
    bool isConst;

    bool isArr = false;
    int arrSize;
    int* intArr;
    float* floatArr;
    bool* boolArr;
    string* stringArr; 
};

struct symbolTable{
    string scopeName;
    vector<symbolTable_data>table_datas;

};

class symbolTables{
    public:
        symbolTables();
        void push(string);
        void pop();
        void dump();
        bool add(symbolTable_data);
        bool update(symbolTable_data);
        symbolTable_data lookup_all(string);
        symbolTable_data lookup_current(string);
    private:
        vector<symbolTable> tables;
};