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

	/*
	 * How the ICG works:
	 * For expressions, each expression's production
	 * returns an stack_t structure, then we just push each
	 * stack_t structure to the more general one.
	 * Then when our expression is finalized, we call the
	 * statements() function which will generate the code
	 * by the stack passed as argument
	 *
	 * Statement stack representation:
	 * [statement_type, data*, end_statement_type]
	 * Ex:
	 * ["expr", "=", "a", "3", ";"]
	 * ["ifelse", "==", "a", "3", "then", "expr", "=", "a", "4", ";" "else", "expr", "=", "a", "3", ";", "endif"]
	 *
	 * declarations stack representation
	 * [type_specifier, identifier, declarations_type]
	 * Ex:
	 * ["int", "a", "declarations"]
	 * (not yet implemented)
	 * ["int", "main", "function_declarations"]
	 *
	 * Correspondence table representation:
	 * It's just a linked list with 2 values: front-end repr & back-end repr
	 * [front-end-value, back-end-value, next]
	 * Ex:
	 * 0xCAFECAFE : ["a", "v0", 0xDEADBABE]
	 * 0xDEADBABE : [NULL, NULL, NULL]
	 */

	#include <stdio.h>
	#include <stdlib.h>

	#include "stack.h"
	#include "declarations.h"
	#include "statements.h"

	void log2 (char *msg)
	{
	    if (0)
	        printf("[***] %s\n", msg);
	}

	/* declarations stack */
	struct stack_t *decl;
	/* Statement stack */
	struct stack_t *stmt;
	/* Correspondence table */
	struct crpdct_t *ct;
	/* declarations buffer */
	struct buf_t *buf_decl;
	/* Statement buffer */
	struct buf_t *buf_stmt;
	/* Variable count */
	unsigned int vx;
	/* Label count */
	unsigned int lx;

	extern char yytext[];
	int printed = 0;
	void yyerror(char const *s);
	int yylex();

	void fix_ifelse (struct stack_t *, unsigned int);
	unsigned int rfix_ifelse (struct stack_t *, unsigned int);
	void create_primitive_functions (struct stack_t *);

#line 139 "structfe.tab.c" /* yacc.c:337  */
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
    WHILET = 282,
    FOR = 283,
    RETURN = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "structfe.y" /* yacc.c:352  */

	  char						* string;
		struct stack_t 	* stk;

#line 217 "structfe.tab.c" /* yacc.c:352  */
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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   398

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

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
       0,   177,   177,   182,   187,   192,   221,   224,   230,   235,
     243,   246,   249,   254,   265,   268,   275,   284,   287,   294,
     303,   306,   313,   320,   327,   336,   339,   346,   355,   358,
     367,   370,   379,   385,   394,   399,   403,   408,   420,   434,
     440,   447,   453,   460,   465,   470,   475,   480,   488,   493,
     498,   503,   508,   513,   519,   526,   528,   530,   532,   537,
     540,   548,   554,   566,   571,   577,   584,   590,   593,   599,
     606,   611,   619,   627,   629,   635,   636,   640,   645,   648,
     655,   662,   669,   674,   677,   684,   690,   699,   706,   714,
     720,   725,   734,   740,   745,   746,   749,   755,   764,   768,
     773,   783,   790,   797,   802,   808,   822,   823,   827,   828,
     831,   832,   833,   834,   835,   839,   840,   841,   842,   843,
     847,   852,   854,   856,   858,   860,   865,   866,   870,   871,
     874,   878,   879,   885,   888,   892,   894,   901,   903,   903,
     910,   909,   918,   917,   927,   926,   939,   938,   952,   951,
     963,   962,   975,   980,   987,   989,   993,   999,  1002,  1004,
    1010,  1009,  1020
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
  "STRUCT", "IF", "ELSE", "WHILET", "FOR", "RETURN", "'('", "')'", "','",
  "'&'", "'-'", "'*'", "'/'", "'+'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "if_expression", "assignment_operator",
  "expression", "declarations", "declarations_specifiers", "function_type",
  "function_oret", "argument_type", "argument_function_pointer",
  "init_declarator_list", "init_declarator", "type_specifier",
  "struct_or_union_specifier", "struct_oret", "struct_declarations_list",
  "struct_declarations", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "declarator",
  "pointer_direct_declarator", "direct_declarator", "function_declarator",
  "function_definer", "function_parameter_list",
  "direct_declarator_pointer", "function_declarator_pointer", "pointer",
  "parameter_list", "parameter_declarations", "identifier_list",
  "abstract_declarator", "abstract_declarator_with_pointer",
  "direct_abstract_declarator", "direct_abstract_declarator_pointer_free",
  "initializer", "statement", "compound_statement",
  "compound_body_statement", "compound_nop_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement", "$@1",
  "if_statement", "$@2", "iteration_statement", "$@3", "$@4", "$@5", "$@6",
  "$@7", "jump_statement", "program", "_start", "external_declarations",
  "function_definition", "$@8", "function_declarations_", YY_NULLPTR
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

