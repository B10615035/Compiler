%{
#include <stdio.h>

#define LIST                strcat(buf, yytext)
#define token(t)            {LIST; printf("<%s>\n", t);}
#define tokenInteger(t, i)  {LIST; printf("<%s:%d>\n", t, i);}
#define tokenString(t, s)   {LIST; printf("<%s:%s>\n", t, s);}
#define tokenKeyword(t)     {LIST; printf("<%s>\n", t);}

#define MAX_LINE_LENG  1024
#define MAX_TABLE_LENG 1024

char buf[MAX_LINE_LENG];
char temp_string[MAX_LINE_LENG];
int linenum = 1;

int table_len = 0;
char **table;
int lookup(char *str);
void insert(char *str);
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

"boolean"    {tokenKeyword("BOOLEAN");}
"break"      {tokenKeyword("BREAK");}
"byte"       {tokenKeyword("BYTE");}
"case"       {tokenKeyword("CASE");}
"catch"      {tokenKeyword("CATCH");}
"char"       {tokenKeyword("CHAR");}
"class"      {tokenKeyword("CLASS");}
"continue"   {tokenKeyword("CONTINUE");}
"default"    {tokenKeyword("DEFAULT");}
"do"         {tokenKeyword("DO");}
"def"        {tokenKeyword("DEF");}
"double"     {tokenKeyword("DOUBLE");}
"else"       {tokenKeyword("ELSE");}
"extends"    {tokenKeyword("EXTENDS");}
"false"      {tokenKeyword("FALSE");}
"final"      {tokenKeyword("FINAL");}
"float"      {tokenKeyword("FLOAT");}
"for"        {tokenKeyword("FOR");}
"if"         {tokenKeyword("IF");}
"implements" {tokenKeyword("IMPLEMENTS");}
"import"     {tokenKeyword("IMPORT");}
"int"        {tokenKeyword("INT");}
"interface"  {tokenKeyword("INTERFACE");}
"long"       {tokenKeyword("LONG");}
"new"        {tokenKeyword("NEW");}
"null"       {tokenKeyword("NULL");}
"object"     {tokenKeyword("OBJECT");}
"package"    {tokenKeyword("PACKAGE");}
"private"    {tokenKeyword("PRIVATE");}
"print"      {tokenKeyword("PRINT");}
"println"    {tokenKeyword("PRINTLN")}
"protected"  {tokenKeyword("PROTECTED");}
"public"     {tokenKeyword("PUBLIC");}
"return"     {tokenKeyword("RETURN");}
"short"      {tokenKeyword("SHORT");}
"static"     {tokenKeyword("STATIC");}
"super"      {tokenKeyword("SUPER");}
"switch"     {tokenKeyword("SWITCH");}
"this"       {tokenKeyword("THIS");}
"throw"      {tokenKeyword("THROW");}
"try"        {tokenKeyword("TRY");}
"true"       {tokenKeyword("TRUE");}
"void"       {tokenKeyword("VOID");}
"var"        {tokenKeyword("VAR");}
"val"        {tokenKeyword("VAL");}
"while"      {tokenKeyword("WHILE");}

"+"  {token(yytext);}
"-"  {token(yytext);}
"*"  {token(yytext);}
"/"  {token(yytext);}
">"  {token(yytext);}
"<"  {token(yytext);}
"!"  {token(yytext);}
"&"  {token(yytext);}
"|"  {token(yytext);}
"&&" {token(yytext);}
"||" {token(yytext);}
"+=" {token(yytext);}
"-=" {token(yytext);}
"*=" {token(yytext);}
"/=" {token(yytext);}
"("  {token(yytext);}
")"  {token(yytext);}
"["  {token(yytext);}
"]"  {token(yytext);}
"{"  {token(yytext);}
"}"  {token(yytext);}
","  {token(yytext);}
";"  {token(yytext);}
":"  {token(yytext);}
"++" {token(yytext);}
"--" {token(yytext);}
">=" {token(yytext);}
"<=" {token(yytext);}
"==" {token(yytext);}
"!=" {token(yytext);}
"="  {token(yytext);}
"%"  {token(yytext);}
"%=" {token(yytext);}

{integer} {
  tokenInteger("INTEGER", atoi(yytext));
}

{real} {
  tokenString("REAL", yytext);
}

{id} {
  tokenString("ID", yytext);
  insert(yytext);
}

\n {
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
  tokenString("STRING", temp_string);
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

int lookup(char *str){
  for(int i =0; i < table_len; i++){
    if(strcmp(table[i], str) == 0)
      return i;
  }
  return -1;
}

void insert(char *str){
  if(lookup(str) == -1){
    table[table_len] = malloc(yyleng * sizeof(char*));
    strcpy(table[table_len], str);
    table_len++;
  }
}

int main(int argc, char* argv[]) {
  table = malloc(MAX_TABLE_LENG * sizeof(char*));
  yylex() ;

  for(int i = 0; i < table_len; i++){
    printf("%s\n", table[i]);
  }
  free(table);

  return EXIT_SUCCESS ;
}