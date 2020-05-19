/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "structfe.y" /* yacc.c:337  */

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

#line 93 "structfe.tab.c" /* yacc.c:337  */
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
#line 25 "structfe.y" /* yacc.c:352  */

	  node_t *	node;
	  char *		string;

#line 171 "structfe.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_STRUCTFE_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  245

#define YYUNDEFTOK  2
#define YYMAXUTOK   284

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,     2,
      30,    31,    35,    37,    32,    34,     2,    36,     2,     2,
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
       0,    69,    69,    73,    77,    81,    87,    90,    94,    98,
     105,   109,   115,   119,   123,   128,   135,   139,   143,   149,
     153,   159,   163,   167,   173,   177,   181,   187,   191,   195,
     199,   203,   209,   213,   217,   223,   227,   233,   237,   243,
     251,   257,   263,   264,   265,   266,   267,   271,   275,   281,
     285,   291,   294,   300,   302,   307,   310,   315,   318,   321,
     327,   330,   332,   338,   340,   345,   350,   352,   357,   359,
     364,   369,   373,   382,   387,   392,   396,   398,   403,   405,
     407,   412,   416,   421,   423,   427,   433,   435,   437,   449,
     455,   458,   465,   469,   473,   478,   480,   486,   488,   493,
     495,   500,   502,   506,   507,   508,   509,   510,   514,   515,
     516,   517,   518,   522,   526,   530,   534,   538,   542,   549,
     550,   552,   556,   559,   566,   569,   574,   575,   580,   584,
     590,   596,   603,   609,   614,   620,   624,   630,   634,   639,
     648,   652,   659
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
  "'&'", "'-'", "'*'", "'/'", "'+'", "'='", "';'", "'{'", "'}'", "$accept",
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
  "pointer_direct_declarator", "direct_declarator", "function_declarator",
  "direct_declarator_pointer", "function_declarator_pointer", "pointer",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "abstract_declarator_with_pointer",
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
      40,    41,    44,    38,    45,    42,    47,    43,    61,    59,
     123,   125
};
# endif