#define YYPACT_NINF -181

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-181)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     147,   152,    39,    39,    38,  -181,    41,  -181,    55,   -29,
     147,   102,  -181,  -181,  -181,   -29,   -29,  -181,   -29,   187,
    -181,  -181,    78,  -181,    78,  -181,    80,    73,  -181,    94,
      -9,  -181,    39,  -181,  -181,  -181,  -181,  -181,   203,  -181,
    -181,    13,  -181,    21,  -181,  -181,    86,  -181,   198,    82,
    -181,  -181,    97,   347,    55,  -181,  -181,    78,  -181,   103,
     203,   104,   156,  -181,  -181,  -181,  -181,    18,  -181,  -181,
     118,  -181,   160,  -181,   129,  -181,    39,    39,  -181,    19,
     -29,   133,   157,   117,  -181,  -181,  -181,   123,   347,  -181,
    -181,  -181,  -181,   134,   347,  -181,    -3,    99,   116,   231,
     141,   178,  -181,  -181,  -181,  -181,   203,   203,     4,  -181,
      22,    70,  -181,   181,   216,   184,   104,   317,  -181,  -181,
    -181,   193,   240,  -181,  -181,    78,    78,    22,  -181,  -181,
      34,    39,  -181,   234,  -181,   214,    39,   200,   206,   224,
      32,  -181,  -181,  -181,     8,  -181,  -181,  -181,  -181,  -181,
     210,  -181,  -181,  -181,   239,  -181,  -181,   302,   268,  -181,
     347,  -181,  -181,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,    74,  -181,  -181,  -181,    31,
    -181,  -181,   241,  -181,  -181,  -181,   317,  -181,   259,   264,
     272,   250,   340,  -181,   282,    22,    22,  -181,   347,   347,
     263,  -181,    68,   347,  -181,  -181,  -181,  -181,   270,   276,
    -181,  -181,  -181,  -181,    -3,    -3,    99,    99,    99,    99,
     116,   116,   231,   141,  -181,    22,  -181,  -181,   287,  -181,
    -181,  -181,   284,  -181,  -181,   178,   299,   352,  -181,   288,
     288,  -181,  -181,   249,  -181,  -181,  -181,   344,  -181,  -181,
    -181,   325,   339,  -181,  -181,   354,   249,   249,  -181,   356,
    -181,   358,  -181,  -181,  -181,   249,  -181,   249,  -181,  -181,
     249,  -181,   249,  -181,  -181
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    43,    45,     0,   157,     0,    42,     0,     0,
     156,     0,   154,   158,   159,    43,    45,    41,     0,     0,
      98,    50,    44,    51,    46,    69,     0,     0,   160,    61,
       0,    59,    47,   155,     1,    44,    46,    47,     0,    64,
      63,     0,    58,   103,    40,    65,     0,    99,     0,     0,
     130,   162,     0,     0,     0,    38,    54,     0,    39,    68,
       0,    82,     0,   101,    78,    79,    84,    81,   102,   106,
     107,    57,     0,    56,     0,   104,    48,    90,    86,     0,
       0,     0,     0,     0,   161,     2,     3,     0,     0,    10,
      12,     5,     6,    13,     0,    14,    17,    20,    25,    28,
      30,    32,   120,    11,    62,    60,     0,    74,     0,    70,
       0,     0,   111,     0,     0,     0,    92,     0,    97,    80,
      96,   109,     0,   100,    55,    49,    52,     0,    85,    89,
      81,    53,    87,     0,    88,     0,     0,     0,     0,     0,
       0,   130,   128,    36,     0,   133,   134,   121,   126,   127,
       0,   131,   122,   123,   137,   124,   125,     0,     0,    35,
       0,    13,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    73,    67,    71,     0,
      75,    77,     0,    83,   112,   110,     0,   116,     0,     0,
       0,     0,     0,   113,     0,     0,     0,   105,     0,     0,
       0,   153,     0,     0,   136,   129,   132,   138,     0,     0,
       4,    33,    15,    16,    19,    18,    23,    24,    21,    22,
      26,    27,    29,    31,    66,     0,    72,    93,     0,   117,
     115,   118,     0,   114,    91,    34,     0,     0,   135,     0,
       0,   152,    37,     0,     8,     9,    76,     0,   119,   140,
     142,     0,     0,   139,    95,     0,     0,     0,   148,     0,
     144,     0,    94,   141,   143,     0,   150,     0,   146,   149,
       0,   145,     0,   151,   147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,  -181,    33,  -181,   -76,   168,   142,   207,   146,
     170,   148,   -49,  -181,  -181,   -85,   -78,  -181,  -181,   348,
     -38,     7,  -181,   300,   -26,  -181,    89,   251,   -89,   269,
    -181,   166,   -33,  -104,  -181,     1,  -181,  -181,  -181,  -181,
      -1,   -19,   320,  -181,   331,  -181,  -181,   327,  -181,     3,
    -181,   343,   369,  -181,   247,  -180,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,   388,
    -181,  -181,  -181
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   143,   236,   160,   144,     5,    43,     6,     7,
       8,    23,    30,    31,    44,    45,    80,   108,   109,   110,
     179,   180,   113,    64,    65,    66,    28,    81,   119,   120,
     103,   190,    47,    82,    68,    69,    70,   191,   104,   146,
     147,   148,   149,   150,   151,   152,   153,   243,   154,   256,
     155,   257,   267,   272,   265,   270,   156,    10,    11,    12,
      13,    52,    14
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      46,    22,    24,   158,   102,   145,    20,    27,    32,    21,
      63,    79,    58,   189,    35,    36,    59,    37,   162,   178,
     240,   116,    61,    54,    61,    61,    39,    40,    41,    74,
      55,    57,   163,   164,   107,    85,    86,   116,    87,    56,
     203,    25,    67,   114,    26,   177,   129,   204,   117,   127,
     128,    62,   127,    60,    20,   202,    20,    20,    29,   251,
     252,    67,    88,   225,   195,    89,    90,    20,   118,    19,
     226,   201,   145,   182,    20,   125,   126,   181,   130,   131,
     107,   107,   107,    21,   188,    75,   178,   212,   213,     9,
      18,   189,    76,   136,     4,   196,    39,    40,    41,     9,
     203,    78,    34,   194,    76,    77,     4,   241,    48,   130,
      49,   211,    50,    78,   237,   224,   130,    71,    72,   209,
      85,    86,   239,    87,   167,   168,   130,   161,   169,   170,
      57,   118,    53,   165,   111,   126,   166,    83,    56,    76,
     136,     4,   137,   106,   138,   139,   140,    88,   122,   107,
      89,    90,    20,   157,   242,   173,   141,    83,   142,    61,
     124,    72,   188,   234,   132,   133,   259,   261,     1,     2,
       3,     4,   159,   232,    15,    16,     4,    38,    39,    40,
      41,    38,    39,    40,    41,   130,    62,   112,   134,   135,
     208,    20,   181,   174,   130,   130,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,    38,    39,
      40,    41,   183,    85,    86,   185,    87,   197,    42,    38,
      39,    40,    41,   192,   130,    39,    40,    41,   255,    73,
     198,   161,    76,   136,     4,   137,   199,   138,   139,   140,
      88,   171,   172,    89,    90,    20,   253,   184,    72,   141,
      83,   205,    85,    86,   200,    87,    76,   136,     4,   263,
     264,    38,    39,    40,    41,   207,    85,    86,   269,    87,
     271,   193,   128,   273,   137,   274,   138,   139,   140,    88,
     192,   230,    89,    90,    20,    76,   136,     4,   141,    83,
     227,    85,    86,    88,    87,   228,    89,    90,    20,   210,
     203,   244,   238,   229,    72,    85,    86,   245,    87,   216,
     217,   218,   219,   233,    72,   248,    72,   247,    88,   222,
      61,    89,    90,    20,    76,   136,     4,   238,    85,    86,
     249,    87,    88,   214,   215,    89,    90,    20,    38,    39,
      40,    41,    85,    86,   223,    87,   235,   186,   187,    17,
      85,    86,    20,    87,   105,    88,   258,   175,    89,    90,
      20,    38,    39,    40,    41,    38,    39,    40,    41,    88,
     260,   231,    89,    90,    20,   254,   176,    88,   220,   221,
      89,    90,    20,   250,   203,   262,    72,   266,   203,   268,
     203,   246,   123,   115,   121,    84,    51,   206,    33
};

