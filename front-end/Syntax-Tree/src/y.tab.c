/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "structfe.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#line 73 "structfe.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "structfe.tab.h".  */
#ifndef YY_YY_STRUCTFE_TAB_H_INCLUDED
# define YY_YY_STRUCTFE_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    SIZEOF = 260,
    PTR_OP = 261,
    LE_OP = 262,
    GE_OP = 263,
    L_OP = 264,
    G_OP = 265,
    EQ_OP = 266,
    NE_OP = 267,
    INC_OP = 268,
    DEC_OP = 269,
    RB_OP = 270,
    LB_OP = 271,
    AND_OP = 272,
    OR_OP = 273,
    EXTERN = 274,
    INT = 275,
    VOID = 276,
    STRUCT = 277,
    IF = 278,
    ELSE = 279,
    WHILE = 280,
    FOR = 281,
    RETURN = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 8 "structfe.y" /* yacc.c:355  */

  node_t *node;
  char *string;

#line 146 "structfe.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_STRUCTFE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 163 "structfe.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    32,     2,
      28,    29,    33,    36,    31,    34,    30,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    37,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    53,    57,    58,    61,    67,    72,
      80,    82,    90,    92,    94,   103,   115,   116,   117,   121,
     122,   124,   129,   130,   132,   137,   138,   140,   142,   144,
     149,   150,   152,   157,   158,   163,   164,   169,   171,   176,
     177,   179,   183,   185,   189,   191,   195,   196,   197,   201,
     202,   203,   207,   208,   212,   216,   220,   224,   225,   226,
     227,   231,   232,   236,   240,   241,   242,   243,   244,   248,
     249,   250,   251,   255,   256,   260,   261,   265,   266,   271,
     272,   276,   277,   281,   282,   286,   287,   291,   292,   296
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT", "SIZEOF",
  "PTR_OP", "LE_OP", "GE_OP", "L_OP", "G_OP", "EQ_OP", "NE_OP", "INC_OP",
  "DEC_OP", "RB_OP", "LB_OP", "AND_OP", "OR_OP", "EXTERN", "INT", "VOID",
  "STRUCT", "IF", "ELSE", "WHILE", "FOR", "RETURN", "'('", "')'", "'.'",
  "','", "'&'", "'*'", "'-'", "'/'", "'+'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "binary_expression", "expression",
  "declaration", "declaration_specifiers", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "declarator", "direct_declarator", "parameter_list",
  "parameter_declaration", "statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "program", "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    40,    41,
      46,    44,    38,    42,    45,    47,    43,    61,    59,   123,
     125
};
# endif