#define YYPACT_NINF -128

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-128)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     354,   145,  -128,  -128,     7,  -128,    46,  -128,  -128,   354,
      19,  -128,  -128,  -128,    -3,   145,  -128,    32,  -128,  -128,
      59,  -128,   -13,  -128,    20,    66,    26,  -128,  -128,   145,
     145,    56,  -128,    32,    23,  -128,    32,  -128,   364,    98,
    -128,   178,  -128,  -128,    32,    29,  -128,    71,  -128,  -128,
    -128,    70,  -128,  -128,  -128,  -128,  -128,  -128,  -128,    40,
     308,  -128,  -128,  -128,     1,   126,   364,  -128,   113,    89,
     183,   165,    58,    69,  -128,  -128,  -128,  -128,  -128,    52,
     147,  -128,   166,    44,    80,    85,    18,  -128,  -128,  -128,
      75,  -128,    46,  -128,  -128,   217,  -128,  -128,  -128,  -128,
    -128,    57,    93,   206,  -128,    32,  -128,   331,   184,     4,
      97,   150,   155,  -128,  -128,  -128,  -128,  -128,   364,  -128,
    -128,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   379,  -128,    30,  -128,  -128,   125,  -128,
     354,  -128,   154,   364,   364,   294,  -128,   115,   364,  -128,
    -128,  -128,  -128,   133,  -128,   193,   200,  -128,   364,   140,
     142,  -128,   350,   157,  -128,   364,  -128,  -128,   222,  -128,
    -128,  -128,  -128,   113,   113,    89,    89,    89,    89,   183,
     183,   165,    58,  -128,   248,   162,   401,   180,   212,  -128,
    -128,    69,   195,   261,  -128,   271,   271,  -128,  -128,   247,
    -128,  -128,  -128,  -128,   242,  -128,  -128,   364,  -128,  -128,
     401,  -128,   276,   218,   395,  -128,   313,   256,   256,   316,
     353,  -128,   358,  -128,  -128,  -128,  -128,   389,  -128,   188,
    -128,   256,   402,   256,   406,  -128,  -128,   256,  -128,   256,
    -128,   256,  -128,  -128,  -128
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    58,    57,     0,   141,     0,    52,    59,   139,
       0,   137,   140,    51,    62,     0,    75,     0,    89,    50,
       0,    53,    55,    71,    72,    77,    74,   138,     1,     0,
      67,     0,    63,     0,     0,    77,     0,    49,     0,     0,
     121,     0,   142,    81,     0,    73,    85,     0,    66,    61,
      64,     0,    68,    70,    76,    54,     2,     3,     4,     0,
       0,    16,    18,     6,    12,    19,     0,    21,    24,    27,
      32,    35,    37,    39,   113,    17,    56,    95,    80,    94,
       0,    90,     0,     0,     0,     0,     0,   121,   119,    47,
       0,   124,     0,   125,   114,     0,   122,   115,   116,   117,
     118,     0,     0,     0,    60,     0,    65,     0,     0,    97,
       0,     0,     0,    43,    44,    45,    46,    42,     0,    19,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,    74,    93,    99,   100,    78,
       0,    79,     0,     0,     0,     0,   136,     0,     0,   127,
     120,   123,    82,     0,    88,     0,     0,    69,     0,     0,
       0,     5,     0,   101,    98,     0,     9,     7,     0,    10,
      40,    22,    23,    26,    25,    30,    31,    28,    29,    33,
      34,    36,    38,   104,     0,     0,     0,   102,     0,    91,
      96,    41,     0,     0,   126,     0,     0,   135,    48,     0,
      86,    87,    14,    15,     0,    20,     8,     0,   105,   103,
       0,   109,     0,     0,     0,   106,     0,     0,     0,     0,
       0,    84,     0,    11,   110,   108,   111,     0,   107,   128,
     130,     0,     0,     0,     0,    83,   112,     0,   133,     0,
     131,     0,   129,   134,   132
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,     9,  -128,   -57,   164,   302,   173,
     124,   135,   139,   -35,  -128,  -128,   -54,   -34,     5,  -128,
     258,    11,  -128,   280,   -11,   -15,  -128,   220,   -16,   -40,
    -128,   317,  -128,  -128,    -6,   -37,   186,   236,   233,   -66,
    -128,  -128,  -119,  -128,   174,   323,  -128,   257,  -127,  -128,
    -128,  -128,  -128,  -128,   351,  -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    63,    64,   168,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    89,   192,   118,    90,     5,    79,    20,
      21,     7,     8,    31,    32,    33,    51,    52,    22,    23,
      24,    35,    45,    46,    75,   212,    81,    82,   110,   185,
     137,   138,   213,    76,    93,    94,    95,    96,    97,    98,
      99,   100,     9,    10,    11,    12
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    34,    80,    74,   102,     6,   108,    91,   111,   120,
      14,    26,    13,   136,     6,    48,   187,    53,   196,    28,
      50,    56,    57,    58,    59,    38,    30,    26,   101,    43,
      26,   112,   147,    43,   162,    16,    50,    29,    26,    18,
      30,    30,    30,   164,   187,   109,    92,    15,    60,    16,
      39,    61,    62,    18,    54,    16,    44,   146,    30,   103,
     186,    91,    17,   134,   171,   172,   155,    18,   219,   220,
     107,    30,   131,   135,   143,   119,    17,   169,     2,     3,
       4,    18,   133,   170,   132,    19,    26,    18,   152,    53,
     193,    36,   109,     2,     3,     4,   184,    49,    37,    26,
      92,    77,   105,   163,   108,    40,    41,   148,   205,   106,
     144,   195,   104,   198,   149,   145,   159,    34,    30,     1,
       2,     3,     4,   123,   153,   184,   124,   135,   165,    78,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   113,   114,   115,   116,   102,   148,   121,   122,
      92,   216,   119,   166,   197,   188,   163,   190,    56,    57,
      58,    59,   222,   199,   117,   232,   234,     2,     3,     4,
     101,   202,   223,   203,   119,   129,   130,   227,   139,   140,
      26,    56,    57,    58,    59,    60,   167,   204,    61,    62,
      18,   125,   126,   209,    34,   127,   128,   141,   142,     1,
       2,     3,     4,    83,    26,    84,    85,    86,    60,    77,
     214,    61,    62,    18,   237,   161,   148,    87,    41,    88,
      56,    57,    58,    59,   200,   140,   217,     1,     2,     3,
       4,   201,   142,     1,     2,     3,     4,   154,     1,     2,
       3,     4,    83,   215,    84,    85,    86,    60,   214,   225,
      61,    62,    18,   206,   207,   181,    87,    41,   150,    56,
      57,    58,    59,     1,     2,     3,     4,   182,     1,     2,
       3,     4,   204,   211,    56,    57,    58,    59,   221,   208,
     140,    83,   191,    84,    85,    86,    60,   173,   174,    61,
      62,    18,   218,   148,    55,    87,    41,    56,    57,    58,
      59,    60,   179,   180,    61,    62,    18,   224,   140,    47,
     194,    56,    57,    58,    59,     1,     2,     3,     4,    56,
      57,    58,    59,    25,    60,   157,   189,    61,    62,    18,
       2,     3,     4,   194,    56,    57,    58,    59,    60,   156,
     160,    61,    62,    18,   228,   140,    60,   231,    42,    61,
      62,    18,   151,     2,     3,     4,    56,    57,    58,    59,
      27,   158,     0,     0,    61,    62,    18,    56,    57,    58,
      59,     1,     2,     3,     4,     1,     2,     3,     4,     0,
     162,   183,    16,    60,   233,    18,    61,    62,    18,   235,
     140,   229,   230,     0,    60,     0,     0,    61,    62,    18,
       1,     2,     3,     4,    16,   238,     0,   240,     0,   133,
     183,   242,     0,   243,    18,   244,     1,     2,     3,     4,
     236,   140,     1,     2,     3,     4,   226,   175,   176,   177,
     178,   210,   211,   239,   148,     0,    18,   241,   148
};