static const yytype_uint16 yycheck[] =
{
      19,     2,     3,    88,    53,    83,    35,     6,     9,     2,
      43,    49,    38,   117,    15,    16,     3,    18,    94,   108,
     200,     3,     3,    32,     3,     3,    22,    23,    24,    48,
      39,    32,    35,    36,    60,     3,     4,     3,     6,    32,
      32,     3,    43,    62,     3,    41,    79,    39,    30,    30,
      31,    30,    30,    40,    35,   140,    35,    35,     3,   239,
     240,    62,    30,    32,    30,    33,    34,    35,    67,    30,
      39,    39,   150,   111,    35,    76,    77,   110,    79,    80,
     106,   107,   108,    76,   117,     3,   175,   163,   164,     0,
       1,   195,    22,    23,    24,   133,    22,    23,    24,    10,
      32,    31,     0,   122,    22,    23,    24,    39,    30,   110,
      30,   160,    39,    31,   199,    41,   117,    31,    32,   157,
       3,     4,   200,     6,     8,     9,   127,    94,    12,    13,
     131,   130,    38,    34,    30,   136,    37,    40,   131,    22,
      23,    24,    25,    40,    27,    28,    29,    30,    30,   175,
      33,    34,    35,    30,   203,    14,    39,    40,    41,     3,
      31,    32,   195,   196,    31,    32,   251,   252,    21,    22,
      23,    24,    38,   192,    22,    23,    24,    21,    22,    23,
      24,    21,    22,    23,    24,   186,    30,    31,    31,    32,
     157,    35,   225,    15,   195,   196,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    21,    22,
      23,    24,    31,     3,     4,    31,     6,     3,    31,    21,
      22,    23,    24,    30,   225,    22,    23,    24,   247,    31,
      30,   198,    22,    23,    24,    25,    30,    27,    28,    29,
      30,    10,    11,    33,    34,    35,   243,    31,    32,    39,
      40,    41,     3,     4,    30,     6,    22,    23,    24,   256,
     257,    21,    22,    23,    24,    26,     3,     4,   265,     6,
     267,    31,    31,   270,    25,   272,    27,    28,    29,    30,
      30,    31,    33,    34,    35,    22,    23,    24,    39,    40,
      31,     3,     4,    30,     6,    31,    33,    34,    35,    31,
      32,    31,    39,    31,    32,     3,     4,    31,     6,   167,
     168,   169,   170,    31,    32,    31,    32,    30,    30,   173,
       3,    33,    34,    35,    22,    23,    24,    39,     3,     4,
      31,     6,    30,   165,   166,    33,    34,    35,    21,    22,
      23,    24,     3,     4,   174,     6,   198,    30,    31,     1,
       3,     4,    35,     6,    54,    30,    31,   106,    33,    34,
      35,    21,    22,    23,    24,    21,    22,    23,    24,    30,
      31,    31,    33,    34,    35,    31,   107,    30,   171,   172,
      33,    34,    35,    31,    32,    31,    32,    31,    32,    31,
      32,   225,    72,    62,    67,    52,    27,   150,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    22,    23,    24,    58,    60,    61,    62,    68,
     109,   110,   111,   112,   114,    22,    23,    61,    68,    30,
      35,    63,    82,    63,    82,     3,     3,    77,    78,     3,
      64,    65,    82,   111,     0,    82,    82,    82,    21,    22,
      23,    24,    31,    59,    66,    67,    83,    84,    30,    30,
      39,    94,   113,    38,    32,    39,    63,    82,    66,     3,
      40,     3,    30,    74,    75,    76,    77,    82,    86,    87,
      88,    31,    32,    31,    83,     3,    22,    23,    31,    62,
      68,    79,    85,    40,    93,     3,     4,     6,    30,    33,
      34,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    82,    90,    65,    40,    66,    69,    70,
      71,    30,    31,    74,    83,    86,     3,    30,    77,    80,
      81,    89,    30,    84,    31,    82,    82,    30,    31,    74,
      82,    82,    31,    32,    31,    32,    23,    25,    27,    28,
      29,    39,    41,    54,    57,    58,    91,    92,    93,    94,
      95,    96,    97,    98,   100,   102,   108,    30,    57,    38,
      56,    45,    47,    35,    36,    34,    37,     8,     9,    12,
      13,    10,    11,    14,    15,    69,    71,    41,    70,    72,
      73,    74,    62,    31,    31,    31,    30,    31,    74,    75,
      83,    89,    30,    31,    83,    30,    62,     3,    30,    30,
      30,    39,    57,    32,    39,    41,    96,    26,    45,    62,
      31,    54,    47,    47,    48,    48,    49,    49,    49,    49,
      50,    50,    51,    52,    41,    32,    39,    31,    31,    31,
      31,    31,    83,    31,    74,    53,    55,    57,    39,    58,
      97,    39,    54,    99,    31,    31,    73,    30,    31,    31,
      31,    97,    97,    91,    31,    83,   101,   103,    31,    57,
      31,    57,    31,    91,    91,   106,    31,   104,    31,    91,
     107,    91,   105,    91,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    45,    45,    45,    45,
      46,    46,    46,    47,    48,    48,    48,    49,    49,    49,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    68,
      69,    69,    70,    71,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    80,    81,    82,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      90,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      94,    95,    95,    96,    96,    97,    97,    98,    99,    98,
     101,   100,   103,   102,   104,   102,   105,   102,   106,   102,
     107,   102,   108,   108,   109,   109,   110,   111,   111,   111,
     113,   112,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     2,     4,     4,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     3,     2,
       1,     2,     1,     1,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     3,     4,     3,     3,     2,     1,
       3,     1,     3,     1,     1,     1,     5,     4,     2,     2,
       1,     2,     3,     2,     1,     1,     3,     1,     1,     1,
       2,     1,     1,     3,     1,     4,     3,     4,     4,     2,
       1,     4,     1,     3,     6,     5,     1,     1,     1,     1,
       3,     2,     2,     1,     1,     3,     1,     1,     1,     2,
       3,     2,     3,     3,     4,     3,     2,     3,     3,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     2,     1,     1,     1,     2,     1,     0,     4,
       0,     6,     0,     6,     0,     7,     0,     8,     0,     7,
       0,     8,     3,     2,     1,     2,     1,     1,     1,     1,
       0,     4,     3
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
#line 178 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *tmp = init_stack();
			tmp->push(tmp, (yyvsp[0].string));
			(yyval.stk) = tmp;}