#define YYPACT_NINF -73

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-73)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   160,   -73,   -73,    10,   -73,   101,   -73,   -30,    53,
     -73,   -73,   -73,   -73,     3,   160,   -73,   101,    13,    21,
      27,   -73,   -73,   -73,   160,   101,   115,   -73,    47,    27,
     -73,   119,   -73,   228,   166,    68,   -73,   -73,   -73,   -73,
     -73,    99,   102,   126,   135,    18,   128,   -73,   -73,   -73,
     -73,   -73,   -73,     1,   106,   128,   -18,   159,    71,   196,
     152,   110,   -73,   175,   -73,   101,   -73,   -73,   145,    62,
     -73,   -73,   -73,   -73,   -73,   101,   183,   -73,   -73,   -73,
     212,   128,   128,    65,   -73,   180,   199,   236,    29,   240,
     128,   -73,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   -73,   213,   -73,   -73,
     171,   -73,   -73,   -73,   -73,     5,   223,   224,   225,   226,
      65,   -73,   -73,   -73,   -73,   190,   -73,   -73,   -73,   -73,
     -73,   -73,   -18,   -18,   159,   159,   159,   159,    71,    71,
     196,   238,   238,   152,   -73,   -73,   -73,   -73,   197,   197,
     128,   -73,   128,   234,   -73,   230,   -73,   197,   197,   -73,
     -73
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    47,    46,     0,    88,     0,    45,    48,     0,
      85,    87,    44,    48,    51,     0,    57,     0,     0,     0,
      56,    43,     1,    86,     0,     0,     0,    52,     0,    55,
      42,     0,    89,     0,     0,     0,    50,    53,    58,     2,
       3,     0,     0,     0,     0,     0,     0,    16,    17,    18,
      77,    69,     5,    12,    19,     0,    22,    25,    30,    33,
      35,    39,    41,     0,    73,     0,    75,    64,     0,     0,
      65,    66,    67,    68,    60,     0,     0,    61,    49,    54,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    71,    74,
       0,    70,    76,    63,    59,     0,     0,     0,     0,     0,
       0,    84,     4,     9,     6,     0,    10,     8,    40,    20,
      21,    19,    24,    23,    28,    29,    26,    27,    31,    32,
      34,    37,    38,    36,    72,    62,    15,    14,     0,     0,
       0,     7,     0,    79,    81,     0,    11,     0,     0,    80,
      82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   -73,    16,   -73,   132,    93,   137,   158,
     156,   138,   -73,   -45,   -21,   -29,     4,     9,   239,   -14,
     -11,   244,   -73,   149,   -66,   246,   -73,   198,   -72,   -73,
     -73,   -73,   -73,   258,   -73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    52,    53,   125,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     5,     6,     7,    13,    26,    27,
      19,    20,    76,    77,    66,    67,    68,    69,    70,    71,
      72,    73,     9,    10,    11
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      85,    86,    65,   112,    75,    12,    28,    87,    21,     8,
      64,   120,    37,    14,    35,    92,    16,    93,     8,    25,
      37,    39,    40,    41,     1,     2,     3,     4,    25,    88,
      25,    89,    39,    40,    41,   116,   118,   119,    25,    65,
       8,    17,    24,   126,   112,   128,    46,   109,   150,    15,
      47,    48,    49,    22,   107,    33,    84,    46,   124,    30,
      31,    47,    48,    49,   113,    39,    40,    41,    39,    40,
      41,    91,     1,     2,     3,     4,    38,     8,    96,    97,
      98,    99,   153,   154,   117,    42,    75,    43,    44,    45,
      46,   159,   160,    46,    47,    48,    49,    47,    48,    49,
      50,    31,   111,    50,    16,   155,    79,   156,   129,   130,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,    39,    40,    41,   103,   104,    80,   105,    17,
      81,    39,    40,    41,    18,     2,     3,     4,     1,     2,
       3,     4,    42,    90,    43,    44,    45,    46,    39,    40,
      41,    47,    48,    49,    82,    36,    46,    50,    31,    51,
      47,    48,    49,    83,     1,     2,     3,     4,    42,   102,
      43,    44,    45,    46,    39,    40,    41,    47,    48,    49,
       2,     3,     4,    50,    31,   108,     2,     3,     4,   134,
     135,   136,   137,    94,    42,    95,    43,    44,    45,    46,
      39,    40,    41,    47,    48,    49,    78,   100,   101,    50,
      31,   144,   114,   106,   115,    39,    40,    41,   121,   151,
      42,   152,    43,    44,    45,    46,   132,   133,   122,    47,
      48,    49,     2,     3,     4,    50,    31,   138,   139,   123,
      46,   141,   142,   127,    47,    48,    49,     1,     2,     3,
       4,    30,   146,   147,   148,   149,   105,    74,   157,   158,
     140,   143,    29,    34,   145,    32,   110,    23
};

