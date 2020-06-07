%{
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"lex.yy.cpp"

#define Trace(t) printf(t)

symbolTables tables = symbolTables();

void yyerror(string);
%}

%union{
    struct{
        bool val_init = false;
        int tokenType;
        int intVal;
        float floatVal;
        bool boolVal;
        std::string stringVal;
    }Token;
};

%token BOOLEAN BREAK CASE CHAR CLASS CONTINUE DO DEF ELSE EXIT FALSE FLOAT FOR IF INT _NULL OBJECT PRINT PRINTLN REPEAT _STRING TO RETURN TYPE TRUE VAR VAL WHILE

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
%token<Token> STRING
%token<Token> REAL
%token<Token> ID

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
    symbolTable_data obj;
    obj.type = TT_OBJ;
    tables.add(obj);
    tables.push($2.stringVal);
} '{' method '}';

method: const_declares method | functions method | ;

const_declares: var_declare | val_declare | arr_declare;

var_declare: VAR ID '=' expression ';' {
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
    
    if(tables.add(new_var) == false)
        yyerror("var id = expression / id has already exit.");
}   
| VAR ID ':' type '=' expression ';'{
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

    if(!tables.add(new_var))
        yyerror("var id : type = expression error");
}
| VAR ID ':' type ';'{
    Trace("var id : type");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = false;
    new_var.isConst = false;

    if(!tables.add(new_var))
        yyerror("var id : type error");
};


val_declare: VAL ID '=' expression ';'{
    Trace("val id = expression");
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = true;
    new_var.isConst = true;
    if($4.tokenType == TT_INT)
        new_var.intVal = $4.intVal;
    else if($4.tokenType == TT_FLOAT)
        new_var.floatVal = $4.floatVal;
    else if($4.tokenType == TT_STRING)
        new_var.stringVal = $4.stringVal;
    else if($4.tokenType == TT_BOOL)
        new_var.boolVal = $4.boolVal;
    
    if(!tables.add(new_var))
        yyerror("var id = expression error");
}
| VAL ID ':' type '=' expression ';'{
    symbolTable_data new_var;
    new_var.name = $2.stringVal;
    new_var.type = $4.tokenType;
    new_var.isInit = true;
    new_var.isConst = true;

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
        new_arr.stringArr = new string[new_arr.arrSize];
    else if($4.tokenType == TT_BOOL)
        new_arr.boolArr = new bool[new_arr.arrSize];
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
};

functions: DEF ID '(' {
    Trace("function id push table");
    symbolTable_data new_func;
    new_func.name = $2.stringVal;
    new_func.type = TT_FUNC;
    if(!tables.add(new_func))
        yyerror("def id (arg) error");
    tables.push($2.stringVal);
} func_arg ')' func_type scope{
    Trace("function end pop table");
};

func_arg: ID ':' type{
    Trace("func id : type");
    symbolTable_data fun_var;
    fun_var.name = $1.stringVal;
    fun_var.type = $3.tokenType;
    fun_var.isInit = false;
    
    if(!tables.add(fun_var))
        yyerror("func id : type error");
}
| ID ':' type ',' func_arg{
    Trace("func id : type , func_arg");
    symbolTable_data fun_var;
    fun_var.name = $1.stringVal;
    fun_var.type = $3.tokenType;
    fun_var.isInit = false;
    
    if(!tables.add(fun_var))
        yyerror("func id : type error");
}
| ;


func_type: ':' type{
    Trace("func : type");
    tables[tables.size()-2].table_datas.back().type = $2.stringVal;
}
| ;

scope: '{' func_content '}' {
    Trace("scope end");
    tables.pop();
};

func_content: const_declares func_content | statement func_content | ;

statement: ID '=' expression ';'{
    Trace("id = expression");
    symbolTable_data id = tables.lookup_all($1.stringVal);
    id.isInit = true;
    if(id.type == TT_NONE)
        yyerror("can not find this ID");
    else if(id.type == TT_FLOAT && $3.tokenType == TT_INT)
        id.floatVal = $3.intVal;
    else if(id.type != $3.type)
        yyerror("id = expression id type != expression type");
    else if(id.type == TT_INT)
        id.intVal = $3.intVal;
    else if(id.type == TT_FLOAT)
        id.floatVal = $3.floatVal;
    else if(id.type == TT_STRING)
        id.stringVal = $3.stringVal;
    else if(id.type == TT_BOOL)
        id.boolVal = $3.boolVal;
    tables.update(id);
}
|ID '[' expression ']' '=' expression ';'{
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

    tables.update(arr);
}
| PRINT '(' expression ')' ';'
| PRINTLN '(' expression ')' ';'
| RETURN ';'
| RETURN '(' expression ')' ';'
| IF '(' bool_type ')' scope
| IF '(' bool_type ')' scope ELSE scope
| WHILE '(' bool_type ')' scope
| FOR '(' ID '<' '-' INTEGER TO INTEGER ')'
| func_call;

func_call: ID '(' param ')' {
    Trace("func_call ID (param)");
    symbolTable_data func = tables.lookup_all($1.stringVal);
    if(func.type == TT_NONE)
        yyerror("can not find function");
    
    $$.tokenType = func.type;
};

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
    if(id.isArr == false)
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
    else if(id.type == TT_BOOL){
        $$.tokenType = TT_BOOL;
        $$.boolVal = id.boolVal;
    }
    
}
| INTEGER {
    Trace("reduce INTEGER");
}
| REAL{
    Trace("reduce REAL");
}
| STRING{
    Trace("reduce STRING");
}
| bool_type {
    Trace("reduce bool_type");
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
    else if(id.type == TT_BOOL){
        $$.tokenType = TT_BOOL;
        $$.boolVal = id.boolArr[$3.intVal];
    }
};

bool_type: TRUE {
    Trace("reduce ture");
    $$.tokenType = TT_BOOL;
    $$.boolVal = true;
}
| FALSE {
    Trace("reduce false");
    $$.tokenType = TT_BOOL;
    $$.boolVal = false;
}
| '!' expression{
    Trace("reduce !expression");
    $$.tokenType = TT_BOOL;
    $$.boolVal = !$2.boolVal;
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
    else
        yyerror("expression > expression type error");
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
    else
        yyerror("expression > expression type error");
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
    else
        yyerror("expression >= expression type error");
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
    else
        yyerror("expression <= expression type error");
}
| expression EQUAL expression{
    Trace("reduce expression == expression");
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
    else
        yyerror("expression <= expression type error");
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
    else
        yyerror("expression != expression type error");
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
}

%%
void yyerror(const string value){
    cout<<value<<"\n";
}

int main()
{
    yyparse();
    return 0;
}