#line 1554 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 183 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *tmp = init_stack();
			tmp->push(tmp, (yyvsp[0].string));
			(yyval.stk) = tmp;}
#line 1562 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 188 "structfe.y" /* yacc.c:1652  */
    { (yyval.stk) = (yyvsp[-1].stk);}
#line 1568 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 193 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1574 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 222 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1580 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 225 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *tmp = init_stack();
			tmp->push(tmp, (yyvsp[-1].string));
			tmp->push_stack(tmp, (yyvsp[0].stk));
			(yyval.stk) = tmp;}
#line 1589 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 231 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "4");
			(yyval.stk) = stk;}
#line 1597 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 236 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "sizeof");
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 1606 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 244 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "u&";}
#line 1612 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 247 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "u*";}
#line 1618 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 250 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "u-";}
#line 1624 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 255 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1630 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 266 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1636 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 269 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "*");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1646 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 276 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "/");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1656 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 285 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1662 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 288 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "+");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1672 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 295 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "-");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1682 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 304 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1688 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 307 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1698 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 314 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1708 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 321 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1718 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 328 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1728 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 337 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1734 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 340 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1744 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 347 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1754 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 356 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1760 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 359 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1770 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 368 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1776 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 371 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1786 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 380 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1792 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 386 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1802 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 395 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1808 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 399 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "=";}
#line 1814 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 404 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "expr");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1823 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 409 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "expr");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push(stk, ";");
			stk->push(stk, "expr");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1835 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 421 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			struct stack_t *ids = (yyvsp[-1].stk);
			for (size_t i = 0; i < ids->size; i++)
			{
				 stk->push_stack(stk, (yyvsp[-2].stk));
				 /* is juste an IDENTIFIER */
				 stk->push(stk, ids->get(ids, i)->value);
				 stk->push(stk, "declaration");
			}
			(yyval.stk) = stk;}
