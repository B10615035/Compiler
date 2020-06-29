#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum{
    TT_OBJ,
    TT_INT,
    TT_CHAR,
    TT_STRING,
    TT_FLOAT,
    TT_BOOL,
    TT_FUNC,
    TT_NONE
};

struct symbolTable_data{
    string* name;
    int type;
    int func_type = TT_NONE;
	vector<int>argType;

    bool global;
    int stackIndex = 0;

    int data_type;
    int intVal;
    char charVal;
    float floatVal;
    bool boolVal;
    string* stringVal;
    bool isInit = false;
    bool isConst;
    int whileBegin;
    int whileExit;
    bool isArr = false;
    int arrSize;
    int* intArr;
    char* charArr;
    float* floatArr;
    bool* boolArr;
    string** stringArr; 
};

struct symbolTable{
    string* scopeName;
    vector<symbolTable_data>table_datas;
};

class symbolTables{
    public:
        symbolTables();
        void push(string*);
        void pop();
        void dump();
        bool add(symbolTable_data);
        bool update(symbolTable_data);
        bool isGlobal();
        symbolTable_data lookup_all(string*);
        symbolTable_data lookup_current(string*);
        vector<symbolTable> tables;
};