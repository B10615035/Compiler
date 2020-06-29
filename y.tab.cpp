/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y"

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

#line 97 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 261 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   563

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    66,     2,     2,
      63,    64,    54,    52,    65,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,     2,
      51,    59,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    79,    93,    96,    99,   102,   104,   104,
     104,   106,   143,   187,   209,   233,   233,   257,   257,   287,
     314,   318,   322,   326,   330,   335,   345,   335,   383,   399,
     415,   417,   421,   423,   428,   428,   436,   438,   438,   438,
     440,   470,   500,   500,   512,   512,   524,   524,   536,   536,
     548,   553,   558,   563,   563,   573,   577,   573,   587,   597,
     601,   631,   631,   639,   641,   641,   641,   643,   662,   693,
     725,   757,   789,   809,   813,   867,   873,   876,   882,   885,
     888,   891,   927,   936,   945,   954,   982,  1010,  1038,  1066,
    1094,  1122,  1135
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOLEAN", "BREAK", "CASE", "_CHAR",
  "CLASS", "CONTINUE", "DO", "DEF", "ELSE", "EXIT", "FALSE", "FLOAT",
  "FOR", "IF", "INT", "_NULL", "OBJECT", "PRINT", "PRINTLN", "REPEAT",
  "_STRING", "TO", "RETURN", "TYPE", "TRUE", "VAR", "VAL", "AND", "OR",
  "ADD_ASSIGN", "SUBT_ASSIGN", "MUTI_ASSIGN", "DIVI_ASSIGN", "INCRESE",
  "DECRESE", "GREAT_EQUAL", "LESS_EQUAL", "EQUAL", "NOT_EQUAL",
  "MOD_EQUAL", "INTEGER", "STR", "REAL", "ID", "CHAR", "WHILE", "'!'",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "UMINUS", "'{'", "'}'", "'='",
  "':'", "'['", "']'", "'('", "')'", "','", "'%'", "$accept", "program",
  "$@1", "method", "const_declares", "var_declare", "val_declare", "$@2",
  "$@3", "arr_declare", "type", "functions", "$@4", "$@5", "func_arg",
  "func_type", "func_scope", "scope", "$@6", "func_content", "statement",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "func_call", "else",
  "$@14", "param", "expression", "bool_type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    33,
      62,    60,    43,    45,    42,    47,   304,   123,   125,    61,
      58,    91,    93,    40,    41,    44,    37
};
# endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,   -36,    14,  -120,  -120,   -14,   197,   -25,   -30,   -23,
     -18,    10,    85,    11,    29,    30,  -120,    18,   197,  -120,
    -120,  -120,   197,   197,  -120,    17,    35,   122,  -120,   122,
    -120,   122,  -120,  -120,  -120,  -120,  -120,   -54,  -120,   122,
     122,   122,  -120,   454,  -120,   -24,    -4,   122,   122,   122,
      21,  -120,  -120,  -120,  -120,  -120,    34,   122,   201,   122,
     454,   122,   454,   122,   142,   -38,   219,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,    97,  -120,    97,   454,   248,    37,   266,   122,    58,
      52,   295,  -120,   313,   342,   360,    67,   142,   473,   -29,
     -29,   454,   -29,   -29,   -29,   -13,   -13,   -38,   -38,   454,
     454,  -120,  -120,  -120,  -120,  -120,   -46,   122,    47,    48,
    -120,   122,   389,    49,    46,   122,  -120,   190,  -120,  -120,
    -120,   122,   122,   454,  -120,   122,  -120,  -120,    97,    57,
     148,  -120,   107,  -120,   454,   407,   122,   454,   190,    54,
      97,  -120,   122,   515,  -120,  -120,  -120,   454,  -120,    58,
    -120,    70,   436,   515,    66,   515,   190,  -120,   515,  -120,
     190,  -120,  -120,  -120,  -120,    75,  -120,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     7,     0,     0,     0,
      44,    48,    52,     0,     0,     0,    55,     0,     7,     8,
       9,    10,     7,     7,    59,     0,     0,     0,    42,     0,
      46,     0,    83,    82,    75,    77,    76,    74,    78,     0,
       0,     0,    80,    51,    79,    14,     0,     0,     0,    66,
       0,     3,     4,     5,     6,    25,     0,     0,     0,     0,
      45,     0,    49,     0,    84,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    40,     0,     0,    64,     0,    30,
       0,     0,    53,     0,     0,     0,    73,    91,    92,    87,
      88,    89,    90,    85,    86,    68,    69,    70,    71,    72,
      11,    23,    24,    21,    20,    22,    13,     0,     0,     0,
      60,    66,     0,     0,     0,     0,    73,     0,    43,    47,
      81,     0,     0,    16,    17,     0,    65,    56,     0,    32,
       0,    34,    63,    36,    12,     0,     0,    41,     0,    28,
       0,    26,     0,    39,    61,    54,    19,    18,    57,    30,
      31,     0,     0,    39,     0,    39,     0,    29,    39,    27,
       0,    37,    35,    38,    62,     0,    58,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -120,  -120,  -120,   -17,   -12,  -120,  -120,  -120,  -120,  -120,
     -64,  -120,  -120,  -120,   -20,  -120,  -120,   -76,  -120,   -66,
    -119,  -120,  -120,  -120,  -120,  -120,  -120,  -120,    -6,  -120,
    -120,    15,    -9,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    17,    18,    19,    20,   117,   146,    21,
     116,    22,    89,   161,   124,   151,   169,   142,   153,   164,
      23,    59,    29,    61,    31,   127,    50,   148,    42,   155,
     166,    86,    87,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    52,    71,    43,     1,    53,    54,    63,   143,    49,
       3,    71,    24,   131,     4,   132,    24,    24,    58,   118,
      60,    25,    62,    75,    76,    77,    78,    71,    79,   143,
      64,    65,    66,    26,   165,    80,    81,    79,    84,    85,
      27,    77,    78,     6,   165,    28,   165,   143,    91,   165,
      93,   143,    94,    79,    95,    82,    83,    45,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   158,    30,   149,    46,    51,   -50,   -50,   122,
      55,    56,   -50,   -50,    88,    90,   160,   -50,   -50,    47,
     174,    48,   -50,    49,   176,   -50,   -50,   171,    32,   173,
     111,   120,   175,   112,   123,   125,   134,   135,   133,   138,
     139,   113,    33,   -50,   114,   -50,   140,   150,   154,   159,
     115,    24,   144,   145,   172,   -50,   147,   168,    34,    35,
      36,    37,    38,   177,    39,    32,   136,   157,    40,   167,
       0,   163,    24,   162,     0,     0,     0,    24,    41,    33,
       0,   163,     0,   163,     0,     0,   163,    24,     0,    24,
      24,     0,    24,     0,    24,    34,    35,    36,    37,    38,
       0,    39,   152,     0,     0,    40,     0,     0,    67,    68,
      69,    70,    71,    72,     0,    57,    69,    70,    71,    72,
       0,     0,    73,    74,    75,    76,    77,    78,    73,    74,
      75,    76,    77,    78,     0,     8,     9,     7,    79,     0,
      10,    11,     8,     9,    79,    12,     0,    10,    11,     0,
       0,     0,    12,     0,     0,    13,    14,     0,     0,     0,
       0,    67,    68,     0,     0,     0,    15,     0,    16,    69,
      70,    71,    72,    15,     0,    16,     0,   141,     0,    67,
      68,    73,    74,    75,    76,    77,    78,    69,    70,    71,
      72,     0,     0,     0,     0,    92,     0,    79,     0,    73,
      74,    75,    76,    77,    78,     0,     0,     0,    67,    68,
       0,     0,     0,    96,     0,    79,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,    67,    68,    73,    74,
      75,    76,    77,    78,    69,    70,    71,    72,     0,     0,
     119,     0,     0,     0,    79,     0,    73,    74,    75,    76,
      77,    78,     0,     0,     0,    67,    68,     0,     0,     0,
       0,   121,    79,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,    67,    68,    73,    74,    75,    76,    77,
      78,    69,    70,    71,    72,     0,     0,     0,     0,   126,
       0,    79,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    67,    68,     0,     0,     0,   128,     0,    79,
      69,    70,    71,    72,     0,     0,     0,     0,     0,     0,
      67,    68,    73,    74,    75,    76,    77,    78,    69,    70,
      71,    72,     0,     0,     0,     0,   129,     0,    79,     0,
      73,    74,    75,    76,    77,    78,     0,     0,     0,    67,
      68,     0,   130,     0,     0,     0,    79,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,    67,    68,    73,
      74,    75,    76,    77,    78,    69,    70,    71,    72,     0,
       0,     0,     0,   137,     0,    79,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,    67,    68,     0,   156,
       0,     0,     0,    79,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,    67,    68,    73,    74,    75,    76,
      77,    78,    69,    70,    71,    72,     0,     0,     0,     0,
     170,     0,    79,    67,    73,    74,    75,    76,    77,    78,
       0,    69,    70,    71,    72,     0,     0,     0,     0,     0,
      79,     0,     0,    73,    74,    75,    76,    77,    78,     0,
       8,     9,     0,     0,     0,    10,    11,     0,     0,    79,
      12,     0,     0,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,    16
};