#line 1850 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 435 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "extern");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1859 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 441 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1867 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 448 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "extern");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1876 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 454 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1884 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 461 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			(yyval.stk) = stk;}
#line 1892 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 466 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int *");
			(yyval.stk) = stk;}
#line 1900 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 471 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void");
			(yyval.stk) = stk;}
#line 1908 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 476 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void *");
			(yyval.stk) = stk;}
#line 1916 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 481 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "struct *");
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 1925 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 489 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			(yyval.stk) = stk;}
#line 1933 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 494 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int *");
			(yyval.stk) = stk;}
#line 1941 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 499 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int p");
			(yyval.stk) = stk;}
#line 1949 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 504 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void p");
			(yyval.stk) = stk;}
#line 1957 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 509 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void *");
			(yyval.stk) = stk;}
#line 1965 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 514 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "struct *");
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 1974 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 520 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void *");
			(yyval.stk) = stk;}
#line 1982 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 538 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1988 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 541 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1997 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 549 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[0].string));
			(yyval.stk) = stk;}
#line 2005 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 555 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stmt->push(stmt, "expr");
			stmt->push(stmt, "=");
			stmt->push(stmt, (yyvsp[-2].string));
			stmt->push_stack(stmt, (yyvsp[0].stk));

			stk->push(stk, (yyvsp[-2].string));
			(yyval.stk) = stk;}
