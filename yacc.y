%{
#include<iostream>
#include<fstream>
#include<vector>
#include"symbol.hpp"
#include"lex.yy.cpp"
using namespace std;

#define Trace(t) { cout<< t << "\n\n";}

symbolTables tables = symbolTables();

extern "C"{
    int yylex();
    void yyerror(string);
};

fstream file;
int stackIndex;
bool func_return;
bool isConst;
int jumpIndex = 0;
bool func_retuen = false;
string* obj_name;
vector<int>elseJump;
%}

%union{
    struct{
        bool val_init;
        int tokenType;
        int intVal;
        char charVal;
        float floatVal;
        bool boolVal;
        string* stringVal;
        int whileBegin;
        int whileExit;
    }Token;
};

%token BOOLEAN BREAK CASE _CHAR CLASS CONTINUE DO DEF ELSE EXIT FALSE FLOAT FOR IF INT _NULL OBJECT PRINT PRINTLN REPEAT _STRING TO RETURN TYPE TRUE VAR VAL

%token AND 
%token OR 
%token ADD_ASSIGN 
%token SUBT_ASSIGN
%token MUTI_ASSIGN 
%token DIVI_ASSIGN
%token INCRESE 
%token DECRESE 
%token GREAT_EQUAL 
%token LESS_EQUAL 
%token EQUAL
%token NOT_EQUAL 
%token MOD_EQUAL 

%token<Token> INTEGER
%token<Token> STR
%token<Token> REAL
%token<Token> ID
%token<Token> CHAR
%token<Token> WHILE

%type<Token> type expression bool_type func_call

%start program

%left OR
%left AND
%left '!'
%left '>' '<' GREAT_EQUAL LESS_EQUAL NOT_EQUAL
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

program: OBJECT ID{
    obj_name = $2.stringVal;
    file << "class " << *$2.stringVal << "\n{\n";
    Trace("OBJECT ID push talbe");
    symbolTable_data obj;
    obj.type = TT_OBJ;
    tables.add(obj);
    tables.push($2.stringVal);
} '{' method '}'{
    Trace("code end");
    tables.pop();
    file << "}\n";
};

method: const_declares method {
    Trace("reduce const_declares method");
}
| functions method {
    Trace("reduce functions method");
}
| statement method {
    Trace("reduce fstatement method");
}
| ;

const_declares: var_declare | val_declare | arr_declare;

