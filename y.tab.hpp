/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOLEAN = 258,
    BREAK = 259,
    CASE = 260,
    _CHAR = 261,
    CLASS = 262,
    CONTINUE = 263,
    DO = 264,
    DEF = 265,
    ELSE = 266,
    EXIT = 267,
    FALSE = 268,
    FLOAT = 269,
    FOR = 270,
    IF = 271,
    INT = 272,
    _NULL = 273,
    OBJECT = 274,
    PRINT = 275,
    PRINTLN = 276,
    REPEAT = 277,
    _STRING = 278,
    TO = 279,
    RETURN = 280,
    TYPE = 281,
    TRUE = 282,
    VAR = 283,
    VAL = 284,
    AND = 285,
    OR = 286,
    ADD_ASSIGN = 287,
    SUBT_ASSIGN = 288,
    MUTI_ASSIGN = 289,
    DIVI_ASSIGN = 290,
    INCRESE = 291,
    DECRESE = 292,
    GREAT_EQUAL = 293,
    LESS_EQUAL = 294,
    EQUAL = 295,
    NOT_EQUAL = 296,
    MOD_EQUAL = 297,
    INTEGER = 298,
    STR = 299,
    REAL = 300,
    ID = 301,
    CHAR = 302,
    WHILE = 303,
    UMINUS = 304
  };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define BREAK 259
#define CASE 260
#define _CHAR 261
#define CLASS 262
#define CONTINUE 263
#define DO 264
#define DEF 265
#define ELSE 266
#define EXIT 267
#define FALSE 268
#define FLOAT 269
#define FOR 270
#define IF 271
#define INT 272
#define _NULL 273
#define OBJECT 274
#define PRINT 275
#define PRINTLN 276
#define REPEAT 277
#define _STRING 278
#define TO 279
#define RETURN 280
#define TYPE 281
#define TRUE 282
#define VAR 283
#define VAL 284
#define AND 285
#define OR 286
#define ADD_ASSIGN 287
#define SUBT_ASSIGN 288
#define MUTI_ASSIGN 289
#define DIVI_ASSIGN 290
#define INCRESE 291
#define DECRESE 292
#define GREAT_EQUAL 293
#define LESS_EQUAL 294
#define EQUAL 295
#define NOT_EQUAL 296
#define MOD_EQUAL 297
#define INTEGER 298
#define STR 299
#define REAL 300
#define ID 301
#define CHAR 302
#define WHILE 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "yacc.y"

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

#line 169 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
