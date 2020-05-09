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
	#include "tree.h"

	int verbose2 = 0;
	int line_count = 1;
	int column_count = 1;
	char line_buffer[1000];
	int buffer_count = 0;

	void log2 (char *msg)
	{
	    if (verbose2)
	        printf("[***] %s\n", msg);
	}

	extern char yytext[];
	int printed = 0;
	void yyerror(char const *s);
	int yylex();

#line 89 "structfe.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    L_OP = 267,
    G_OP = 268,
    AND_OP = 269,
    OR_OP = 270,
    MUL_ASSIGN = 271,
    DIV_ASSIGN = 272,
    ADD_ASSIGN = 273,
    SUB_ASSIGN = 274,
    TYPE_NAME = 275,
    EXTERN = 276,
    INT = 277,
    VOID = 278,
    STRUCT = 279,
    IF = 280,
    ELSE = 281,
    WHILE = 282,
    FOR = 283,
    RETURN = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "structfe.y" /* yacc.c:355  */

	  node_t *	node;
	  char *		string;

#line 164 "structfe.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_STRUCTFE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 181 "structfe.tab.c" /* yacc.c:358  */

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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   443

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,     2,
      30,    31,    36,    34,    32,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    72,    76,    80,    86,    89,    93,    97,
     104,   108,   114,   118,   122,   127,   134,   138,   142,   146,
     152,   156,   162,   166,   170,   176,   180,   184,   190,   194,
     198,   202,   206,   212,   216,   220,   226,   230,   236,   240,
     246,   254,   260,   266,   267,   268,   269,   270,   274,   278,
     284,   288,   294,   297,   303,   305,   310,   313,   318,   321,
     324,   330,   333,   335,   341,   343,   348,   353,   355,   360,
     362,   367,   372,   376,   385,   390,   395,   399,   401,   403,
     405,   410,   414,   419,   421,   425,   427,   429,   440,   445,
     448,   455,   459,   463,   468,   470,   476,   478,   483,   485,
     490,   492,   496,   497,   498,   499,   500,   504,   505,   506,
     507,   508,   512,   516,   520,   524,   528,   532,   539,   540,
     542,   546,   549,   556,   559,   564,   565,   570,   574,   580,
     586,   593,   599,   604,   610,   614,   620,   624,   629,   636,
     640,   647
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "L_OP", "G_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "TYPE_NAME", "EXTERN", "INT", "VOID",
  "STRUCT", "IF", "ELSE", "WHILE", "FOR", "RETURN", "'('", "')'", "','",
  "'&'", "'+'", "'-'", "'*'", "'/'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression",
  "relational_expression", "equality_expression", "logical_and_expression",
  "logical_or_expression", "assignment_expression", "if_expression",
  "assignment_operator", "expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "struct_or_union_specifier", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "declarator",
  "pointer_direct_declarator", "direct_declarator",
  "direct_declarator_pointer", "pointer", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "abstract_declarator_with_pointer",
  "direct_abstract_declarator", "direct_abstract_declarator_pointer_free",
  "initializer", "statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "program", "_start",
  "external_declaration", "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      40,    41,    44,    38,    43,    45,    42,    47,    61,    59,
     123,   125
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     258,   211,  -127,  -127,    15,  -127,    35,  -127,  -127,   258,
      19,  -127,  -127,  -127,    33,   211,  -127,    14,  -127,  -127,
      -7,  -127,   234,  -127,    58,    37,  -127,  -127,   211,   211,
      71,  -127,    14,    65,    14,  -127,   365,  -127,   187,  -127,
     215,  -127,    14,    76,   141,  -127,  -127,  -127,    68,  -127,
    -127,  -127,  -127,    72,  -127,  -127,  -127,    96,   309,  -127,
    -127,  -127,  -127,     0,   158,   365,  -127,    40,   -19,   193,
     126,   117,   139,  -127,  -127,  -127,   136,   156,   159,   164,
    -127,  -127,  -127,   100,  -127,    35,  -127,  -127,   226,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,    36,   127,  -127,   140,
     147,   173,   221,  -127,    14,  -127,   324,   149,    78,   182,
     192,   287,  -127,  -127,  -127,  -127,  -127,   365,  -127,  -127,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   265,  -127,   101,   365,  -127,  -127,
    -127,    94,  -127,    53,  -127,  -127,   189,  -127,   258,  -127,
     222,  -127,   255,  -127,   152,   209,  -127,   365,   263,   285,
    -127,   381,   273,  -127,   365,  -127,  -127,   232,  -127,  -127,
    -127,  -127,    40,    40,   -19,   -19,   -19,   -19,   193,   193,
     126,   117,   139,   288,   252,  -127,   272,   272,  -127,  -127,
    -127,   278,   295,    98,   308,   397,  -127,  -127,   401,  -127,
    -127,  -127,  -127,   385,  -127,  -127,   365,    18,    18,   331,
     346,  -127,  -127,    98,  -127,   293,   227,   412,  -127,   361,
    -127,   382,  -127,   327,  -127,    18,   395,    18,   398,  -127,
    -127,  -127,   406,  -127,  -127,    18,  -127,    18,  -127,    18,
    -127,  -127,  -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    59,    58,     0,   140,     0,    53,    60,   138,
       0,   136,   139,    52,    63,     0,    76,     0,    88,    51,
       0,    54,    56,    72,    73,    75,   137,     1,     0,    68,
       0,    64,     0,     0,     0,    50,     0,   120,     0,   141,
       0,    81,     0,    74,     0,    67,    62,    65,     0,    69,
      71,    77,    55,    56,     2,     3,     4,     0,     0,    16,
      18,    19,     6,    12,    20,     0,    22,    25,    28,    33,
      36,    38,    40,   112,    17,    57,     0,     0,     0,     0,
     120,   118,    48,     0,   123,     0,   124,   113,     0,   121,
     114,   115,   116,   117,    94,    80,    93,     0,    89,     0,
       0,     0,     0,    61,     0,    66,     0,     0,    96,     0,
       0,     0,    44,    45,    46,    47,    43,     0,    20,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,     0,   126,   119,
     122,     0,    91,    75,    92,    98,    99,    78,     0,    79,
       0,    82,     0,    87,     0,     0,    70,     0,     0,     0,
       5,     0,   100,    97,     0,     9,     7,     0,    10,    41,
      23,    24,    26,    27,    31,    32,    29,    30,    34,    35,
      37,    39,    42,     0,     0,   125,     0,     0,   134,    49,
     103,     0,     0,     0,   101,     0,    90,    95,     0,    85,
      86,    14,    15,     0,    21,     8,     0,     0,     0,     0,
       0,   104,   102,     0,   108,     0,     0,     0,   105,     0,
      84,     0,    11,   127,   129,     0,     0,     0,     0,   109,
     107,   110,     0,   106,    83,     0,   132,     0,   130,     0,
     111,   128,   133,   131
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,    21,  -127,   -51,   174,   264,   212,
     233,   241,   242,   -33,  -127,  -127,   -48,   -29,     4,  -127,
     344,     5,  -127,   356,    38,   -17,  -127,   282,    -5,   -37,
    -127,  -127,    -6,   -38,   246,   294,   291,   -21,  -127,  -127,
     -81,  -127,   148,   388,  -127,   343,  -126,  -127,  -127,  -127,
    -127,  -127,   430,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    62,    63,   167,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    82,   183,   117,    83,     5,    96,    20,
      21,     7,     8,    30,    31,    32,    48,    49,    33,    23,
      24,    43,    74,   215,    98,    99,   109,   192,   145,   146,
     216,    75,    86,    87,    88,    89,    90,    91,    92,    93,
       9,    10,    11,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    22,    97,    73,     6,   101,    13,   110,   187,    84,
     107,    25,    45,     6,   119,   122,   123,    16,    14,    27,
      29,    54,    55,    56,    57,    34,    25,    50,    25,    53,
     111,   136,    35,    29,    29,    29,    25,   100,    16,    16,
      41,   108,    85,    76,    17,    77,    78,    79,    58,    29,
      18,    59,    60,    61,    18,    15,    41,    80,    38,    84,
     209,   210,   194,    29,   154,    17,   141,    42,    47,   170,
     171,    18,    18,    28,    19,   144,   120,   121,   168,    25,
      53,   194,    47,   193,   169,   184,   118,   163,    40,   108,
     143,   142,    85,     2,     3,     4,    51,    16,    25,    50,
     104,    16,   162,   191,   189,   186,   102,   105,   161,   107,
      36,    29,    46,   204,    18,     1,     2,     3,     4,     1,
       2,     3,     4,   191,   141,   190,   106,   158,   213,   214,
      18,   130,   137,   137,    18,   143,   128,   129,    85,   138,
     188,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   131,   162,   101,   219,   147,   148,
     221,   226,   228,     2,     3,     4,   132,    54,    55,    56,
      57,   149,   150,   222,   112,   113,   114,   115,   151,   232,
     160,   137,   103,   199,   148,   118,   133,    25,   100,   134,
      54,    55,    56,    57,    58,   165,   116,    59,    60,    61,
      18,   124,   125,   135,   152,   126,   127,    25,     1,     2,
       3,     4,    76,   164,    77,    78,    79,    58,    94,   195,
      59,    60,    61,    18,    94,   197,    80,    38,    81,    54,
      55,    56,    57,     2,     3,     4,     1,     2,     3,     4,
     200,   150,     1,     2,     3,     4,    95,     1,     2,     3,
       4,    76,   153,    77,    78,    79,    58,   217,   230,    59,
      60,    61,    18,   205,   206,    80,    38,   139,    54,    55,
      56,    57,    36,    37,    38,    54,    55,    56,    57,     1,
       2,     3,     4,   208,   137,   198,     1,     2,     3,     4,
      54,    55,    56,    57,   201,    58,   172,   173,    59,    60,
      61,    18,    58,   203,   185,    59,    60,    61,    18,   211,
     148,   185,    54,    55,    56,    57,   202,    58,   166,   207,
      59,    60,    61,    18,   229,   148,   212,    54,    55,    56,
      57,     2,     3,     4,    54,    55,    56,    57,   217,    58,
     178,   179,    59,    60,    61,    18,     2,     3,     4,    54,
      55,    56,    57,   235,   157,   223,   224,    59,    60,    61,
      18,    58,   225,   180,    59,    60,    61,    18,    54,    55,
      56,    57,   181,   236,   182,   238,    58,   227,    52,    59,
      60,    61,    18,   241,    44,   242,   156,   243,   174,   175,
     176,   177,   233,   148,   196,    58,   155,   159,    59,    60,
      61,    18,     1,     2,     3,     4,     1,     2,     3,     4,
      39,   161,   190,   234,   148,   203,   214,    18,     1,     2,
       3,     4,     1,     2,     3,     4,   237,   137,   218,   239,
     137,   140,   220,     1,     2,     3,     4,   240,   148,    26,
       0,     0,     0,   231
};