var_declare: VAR ID '=' expression {
    isConst = false;
    Trace("var id = expression");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = true;
    new_var.isConst = false;
    if($4.tokenType == TT_INT)
        new_var.intVal = $4.intVal;
    else if($4.tokenType == TT_FLOAT)
        new_var.floatVal = $4.floatVal;
    else if($4.tokenType == TT_STRING)
        new_var.stringVal = $4.stringVal;
    else if($4.tokenType == TT_BOOL)
        new_var.boolVal = $4.boolVal;
    else if($4.tokenType == TT_CHAR)
        new_var.charVal = $4.charVal;

    if (tables.isGlobal()){
        new_var.global = true;
        
        if(new_var.type == TT_INT)
            file << "field static int " << *new_var.name << " = " << new_var.intVal << "\n";
        else if(new_var.type == TT_BOOL)
            file << "field static int " << *new_var.name << " = " << new_var.boolVal << "\n";
    }
    else{
        new_var.global = false;
        new_var.stackIndex = stackIndex;
        stackIndex++;
        
        file << "istore " << new_var.stackIndex << "\n";
    }
    if(tables.add(new_var) == false)
        yyerror("var id = expression / id has already exit.");
}   
| VAR ID ':' type '=' expression{
    isConst = false;
    Trace("var id : type = expression");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = true;
    new_var.isConst = false;

    if($4.tokenType == TT_FLOAT && $6.tokenType == TT_INT)
        new_var.floatVal = $6.intVal;
    else if($4.tokenType != $6.tokenType){
        yyerror("var id : type = expression  type != expression.type");
    }
    else if($4.tokenType == TT_INT)
        new_var.intVal = $6.intVal;
    else if($4.tokenType == TT_FLOAT)
        new_var.floatVal = $6.floatVal;
    else if($4.tokenType == TT_STRING)
        new_var.stringVal = $6.stringVal;
    else if($4.tokenType == TT_BOOL)
        new_var.boolVal = $6.boolVal;
    else if($4.tokenType == TT_CHAR)
        new_var.charVal = $6.charVal;

    if (tables.isGlobal()){
        new_var.global = true;
        
        if(new_var.type == TT_INT)
            file << "field static int " << *new_var.name << " = " << new_var.intVal << "\n";
        else if(new_var.type == TT_BOOL)
            file << "field static int " << *new_var.name << " = " << new_var.boolVal << "\n";

    }
    else{
        new_var.global = false;
        new_var.stackIndex = stackIndex;
        stackIndex++;
        file << "istore " << new_var.stackIndex << "\n";
    }

    if(!tables.add(new_var))
        yyerror("var id : type = expression error");
}
| VAR ID ':' type{
    isConst = false;
    Trace("var id : type");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = false;
    new_var.isConst = false;

    if(tables.isGlobal()){
        new_var.global = true;
		file << "field static int " << *new_var.name << endl;
    }
    else{
        new_var.global = false;
        new_var.stackIndex = stackIndex;
        stackIndex++;
    }

    if(!tables.add(new_var))
        yyerror("var id : type error");
}
| VAR ID{
    isConst = false;
    Trace("var id");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = TT_INT;
    new_var.isInit = false;
    new_var.isConst = false;

    if(tables.isGlobal()){
        new_var.global = true;
		file << "field static int " << *new_var.name << endl;
    }
    else{
        new_var.global = false;
        new_var.stackIndex = stackIndex;
        stackIndex++;
    }

    if(!tables.add(new_var))
        yyerror("var id : type error");
};


val_declare: VAL ID '=' {
    isConst = true;
} expression {
    isConst = false;
    Trace("val id = expression");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $5.tokenType;
    new_var.isInit = true;
    new_var.isConst = true;
    if($5.tokenType == TT_INT)
        new_var.intVal = $5.intVal;
    else if($5.tokenType == TT_FLOAT)
        new_var.floatVal = $5.floatVal;
    else if($5.tokenType == TT_STRING)
        new_var.stringVal = $5.stringVal;
    else if($5.tokenType == TT_BOOL)
        new_var.boolVal = $5.boolVal;
    else if($5.tokenType == TT_CHAR)
        new_var.charVal = $5.charVal;
    
    if(!tables.add(new_var))
        yyerror("var id = expression error");
}
| VAL ID ':' type '=' { 
    isConst = true;
} expression {
    isConst = false;
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = true;
    new_var.isConst = true;

    if($4.tokenType == TT_FLOAT && $7.tokenType == TT_INT)
        new_var.floatVal = $7.intVal;
    else if($4.tokenType != $7.tokenType){
        yyerror("var id : type = expression  type != expression.type");
    }
    else if($4.tokenType == TT_INT)
        new_var.intVal = $7.intVal;
    else if($4.tokenType == TT_FLOAT)
        new_var.floatVal = $7.floatVal;
    else if($4.tokenType == TT_STRING)
        new_var.stringVal = $7.stringVal;
    else if($4.tokenType == TT_BOOL)
        new_var.boolVal = $7.boolVal;
    else if($4.tokenType == TT_CHAR)
        new_var.charVal = $7.charVal;

    if(!tables.add(new_var))
        yyerror("var id : type = expression error");
};

arr_declare: VAR ID ':' type '[' expression ']'{
    Trace("var id type[int]");
    if($6.tokenType != TT_INT)
        yyerror("arr len must be integer");

    symbolTable_data new_arr;
    new_arr.name = $2.stringVal;
    new_arr.type = $4.tokenType;
    new_arr.arrSize = $6.intVal;
    new_arr.isConst = false;
    new_arr.isArr = true;

    if($4.tokenType == TT_INT)
        new_arr.intArr = new int[new_arr.arrSize];
    else if($4.tokenType == TT_FLOAT)
        new_arr.floatArr = new float[new_arr.arrSize];
    else if($4.tokenType == TT_STRING)
        new_arr.stringArr = new string*[new_arr.arrSize];
    else if($4.tokenType == TT_BOOL)
        new_arr.boolArr = new bool[new_arr.arrSize];
    else if($4.tokenType == TT_CHAR)
        new_arr.charArr = new char[new_arr.arrSize];

    tables.add(new_arr);
};