#line 2018 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 567 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void");
			(yyval.stk) = stk;}
#line 2026 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 572 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			(yyval.stk) = stk;}
#line 2034 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 578 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "struct");
			(yyval.stk) = stk;}
#line 2042 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 585 "structfe.y" /* yacc.c:1652  */
    {decl->push(decl, "struct");
		 decl->push(decl, (yyvsp[-3].string));
		 decl->push_stack(decl, (yyvsp[-1].stk));
	 	 decl->push(decl, "struct_declarations");}
#line 2051 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 594 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "struct");
		 stmt->push(stmt, (yyvsp[0].string));}
#line 2058 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 600 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[0].string));
			(yyval.stk) = stk;}
#line 2066 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 607 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2074 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 612 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-1].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2083 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 620 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 2092 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 628 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2098 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 630 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2104 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 641 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2110 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 646 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2116 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 649 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2122 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 656 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "u*");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2131 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 663 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "u*");
			(yyval.stk) = stk;}
#line 2139 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 670 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[0].string));
			(yyval.stk) = stk;}
#line 2147 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 675 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[-1].stk);}
#line 2153 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 678 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2161 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 685 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-3].string));
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 2170 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 691 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-2].string));
			stk->push(stk, "void");
			(yyval.stk) = stk;}
#line 2179 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 700 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-3].string));
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 2188 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 707 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-3].string));
			stk->push_stack(stk, (yyvsp[-1].stk));
			(yyval.stk) = stk;}
#line 2197 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 715 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-1].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2206 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 721 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "void");
			(yyval.stk) = stk;}