static const yytype_uint8 yycheck[] =
{
      45,    46,    31,    69,    33,     1,    17,     6,    38,     0,
      31,    83,    26,     3,    25,    33,     3,    35,     9,    15,
      34,     3,     4,     5,    19,    20,    21,    22,    24,    28,
      26,    30,     3,     4,     5,    80,    81,    82,    34,    68,
      31,    28,    39,    88,   110,    90,    28,    68,   120,    39,
      32,    33,    34,     0,    65,    28,    38,    28,    29,    38,
      39,    32,    33,    34,    75,     3,     4,     5,     3,     4,
       5,    55,    19,    20,    21,    22,    29,    68,     7,     8,
       9,    10,   148,   149,    80,    23,   115,    25,    26,    27,
      28,   157,   158,    28,    32,    33,    34,    32,    33,    34,
      38,    39,    40,    38,     3,   150,    38,   152,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,     3,     4,     5,    15,    16,    28,    18,    28,
      28,     3,     4,     5,    33,    20,    21,    22,    19,    20,
      21,    22,    23,    37,    25,    26,    27,    28,     3,     4,
       5,    32,    33,    34,    28,    40,    28,    38,    39,    40,
      32,    33,    34,    28,    19,    20,    21,    22,    23,    17,
      25,    26,    27,    28,     3,     4,     5,    32,    33,    34,
      20,    21,    22,    38,    39,    40,    20,    21,    22,    96,
      97,    98,    99,    34,    23,    36,    25,    26,    27,    28,
       3,     4,     5,    32,    33,    34,    40,    11,    12,    38,
      39,    40,    29,    38,    31,     3,     4,     5,    38,    29,
      23,    31,    25,    26,    27,    28,    94,    95,    29,    32,
      33,    34,    20,    21,    22,    38,    39,   100,   101,     3,
      28,   103,   104,     3,    32,    33,    34,    19,    20,    21,
      22,    38,    29,    29,    29,    29,    18,    29,    24,    29,
     102,   105,    18,    24,   115,    19,    68,     9
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    20,    21,    22,    55,    56,    57,    58,    73,
      74,    75,    57,    58,     3,    39,     3,    28,    33,    61,
      62,    38,     0,    74,    39,    57,    59,    60,    61,    62,
      38,    39,    66,    28,    59,    61,    40,    60,    29,     3,
       4,     5,    23,    25,    26,    27,    28,    32,    33,    34,
      38,    40,    42,    43,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    65,    66,    67,    68,
      69,    70,    71,    72,    29,    56,    63,    64,    40,    38,
      28,    28,    28,    28,    38,    54,    54,     6,    28,    30,
      37,    45,    33,    35,    34,    36,     7,     8,     9,    10,
      11,    12,    17,    15,    16,    18,    38,    61,    40,    55,
      68,    40,    65,    61,    29,    31,    54,    57,    54,    54,
      69,    38,    29,     3,    29,    44,    54,     3,    54,    45,
      45,    45,    47,    47,    48,    48,    48,    48,    49,    49,
      50,    52,    52,    51,    40,    64,    29,    29,    29,    29,
      69,    29,    31,    65,    65,    54,    54,    24,    29,    65,
      65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    46,    46,    46,    47,
      47,    47,    48,    48,    48,    49,    49,    49,    49,    49,
      50,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      58,    58,    59,    59,    60,    61,    61,    62,    62,    62,
      62,    63,    63,    64,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     3,     4,     3,     3,
       1,     3,     1,     2,     4,     4,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     1,     1,     5,
       4,     2,     1,     2,     3,     2,     1,     1,     3,     4,
       3,     1,     3,     2,     1,     1,     1,     1,     1,     2,
       3,     3,     4,     1,     2,     1,     2,     1,     2,     5,
       7,     5,     7,     2,     3,     1,     2,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 51 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TID, (yyvsp[0].string));}
#line 1380 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TCONS, (yyvsp[0].string));}
#line 1386 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1392 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 57 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1398 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->leaf->value = realloc((yyvsp[-2].node)->leaf->value, strlen((yyvsp[-2].node)->leaf->value) + 3);
                                      strcat((yyvsp[-2].node)->leaf->value, "()");
                                      (yyval.node) = (yyvsp[-2].node);}
#line 1406 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 62 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[-3].node)->leaf->value = realloc((yyvsp[-3].node)->leaf->value, strlen((yyvsp[-3].node)->leaf->value) + 3 + strlen((yyvsp[-1].node)->leaf->value));
                                      strcat((yyvsp[-3].node)->leaf->value, "(");
                                      strcat((yyvsp[-3].node)->leaf->value, (yyvsp[-1].node)->leaf->value);
                                      strcat((yyvsp[-3].node)->leaf->value, ")");
                                      (yyval.node) = (yyvsp[-3].node);}
#line 1416 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 68 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->leaf->value = realloc((yyvsp[-2].node)->leaf->value, strlen((yyvsp[-2].node)->leaf->value) + 2 + strlen((yyvsp[0].string)));
                                      strcat((yyvsp[-2].node)->leaf->value, ".");
                                      strcat((yyvsp[-2].node)->leaf->value, (yyvsp[0].string));
                                      (yyval.node) = (yyvsp[-2].node);}