static const yytype_int16 yycheck[] =
{
       6,    17,    39,    38,    44,     0,    60,    41,     7,    66,
       3,    17,     1,    79,     9,    30,   135,    33,   145,     0,
      31,     3,     4,     5,     6,    38,    15,    33,    44,     3,
      36,    30,    86,     3,    30,     3,    47,    40,    44,    35,
      29,    30,    31,   109,   163,    60,    41,    40,    30,     3,
      30,    33,    34,    35,    31,     3,    30,    39,    47,    30,
      30,    95,    30,    79,   121,   122,   103,    35,   195,   196,
      30,    60,    14,    79,    30,    66,    30,   112,    22,    23,
      24,    35,    30,   118,    15,    39,    92,    35,    31,   105,
     144,    32,   107,    22,    23,    24,   133,    41,    39,   105,
      95,     3,    32,   109,   158,    39,    40,    32,   165,    39,
      30,   145,    41,   148,    39,    30,   107,   133,   107,    21,
      22,    23,    24,    34,    31,   162,    37,   133,    31,    31,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    16,    17,    18,    19,   186,    32,    35,    36,
     145,   188,   143,     3,    39,    30,   162,     3,     3,     4,
       5,     6,   199,    30,    38,   219,   220,    22,    23,    24,
     186,    31,   207,    31,   165,    10,    11,   214,    31,    32,
     186,     3,     4,     5,     6,    30,    31,    30,    33,    34,
      35,     8,     9,    31,   210,    12,    13,    31,    32,    21,
      22,    23,    24,    25,   210,    27,    28,    29,    30,     3,
      30,    33,    34,    35,    26,    31,    32,    39,    40,    41,
       3,     4,     5,     6,    31,    32,    31,    21,    22,    23,
      24,    31,    32,    21,    22,    23,    24,    31,    21,    22,
      23,    24,    25,    31,    27,    28,    29,    30,    30,    31,
      33,    34,    35,    31,    32,   131,    39,    40,    41,     3,
       4,     5,     6,    21,    22,    23,    24,   132,    21,    22,
      23,    24,    30,    31,     3,     4,     5,     6,    31,    31,
      32,    25,   143,    27,    28,    29,    30,   123,   124,    33,
      34,    35,    31,    32,    36,    39,    40,     3,     4,     5,
       6,    30,   129,   130,    33,    34,    35,    31,    32,    29,
      39,     3,     4,     5,     6,    21,    22,    23,    24,     3,
       4,     5,     6,     6,    30,   105,   140,    33,    34,    35,
      22,    23,    24,    39,     3,     4,     5,     6,    30,   103,
     107,    33,    34,    35,    31,    32,    30,    31,    25,    33,
      34,    35,    95,    22,    23,    24,     3,     4,     5,     6,
       9,    30,    -1,    -1,    33,    34,    35,     3,     4,     5,
       6,    21,    22,    23,    24,    21,    22,    23,    24,    -1,
      30,    31,     3,    30,    31,    35,    33,    34,    35,    31,
      32,   217,   218,    -1,    30,    -1,    -1,    33,    34,    35,
      21,    22,    23,    24,     3,   231,    -1,   233,    -1,    30,
      31,   237,    -1,   239,    35,   241,    21,    22,    23,    24,
      31,    32,    21,    22,    23,    24,    31,   125,   126,   127,
     128,    30,    31,    31,    32,    -1,    35,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    23,    24,    59,    60,    63,    64,    94,
      95,    96,    97,    63,     3,    40,     3,    30,    35,    39,
      61,    62,    70,    71,    72,    73,    76,    96,     0,    40,
      63,    65,    66,    67,    70,    73,    32,    39,    38,    30,
      39,    40,    87,     3,    30,    74,    75,    65,    67,    41,
      66,    68,    69,    70,    31,    62,     3,     4,     5,     6,
      30,    33,    34,    43,    44,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    76,    85,     3,    31,    60,
      77,    78,    79,    25,    27,    28,    29,    39,    41,    55,
      58,    59,    60,    86,    87,    88,    89,    90,    91,    92,
      93,    70,    71,    30,    41,    32,    39,    30,    58,    67,
      80,     7,    30,    16,    17,    18,    19,    38,    57,    46,
      48,    35,    36,    34,    37,     8,     9,    12,    13,    10,
      11,    14,    15,    30,    70,    76,    81,    82,    83,    31,
      32,    31,    32,    30,    30,    30,    39,    58,    32,    39,
      41,    89,    31,    31,    31,    77,    79,    69,    30,    46,
      80,    31,    30,    76,    81,    31,     3,    31,    45,    55,
      55,    48,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    53,    31,    77,    81,    30,    84,    30,    78,
       3,    54,    56,    58,    39,    59,    90,    39,    55,    30,
      31,    31,    31,    31,    30,    48,    31,    32,    31,    31,
      30,    31,    77,    84,    30,    31,    77,    31,    31,    90,
      90,    31,    77,    55,    31,    31,    31,    77,    31,    86,
      86,    31,    58,    31,    58,    31,    31,    26,    86,    31,
      86,    31,    86,    86,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    44,    44,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    47,    48,
      48,    49,    49,    49,    50,    50,    50,    51,    51,    51,
      51,    51,    52,    52,    52,    53,    53,    54,    54,    55,
      55,    56,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    72,    73,    73,
      73,    74,    74,    74,    74,    74,    75,    75,    75,    76,
      77,    77,    78,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      84,    84,    84,    85,    86,    86,    86,    86,    86,    87,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    93,    93,    94,    94,    95,
      96,    96,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     3,     4,     3,
       1,     3,     1,     2,     4,     4,     1,     1,     1,     1,
       4,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     2,     1,     1,     3,     1,     3,     1,     1,     1,
       5,     4,     2,     1,     2,     3,     2,     1,     1,     3,
       1,     1,     1,     2,     1,     1,     3,     1,     4,     4,
       3,     1,     3,     6,     5,     1,     4,     4,     3,     1,
       1,     3,     2,     2,     1,     1,     3,     1,     2,     1,
       1,     1,     2,     3,     2,     3,     3,     4,     3,     2,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     6,     7,     6,     7,     3,     2,     1,     2,     1,
       1,     1,     3
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
  YYUSE (yytype);
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
  unsigned long yylno = yyrline[yyrule];
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
#line 70 "structfe.y" /* yacc.c:1652  */
    {log2("primary_expression -> IDENTIFIER");
    (yyval.node) = build_leaf(TID, (yyvsp[0].string));}
#line 1492 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 74 "structfe.y" /* yacc.c:1652  */
    {log2("primary_expression -> CONSTANT");
    (yyval.node) = build_leaf(TCONS, (yyvsp[0].string));}
#line 1499 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 78 "structfe.y" /* yacc.c:1652  */
    {log2("primary_expression -> STRING_LITERAL");
    (yyval.node) = build_leaf(TCONS, (yyvsp[0].string));}
#line 1506 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 82 "structfe.y" /* yacc.c:1652  */
    {log2("primary_expression -> ( expression )");
    (yyval.node) = (yyvsp[-1].node);}
#line 1513 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 88 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1519 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 91 "structfe.y" /* yacc.c:1652  */
    {log2("postfix_expression -> postfix_expression ( )");
    (yyval.node) = build_func((yyvsp[-2].node),NULL);}
#line 1526 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 95 "structfe.y" /* yacc.c:1652  */
    {log2("postfix_expression -> postfix_expression ( argument_expression_list )");
		(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1533 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 99 "structfe.y" /* yacc.c:1652  */
    {log2("postfix_expression -> postfix_expression PTR_OP IDENTIFIER");
		node_t *leaf = build_leaf(TID,(yyvsp[0].string));
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),leaf);}
#line 1541 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 106 "structfe.y" /* yacc.c:1652  */
    {log2("argument_expression_list -> expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1548 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 110 "structfe.y" /* yacc.c:1652  */
    {log2("argument_expression_list -> argument_expression_list , expression");
    (yyval.node) = build_opr("argument_expression_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1555 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 116 "structfe.y" /* yacc.c:1652  */
    {log2("unary_expression -> postfix_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1562 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 120 "structfe.y" /* yacc.c:1652  */
    {log2("unary_expression -> unary_operator unary_expression");
    (yyval.node) = build_uopr((yyvsp[-1].string),(yyvsp[0].node));}
#line 1569 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 124 "structfe.y" /* yacc.c:1652  */
    {log2("unary_expression -> SIZEOF ( unary_expression)");
    (yyval.node) = build_uopr((yyvsp[-3].string),(yyvsp[-1].node));
    }
#line 1577 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 129 "structfe.y" /* yacc.c:1652  */
    {log2("unary_expression -> SIZEOF ( type_name )");
    (yyval.node) = build_uopr((yyvsp[-3].string),(yyvsp[-1].string));
    }
#line 1585 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 136 "structfe.y" /* yacc.c:1652  */
    {log2("unary_operator -> &");
    (yyval.string) = "&";}
#line 1592 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 140 "structfe.y" /* yacc.c:1652  */
    {log2("unary_operator -> pointer");
    (yyval.string) = (yyvsp[0].string);}
#line 1599 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 144 "structfe.y" /* yacc.c:1652  */
    {log2("unary_operator -> -");
    (yyval.string) = "-";}
#line 1606 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 150 "structfe.y" /* yacc.c:1652  */
    {log2("cast_expression -> unary_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1613 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 154 "structfe.y" /* yacc.c:1652  */
    {log2("cast_expression -> '(' type_name ')' cast_expression");
    (yyval.node) = build_opr("cast",(yyvsp[-2].string),(yyvsp[0].node));}
#line 1620 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 160 "structfe.y" /* yacc.c:1652  */
    {log2("multiplicative_expression -> cast_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1627 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 164 "structfe.y" /* yacc.c:1652  */
    {log2("multiplicative_expression -> multiplicative_expression * cast_expression");
    (yyval.node) = build_opr("*",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1634 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 168 "structfe.y" /* yacc.c:1652  */
    {log2("multiplicative_expression -> multiplicative_expression / cast_expression");
    (yyval.node) = build_opr("/",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1641 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 174 "structfe.y" /* yacc.c:1652  */
    {log2("additive_expression -> multiplicative_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1648 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 178 "structfe.y" /* yacc.c:1652  */
    {log2("additive_expression -> additive_expression + multiplicative_expression");
    (yyval.node) = build_opr("+",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1655 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 182 "structfe.y" /* yacc.c:1652  */
    {log2("additive_expression -> additive_expression - multiplicative_expression");
    (yyval.node) = build_opr("-",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1662 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 188 "structfe.y" /* yacc.c:1652  */
    {log2("relational_expression -> additive_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1669 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 192 "structfe.y" /* yacc.c:1652  */
    {log2("relational_expression -> relational_expression L_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1676 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 196 "structfe.y" /* yacc.c:1652  */
    {log2("relational_expression -> relational_expression G_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1683 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 200 "structfe.y" /* yacc.c:1652  */
    {log2("relational_expression -> relational_expression LE_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1690 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 204 "structfe.y" /* yacc.c:1652  */
    {log2("relational_expression -> relational_expression GE_OP additive_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1697 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 210 "structfe.y" /* yacc.c:1652  */
    {log2("equality_expression -> relational_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1704 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 214 "structfe.y" /* yacc.c:1652  */
    {log2("equality_expression -> equality_expression EQ_OP relational_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1711 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 218 "structfe.y" /* yacc.c:1652  */
    {log2("equality_expression -> equality_expression NE_OP relational_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1718 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 224 "structfe.y" /* yacc.c:1652  */
    {log2("logical_and_expression -> equality_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1725 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 228 "structfe.y" /* yacc.c:1652  */
    {log2("logical_and_expression -> logical_and_expression AND_OP equality_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1732 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 234 "structfe.y" /* yacc.c:1652  */
    {log2("logical_or_expression -> logical_and_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1739 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 238 "structfe.y" /* yacc.c:1652  */
    {log2("logical_or_expression -> logical_or_expression OR_OP logical_and_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1746 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 244 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_expression -> logical_or_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1753 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 252 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_expression -> unary_expression assignment_operator assignment_expression");
    (yyval.node) = build_opr((yyvsp[-1].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1760 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 258 "structfe.y" /* yacc.c:1652  */
    {log2("if_expression -> logical_or_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1767 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 263 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_operator -> ="); (yyval.string) = "=";}
#line 1773 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 264 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_operator -> MUL_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1779 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 265 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_operator -> DIV_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1785 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 266 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_operator -> ADD_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1791 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 267 "structfe.y" /* yacc.c:1652  */
    {log2("assignment_operator -> SUB_ASSIGN"); (yyval.string) = (yyvsp[0].string);}
#line 1797 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 272 "structfe.y" /* yacc.c:1652  */
    {log2("expression -> assignment_expression");
    (yyval.node) = (yyvsp[0].node);}
#line 1804 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 276 "structfe.y" /* yacc.c:1652  */
    {log2("expression -> assignment_expression = expression");
    (yyval.node) = build_opr("expr",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1811 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 282 "structfe.y" /* yacc.c:1652  */
    {log2("declaration -> declaration_specifiers init_declarator_list ';'");
    (yyval.node) = build_opr("declaration",(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1818 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 286 "structfe.y" /* yacc.c:1652  */
    {log2("declaration -> declaration_specifiers ';'");
    (yyval.node) = build_opr("declaration",(yyvsp[-1].node),NULL);}
#line 1825 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 292 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_uopr("extern",(yyvsp[0].node));}
#line 1831 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 295 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1837 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 301 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1843 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 303 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("init_declarator_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1849 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 308 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1855 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 311 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("=",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1861 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 316 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID,(yyvsp[0].string));}
#line 1867 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 319 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID,(yyvsp[0].string));}
#line 1873 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 322 "structfe.y" /* yacc.c:1652  */
    {log2("type_specifier -> struct_or_union_specifier");
		(yyval.node) = (yyvsp[0].node);}
#line 1880 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 328 "structfe.y" /* yacc.c:1652  */
    {node_t *leaf = build_leaf(TID,(yyvsp[-3].string));
		(yyval.node) = build_struct(leaf,(yyvsp[-1].node));}
#line 1887 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 331 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_struct(NULL,(yyvsp[-1].node));}
#line 1893 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 333 "structfe.y" /* yacc.c:1652  */
    {node_t *leaf = build_leaf(TID,(yyvsp[0].string));
		(yyval.node) = build_struct(leaf,NULL);}
#line 1900 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 339 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1906 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 341 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("struct_declaration_list",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1912 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 346 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("struct_declaration",(yyvsp[-2].node),(yyvsp[-1].node));}
#line 1918 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 351 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("specifier_qualifier_list",(yyvsp[-1].node),(yyvsp[0].node));}
#line 1924 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 353 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1930 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 358 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1936 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 360 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("struct_declarator_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 1942 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 365 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1948 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 370 "structfe.y" /* yacc.c:1652  */
    {log2("declarator -> pointer_direct_declarator direct_declarator");
    (yyval.node) = (yyvsp[0].node);}
#line 1955 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 374 "structfe.y" /* yacc.c:1652  */
    {log2("declarator -> direct_declarator");
    (yyval.node) = (yyvsp[0].node);}
#line 1962 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 383 "structfe.y" /* yacc.c:1652  */
    {log2("pointer_direct_declarator -> pointer direct_declarator_pointer");
    (yyval.node) = build_uopr("pointer_direct_declarator",(yyvsp[0].node));}
#line 1969 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 388 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].string);}
#line 1975 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 393 "structfe.y" /* yacc.c:1652  */
    {log2("direct_declarator -> IDENTIFIER");
        log2((yyvsp[0].string));
        (yyval.node) = build_leaf(TID,(yyvsp[0].string));}
#line 1983 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 397 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1989 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 399 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1995 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 404 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2001 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 406 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2007 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 408 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-2].node),NULL);}
#line 2013 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 413 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID, (yyvsp[0].string));}
#line 2019 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 417 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2025 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 422 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-4].node),(yyvsp[-1].node));}
#line 2031 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 424 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-3].node),NULL);}
#line 2037 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 428 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2043 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 434 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2049 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 436 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-3].node),(yyvsp[-1].node));}
#line 2055 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 438 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_func((yyvsp[-2].node),NULL);}
#line 2061 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 450 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "pointer";}
#line 2067 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 456 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2073 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 459 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("parameter_list",(yyvsp[-2].node),(yyvsp[0].node));}
#line 2079 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 466 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("parameter_declaration",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2085 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 470 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("parameter_declaration",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2091 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 474 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2097 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 479 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID,(yyvsp[0].string));}
#line 2103 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 481 "structfe.y" /* yacc.c:1652  */
    {node_t *leaf = build_leaf(TID,(yyvsp[0].string));
		(yyval.node) = build_opr("identifier_list",(yyvsp[-2].node),leaf);}
#line 2110 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 487 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = (yyvsp[0].node);}
#line 2116 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 489 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = build_opr("type_name",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2122 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 494 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2128 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 496 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2134 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 501 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].string);}
#line 2140 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 503 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("abstract_declarator_with_pointer",(yyvsp[-1].string),(yyvsp[0].node));}
#line 2146 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 113:
#line 522 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2152 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 114:
#line 527 "structfe.y" /* yacc.c:1652  */
    {log2("statement -> compound_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2159 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 115:
#line 531 "structfe.y" /* yacc.c:1652  */
    {log2("statement -> expression_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2166 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 116:
#line 535 "structfe.y" /* yacc.c:1652  */
    {log2("statement -> selection_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2173 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 117:
#line 539 "structfe.y" /* yacc.c:1652  */
    {log2("statement -> iteration_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2180 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 118:
#line 543 "structfe.y" /* yacc.c:1652  */
    {log2("statement -> jump_statement");
    (yyval.node) = (yyvsp[0].node);}
#line 2187 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 119:
#line 549 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID,"{}");}
#line 2193 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 551 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2199 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 552 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID,";");}
#line 2205 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 557 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2211 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 560 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("block_item_list",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2217 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 567 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2223 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 125:
#line 570 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2229 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 126:
#line 574 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_leaf(TID,";");}
#line 2235 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 576 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2241 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 581 "structfe.y" /* yacc.c:1652  */
    {log2("selection_statement -> IF ( expression ) statement");
    (yyval.node) = build_if((yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 2248 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 129:
#line 585 "structfe.y" /* yacc.c:1652  */
    {log2("selection_statement -> IF ( expression ) statement ELSE statement");
    (yyval.node) = build_if((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2255 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 130:
#line 591 "structfe.y" /* yacc.c:1652  */
    {log2("iteration_statement -> WHILE '(' expression ')' statement ");
    (yyval.node) = build_opr((yyvsp[-4].string),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2262 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 131:
#line 597 "structfe.y" /* yacc.c:1652  */
    {log2("iteration_statement -> FOR '(' expression_statement expression_statement ')' statement ");
    (yyval.node) = build_for((yyvsp[-3].node),(yyvsp[-2].node), NULL,(yyvsp[0].node));}
#line 2269 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 132:
#line 604 "structfe.y" /* yacc.c:1652  */
    {log2("iteration_statement -> FOR '(' expression_statement expression_statement expression ')' statement ");
    (yyval.node) = build_for((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2276 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 133:
#line 610 "structfe.y" /* yacc.c:1652  */
    {log2("iteration_statement -> FOR '(' declaration expression_statement ')' statement ");
    (yyval.node) = build_for((yyvsp[-3].node),(yyvsp[-2].node), NULL,(yyvsp[0].node));}
#line 2283 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 134:
#line 615 "structfe.y" /* yacc.c:1652  */
    {log2("iteration_statement -> FOR '(' declaration expression_statement expression ')' statement ");
    (yyval.node) = build_for((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2290 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 135:
#line 621 "structfe.y" /* yacc.c:1652  */
    {log2("jump_statement -> RETURN expression ;");
    (yyval.node) = build_uopr("return",(yyvsp[-1].node));}
#line 2297 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 136:
#line 625 "structfe.y" /* yacc.c:1652  */
    {log2("jump_statement -> RETURN ;");
    (yyval.node) = build_leaf(TRET,(yyvsp[-1].string));}
#line 2304 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 137:
#line 631 "structfe.y" /* yacc.c:1652  */
    {log2("program -> external_declaration");
		(yyval.node) = (yyvsp[0].node);}
#line 2311 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 138:
#line 635 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("program",(yyvsp[-1].node),(yyvsp[0].node));}
#line 2317 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 139:
#line 640 "structfe.y" /* yacc.c:1652  */
    {stringify((yyvsp[0].node),0);
	//build_symbol_table($1);
	semantical_check((yyvsp[0].node));}
#line 2325 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 140:
#line 649 "structfe.y" /* yacc.c:1652  */
    {log2("external_declaration -> function_definition");
    (yyval.node) = (yyvsp[0].node);}
#line 2332 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 141:
#line 653 "structfe.y" /* yacc.c:1652  */
    {log2("external_declaration -> declaration");
    (yyval.node) = (yyvsp[0].node);}
#line 2339 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 142:
#line 660 "structfe.y" /* yacc.c:1652  */
    {(yyval.node) = build_opr("function_definition",build_opr("function",(yyvsp[-2].node),(yyvsp[-1].node)),(yyvsp[0].node));}
#line 2345 "structfe.tab.c" /* yacc.c:1652  */
    break;


#line 2349 "structfe.tab.c" /* yacc.c:1652  */
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
#line 672 "structfe.y" /* yacc.c:1918  */


extern FILE *yyin;

char *fname;

void
yyerror (char const *s)
{
	FILE* fd = fopen(fname,"r");
	char *code_line;
	get_nth_line(fd,line_count - 1,&code_line);
	char *tmp = calloc(10,1);
	sprintf(tmp,"%d",line_count);
	printf("line %d: %s\n%*s\n%*s\n",line_count,code_line, (column_count + 7 + strlen(tmp)), "^", column_count, s);
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