#line 2214 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 726 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-3].stk));
			stk->push_stack(stk, (yyvsp[-1].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2224 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 735 "structfe.y" /* yacc.c:1652  */
    { char *tmp = (char *) calloc (strlen((yyvsp[0].string)) + 2, 1);
			sprintf(tmp, "*%s", (yyvsp[0].string));
			decl->push(decl, tmp);}
#line 2232 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 741 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[-1].stk);}
#line 2238 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 750 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2244 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 756 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2250 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 769 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2258 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 774 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2267 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 784 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-1].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2276 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 791 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-1].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 2285 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 798 "structfe.y" /* yacc.c:1652  */
    { (yyval.stk) = (yyvsp[0].stk); }
#line 2291 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 803 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			stk->push(stk, (yyvsp[0].string));
			(yyval.stk) = stk;}
#line 2300 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 809 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push(stk, "int");
			stk->push(stk, (yyvsp[0].string));
			(yyval.stk) = stk;}
#line 2310 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 120:
#line 848 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 2316 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 133:
#line 886 "structfe.y" /* yacc.c:1652  */
    { decl->push_stack(decl, (yyvsp[0].stk));}
#line 2322 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 135:
#line 893 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = stmt;}
#line 2328 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 136:
#line 895 "structfe.y" /* yacc.c:1652  */
    { stmt->push_stack(stmt, (yyvsp[-1].stk));
			stmt->push(stmt, ";");
	    (yyval.stk) = stmt;}
#line 2336 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 137:
#line 901 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endif");}
#line 2342 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 138:
#line 903 "structfe.y" /* yacc.c:1652  */
    {fix_ifelse(stmt, stmt->size);
														 stmt->push(stmt, "else");}
#line 2349 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 139:
#line 905 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endif");}
#line 2355 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 140:
#line 910 "structfe.y" /* yacc.c:1652  */
    { stmt->push(stmt, "if");
	  	stmt->push_stack(stmt, (yyvsp[-1].stk));
		  stmt->push(stmt, "then");}
#line 2363 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 142:
#line 918 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "while");
				stmt->push_stack(stmt, (yyvsp[-1].stk));
				stmt->push(stmt, "do");}
#line 2371 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 143:
#line 923 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endwhile");}
#line 2377 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 144:
#line 927 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "for");
		stmt->push_stack(stmt, (yyvsp[-2].stk));
		stmt->push(stmt, "endecl");
		stmt->push_stack(stmt, (yyvsp[-1].stk));
		stmt->push(stmt, "endcond");
		stmt->push(stmt, "endstep");}
#line 2388 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 145:
#line 935 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endfor");}
#line 2394 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 146:
#line 939 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "for");
		stmt->push_stack(stmt, (yyvsp[-3].stk));
		stmt->push(stmt, "endecl");
		stmt->push_stack(stmt, (yyvsp[-2].stk));
		stmt->push(stmt, "endcond");
		stmt->push_stack(stmt, (yyvsp[-1].stk));
		stmt->push(stmt, "endstep");}
#line 2406 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 147:
#line 948 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endfor");}
#line 2412 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 148:
#line 952 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "for");
		stmt->push(stmt, "endecl");
		stmt->push_stack(stmt, (yyvsp[-1].stk));
		stmt->push(stmt, "endcond");
		stmt->push(stmt, "endstep");}
#line 2422 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 149:
#line 959 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endfor");}
#line 2428 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 150:
#line 963 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "for");
		stmt->push(stmt, "endecl");
		stmt->push_stack(stmt, (yyvsp[-2].stk));
		stmt->push(stmt, "endcond");
		stmt->push_stack(stmt, (yyvsp[-1].stk));
		stmt->push(stmt, "endstep");}
#line 2439 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 151:
#line 971 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endfor");}
#line 2445 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 152:
#line 976 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "return");
		 stmt->push_stack(stmt, (yyvsp[-1].stk));
	 	 stmt->push(stmt, ";");}
#line 2453 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 153:
#line 981 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "return");
		 stmt->push(stmt, "expr");
	 	 stmt->push(stmt, ";");}
#line 2461 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 156:
#line 994 "structfe.y" /* yacc.c:1652  */
    { declaration(decl, ct, buf_decl, &vx, 0);
      statements(decl, stmt, ct, buf_decl, buf_stmt, &vx, &lx, 0, stmt->size, 0);}
#line 2468 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 157:
#line 1000 "structfe.y" /* yacc.c:1652  */
    { decl->push_stack(decl, (yyvsp[0].stk));}