#line 1425 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 73 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->leaf->value = realloc((yyvsp[-2].node)->leaf->value, strlen((yyvsp[-2].node)->leaf->value) + strlen((yyvsp[-1].string)) + 1 + strlen((yyvsp[0].string)));
                                      strcat((yyvsp[-2].node)->leaf->value, (yyvsp[-1].string));
                                      strcat((yyvsp[-2].node)->leaf->value, (yyvsp[0].string));
                                      (yyval.node) = (yyvsp[-2].node);}
#line 1434 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 81 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1440 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 83 "structfe.y" /* yacc.c:1646  */
    {(yyvsp[-2].node)->leaf->value = realloc((yyvsp[-2].node)->leaf->value, strlen((yyvsp[-2].node)->leaf->value) + 3 + strlen((yyvsp[0].node)->leaf->value));
                                      strcat((yyvsp[-2].node)->leaf->value, ", ");
                                      strcat((yyvsp[-2].node)->leaf->value, (yyvsp[0].node)->leaf->value);
                                      (yyval.node) = (yyvsp[-2].node);}
#line 1449 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 91 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1455 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 93 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_uopr((yyvsp[-1].node),(yyvsp[0].node));}
#line 1461 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 95 "structfe.y" /* yacc.c:1646  */
    {
                                      char* s = malloc(strlen((yyvsp[-3].string)) + 3 + strlen((yyvsp[-1].node)->leaf->value));
                                      strcat(s, (yyvsp[-3].string));
                                      strcat(s, "(");
                                      strcat(s, (yyvsp[-1].node)->leaf->value);
                                      strcat(s, ")");
                                      (yyval.node) = build_leaf(TID,s);
                                      }
#line 1474 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 104 "structfe.y" /* yacc.c:1646  */
    {
                                      char* s = malloc(strlen((yyvsp[-3].string)) + 3 + strlen((yyvsp[-1].node)->leaf->value));
                                      strcat(s, (yyvsp[-3].string));
                                      strcat(s, "(");
                                      strcat(s, (yyvsp[-1].node)->leaf->value);
                                      strcat(s, ")");
                                      (yyval.node) = build_leaf(TID,s);
                                      }
#line 1487 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 115 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = "&";}
#line 1493 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 116 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = "*";}
#line 1499 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 117 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = "-";}
#line 1505 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1511 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 123 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr('*',(yyvsp[-2].node),(yyvsp[0].node));}
#line 1517 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 125 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr('/',(yyvsp[-2].node),(yyvsp[0].node));}
#line 1523 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 129 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1529 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr('+',(yyvsp[-2].node),(yyvsp[0].node));}
#line 1535 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 133 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr('-',(yyvsp[-2].node),(yyvsp[0].node));}
#line 1541 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 137 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1547 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 139 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1553 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 141 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1559 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1565 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 145 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1571 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 149 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1577 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 151 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1583 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 153 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1589 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1595 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 159 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1601 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 163 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1607 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 165 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1613 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 170 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1619 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 172 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1625 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 176 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1631 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 178 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr('=',(yyvsp[-2].node),(yyvsp[0].node));}
#line 1637 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 179 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1643 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 184 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_uopr(';',(yyvsp[-1].node));}
#line 1649 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 189 "structfe.y" /* yacc.c:1646  */
    {printf("%s %p",(yyvsp[0].node),(yyvsp[0].node));
                                      }
#line 1656 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 216 "structfe.y" /* yacc.c:1646  */
    {char* s = malloc(strlen("*") + strlen((yyvsp[0].node)) + 1);
                                            strcat(s, "*");
                                            strcat(s, (yyvsp[0].node));
                                            (yyval.node) = s;}
#line 1665 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 220 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1671 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 231 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1677 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 240 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1683 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 241 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1689 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 242 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1695 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 243 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1701 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 244 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1707 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 255 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1713 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 260 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1719 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 266 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
                          stringify((yyval.node),0);}
#line 1726 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 286 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1732 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 291 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1738 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 292 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1744 "structfe.tab.c" /* yacc.c:1646  */
    break;


#line 1748 "structfe.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 299 "structfe.y" /* yacc.c:1906  */


extern FILE *yyin;

void
yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
	exit(2);
}

int
main (int argc, char *argv[])
{
	if ((yyin = fopen(argv[1], "r")) == NULL)
	{
		yyerror("[E] File not found\n");
		exit(2);
	} else {
		yyparse();
		printf("Success.\n");
	}
	return 0;
}