static const yytype_int16 yycheck[] =
{
       6,     6,    40,    36,     0,    42,     1,     7,   134,    38,
      58,    17,    29,     9,    65,    34,    35,     3,     3,     0,
      15,     3,     4,     5,     6,    32,    32,    32,    34,    34,
      30,    79,    39,    28,    29,    30,    42,    42,     3,     3,
       3,    58,    38,    25,    30,    27,    28,    29,    30,    44,
      36,    33,    34,    35,    36,    40,     3,    39,    40,    88,
     186,   187,   143,    58,   102,    30,    30,    30,    30,   120,
     121,    36,    36,    40,    39,    96,    36,    37,   111,    85,
      85,   162,    44,    30,   117,   133,    65,   108,    30,   106,
      96,    96,    88,    22,    23,    24,    31,     3,   104,   104,
      32,     3,   108,   141,   137,   134,    30,    39,    30,   157,
      38,   106,    41,   164,    36,    21,    22,    23,    24,    21,
      22,    23,    24,   161,    30,    31,    30,   106,    30,    31,
      36,    14,    32,    32,    36,   141,    10,    11,   134,    39,
      39,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,    15,   161,   193,   195,    31,    32,
     198,   209,   210,    22,    23,    24,    30,     3,     4,     5,
       6,    31,    32,   206,    16,    17,    18,    19,    31,   217,
      31,    32,    41,    31,    32,   164,    30,   193,   193,    30,
       3,     4,     5,     6,    30,     3,    38,    33,    34,    35,
      36,     8,     9,    39,    31,    12,    13,   213,    21,    22,
      23,    24,    25,    31,    27,    28,    29,    30,     3,    30,
      33,    34,    35,    36,     3,     3,    39,    40,    41,     3,
       4,     5,     6,    22,    23,    24,    21,    22,    23,    24,
      31,    32,    21,    22,    23,    24,    31,    21,    22,    23,
      24,    25,    31,    27,    28,    29,    30,    30,    31,    33,
      34,    35,    36,    31,    32,    39,    40,    41,     3,     4,
       5,     6,    38,    39,    40,     3,     4,     5,     6,    21,
      22,    23,    24,    31,    32,    30,    21,    22,    23,    24,
       3,     4,     5,     6,    31,    30,   122,   123,    33,    34,
      35,    36,    30,    30,    39,    33,    34,    35,    36,    31,
      32,    39,     3,     4,     5,     6,    31,    30,    31,    31,
      33,    34,    35,    36,    31,    32,    31,     3,     4,     5,
       6,    22,    23,    24,     3,     4,     5,     6,    30,    30,
     128,   129,    33,    34,    35,    36,    22,    23,    24,     3,
       4,     5,     6,    26,    30,   207,   208,    33,    34,    35,
      36,    30,    31,   130,    33,    34,    35,    36,     3,     4,
       5,     6,   131,   225,   132,   227,    30,    31,    34,    33,
      34,    35,    36,   235,    28,   237,   104,   239,   124,   125,
     126,   127,    31,    32,   148,    30,   102,   106,    33,    34,
      35,    36,    21,    22,    23,    24,    21,    22,    23,    24,
      22,    30,    31,    31,    32,    30,    31,    36,    21,    22,
      23,    24,    21,    22,    23,    24,    31,    32,    31,    31,
      32,    88,    31,    21,    22,    23,    24,    31,    32,     9,
      -1,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    23,    24,    59,    60,    63,    64,    92,
      93,    94,    95,    63,     3,    40,     3,    30,    36,    39,
      61,    62,    70,    71,    72,    74,    94,     0,    40,    63,
      65,    66,    67,    70,    32,    39,    38,    39,    40,    85,
      30,     3,    30,    73,    65,    67,    41,    66,    68,    69,
      70,    31,    62,    70,     3,     4,     5,     6,    30,    33,
      34,    35,    43,    44,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    74,    83,    25,    27,    28,    29,
      39,    41,    55,    58,    59,    60,    84,    85,    86,    87,
      88,    89,    90,    91,     3,    31,    60,    75,    76,    77,
      70,    71,    30,    41,    32,    39,    30,    58,    67,    78,
       7,    30,    16,    17,    18,    19,    38,    57,    46,    48,
      36,    37,    34,    35,     8,     9,    12,    13,    10,    11,
      14,    15,    30,    30,    30,    39,    58,    32,    39,    41,
      87,    30,    70,    74,    79,    80,    81,    31,    32,    31,
      32,    31,    31,    31,    75,    77,    69,    30,    46,    78,
      31,    30,    74,    79,    31,     3,    31,    45,    55,    55,
      48,    48,    49,    49,    50,    50,    50,    50,    51,    51,
      52,    53,    54,    56,    58,    39,    59,    88,    39,    55,
      31,    75,    79,    30,    82,    30,    76,     3,    30,    31,
      31,    31,    31,    30,    48,    31,    32,    31,    31,    88,
      88,    31,    31,    30,    31,    75,    82,    30,    31,    75,
      31,    75,    55,    84,    84,    31,    58,    31,    58,    31,
      31,    31,    75,    31,    31,    26,    84,    31,    84,    31,
      31,    84,    84,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    44,    44,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    47,    47,
      48,    48,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    64,    65,    65,    66,    67,    67,    68,
      68,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    74,    75,
      75,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    83,    84,    84,    84,    84,    84,    85,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    90,    90,    91,    91,    92,    92,    93,    94,
      94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     3,     4,     3,
       1,     3,     1,     2,     4,     4,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     2,     1,     1,     3,     1,     3,     1,     1,
       1,     5,     4,     2,     1,     2,     3,     2,     1,     1,
       3,     1,     1,     1,     2,     1,     1,     3,     4,     4,
       3,     1,     3,     6,     5,     4,     4,     3,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       1,     2,     3,     2,     3,     3,     4,     3,     2,     3,
       3,     4,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     2,     1,     1,     1,     2,     5,     7,     5,
       6,     7,     6,     7,     3,     2,     1,     2,     1,     1,
       1,     3
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
#line 69 "structfe.y" /* yacc.c:1646  */
    {log2("primary_expression -> IDENTIFIER");
    (yyval.node) = build_leaf(TID, (yyvsp[0].string));}
#line 1489 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "structfe.y" /* yacc.c:1646  */
    {log2("primary_expression -> CONSTANT");
    (yyval.node) = build_leaf(TCONS, (yyvsp[0].string));}
#line 1496 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "structfe.y" /* yacc.c:1646  */
    {log2("primary_expression -> STRING_LITERAL");
    (yyval.node) = build_leaf(TCONS, (yyvsp[0].string));}
#line 1503 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "structfe.y" /* yacc.c:1646  */
    {log2("primary_expression -> ( expression )");
    (yyval.node) = (yyvsp[-1].node);}
#line 1510 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1516 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "structfe.y" /* yacc.c:1646  */
    {log2("postfix_expression -> postfix_expression ( )");
    (yyval.node) = build_func((yyvsp[-2].node),NULL);}
#line 1523 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "structfe.y" /* yacc.c:1646  */
    {log2("postfix_expression -> postfix_expression ( argument_expression_list )");
		(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1530 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "structfe.y" /* yacc.c:1646  */
    {log2("postfix_expression -> postfix_expression PTR_OP IDENTIFIER");
		node_t *leaf = build_leaf(TID,(yyvsp[0].string));
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),leaf);}
#line 1538 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 105 "structfe.y" /* yacc.c:1646  */
    {log2("argument_expression_list -> expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1545 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 109 "structfe.y" /* yacc.c:1646  */
    {log2("argument_expression_list -> argument_expression_list , expression");
    (yyval.node) = build_opr("argument_expression_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1552 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 115 "structfe.y" /* yacc.c:1646  */
    {log2("unary_expression -> postfix_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1559 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "structfe.y" /* yacc.c:1646  */
    {log2("unary_expression -> unary_operator unary_expression");
    (yyval.node) = build_uopr((yyvsp[-1].string),(yyvsp[0].node));}
#line 1566 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 123 "structfe.y" /* yacc.c:1646  */
    {log2("unary_expression -> SIZEOF ( unary_expression)");
    (yyval.node) = build_uopr((yyvsp[-3].string),(yyvsp[-1].node));
    }
#line 1574 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "structfe.y" /* yacc.c:1646  */
    {log2("unary_expression -> SIZEOF ( type_name )");
    (yyval.node) = build_uopr((yyvsp[-3].string),(yyvsp[-1].string));
    }
#line 1582 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 135 "structfe.y" /* yacc.c:1646  */
    {log2("unary_operator -> &");
    (yyval.string) = "&";}
#line 1589 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 139 "structfe.y" /* yacc.c:1646  */
    {log2("unary_operator -> pointer");
    (yyval.string) = (yyvsp[0].string);}
#line 1596 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "structfe.y" /* yacc.c:1646  */
    {log2("unary_operator -> +");
    (yyval.string) = "+";}
#line 1603 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 147 "structfe.y" /* yacc.c:1646  */
    {log2("unary_operator -> -");
    (yyval.string) = "-";}
#line 1610 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "structfe.y" /* yacc.c:1646  */
    {log2("cast_expression -> unary_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1617 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 157 "structfe.y" /* yacc.c:1646  */
    {log2("cast_expression -> '(' type_name ')' cast_expression");
    (yyval.node) = build_opr("cast",(yyvsp[-2].string),(yyvsp[0].node));}
#line 1624 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 163 "structfe.y" /* yacc.c:1646  */
    {log2("multiplicative_expression -> cast_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1631 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 167 "structfe.y" /* yacc.c:1646  */
    {log2("multiplicative_expression -> multiplicative_expression * cast_expression");
    (yyval.node) = build_opr("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1638 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "structfe.y" /* yacc.c:1646  */
    {log2("multiplicative_expression -> multiplicative_expression / cast_expression");
    (yyval.node) = build_opr("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1645 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 177 "structfe.y" /* yacc.c:1646  */
    {log2("additive_expression -> multiplicative_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1652 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 181 "structfe.y" /* yacc.c:1646  */
    {log2("additive_expression -> additive_expression + multiplicative_expression");
    (yyval.node) = build_opr("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1659 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 185 "structfe.y" /* yacc.c:1646  */
    {log2("additive_expression -> additive_expression - multiplicative_expression");
    (yyval.node) = build_opr("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1666 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "structfe.y" /* yacc.c:1646  */
    {log2("relational_expression -> additive_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1673 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 195 "structfe.y" /* yacc.c:1646  */
    {log2("relational_expression -> relational_expression L_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1680 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 199 "structfe.y" /* yacc.c:1646  */
    {log2("relational_expression -> relational_expression G_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1687 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 203 "structfe.y" /* yacc.c:1646  */
    {log2("relational_expression -> relational_expression LE_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1694 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 207 "structfe.y" /* yacc.c:1646  */
    {log2("relational_expression -> relational_expression GE_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1701 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 213 "structfe.y" /* yacc.c:1646  */
    {log2("equality_expression -> relational_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1708 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 217 "structfe.y" /* yacc.c:1646  */
    {log2("equality_expression -> equality_expression EQ_OP relational_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1715 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "structfe.y" /* yacc.c:1646  */
    {log2("equality_expression -> equality_expression NE_OP relational_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1722 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 227 "structfe.y" /* yacc.c:1646  */
    {log2("logical_and_expression -> equality_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1729 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 231 "structfe.y" /* yacc.c:1646  */
    {log2("logical_and_expression -> logical_and_expression AND_OP equality_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1736 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 237 "structfe.y" /* yacc.c:1646  */
    {log2("logical_or_expression -> logical_and_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1743 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 241 "structfe.y" /* yacc.c:1646  */
    {log2("logical_or_expression -> logical_or_expression OR_OP logical_and_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1750 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 247 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_expression -> logical_or_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1757 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 255 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_expression -> unary_expression assignment_operator assignment_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1764 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "structfe.y" /* yacc.c:1646  */
    {log2("if_expression -> logical_or_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1771 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 266 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_operator -> ="); (yyval.string) = "=";}
#line 1777 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_operator -> MUL_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1783 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 268 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_operator -> DIV_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1789 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_operator -> ADD_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1795 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 270 "structfe.y" /* yacc.c:1646  */
    {log2("assignment_operator -> SUB_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1801 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 275 "structfe.y" /* yacc.c:1646  */
    {log2("expression -> assignment_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1808 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 279 "structfe.y" /* yacc.c:1646  */
    {log2("expression -> assignment_expression = expression");
    (yyval.node) = build_opr("expr",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1815 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 285 "structfe.y" /* yacc.c:1646  */
    {log2("declaration -> declaration_specifiers init_declarator_list ';'");
    (yyval.node) = build_opr("declaration",(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1822 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 289 "structfe.y" /* yacc.c:1646  */
    {log2("declaration -> declaration_specifiers ';'");
    (yyval.node) = build_opr("declaration",(yyvsp[-1].node),NULL);}
#line 1829 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 295 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_uopr("extern",(yyvsp[0].node));}
#line 1835 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 298 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1841 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 304 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1847 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 306 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("init_declarator_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1853 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 311 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1859 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 314 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1865 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 319 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TT,(yyvsp[0].string));}
#line 1871 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 322 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TT,(yyvsp[0].string));}
#line 1877 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 325 "structfe.y" /* yacc.c:1646  */
    {log2("type_specifier -> struct_or_union_specifier");
		(yyval.node) = (yyvsp[0].node);}
#line 1884 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 331 "structfe.y" /* yacc.c:1646  */
    {node_t *leaf = build_leaf(TID,(yyvsp[-3].string));
		(yyval.node) = build_struct(leaf,(yyvsp[-1].node));}
#line 1891 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 334 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_struct(NULL,(yyvsp[-1].node));}
#line 1897 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 336 "structfe.y" /* yacc.c:1646  */
    {node_t *leaf = build_leaf(TID,(yyvsp[0].string));
		(yyval.node) = build_struct(leaf,NULL);}
#line 1904 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 342 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1910 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 344 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("struct_declaration_list",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1916 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 349 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("struct_declaration",(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1922 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 354 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("specifier_qualifier_list",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1928 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 356 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1934 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 361 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1940 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 363 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("struct_declarator_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1946 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 368 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1952 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 373 "structfe.y" /* yacc.c:1646  */
    {log2("declarator -> pointer_direct_declarator direct_declarator");
    (yyval.node) = (yyvsp[0].node);}
#line 1959 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 377 "structfe.y" /* yacc.c:1646  */
    {log2("declarator -> direct_declarator");
    (yyval.node) = (yyvsp[0].node);}
#line 1966 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 386 "structfe.y" /* yacc.c:1646  */
    {log2("pointer_direct_declarator -> pointer direct_declarator_pointer");
    (yyval.node) = build_opr("pointer_direct_declarator", (yyvsp[-1].string),(yyvsp[0].node));}
#line 1973 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 391 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].string);}
#line 1979 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 396 "structfe.y" /* yacc.c:1646  */
    {log2("direct_declarator -> IDENTIFIER");
		log2((yyvsp[0].string));
		(yyval.node) = build_leaf(TID,(yyvsp[0].string));}
#line 1987 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 400 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1993 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 402 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1999 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 404 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2005 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 406 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-2].node),NULL);}
#line 2011 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 411 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TID, (yyvsp[0].string));}
#line 2017 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 415 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2023 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 420 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-4].node),(yyvsp[-1].node));}
#line 2029 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 422 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-3].node),NULL);}
#line 2035 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 426 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2041 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 428 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2047 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 430 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_func((yyvsp[-2].node),NULL);}
#line 2053 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 441 "structfe.y" /* yacc.c:1646  */
    {(yyval.string) = build_leaf(TID,"*");}
#line 2059 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 446 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2065 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 449 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("parameter_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2071 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 456 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("parameter_declaration",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2077 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 460 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("parameter_declaration",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2083 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 464 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2089 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 469 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TID,(yyvsp[0].string));}
#line 2095 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 471 "structfe.y" /* yacc.c:1646  */
    {node_t *leaf = build_leaf(TID,(yyvsp[0].string));
		(yyval.node) = build_opr("identifier_list",(yyvsp[-2].node),leaf);}
#line 2102 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 477 "structfe.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].node);}
#line 2108 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 479 "structfe.y" /* yacc.c:1646  */
    {(yyval.string) = build_opr("type_name",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2114 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 484 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2120 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 486 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2126 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 491 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].string);}
#line 2132 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 493 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("abstract_declarator_with_pointer",(yyvsp[-1].string),(yyvsp[0].node));}
#line 2138 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 512 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2144 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 517 "structfe.y" /* yacc.c:1646  */
    {log2("statement -> compound_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2151 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 521 "structfe.y" /* yacc.c:1646  */
    {log2("statement -> expression_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2158 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 525 "structfe.y" /* yacc.c:1646  */
    {log2("statement -> selection_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2165 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 529 "structfe.y" /* yacc.c:1646  */
    {log2("statement -> iteration_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2172 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 533 "structfe.y" /* yacc.c:1646  */
    {log2("statement -> jump_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2179 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 539 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TID,"{}");}
#line 2185 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 541 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2191 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 542 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TID,";");}
#line 2197 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 547 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2203 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 550 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("block_item_list",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2209 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 557 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2215 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 560 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2221 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 564 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_leaf(TID,";");}
#line 2227 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 566 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2233 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 571 "structfe.y" /* yacc.c:1646  */
    {log2("selection_statement -> IF ( expression ) statement");
    (yyval.node) = build_if((yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 2240 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 575 "structfe.y" /* yacc.c:1646  */
    {log2("selection_statement -> IF ( expression ) statement ELSE statement");
    (yyval.node) = build_if((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2247 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 581 "structfe.y" /* yacc.c:1646  */
    {log2("iteration_statement -> WHILE '(' expression ')' statement ");
    (yyval.node) = build_opr((yyvsp[-4].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2254 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 587 "structfe.y" /* yacc.c:1646  */
    {log2("iteration_statement -> FOR '(' expression_statement expression_statement ')' statement ");
    (yyval.node) = build_for((yyvsp[-3].node),(yyvsp[-2].node), NULL,(yyvsp[0].node));}
#line 2261 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 594 "structfe.y" /* yacc.c:1646  */
    {log2("iteration_statement -> FOR '(' expression_statement expression_statement expression ')' statement ");
    (yyval.node) = build_for((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2268 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 600 "structfe.y" /* yacc.c:1646  */
    {log2("iteration_statement -> FOR '(' declaration expression_statement ')' statement ");
    (yyval.node) = build_for((yyvsp[-3].node),(yyvsp[-2].node), NULL,(yyvsp[0].node));}
#line 2275 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 605 "structfe.y" /* yacc.c:1646  */
    {log2("iteration_statement -> FOR '(' declaration expression_statement expression ')' statement ");
    (yyval.node) = build_for((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2282 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 611 "structfe.y" /* yacc.c:1646  */
    {log2("jump_statement -> RETURN expression ;");
    (yyval.node) = build_uopr("return",(yyvsp[-1].node));}
#line 2289 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 615 "structfe.y" /* yacc.c:1646  */
    {log2("jump_statement -> RETURN ;");
    (yyval.node) = build_leaf(TRET,(yyvsp[-1].string));}
#line 2296 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 621 "structfe.y" /* yacc.c:1646  */
    {log2("program -> external_declaration");
		(yyval.node) = (yyvsp[0].node);}
#line 2303 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 625 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("program",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2309 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 630 "structfe.y" /* yacc.c:1646  */
    {stringify((yyvsp[0].node),0);}
#line 2315 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 637 "structfe.y" /* yacc.c:1646  */
    {log2("external_declaration -> function_definition");
    (yyval.node) = (yyvsp[0].node);}
#line 2322 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 641 "structfe.y" /* yacc.c:1646  */
    {log2("external_declaration -> declaration");
    (yyval.node) = (yyvsp[0].node);}
#line 2329 "structfe.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 648 "structfe.y" /* yacc.c:1646  */
    {(yyval.node) = build_opr("function_definition",build_opr("function",(yyvsp[-2].node),(yyvsp[-1].node)),(yyvsp[0].node));}
#line 2335 "structfe.tab.c" /* yacc.c:1646  */
    break;


#line 2339 "structfe.tab.c" /* yacc.c:1646  */
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
#line 660 "structfe.y" /* yacc.c:1906  */


extern FILE *yyin;

char *fname;

void
yyerror (char const *s)
{
	FILE* fd = fopen(fname,"r");
	char *code_line;
	get_nth_line(fd,line_count - 1,&code_line);
	printf("line %d: %s\n%*s\n%*s\n",line_count,code_line, column_count, "^", column_count, s);
	exit(2);
}

int
main (int argc, char *argv[])
{
	fname = strdup(argv[1]);
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