#line 2474 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 160:
#line 1010 "structfe.y" /* yacc.c:1652  */
    { stmt->push(stmt, "func");
			stmt->push_stack(stmt, (yyvsp[-1].stk)); /* (extern) + ??? */
			stmt->push_stack(stmt, (yyvsp[0].stk)); /* fun_name ((types +) args) */
			stmt->push(stmt, "endarg");}
#line 2483 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 161:
#line 1015 "structfe.y" /* yacc.c:1652  */
    { stmt->push(stmt, "endfun");}
#line 2489 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 162:
#line 1021 "structfe.y" /* yacc.c:1652  */
    { decl->push_stack(decl, (yyvsp[-2].stk)); /* (extern) + ??? */
			decl->push_stack(decl, (yyvsp[-1].stk)); /* fun_name (types) */
			decl->push(decl, "fundecl");}
#line 2497 "structfe.tab.c" /* yacc.c:1652  */
    break;


#line 2501 "structfe.tab.c" /* yacc.c:1652  */
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
#line 1034 "structfe.y" /* yacc.c:1918  */


extern FILE *yyin;

char *fname;

void
yyerror (char const *s)
{
	fprintf(stderr, "%s", s);
	exit(2);
}

int
main (int argc, char *argv[])
{
	FILE *fbe;

	decl = init_stack();
	stmt = init_stack();
	create_primitive_functions(stmt);
	ct = init_crpcdt();
	buf_decl = init_buf();
	buf_stmt = init_buf();
	vx = 0;
	lx = 0;

	fname = strdup(argv[1]);
	if ((yyin = fopen(fname, "r")) == NULL)
	{
		yyerror("[!] File not found\n");
		exit(2);
	} else {
		yyparse();
		//print_ct(ct);
		if (strlen(buf_decl->string))
		{
			buf_decl->add(buf_decl, "\n");
		}

		if (argc > 2)
		{
			stmt->print_stack(stmt);
			decl->print_stack(decl);
		}

		fbe = fopen("a.be", "w+");
		fprintf(stdout, "%s%s", buf_decl->string, buf_stmt->string);
		fclose(fbe);
		printf("Success.\n");
	}
	return 0;
}

unsigned int
rfix_ifelse (struct stack_t 	* stk,
						 unsigned int 		index)
{
	for (size_t i = index; i > 0 ; i--)
	{
			if (!strcmp(stk->get(stk, i)->value, "endif"))
			{
					i = rfix_ifelse(stk, i - 1);
					continue;
			}

			if (!strcmp(stk->get(stk, i)->value, "if"))
			{
					return i;
			}
	}
  return (unsigned int)-1;
}

void
fix_ifelse (struct stack_t 	* stk,
						unsigned int 		index)
{
	for (size_t i = index; i > 0 ; i--)
	{
			if (!strcmp(stk->get(stk, i)->value, "endif"))
			{
					i = rfix_ifelse(stk, i - 1);
					continue;
			}

			if (!strcmp(stk->get(stk, i)->value, "if"))
			{
					stk->get(stk, i)->value = strdup("ifelse");
					return;
			}
	}
  return (unsigned int)-1;
}

void
create_primitive_functions (struct stack_t *stmt)
{
		stmt->push(stmt, "func");
    stmt->push(stmt, "int");
    stmt->push(stmt, "and");
    stmt->push(stmt, "int");
    stmt->push(stmt, "a");
    stmt->push(stmt, "int");
    stmt->push(stmt, "b");
    stmt->push(stmt, "endarg");
    stmt->push(stmt, "if");
    stmt->push(stmt, "==");
    stmt->push(stmt, "a");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "0");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "if");
    stmt->push(stmt, "==");
    stmt->push(stmt, "b");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "0");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "1");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endfun");

    stmt->push(stmt, "func");
    stmt->push(stmt, "int");
    stmt->push(stmt, "or");
    stmt->push(stmt, "int");
    stmt->push(stmt, "a");
    stmt->push(stmt, "int");
    stmt->push(stmt, "b");
    stmt->push(stmt, "endarg");
    stmt->push(stmt, "if");
    stmt->push(stmt, "!=");
    stmt->push(stmt, "a");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "1");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "if");
    stmt->push(stmt, "!=");
    stmt->push(stmt, "b");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "1");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "0");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endfun");
}
