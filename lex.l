%{
#include <stdio.h>
#include"y.tab.hpp"
#include"symbol.hpp"

#define LIST                  strcat(buf, yytext)
#define token(t)              {LIST; printf("<%s>\n", t); return t;}
#define tokenType(t, value)   {LIST; printf("<%s:%d>\n", t, value); return t;}

#define MAX_LINE_LENG  1024

char buf[MAX_LINE_LENG];
char temp_string[MAX_LINE_LENG];
int linenum = 1;

%}

%x COMMENT
%x MUTICOMMENT
%x STRING

digs        [0-9]+
letter      [A-Za-z]+
integer     {digs}
plain_real  [+-]?{digs}.{digs}
expreal     [+-]?{digs}"."{digs}[Ee][+-]?{digs}
real        {plain_real}|{expreal}|[+-]?{digs}[Ee][+-]?{digs}
id          {letter}({letter}|{digs})*

%%


"boolean"    {token(BOOLEAN);}
"break"      {token(BREAK);}
"case"       {token(CASE);}
"char"       {token(CHAR);}
"class"      {token(CLASS);}
"continue"   {token(CONTINUE);}
"do"         {token(DO);}
"def"        {token(DEF);}
"else"       {token(ELSE);}
"exit"       {token(EXIT);}
"false"      {token(FALSE);}
"float"      {token(FLOAT);}
"for"        {token(FOR);}
"if"         {token(IF);}
"int"        {token(INT);}
"null"       {token(_NULL);}
"object"     {token(OBJECT);}
"print"      {token(PRINT);}
"println"    {token(PRINTLN)}
"repeat"     {token(REPEAT);}
"string"     {token(_STRING);}
"to"         {token(TO);}
"return"     {token(RETURN);}
"type"       {token(TYPE)}
"true"       {token(TRUE);}
"var"        {token(VAR);}
"val"        {token(VAL);}
"while"      {token(WHILE);}

"+"  {token('+');}
"-"  {token('-');}
"*"  {token('*');}
"/"  {token('/');}
">"  {token('>');}
"<"  {token('<');}
"!"  {token('!');}
"&"  {token('&');}
"|"  {token('!');}
"&&" {token(AND);}
"||" {token(OR);}
"+=" {token(ADD_ASSIGN);}
"-=" {token(SUBT_ASSIGN);}
"*=" {token(MUTI_ASSIGN);}
"/=" {token(DIVI_ASSIGN);}
"("  {token('(');}
")"  {token(')');}
"["  {token('[');}
"]"  {token(']');}
"{"  {token('{');}
"}"  {token('}');}
","  {token(',');}
";"  {token(';');}
":"  {token(':');}
"++" {token(INCRESE);}
"--" {token(DECRESE);}
">=" {token(GREAT_EQUAL);}
"<=" {token(LESS_EQUAL);}
"==" {token(EQUAL);}
"!=" {token(NOT_EQUAL);}
"="  {token('=');}
"%"  {token('%');}
"%=" {token(MOD_EQUAL);}

{integer} {
  yylval.Token.tokenType = TT_INT;
  yylval.Token.intVal = atoi(yytext);
  yylval.Token.val_init = true;
  tokenType(INTEGER, atoi(yytext));
}

{real} {
  yylval.Token.tokenType = TT_FLOAT;
  yylval.Token.floatVal = atof(yytext);
  yylval.Token.val_init = true;
  tokenType(REAL, yytext);
}

{id} {
  yylval.Token.stringVal = yytext;
  tokenType(ID, yytext);
}

\n {
  LIST;
  printf("%d: %s\n", linenum++, buf);
  buf[0]='\0';
}

"//" {
  LIST;
  BEGIN(COMMENT);
}

<COMMENT>. {
  LIST;
}

<COMMENT>\n {
  LIST;
  printf("%d: %s\n", linenum++, buf);
  buf[0]='\0';
  BEGIN(INITIAL);
}

"/*" {
  LIST;
  BEGIN(MUTICOMMENT);
}

"*/" {
  LIST;
  printf("%d: %s\n", linenum, buf);
  printf("error\n");
  exit(-1);
}

<MUTICOMMENT>. {
  LIST;
}

<MUTICOMMENT>\n {
  printf("%d: %s\n", linenum++, buf);
  buf[0] = '\0';
}

<MUTICOMMENT>"*/" {
  LIST;
  BEGIN(INITIAL);
}

\" {
  LIST;
  BEGIN(STRING);
}

<STRING>\"\" {
  LIST;
  strcat(temp_string, "\"");
}


<STRING>\" {
  yylval.Token.tokenType = TT_STRING;
  yylval.Token.stringVal = temp_string;
  yylval.Token.val_init = true;
  tokenType(STRING, temp_string);
  temp_string[0] = '\0';
  BEGIN(INITIAL);
}

<STRING>. {
  LIST;
  strcat(temp_string, yytext);
}

<STRING>\n {
  printf("%d: %s\n", linenum++, buf);
  printf("error\n");
  exit(-1);
}

[ \t]* {
  LIST;
}

. {
  LIST;
  printf("%d: %s", linenum++, buf);
  printf("error\n");
  exit(-1);
}

<<EOF>> {
  LIST;
  printf("%d: %s\n", linenum++, buf);
  return 0;
}
%%