type: INT{
    Trace("reduce INT");
    $$.tokenType = TT_INT;
}
| FLOAT{
    Trace("reduce FLOAT");
    $$.tokenType = TT_FLOAT;
}
| _STRING{
    Trace("reduce _STRING");
    $$.tokenType = TT_STRING;
}
| BOOLEAN{
    Trace("reduce BOOLEAN");
    $$.tokenType = TT_BOOL;
}
| _CHAR{
    Trace("reduce CHAR");
    $$.tokenType = TT_CHAR;
};

functions: DEF ID '(' {
    Trace("function id push table");
    symbolTable_data new_func;
    new_func.name = $2.stringVal;
    new_func.type = TT_FUNC;
    if(!tables.add(new_func))
        yyerror("def id (arg) error");
    tables.push($2.stringVal);
    stackIndex = 0;
    func_return = false;
} func_arg ')' func_type{
    file << "method public static ";
    symbolTable_data new_func = tables.tables[tables.tables.size()-2].table_datas.back();
    if(*new_func.name == "main"){
        file << "void main(java.lang.String[])\n";
    }
    else {
        if (new_func.func_type == TT_INT)
            file << "int ";
        else if (new_func.func_type == TT_BOOL)
            file << "int ";
        else{
            file << "void ";
        }

        file << *new_func.name << "(";

        for(int i = 0; i < new_func.argType.size(); i++){
            if(new_func.argType[i] == TT_INT)
                file << "int";
            else if (new_func.argType[i] == TT_BOOL)
                file << "int";
            
            if(i != new_func.argType.size() - 1)
                file << ", ";
        }
        file << ")\n";
    }
    file << "max_stack 15\n";
    file << "max_locals 15\n";
    file << "{\n";    
} func_scope{
    Trace("function end");
    if(!func_return)
        file << "return\n";
    file << "}\n";
};

func_arg: ID ':' type{
    Trace("func id : type");
    symbolTable_data fun_var;
    fun_var.name = $1.stringVal;
    fun_var.type = $3.tokenType;
    fun_var.isInit = false;
    fun_var.global = false;

    fun_var.stackIndex = stackIndex;
    stackIndex++;

    if(!tables.add(fun_var))
        yyerror("func id : type error");

	tables.tables[tables.tables.size()-2].table_datas.back().argType.push_back($3.tokenType);
}
| ID ':' type ',' func_arg{
    Trace("func id : type , func_arg");
    symbolTable_data fun_var;
    fun_var.name = $1.stringVal;
    fun_var.type = $3.tokenType;
    fun_var.isInit = false;
    fun_var.global = false;

    fun_var.stackIndex = stackIndex;
    stackIndex++;
    
    if(!tables.add(fun_var))
        yyerror("func id : type error");

	tables.tables[tables.tables.size()-2].table_datas.back().argType.push_back($3.tokenType);
}
| ;

func_type: ':' type{
    Trace("func : type");
    tables.tables[tables.tables.size()-2].table_datas.back().func_type = $2.tokenType;
}
| ;

func_scope: '{' func_content '}' {
    Trace("scope end");
    tables.pop();
};

scope: '{' {
    Trace("scope start");
    string* temp = new string("statement");
    tables.push(temp);
} func_content '}' {
    Trace("scope end");
    tables.pop();
}
| statement;

func_content: const_declares func_content | statement func_content | ;