static const yytype_int16 yycheck[] =
{
       6,    18,    40,    12,    19,    22,    23,    61,   127,    63,
      46,    40,    18,    59,     0,    61,    22,    23,    27,    83,
      29,    46,    31,    52,    53,    54,    55,    40,    66,   148,
      39,    40,    41,    63,   153,    59,    60,    66,    47,    48,
      63,    54,    55,    57,   163,    63,   165,   166,    57,   168,
      59,   170,    61,    66,    63,    59,    60,    46,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   148,    63,   138,    46,    58,    10,    11,    88,
      63,    46,    15,    16,    63,    51,   150,    20,    21,    59,
     166,    61,    25,    63,   170,    28,    29,   163,    13,   165,
       3,    64,   168,     6,    46,    53,    59,    59,   117,    60,
      64,    14,    27,    46,    17,    48,   125,    60,    11,    65,
      23,   127,   131,   132,    58,    58,   135,    57,    43,    44,
      45,    46,    47,    58,    49,    13,   121,   146,    53,   159,
      -1,   153,   148,   152,    -1,    -1,    -1,   153,    63,    27,
      -1,   163,    -1,   165,    -1,    -1,   168,   163,    -1,   165,
     166,    -1,   168,    -1,   170,    43,    44,    45,    46,    47,
      -1,    49,    24,    -1,    -1,    53,    -1,    -1,    30,    31,
      38,    39,    40,    41,    -1,    63,    38,    39,    40,    41,
      -1,    -1,    50,    51,    52,    53,    54,    55,    50,    51,
      52,    53,    54,    55,    -1,    15,    16,    10,    66,    -1,
      20,    21,    15,    16,    66,    25,    -1,    20,    21,    -1,
      -1,    -1,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    46,    -1,    48,    38,
      39,    40,    41,    46,    -1,    48,    -1,    57,    -1,    30,
      31,    50,    51,    52,    53,    54,    55,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    64,    -1,    66,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    50,    51,
      52,    53,    54,    55,    38,    39,    40,    41,    -1,    -1,
      62,    -1,    -1,    -1,    66,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    65,    66,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    50,    51,    52,    53,    54,
      55,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    64,
      -1,    66,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    64,    -1,    66,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    50,    51,    52,    53,    54,    55,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    64,    -1,    66,    -1,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    30,
      31,    -1,    62,    -1,    -1,    -1,    66,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    50,
      51,    52,    53,    54,    55,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    64,    -1,    66,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    30,    31,    -1,    62,
      -1,    -1,    -1,    66,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    50,    51,    52,    53,
      54,    55,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      64,    -1,    66,    30,    50,    51,    52,    53,    54,    55,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    50,    51,    52,    53,    54,    55,    -1,
      15,    16,    -1,    -1,    -1,    20,    21,    -1,    -1,    66,
      25,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    68,    46,     0,    69,    57,    10,    15,    16,
      20,    21,    25,    28,    29,    46,    48,    70,    71,    72,
      73,    76,    78,    87,    95,    46,    63,    63,    63,    89,
      63,    91,    13,    27,    43,    44,    45,    46,    47,    49,
      53,    63,    95,    99,   100,    46,    46,    59,    61,    63,
      93,    58,    70,    70,    70,    63,    46,    63,    99,    88,
      99,    90,    99,    61,    99,    99,    99,    30,    31,    38,
      39,    40,    41,    50,    51,    52,    53,    54,    55,    66,
      59,    60,    59,    60,    99,    99,    98,    99,    63,    79,
      51,    99,    64,    99,    99,    99,    64,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,     3,     6,    14,    17,    23,    77,    74,    77,    62,
      64,    65,    99,    46,    81,    53,    64,    92,    64,    64,
      62,    59,    61,    99,    59,    59,    98,    64,    60,    64,
      99,    57,    84,    87,    99,    99,    75,    99,    94,    77,
      60,    82,    24,    85,    11,    96,    62,    99,    84,    65,
      77,    80,    99,    71,    86,    87,    97,    81,    57,    83,
      64,    86,    58,    86,    84,    86,    84,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    70,    70,    71,    71,
      71,    72,    72,    72,    72,    74,    73,    75,    73,    76,
      77,    77,    77,    77,    77,    79,    80,    78,    81,    81,
      81,    82,    82,    83,    85,    84,    84,    86,    86,    86,
      87,    87,    88,    87,    89,    87,    90,    87,    91,    87,
      87,    87,    87,    92,    87,    93,    94,    87,    87,    87,
      95,    97,    96,    96,    98,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     2,     2,     0,     1,     1,
       1,     4,     6,     4,     2,     0,     5,     0,     7,     7,
       1,     1,     1,     1,     1,     0,     0,     9,     3,     5,
       0,     2,     0,     3,     0,     4,     1,     2,     2,     0,
       3,     6,     0,     5,     0,     3,     0,     5,     0,     3,
       4,     2,     1,     0,     7,     0,     0,     7,    10,     1,
       4,     0,     3,     0,     1,     3,     0,     2,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     2,     3,     3,     3,     3,     3,
       3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 79 "yacc.y"
                  {
    obj_name = (yyvsp[0].Token).stringVal;
    file << "class " << *(yyvsp[0].Token).stringVal << "\n{\n";
    Trace("OBJECT ID push talbe");
    symbolTable_data obj;
    obj.type = TT_OBJ;
    tables.add(obj);
    tables.push((yyvsp[0].Token).stringVal);
}
#line 1650 "y.tab.cpp"
    break;

  case 3:
#line 87 "yacc.y"
                {
    Trace("code end");
    tables.pop();
    file << "}\n";
}
#line 1660 "y.tab.cpp"
    break;

  case 4:
#line 93 "yacc.y"
                              {
    Trace("reduce const_declares method");
}
#line 1668 "y.tab.cpp"
    break;

  case 5:
#line 96 "yacc.y"
                   {
    Trace("reduce functions method");
}
#line 1676 "y.tab.cpp"
    break;

  case 6:
#line 99 "yacc.y"
                   {
    Trace("reduce fstatement method");
}
#line 1684 "y.tab.cpp"
    break;

  case 11:
#line 106 "yacc.y"
                                   {
    isConst = false;
    Trace("var id = expression");
    symbolTable_data new_var;
    new_var.name = (yyvsp[-2].Token).stringVal;
    new_var.type = (yyvsp[0].Token).tokenType;
    new_var.isInit = true;
    new_var.isConst = false;
    if((yyvsp[0].Token).tokenType == TT_INT)
        new_var.intVal = (yyvsp[0].Token).intVal;
    else if((yyvsp[0].Token).tokenType == TT_FLOAT)
        new_var.floatVal = (yyvsp[0].Token).floatVal;
    else if((yyvsp[0].Token).tokenType == TT_STRING)
        new_var.stringVal = (yyvsp[0].Token).stringVal;
    else if((yyvsp[0].Token).tokenType == TT_BOOL)
        new_var.boolVal = (yyvsp[0].Token).boolVal;
    else if((yyvsp[0].Token).tokenType == TT_CHAR)
        new_var.charVal = (yyvsp[0].Token).charVal;

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
#line 1726 "y.tab.cpp"
    break;

  case 12:
#line 143 "yacc.y"
                                {
    isConst = false;
    Trace("var id : type = expression");
    symbolTable_data new_var;
    new_var.name = (yyvsp[-4].Token).stringVal;
    new_var.type = (yyvsp[-2].Token).tokenType;
    new_var.isInit = true;
    new_var.isConst = false;

    if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT)
        new_var.floatVal = (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType != (yyvsp[0].Token).tokenType){
        yyerror("var id : type = expression  type != expression.type");
    }
    else if((yyvsp[-2].Token).tokenType == TT_INT)
        new_var.intVal = (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT)
        new_var.floatVal = (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING)
        new_var.stringVal = (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_BOOL)
        new_var.boolVal = (yyvsp[0].Token).boolVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR)
        new_var.charVal = (yyvsp[0].Token).charVal;

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
#line 1775 "y.tab.cpp"
    break;

  case 13:
#line 187 "yacc.y"
                 {
    isConst = false;
    Trace("var id : type");
    symbolTable_data new_var;
    new_var.name = (yyvsp[-2].Token).stringVal;
    new_var.type = (yyvsp[0].Token).tokenType;
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
#line 1802 "y.tab.cpp"
    break;

  case 14:
#line 209 "yacc.y"
        {
    isConst = false;
    Trace("var id");
    symbolTable_data new_var;
    new_var.name = (yyvsp[0].Token).stringVal;
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
}
#line 1829 "y.tab.cpp"
    break;

  case 15:
#line 233 "yacc.y"
                        {
    isConst = true;
}
#line 1837 "y.tab.cpp"
    break;

  case 16:
#line 235 "yacc.y"
             {
    isConst = false;
    Trace("val id = expression");
    symbolTable_data new_var;
    new_var.name = (yyvsp[-3].Token).stringVal;
    new_var.type = (yyvsp[0].Token).tokenType;
    new_var.isInit = true;
    new_var.isConst = true;
    if((yyvsp[0].Token).tokenType == TT_INT)
        new_var.intVal = (yyvsp[0].Token).intVal;
    else if((yyvsp[0].Token).tokenType == TT_FLOAT)
        new_var.floatVal = (yyvsp[0].Token).floatVal;
    else if((yyvsp[0].Token).tokenType == TT_STRING)
        new_var.stringVal = (yyvsp[0].Token).stringVal;
    else if((yyvsp[0].Token).tokenType == TT_BOOL)
        new_var.boolVal = (yyvsp[0].Token).boolVal;
    else if((yyvsp[0].Token).tokenType == TT_CHAR)
        new_var.charVal = (yyvsp[0].Token).charVal;
    
    if(!tables.add(new_var))
        yyerror("var id = expression error");
}
#line 1864 "y.tab.cpp"
    break;

  case 17:
#line 257 "yacc.y"
                      { 
    isConst = true;
}
#line 1872 "y.tab.cpp"
    break;

  case 18:
#line 259 "yacc.y"
             {
    isConst = false;
    symbolTable_data new_var;
    new_var.name = (yyvsp[-5].Token).stringVal;
    new_var.type = (yyvsp[-3].Token).tokenType;
    new_var.isInit = true;
    new_var.isConst = true;

    if((yyvsp[-3].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT)
        new_var.floatVal = (yyvsp[0].Token).intVal;
    else if((yyvsp[-3].Token).tokenType != (yyvsp[0].Token).tokenType){
        yyerror("var id : type = expression  type != expression.type");
    }
    else if((yyvsp[-3].Token).tokenType == TT_INT)
        new_var.intVal = (yyvsp[0].Token).intVal;
    else if((yyvsp[-3].Token).tokenType == TT_FLOAT)
        new_var.floatVal = (yyvsp[0].Token).floatVal;
    else if((yyvsp[-3].Token).tokenType == TT_STRING)
        new_var.stringVal = (yyvsp[0].Token).stringVal;
    else if((yyvsp[-3].Token).tokenType == TT_BOOL)
        new_var.boolVal = (yyvsp[0].Token).boolVal;
    else if((yyvsp[-3].Token).tokenType == TT_CHAR)
        new_var.charVal = (yyvsp[0].Token).charVal;

    if(!tables.add(new_var))
        yyerror("var id : type = expression error");
}
#line 1904 "y.tab.cpp"
    break;

  case 19:
#line 287 "yacc.y"
                                               {
    Trace("var id type[int]");
    if((yyvsp[-1].Token).tokenType != TT_INT)
        yyerror("arr len must be integer");

    symbolTable_data new_arr;
    new_arr.name = (yyvsp[-5].Token).stringVal;
    new_arr.type = (yyvsp[-3].Token).tokenType;
    new_arr.arrSize = (yyvsp[-1].Token).intVal;
    new_arr.isConst = false;
    new_arr.isArr = true;

    if((yyvsp[-3].Token).tokenType == TT_INT)
        new_arr.intArr = new int[new_arr.arrSize];
    else if((yyvsp[-3].Token).tokenType == TT_FLOAT)
        new_arr.floatArr = new float[new_arr.arrSize];
    else if((yyvsp[-3].Token).tokenType == TT_STRING)
        new_arr.stringArr = new string*[new_arr.arrSize];
    else if((yyvsp[-3].Token).tokenType == TT_BOOL)
        new_arr.boolArr = new bool[new_arr.arrSize];
    else if((yyvsp[-3].Token).tokenType == TT_CHAR)
        new_arr.charArr = new char[new_arr.arrSize];

    tables.add(new_arr);
}
#line 1934 "y.tab.cpp"
    break;

  case 20:
#line 314 "yacc.y"
         {
    Trace("reduce INT");
    (yyval.Token).tokenType = TT_INT;
}
#line 1943 "y.tab.cpp"
    break;

  case 21:
#line 318 "yacc.y"
       {
    Trace("reduce FLOAT");
    (yyval.Token).tokenType = TT_FLOAT;
}
#line 1952 "y.tab.cpp"
    break;

  case 22:
#line 322 "yacc.y"
         {
    Trace("reduce _STRING");
    (yyval.Token).tokenType = TT_STRING;
}
#line 1961 "y.tab.cpp"
    break;

  case 23:
#line 326 "yacc.y"
         {
    Trace("reduce BOOLEAN");
    (yyval.Token).tokenType = TT_BOOL;
}
#line 1970 "y.tab.cpp"
    break;

  case 24:
#line 330 "yacc.y"
       {
    Trace("reduce CHAR");
    (yyval.Token).tokenType = TT_CHAR;
}
#line 1979 "y.tab.cpp"
    break;

  case 25:
#line 335 "yacc.y"
                      {
    Trace("function id push table");
    symbolTable_data new_func;
    new_func.name = (yyvsp[-1].Token).stringVal;
    new_func.type = TT_FUNC;
    if(!tables.add(new_func))
        yyerror("def id (arg) error");
    tables.push((yyvsp[-1].Token).stringVal);
    stackIndex = 0;
    func_return = false;
}
#line 1995 "y.tab.cpp"
    break;

  case 26:
#line 345 "yacc.y"
                        {
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
}
#line 2032 "y.tab.cpp"
    break;

  case 27:
#line 376 "yacc.y"
            {
    Trace("function end");
    if(!func_return)
        file << "return\n";
    file << "}\n";
}
#line 2043 "y.tab.cpp"
    break;

  case 28:
#line 383 "yacc.y"
                     {
    Trace("func id : type");
    symbolTable_data fun_var;
    fun_var.name = (yyvsp[-2].Token).stringVal;
    fun_var.type = (yyvsp[0].Token).tokenType;
    fun_var.isInit = false;
    fun_var.global = false;

    fun_var.stackIndex = stackIndex;
    stackIndex++;

    if(!tables.add(fun_var))
        yyerror("func id : type error");

	tables.tables[tables.tables.size()-2].table_datas.back().argType.push_back((yyvsp[0].Token).tokenType);
}
#line 2064 "y.tab.cpp"
    break;

  case 29:
#line 399 "yacc.y"
                          {
    Trace("func id : type , func_arg");
    symbolTable_data fun_var;
    fun_var.name = (yyvsp[-4].Token).stringVal;
    fun_var.type = (yyvsp[-2].Token).tokenType;
    fun_var.isInit = false;
    fun_var.global = false;

    fun_var.stackIndex = stackIndex;
    stackIndex++;
    
    if(!tables.add(fun_var))
        yyerror("func id : type error");

	tables.tables[tables.tables.size()-2].table_datas.back().argType.push_back((yyvsp[-2].Token).tokenType);
}
#line 2085 "y.tab.cpp"
    break;

  case 31:
#line 417 "yacc.y"
                   {
    Trace("func : type");
    tables.tables[tables.tables.size()-2].table_datas.back().func_type = (yyvsp[0].Token).tokenType;
}
#line 2094 "y.tab.cpp"
    break;

  case 33:
#line 423 "yacc.y"
                                 {
    Trace("scope end");
    tables.pop();
}
#line 2103 "y.tab.cpp"
    break;

  case 34:
#line 428 "yacc.y"
           {
    Trace("scope start");
    string* temp = new string("statement");
    tables.push(temp);
}
#line 2113 "y.tab.cpp"
    break;

  case 35:
#line 432 "yacc.y"
                   {
    Trace("scope end");
    tables.pop();
}
#line 2122 "y.tab.cpp"
    break;

  case 40:
#line 440 "yacc.y"
                              {
    Trace("id = expression");
    symbolTable_data id = tables.lookup_all((yyvsp[-2].Token).stringVal);
    id.isInit = true;
    if(id.type == TT_NONE)
        yyerror("can not find this ID");
    else if(id.type == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT)
        id.floatVal = (yyvsp[0].Token).intVal;
    else if(id.type != (yyvsp[0].Token).tokenType)
        yyerror("id = expression id type != expression type");
    else if(id.type == TT_INT)
        id.intVal = (yyvsp[0].Token).intVal;
    else if(id.type == TT_FLOAT)
        id.floatVal = (yyvsp[0].Token).floatVal;
    else if(id.type == TT_STRING)
        id.stringVal = (yyvsp[0].Token).stringVal;
    else if(id.type == TT_BOOL)
        id.boolVal = (yyvsp[0].Token).boolVal;
    else if(id.type == TT_CHAR)
        id.charVal = (yyvsp[0].Token).charVal;
    tables.update(id);

    if(id.global){
        file <<  "putstatic int " << *obj_name << "." << *id.name << "\n";
    }
    else{
        
        file << "istore " << id.stackIndex << "\n";
    }
}
#line 2157 "y.tab.cpp"
    break;

  case 41:
#line 470 "yacc.y"
                                      {
    Trace("id[expressino] = expression");
    symbolTable_data arr = tables.lookup_all((yyvsp[-5].Token).stringVal);
    arr.isInit = true;
    if((yyvsp[-3].Token).tokenType != TT_INT)
        yyerror("id[expressino] = expression type is not integer");
    if(arr.type == TT_NONE)
        yyerror("id[expressino] = expression array is not exit");
    if((yyvsp[-3].Token).intVal > arr.arrSize)
        yyerror("id[expressino] = expression array index out of range");
    if(arr.isArr == false)
        yyerror("id[expressino] = expression this id is not array");

    if(arr.type == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT)
        arr.floatArr[(yyvsp[-3].Token).intVal] = (yyvsp[0].Token).intVal;
    else if(arr.type != (yyvsp[0].Token).tokenType)
        yyerror("id[expressino] = expression type error");
    else if(arr.type == TT_INT)
        arr.intArr[(yyvsp[-3].Token).intVal] = (yyvsp[0].Token).intVal;
    else if(arr.type == TT_FLOAT)
        arr.floatArr[(yyvsp[-3].Token).intVal] = (yyvsp[0].Token).floatVal;
    else if(arr.type == TT_STRING)
        arr.stringArr[(yyvsp[-3].Token).intVal] = (yyvsp[0].Token).stringVal;
    else if(arr.type == TT_BOOL)
        arr.boolArr[(yyvsp[-3].Token).intVal] = (yyvsp[0].Token).boolVal;
    else if(arr.type == TT_CHAR)
        arr.charArr[(yyvsp[-3].Token).intVal] = (yyvsp[0].Token).charVal;

    tables.update(arr);
}
#line 2192 "y.tab.cpp"
    break;

  case 42:
#line 500 "yacc.y"
            {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
}
#line 2200 "y.tab.cpp"
    break;

  case 43:
#line 502 "yacc.y"
                 {
    Trace("print (expression)");
    file << "invokevirtual void java.io.PrintStream.print(";
    if((yyvsp[-1].Token).tokenType == TT_INT)
        file << "int)\n";
    else if((yyvsp[-1].Token).tokenType == TT_BOOL)
        file << "int)\n";
    else if((yyvsp[-1].Token).tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
#line 2215 "y.tab.cpp"
    break;

  case 44:
#line 512 "yacc.y"
        {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
}
#line 2223 "y.tab.cpp"
    break;

  case 45:
#line 514 "yacc.y"
              {
    Trace("print expression");
    file << "invokevirtual void java.io.PrintStream.print(";
    if((yyvsp[0].Token).tokenType == TT_INT)
        file << "int)\n";
    else if((yyvsp[0].Token).tokenType == TT_BOOL)
        file << "int)\n";
    else if((yyvsp[0].Token).tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
#line 2238 "y.tab.cpp"
    break;

  case 46:
#line 524 "yacc.y"
              {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
}
#line 2246 "y.tab.cpp"
    break;

  case 47:
#line 526 "yacc.y"
                 {
    Trace("println (expression)");
    file << "invokevirtual void java.io.PrintStream.println(";
    if((yyvsp[-1].Token).tokenType == TT_INT)
        file << "int)\n";
    else if((yyvsp[-1].Token).tokenType == TT_BOOL)
        file << "int)\n";
    else if((yyvsp[-1].Token).tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
#line 2261 "y.tab.cpp"
    break;

  case 48:
#line 536 "yacc.y"
          {
    file << "getstatic java.io.PrintStream java.lang.System.out\n";
}
#line 2269 "y.tab.cpp"
    break;

  case 49:
#line 538 "yacc.y"
             {
    Trace("println expression");
    file << "invokevirtual void java.io.PrintStream.println(";
    if((yyvsp[0].Token).tokenType == TT_INT)
        file << "int)\n";
    else if((yyvsp[0].Token).tokenType == TT_BOOL)
        file << "int)\n";
    else if((yyvsp[0].Token).tokenType == TT_STRING)
        file << "java.lang.String)\n";
}
#line 2284 "y.tab.cpp"
    break;

  case 50:
#line 548 "yacc.y"
                            {
    func_return = true;
    Trace("return (expression)");
    file << "ireturn\n";
}
#line 2294 "y.tab.cpp"
    break;

  case 51:
#line 553 "yacc.y"
                    {
    func_return = true;
    Trace("return expression");
    file << "ireturn\n";
}
#line 2304 "y.tab.cpp"
    break;

  case 52:
#line 558 "yacc.y"
         {
    Trace("return");
    func_return = true;
    file << "return\n";
}
#line 2314 "y.tab.cpp"
    break;

  case 53:
#line 563 "yacc.y"
                        {
    file << "ifeq " << "L" << jumpIndex << "\n";
    elseJump.push_back(jumpIndex);
    jumpIndex++;
}
#line 2324 "y.tab.cpp"
    break;

  case 54:
#line 567 "yacc.y"
             {
    Trace("if(bool_type) scope");
    file << "L" << elseJump.back() << ":\n";
    elseJump.pop_back();
    file << "nop\n";
}
#line 2335 "y.tab.cpp"
    break;

  case 55:
#line 573 "yacc.y"
        {
    file << "L" << jumpIndex << ":\n";
    (yyvsp[0].Token).whileBegin = jumpIndex;
    jumpIndex++;
}
#line 2345 "y.tab.cpp"
    break;

  case 56:
#line 577 "yacc.y"
                     {
    file << "ifeq " << "L" << jumpIndex << "\n";
    (yyvsp[-4].Token).whileExit = jumpIndex;
    jumpIndex++;
}
#line 2355 "y.tab.cpp"
    break;

  case 57:
#line 581 "yacc.y"
        {
    Trace("while(bool_type) scope");
    file << "goto " << "L" << (yyvsp[-6].Token).whileBegin << "\n";
    file << "L" << (yyvsp[-6].Token).whileExit << ":\n";
    file << "nop\n";
}
#line 2366 "y.tab.cpp"
    break;

  case 58:
#line 587 "yacc.y"
                                                       {
    Trace("for(id <- int to int ");

    if(tables.lookup_all((yyvsp[-7].Token).stringVal).type == TT_NONE)
        yyerror("for loop id is not find.");

    if((yyvsp[-4].Token).tokenType != TT_INT || (yyvsp[-2].Token).tokenType != TT_INT)
        yyerror("for loop type error");
}
#line 2380 "y.tab.cpp"
    break;

  case 59:
#line 597 "yacc.y"
           {
    Trace("func_call;");
}
#line 2388 "y.tab.cpp"
    break;

  case 60:
#line 601 "yacc.y"
                            {
    Trace("func_call ID (param)");
    symbolTable_data func = tables.lookup_all((yyvsp[-3].Token).stringVal);
    if(func.type == TT_NONE)
        yyerror("can not find function");
    (yyval.Token).tokenType = func.func_type;

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

}
#line 2422 "y.tab.cpp"
    break;

  case 61:
#line 631 "yacc.y"
           {
    file << "goto " << "L" << jumpIndex << "\n";
    file << "L" << elseJump.back() << ":\n";
    elseJump.pop_back();
    elseJump.push_back(jumpIndex);
    jumpIndex++;
    file << "nop\n";
}
#line 2435 "y.tab.cpp"
    break;

  case 67:
#line 643 "yacc.y"
                                        {
    Trace("- expression");
    if((yyvsp[0].Token).val_init == false)
        yyerror("- expression $2 is not initial.");
    
    if((yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = -1 * (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = -1 * (yyvsp[0].Token).floatVal;
    }
    else
        yyerror("- expression type error");

    if(!isConst)
        file << "ineg\n";
}
#line 2459 "y.tab.cpp"
    break;

  case 68:
#line 662 "yacc.y"
                            {
    Trace("expression + expression");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression + expression $1 is not initial.");

    if((yyvsp[0].Token).val_init == false)
        yyerror("expression + expression $3 is not initial.");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = (yyvsp[-2].Token).intVal + (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal + (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).intVal + (yyvsp[0].Token).floatVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal + (yyvsp[0].Token).floatVal;
    }
    else
        yyerror("expression + expression type error.");
    
    if(!isConst){
        file << "iadd\n";
    }
}
#line 2495 "y.tab.cpp"
    break;

  case 69:
#line 693 "yacc.y"
                            {
    Trace("expression - expression");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression - expression $1 is not initial.");

    if((yyvsp[0].Token).val_init == false)
        yyerror("expression - expression $3 is not initial.");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = (yyvsp[-2].Token).intVal - (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal - (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).intVal - (yyvsp[0].Token).floatVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal - (yyvsp[0].Token).floatVal;
    }
    else{
        yyerror("expression * expression type error.");
    }

    if(!isConst){
        file << "isub\n";
    }
}
#line 2532 "y.tab.cpp"
    break;

  case 70:
#line 725 "yacc.y"
                            {
    Trace("expression * expression");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression * expression $1 is not initial.");

    if((yyvsp[0].Token).val_init == false)
        yyerror("expression * expression $3 is not initial.");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = (yyvsp[-2].Token).intVal * (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal * (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).intVal * (yyvsp[0].Token).floatVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal * (yyvsp[0].Token).floatVal;
    }
    else{
        yyerror("expression * expression type error.");
    }

    if(!isConst){
        file << "imul\n";
    }
}
#line 2569 "y.tab.cpp"
    break;

  case 71:
#line 757 "yacc.y"
                            {
    Trace("expression / expression");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression / expression $1 is not initial.");

    if((yyvsp[0].Token).val_init == false)
        yyerror("expression / expression $3 is not initial.");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = (yyvsp[-2].Token).intVal / (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal / (yyvsp[0].Token).intVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).intVal / (yyvsp[0].Token).floatVal;
    }
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = (yyvsp[-2].Token).floatVal / (yyvsp[0].Token).floatVal;
    }
    else{
        yyerror("expression / expression type error.");
    }

    if(!isConst){
        file << "idiv\n";
    }
}
#line 2606 "y.tab.cpp"
    break;

  case 72:
#line 789 "yacc.y"
                            {
    Trace("expression % expression");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression % expression $1 is not initial.");

    if((yyvsp[0].Token).val_init == false)
        yyerror("expression % expression $3 is not initial.");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = (yyvsp[-2].Token).intVal % (yyvsp[0].Token).intVal;
    }
    else{
        yyerror("expression % expression type error.");
    }

    if(!isConst){
        file << "irem\n";
    }
}
#line 2631 "y.tab.cpp"
    break;

  case 73:
#line 809 "yacc.y"
                    {
    Trace("( expression )");
    (yyval.Token) = (yyvsp[-1].Token);
}
#line 2640 "y.tab.cpp"
    break;

  case 74:
#line 813 "yacc.y"
     {
    Trace("ID");
    
    symbolTable_data id = tables.lookup_all((yyvsp[0].Token).stringVal);

    if(id.isInit == true)
        (yyval.Token).val_init = true;

    if(id.type == TT_NONE)
        yyerror("ID can not find this id");
    if(id.isArr == true)
        yyerror("ID this id is array but without [ ]");
    
    if(id.type == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = id.intVal;
    }
    else if(id.type == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = id.floatVal;
    }
    else if(id.type == TT_STRING){
        (yyval.Token).tokenType = TT_STRING;
        (yyval.Token).stringVal = id.stringVal;
    }
    else if(id.type == TT_CHAR){
        (yyval.Token).tokenType = TT_CHAR;
        (yyval.Token).charVal = id.charVal;
    }
    else if(id.type == TT_BOOL){
        (yyval.Token).tokenType = TT_BOOL;
        (yyval.Token).boolVal = id.boolVal;
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
#line 2699 "y.tab.cpp"
    break;

  case 75:
#line 867 "yacc.y"
          {
    Trace("reduce INTEGER");
    if(!isConst){
        file << "sipush " << (yyvsp[0].Token).intVal << "\n";
    }
}
#line 2710 "y.tab.cpp"
    break;

  case 76:
#line 873 "yacc.y"
      {
    Trace("reduce REAL");
}
#line 2718 "y.tab.cpp"
    break;

  case 77:
#line 876 "yacc.y"
     {
    Trace("reduce STR");
    if(!isConst){
        file << "ldc \"" << *(yyvsp[0].Token).stringVal << "\"\n";
    }
}
#line 2729 "y.tab.cpp"
    break;

  case 78:
#line 882 "yacc.y"
       {
    Trace("reduce CHAR");
}
#line 2737 "y.tab.cpp"
    break;

  case 79:
#line 885 "yacc.y"
            {
    Trace("reduce bool_type");
}
#line 2745 "y.tab.cpp"
    break;

  case 80:
#line 888 "yacc.y"
           {
    Trace("function call")
}
#line 2753 "y.tab.cpp"
    break;

  case 81:
#line 891 "yacc.y"
                      {
    Trace("id[expression]");
    symbolTable_data id = tables.lookup_all((yyvsp[-3].Token).stringVal);
    if((yyvsp[-1].Token).tokenType != TT_INT)
        yyerror("id[expression] index type error");
    
    if(id.type == TT_NONE)
        yyerror("id[expression] id is not find");
    if(id.isArr == false)
        yyerror("id[expression] this id is not array");

    if((yyvsp[-1].Token).intVal > id.arrSize)
        yyerror("id[expression] index out of range");

    if(id.type == TT_INT){
        (yyval.Token).tokenType = TT_INT;
        (yyval.Token).intVal = id.intArr[(yyvsp[-1].Token).intVal];
    }
    else if(id.type == TT_FLOAT){
        (yyval.Token).tokenType = TT_FLOAT;
        (yyval.Token).floatVal = id.floatArr[(yyvsp[-1].Token).intVal];
    }
    else if(id.type == TT_STRING){
        (yyval.Token).tokenType = TT_STRING;
        (yyval.Token).stringVal = id.stringArr[(yyvsp[-1].Token).intVal];
    }
    else if(id.type == TT_CHAR){
        (yyval.Token).tokenType = TT_CHAR;
        (yyval.Token).charVal = id.charArr[(yyvsp[-1].Token).intVal];
    }
    else if(id.type == TT_BOOL){
        (yyval.Token).tokenType = TT_BOOL;
        (yyval.Token).boolVal = id.boolArr[(yyvsp[-1].Token).intVal];
    }
}
#line 2793 "y.tab.cpp"
    break;

  case 82:
#line 927 "yacc.y"
                {
    Trace("reduce ture");
    (yyval.Token).tokenType = TT_BOOL;
    (yyval.Token).boolVal = true;

    if(!isConst){
        file << "iconst_1\n";
    }
}
#line 2807 "y.tab.cpp"
    break;

  case 83:
#line 936 "yacc.y"
        {
    Trace("reduce false");
    (yyval.Token).tokenType = TT_BOOL;
    (yyval.Token).boolVal = false;

    if(!isConst){
        file << "iconst_0\n";
    }
}
#line 2821 "y.tab.cpp"
    break;

  case 84:
#line 945 "yacc.y"
                {
    Trace("reduce !expression");
    (yyval.Token).tokenType = TT_BOOL;
    (yyval.Token).boolVal = !(yyvsp[0].Token).boolVal;
    if(!isConst){
        file << "iconst_1\n";
        file << "ixor\n";
    }
}
#line 2835 "y.tab.cpp"
    break;

  case 85:
#line 954 "yacc.y"
                           {
    Trace("reduce expression > expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression > expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression > expression $1 is not init");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).intVal > (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).floatVal > (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING && (yyvsp[0].Token).tokenType == TT_STRING)
        (yyval.Token).boolVal = (yyvsp[-2].Token).stringVal > (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR && (yyvsp[0].Token).tokenType == TT_CHAR)
        (yyval.Token).boolVal = (yyvsp[-2].Token).charVal > (yyvsp[0].Token).charVal;
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
#line 2868 "y.tab.cpp"
    break;

  case 86:
#line 982 "yacc.y"
                           {
    Trace("reduce expression < expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression < expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression < expression $1 is not init");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).intVal < (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).floatVal < (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING && (yyvsp[0].Token).tokenType == TT_STRING)
        (yyval.Token).boolVal = (yyvsp[-2].Token).stringVal < (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR && (yyvsp[0].Token).tokenType == TT_CHAR)
        (yyval.Token).boolVal = (yyvsp[-2].Token).charVal < (yyvsp[0].Token).charVal;
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
#line 2901 "y.tab.cpp"
    break;

  case 87:
#line 1010 "yacc.y"
                                   {
    Trace("reduce expression >= expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression >= expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression >= expression $1 is not init");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).intVal >= (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).floatVal >= (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING && (yyvsp[0].Token).tokenType == TT_STRING)
        (yyval.Token).boolVal = (yyvsp[-2].Token).stringVal >= (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR && (yyvsp[0].Token).tokenType == TT_CHAR)
        (yyval.Token).boolVal = (yyvsp[-2].Token).charVal >= (yyvsp[0].Token).charVal;
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
#line 2934 "y.tab.cpp"
    break;

  case 88:
#line 1038 "yacc.y"
                                  {
    Trace("reduce expression <= expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression <= expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression <= expression $1 is not init");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).intVal <= (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).floatVal <= (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING && (yyvsp[0].Token).tokenType == TT_STRING)
        (yyval.Token).boolVal = (yyvsp[-2].Token).stringVal <= (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR && (yyvsp[0].Token).tokenType == TT_CHAR)
        (yyval.Token).boolVal = (yyvsp[-2].Token).charVal <= (yyvsp[0].Token).charVal;
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
#line 2967 "y.tab.cpp"
    break;

  case 89:
#line 1066 "yacc.y"
                             {
    Trace("reduce expression == expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression == expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression == expression $1 is not init");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).intVal == (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).floatVal == (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING && (yyvsp[0].Token).tokenType == TT_STRING)
        (yyval.Token).boolVal = (yyvsp[-2].Token).stringVal == (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR && (yyvsp[0].Token).tokenType == TT_CHAR)
        (yyval.Token).boolVal = (yyvsp[-2].Token).charVal == (yyvsp[0].Token).charVal;
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
#line 3000 "y.tab.cpp"
    break;

  case 90:
#line 1094 "yacc.y"
                                 {
    Trace("reduce expression != expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression != expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression != expression $1 is not init");

    if((yyvsp[-2].Token).tokenType == TT_INT && (yyvsp[0].Token).tokenType == TT_INT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).intVal != (yyvsp[0].Token).intVal;
    else if((yyvsp[-2].Token).tokenType == TT_FLOAT && (yyvsp[0].Token).tokenType == TT_FLOAT)
        (yyval.Token).boolVal = (yyvsp[-2].Token).floatVal != (yyvsp[0].Token).floatVal;
    else if((yyvsp[-2].Token).tokenType == TT_STRING && (yyvsp[0].Token).tokenType == TT_STRING)
        (yyval.Token).boolVal = (yyvsp[-2].Token).stringVal != (yyvsp[0].Token).stringVal;
    else if((yyvsp[-2].Token).tokenType == TT_CHAR && (yyvsp[0].Token).tokenType == TT_CHAR)
        (yyval.Token).boolVal = (yyvsp[-2].Token).charVal != (yyvsp[0].Token).charVal;
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
#line 3033 "y.tab.cpp"
    break;

  case 91:
#line 1122 "yacc.y"
                           {
    Trace("reduce expression && expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression && expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression && expression $1 is not init");

    if((yyvsp[-2].Token).tokenType != TT_BOOL || (yyvsp[0].Token).tokenType != TT_BOOL)
        yyerror("expression && expression type error");
    
    (yyval.Token).boolVal = (yyvsp[-2].Token).boolVal && (yyvsp[0].Token).boolVal;
}
#line 3051 "y.tab.cpp"
    break;

  case 92:
#line 1135 "yacc.y"
                          {
    Trace("reduce expression || expression");
    (yyval.Token).tokenType = TT_BOOL;
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression || expression $1 is not init");
    if((yyvsp[-2].Token).val_init == false)
        yyerror("expression || expression $1 is not init");

    if((yyvsp[-2].Token).tokenType != TT_BOOL || (yyvsp[0].Token).tokenType != TT_BOOL)
        yyerror("expression || expression type error");
    
    (yyval.Token).boolVal = (yyvsp[-2].Token).boolVal || (yyvsp[0].Token).boolVal;
}
#line 3069 "y.tab.cpp"
    break;


#line 3073 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1149 "yacc.y"

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