statement : ID '=' expression {
    Trace("id = expression");
    symbolTable_data id = tables.lookup_all($1.stringVal);
    id.isInit = true;
    if(id.type == TT_NONE)
        yyerror("can not find this ID");
    else if(id.type == TT_FLOAT && $3.tokenType == TT_INT)
        id.floatVal = $3.intVal;
    else if(id.type != $3.tokenType)
        yyerror("id = expression id type != expression type");
    else if(id.type == TT_INT)
        id.intVal = $3.intVal;
    else if(id.type == TT_FLOAT)
        id.floatVal = $3.floatVal;
    else if(id.type == TT_STRING)
        id.stringVal = $3.stringVal;
    else if(id.type == TT_BOOL)
        id.boolVal = $3.boolVal;
    else if(id.type == TT_CHAR)
        id.charVal = $3.charVal;
    tables.update(id);

    if(id.global){
        file <<  "putstatic int " << *obj_name << "." << *id.name << "\n";
    }
    else{
        
        file << "istore " << id.stackIndex << "\n";
    }
}
|ID '[' expression ']' '=' expression {
    Trace("id[expressino] = expression");
    symbolTable_data arr = tables.lookup_all($1.stringVal);
    arr.isInit = true;
    if($3.tokenType != TT_INT)
        yyerror("id[expressino] = expression type is not integer");
    if(arr.type == TT_NONE)
        yyerror("id[expressino] = expression array is not exit");
    if($3.intVal > arr.arrSize)
        yyerror("id[expressino] = expression array index out of range");
    if(arr.isArr == false)
        yyerror("id[expressino] = expression this id is not array");

    if(arr.type == TT_FLOAT && $6.tokenType == TT_INT)
        arr.floatArr[$3.intVal] = $6.intVal;
    else if(arr.type != $6.tokenType)
        yyerror("id[expressino] = expression type error");
    else if(arr.type == TT_INT)
        arr.intArr[$3.intVal] = $6.intVal;
    else if(arr.type == TT_FLOAT)
        arr.floatArr[$3.intVal] = $6.floatVal;
    else if(arr.type == TT_STRING)
        arr.stringArr[$3.intVal] = $6.stringVal;
    else if(arr.type == TT_BOOL)
        arr.boolArr[$3.intVal] = $6.boolVal;
    else if(arr.type == TT_CHAR)
        arr.charArr[$3.intVal] = $6.charVal;

    tables.update(arr);
}
| PRINT '(' {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
} expression ')' {
    Trace("print (expression)");
    file << "invokevirtual void java.io.PrintStream.print(";
    if($4.tokenType == TT_INT)
        file << "int)\n";
    else if($4.tokenType == TT_BOOL)
        file << "int)\n";
    else if($4.tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
| PRINT {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
} expression  {
    Trace("print expression");
    file << "invokevirtual void java.io.PrintStream.print(";
    if($3.tokenType == TT_INT)
        file << "int)\n";
    else if($3.tokenType == TT_BOOL)
        file << "int)\n";
    else if($3.tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
| PRINTLN '(' {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
} expression ')' {
    Trace("println (expression)");
    file << "invokevirtual void java.io.PrintStream.println(";
    if($4.tokenType == TT_INT)
        file << "int)\n";
    else if($4.tokenType == TT_BOOL)
        file << "int)\n";
    else if($4.tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
| PRINTLN {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
} expression {
    Trace("println expression");
    file << "invokevirtual void java.io.PrintStream.println(";
    if($3.tokenType == TT_INT)
        file << "int)\n";
    else if($3.tokenType == TT_BOOL)
        file << "int)\n";
    else if($3.tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
| RETURN '(' expression ')' {
    func_return = true;
    Trace("return (expression)");
    file << "ireturn\n";
}
| RETURN expression {
    func_return = true;
    Trace("return expression");
    file << "ireturn\n";
}
| RETURN {
    Trace("return");
    func_return = true;
    file << "return\n";
}
| IF '(' expression ')' {
    file << "ifeq " << "L" << jumpIndex << "\n";
    elseJump.push_back(jumpIndex);
    jumpIndex++;
} scope else {
    Trace("if(bool_type) scope");
    file << "L" << elseJump.back() << ":\n";
    elseJump.pop_back();
    file << "nop\n";
}
| WHILE {
    file << "L" << jumpIndex << ":\n";
    $1.whileBegin = jumpIndex;
    jumpIndex++;
} '(' expression ')' {
    file << "ifeq " << "L" << jumpIndex << "\n";
    $1.whileExit = jumpIndex;
    jumpIndex++;
} scope {
    Trace("while(bool_type) scope");
    file << "goto " << "L" << $1.whileBegin << "\n";
    file << "L" << $1.whileExit << ":\n";
    file << "nop\n";
}
| FOR '(' ID '<' '-' expression TO expression ')' scope{
    Trace("for(id <- int to int ");

    if(tables.lookup_all($3.stringVal).type == TT_NONE)
        yyerror("for loop id is not find.");

    if($6.tokenType != TT_INT || $8.tokenType != TT_INT)
        yyerror("for loop type error");
}

| func_call{
    Trace("func_call;");
};

func_call: ID '(' param ')' {
    Trace("func_call ID (param)");
    symbolTable_data func = tables.lookup_all($1.stringVal);
    if(func.type == TT_NONE)
        yyerror("can not find function");
    $$.tokenType = func.func_type;

    file << "invokestatic ";
    if (func.func_type == TT_INT)
        file << "int ";
    else if (func.func_type == TT_BOOL)
        file << "int ";
    else
        file << "void ";

    file << *obj_name << "." << *func.name << "(";

    for(int i = 0; i < func.argType.size(); i++){
        if(func.argType[i] == TT_INT)
            file << "int";
        else if (func.argType[i] == TT_BOOL)
            file << "int";
        
        if(i != func.argType.size() - 1)
            file << ", ";
    }
    file << ")\n";

};

else: ELSE {
    file << "goto " << "L" << jumpIndex << "\n";
    file << "L" << elseJump.back() << ":\n";
    elseJump.pop_back();
    elseJump.push_back(jumpIndex);
    jumpIndex++;
    file << "nop\n";
} scope
| ;

param: expression | expression ',' param | ;

expression: '-' expression %prec UMINUS {
    Trace("- expression");
    if($2.val_init == false)
        yyerror("- expression $2 is not initial.");
    
    if($2.tokenType == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = -1 * $2.intVal;
    }
    else if($2.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = -1 * $2.floatVal;
    }
    else
        yyerror("- expression type error");

    if(!isConst && !tables.isGlobal())
        file << "ineg\n";
}
| expression '+' expression {
    Trace("expression + expression");
    if($1.val_init == false)
        yyerror("expression + expression $1 is not initial.");

    if($3.val_init == false)
        yyerror("expression + expression $3 is not initial.");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = $1.intVal + $3.intVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_INT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal + $3.intVal;
    }
    else if($1.tokenType == TT_INT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.intVal + $3.floatVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal + $3.floatVal;
    }
    else
        yyerror("expression + expression type error.");
    
    if(!isConst && !tables.isGlobal()){
        file << "iadd\n";
    }
}
| expression '-' expression {
    Trace("expression - expression");
    if($1.val_init == false)
        yyerror("expression - expression $1 is not initial.");

    if($3.val_init == false)
        yyerror("expression - expression $3 is not initial.");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = $1.intVal - $3.intVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_INT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal - $3.intVal;
    }
    else if($1.tokenType == TT_INT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.intVal - $3.floatVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal - $3.floatVal;
    }
    else{
        yyerror("expression * expression type error.");
    }

    if(!isConst && !tables.isGlobal()){
        file << "isub\n";
    }
}
| expression '*' expression {
    Trace("expression * expression");
    if($1.val_init == false)
        yyerror("expression * expression $1 is not initial.");

    if($3.val_init == false)
        yyerror("expression * expression $3 is not initial.");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = $1.intVal * $3.intVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_INT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal * $3.intVal;
    }
    else if($1.tokenType == TT_INT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.intVal * $3.floatVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal * $3.floatVal;
    }
    else{
        yyerror("expression * expression type error.");
    }

    if(!isConst && !tables.isGlobal()){
        file << "imul\n";
    }
}
| expression '/' expression {
    Trace("expression / expression");
    if($1.val_init == false)
        yyerror("expression / expression $1 is not initial.");

    if($3.val_init == false)
        yyerror("expression / expression $3 is not initial.");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = $1.intVal / $3.intVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_INT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal / $3.intVal;
    }
    else if($1.tokenType == TT_INT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.intVal / $3.floatVal;
    }
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = $1.floatVal / $3.floatVal;
    }
    else{
        yyerror("expression / expression type error.");
    }

    if(!isConst && !tables.isGlobal()){
        file << "idiv\n";
    }
}
| expression '%' expression {
    Trace("expression % expression");
    if($1.val_init == false)
        yyerror("expression % expression $1 is not initial.");

    if($3.val_init == false)
        yyerror("expression % expression $3 is not initial.");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = $1.intVal % $3.intVal;
    }
    else{
        yyerror("expression % expression type error.");
    }

    if(!isConst && !tables.isGlobal()){
        file << "irem\n";
    }
}
| '(' expression ')'{
    Trace("( expression )");
    $$ = $2;
}
| ID {
    Trace("ID");
    
    symbolTable_data id = tables.lookup_all($1.stringVal);

    if(id.isInit == true)
        $$.val_init = true;

    if(id.type == TT_NONE)
        yyerror("ID can not find this id");
    if(id.isArr == true)
        yyerror("ID this id is array but without [ ]");
    
    if(id.type == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = id.intVal;
    }
    else if(id.type == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = id.floatVal;
    }
    else if(id.type == TT_STRING){
        $$.tokenType = TT_STRING;
        $$.stringVal = id.stringVal;
    }
    else if(id.type == TT_CHAR){
        $$.tokenType = TT_CHAR;
        $$.charVal = id.charVal;
    }
    else if(id.type == TT_BOOL){
        $$.tokenType = TT_BOOL;
        $$.boolVal = id.boolVal;
    }
    
    if(id.isConst){
        if(id.type == TT_INT)
            file << "sipush " << id.intVal << "\n";
        else if(id.type == TT_BOOL){
            if(id.boolVal)
                file << "iconst_1\n";
            else
                file << "iconst_0\n";
        }
        else if(id.type == TT_STRING)
            file << "ldc \"" << *id.stringVal << "\"\n";
    }else{
        if(id.global){
            file << "getstatic int " << *obj_name << "." << *id.name <<"\n";
        }
        else{
            file << "iload " << id.stackIndex << "\n";
        }
    }
}
| INTEGER {
    Trace("reduce INTEGER");
    if(!isConst && !tables.isGlobal()){
        file << "sipush " << $1.intVal << "\n";
    }
}
| REAL{
    Trace("reduce REAL");
}
| STR{
    Trace("reduce STR");
    if(!isConst && !tables.isGlobal()){
        file << "ldc \"" << *$1.stringVal << "\"\n";
    }
}
| CHAR {
    Trace("reduce CHAR");
}
| bool_type {
    Trace("reduce bool_type");
}
| func_call{
    Trace("function call")
}
|ID '[' expression ']'{
    Trace("id[expression]");
    symbolTable_data id = tables.lookup_all($1.stringVal);
    if($3.tokenType != TT_INT)
        yyerror("id[expression] index type error");
    
    if(id.type == TT_NONE)
        yyerror("id[expression] id is not find");
    if(id.isArr == false)
        yyerror("id[expression] this id is not array");

    if($3.intVal > id.arrSize)
        yyerror("id[expression] index out of range");

    if(id.type == TT_INT){
        $$.tokenType = TT_INT;
        $$.intVal = id.intArr[$3.intVal];
    }
    else if(id.type == TT_FLOAT){
        $$.tokenType = TT_FLOAT;
        $$.floatVal = id.floatArr[$3.intVal];
    }
    else if(id.type == TT_STRING){
        $$.tokenType = TT_STRING;
        $$.stringVal = id.stringArr[$3.intVal];
    }
    else if(id.type == TT_CHAR){
        $$.tokenType = TT_CHAR;
        $$.charVal = id.charArr[$3.intVal];
    }
    else if(id.type == TT_BOOL){
        $$.tokenType = TT_BOOL;
        $$.boolVal = id.boolArr[$3.intVal];
    }
};

bool_type: TRUE {
    Trace("reduce ture");
    $$.tokenType = TT_BOOL;
    $$.boolVal = true;

    if(!isConst && !tables.isGlobal()){
        file << "iconst_1\n";
    }
}
| FALSE {
    Trace("reduce false");
    $$.tokenType = TT_BOOL;
    $$.boolVal = false;

    if(!isConst && !tables.isGlobal()){
        file << "iconst_0\n";
    }
}
| '!' expression{
    Trace("reduce !expression");
    $$.tokenType = TT_BOOL;
    $$.boolVal = !$2.boolVal;
    if(!isConst && !tables.isGlobal()){
        file << "iconst_1\n";
        file << "ixor\n";
    }
}
| expression '>' expression{
    Trace("reduce expression > expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression > expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression > expression $1 is not init");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT)
        $$.boolVal = $1.intVal > $3.intVal;
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT)
        $$.boolVal = $1.floatVal > $3.floatVal;
    else if($1.tokenType == TT_STRING && $3.tokenType == TT_STRING)
        $$.boolVal = $1.stringVal > $3.stringVal;
    else if($1.tokenType == TT_CHAR && $3.tokenType == TT_CHAR)
        $$.boolVal = $1.charVal > $3.charVal;
    else
        yyerror("expression > expression type error");

    file << "isub\n";
    file << "ifgt " << "L" << jumpIndex << "\n";
    file << "iconst_0\n";
    file << "goto " << "L" << jumpIndex + 1 << "\n";
    file << "L" << jumpIndex << ":\n";
    file << "iconst_1" << "\n";
    file << "L" << jumpIndex + 1 << ":\n";
    jumpIndex += 2;
}
| expression '<' expression{
    Trace("reduce expression < expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression < expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression < expression $1 is not init");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT)
        $$.boolVal = $1.intVal < $3.intVal;
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT)
        $$.boolVal = $1.floatVal < $3.floatVal;
    else if($1.tokenType == TT_STRING && $3.tokenType == TT_STRING)
        $$.boolVal = $1.stringVal < $3.stringVal;
    else if($1.tokenType == TT_CHAR && $3.tokenType == TT_CHAR)
        $$.boolVal = $1.charVal < $3.charVal;
    else
        yyerror("expression > expression type error");

    file << "isub\n";
    file << "iflt " << "L" << jumpIndex << "\n";
    file << "iconst_0\n";
    file << "goto " << "L" << jumpIndex + 1 << "\n";
    file << "L" << jumpIndex << ":\n";
    file << "iconst_1" << "\n";
    file << "L" << jumpIndex + 1 << ":\n";
    jumpIndex += 2;
}
| expression GREAT_EQUAL expression{
    Trace("reduce expression >= expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression >= expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression >= expression $1 is not init");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT)
        $$.boolVal = $1.intVal >= $3.intVal;
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT)
        $$.boolVal = $1.floatVal >= $3.floatVal;
    else if($1.tokenType == TT_STRING && $3.tokenType == TT_STRING)
        $$.boolVal = $1.stringVal >= $3.stringVal;
    else if($1.tokenType == TT_CHAR && $3.tokenType == TT_CHAR)
        $$.boolVal = $1.charVal >= $3.charVal;
    else
        yyerror("expression >= expression type error");
    
    file << "isub\n";
    file << "ifge " << "L" << jumpIndex << "\n";
    file << "iconst_0\n";
    file << "goto " << "L" << jumpIndex + 1 << "\n";
    file << "L" << jumpIndex << ":\n";
    file << "iconst_1" << "\n";
    file << "L" << jumpIndex + 1 << ":\n";
    jumpIndex += 2;
}
| expression LESS_EQUAL expression{
    Trace("reduce expression <= expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression <= expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression <= expression $1 is not init");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT)
        $$.boolVal = $1.intVal <= $3.intVal;
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT)
        $$.boolVal = $1.floatVal <= $3.floatVal;
    else if($1.tokenType == TT_STRING && $3.tokenType == TT_STRING)
        $$.boolVal = $1.stringVal <= $3.stringVal;
    else if($1.tokenType == TT_CHAR && $3.tokenType == TT_CHAR)
        $$.boolVal = $1.charVal <= $3.charVal;
    else
        yyerror("expression <= expression type error");

    file << "isub\n";
    file << "ifle " << "L" << jumpIndex << "\n";
    file << "iconst_0\n";
    file << "goto " << "L" << jumpIndex + 1 << "\n";
    file << "L" << jumpIndex << ":\n";
    file << "iconst_1" << "\n";
    file << "L" << jumpIndex + 1 << ":\n";
    jumpIndex += 2;
}
| expression EQUAL expression{
    Trace("reduce expression == expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression == expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression == expression $1 is not init");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT)
        $$.boolVal = $1.intVal == $3.intVal;
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT)
        $$.boolVal = $1.floatVal == $3.floatVal;
    else if($1.tokenType == TT_STRING && $3.tokenType == TT_STRING)
        $$.boolVal = $1.stringVal == $3.stringVal;
    else if($1.tokenType == TT_CHAR && $3.tokenType == TT_CHAR)
        $$.boolVal = $1.charVal == $3.charVal;
    else
        yyerror("expression == expression type error");

    file << "isub\n";
    file << "ifeq " << "L" << jumpIndex << "\n";
    file << "iconst_0\n";
    file << "goto " << "L" << jumpIndex + 1 << "\n";
    file << "L" << jumpIndex << ":\n";
    file << "iconst_1" << "\n";
    file << "L" << jumpIndex + 1 << ":\n";
    jumpIndex += 2;
}
| expression NOT_EQUAL expression{
    Trace("reduce expression != expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression != expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression != expression $1 is not init");

    if($1.tokenType == TT_INT && $3.tokenType == TT_INT)
        $$.boolVal = $1.intVal != $3.intVal;
    else if($1.tokenType == TT_FLOAT && $3.tokenType == TT_FLOAT)
        $$.boolVal = $1.floatVal != $3.floatVal;
    else if($1.tokenType == TT_STRING && $3.tokenType == TT_STRING)
        $$.boolVal = $1.stringVal != $3.stringVal;
    else if($1.tokenType == TT_CHAR && $3.tokenType == TT_CHAR)
        $$.boolVal = $1.charVal != $3.charVal;
    else
        yyerror("expression != expression type error");

    file << "isub\n";
    file << "ifne " << "L" << jumpIndex << "\n";
    file << "iconst_0\n";
    file << "goto " << "L" << jumpIndex + 1 << "\n";
    file << "L" << jumpIndex << ":\n";
    file << "iconst_1" << "\n";
    file << "L" << jumpIndex + 1 << ":\n";
    jumpIndex += 2;
}
| expression AND expression{
    Trace("reduce expression && expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression && expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression && expression $1 is not init");

    if($1.tokenType != TT_BOOL || $3.tokenType != TT_BOOL)
        yyerror("expression && expression type error");
    
    $$.boolVal = $1.boolVal && $3.boolVal;

    if(!isConst && !tables.isGlobal()){
        file << "iand\n";
    }
}
| expression OR expression{
    Trace("reduce expression || expression");
    $$.tokenType = TT_BOOL;
    if($1.val_init == false)
        yyerror("expression || expression $1 is not init");
    if($1.val_init == false)
        yyerror("expression || expression $1 is not init");

    if($1.tokenType != TT_BOOL || $3.tokenType != TT_BOOL)
        yyerror("expression || expression type error");
    
    $$.boolVal = $1.boolVal || $3.boolVal;
    if(!isConst && !tables.isGlobal()){
        file << "ior\n";
    }
};

%%
void yyerror(string value){
    cout << value << "\n";
}

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");

    string fn = "./jasm/" + string(argv[2]) + ".jasm";

    file.open(fn, std::ios::out);

    if(!file){
        printf("========cant open file============\n");
    }
    if (yyparse() == 1)
        yyerror("Parsing error !");

    file.close();
    return 0;
}