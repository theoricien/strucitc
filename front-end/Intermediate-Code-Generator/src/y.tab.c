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
	 * Author: Maxime JEROME (maxime.jerome[at]protonmail[dot]com)
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
	 * Declaration stack representation
	 * [type_specifier, identifier, declaration_type]
	 * Ex:
	 * ["int", "a", "declaration"]
	 * (not yet implemented)
	 * ["int", "main", "function_declaration"]
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

	/* Declaration stack */
	struct stack_t *decl;
	/* Statement stack */
	struct stack_t *stmt;
	/* Correspondence table */
	struct crpdct_t *ct;
	/* Declaration buffer */
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

#line 136 "structfe.tab.c" /* yacc.c:337  */
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
#line 68 "structfe.y" /* yacc.c:352  */

	  char						* string;
		struct stack_t 	* stk;

#line 214 "structfe.tab.c" /* yacc.c:352  */
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
#define YYFINAL  99
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

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
       0,   148,   148,   153,   158,   163,   192,   195,   202,   207,
     214,   217,   220,   223,   228,   239,   242,   249,   258,   261,
     268,   277,   280,   287,   294,   301,   310,   313,   320,   329,
     332,   341,   344,   353,   359,   368,   373,   374,   375,   376,
     377,   381,   386,   397,   400,   405,   407,   412,   413,   417,
     419,   419,   423,   427,   431,   436,   437,   438,   442,   443,
     447,   451,   452,   456,   457,   461,   465,   467,   473,   476,
     480,   483,   484,   488,   489,   490,   494,   500,   504,   505,
     508,   513,   514,   515,   524,   529,   531,   537,   540,   543,
     547,   548,   552,   553,   557,   558,   562,   563,   566,   567,
     568,   569,   570,   574,   575,   576,   577,   578,   582,   586,
     588,   590,   592,   594,   599,   600,   601,   605,   606,   612,
     615,   620,   622,   629,   630,   629,   633,   634,   636,   633,
     641,   645,   650,   654,   657,   661,   663,   667,   669,   673,
     677,   679,   681,   685
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
  "primary_expression", "postfix_expression", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "if_expression", "assignment_operator",
  "expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "$@1", "type_specifier",
  "struct_or_union_specifier", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "declarator",
  "pointer_direct_declarator", "direct_declarator", "function_declarator",
  "direct_declarator_pointer", "function_declarator_pointer", "pointer",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "abstract_declarator_with_pointer",
  "direct_abstract_declarator", "direct_abstract_declarator_pointer_free",
  "initializer", "statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement", "$@2",
  "$@3", "$@4", "$@5", "$@6", "iteration_statement", "jump_statement",
  "program", "_start", "external_declaration", "function_definition", YY_NULLPTR
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

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     222,  -146,  -146,   -12,    14,  -146,  -146,     6,  -146,    -7,
      54,   235,   361,  -146,  -146,  -146,  -146,  -146,   141,  -146,
    -146,   177,   361,  -146,    57,    82,    96,   132,    74,    81,
    -146,     0,  -146,   100,  -146,  -146,  -146,  -146,  -146,   222,
    -146,  -146,  -146,  -146,  -146,   222,    98,  -146,  -146,   320,
    -146,    62,    14,    76,   107,   361,   280,  -146,     1,   147,
    -146,  -146,   100,   183,  -146,  -146,  -146,  -146,  -146,   361,
    -146,  -146,   361,   361,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   361,   361,  -146,  -146,   154,  -146,    50,
    -146,   154,  -146,  -146,   118,   133,    18,  -146,  -146,  -146,
     119,    14,    56,   125,    14,   207,  -146,   154,   361,   361,
     166,  -146,   302,   302,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,    57,    57,    82,    82,    82,    82,    96,    96,   132,
      74,  -146,   128,   154,  -146,   129,   211,  -146,  -146,  -146,
     154,   153,  -146,  -146,  -146,   393,   162,  -146,  -146,   197,
    -146,   256,  -146,  -146,    51,  -146,  -146,    81,   209,   236,
     260,   327,   342,  -146,  -146,   361,  -146,  -146,   155,   189,
    -146,   205,   246,   267,   381,  -146,   228,   276,   397,   279,
       4,  -146,   154,  -146,  -146,  -146,  -146,   260,   241,   260,
     244,  -146,  -146,   110,  -146,    19,  -146,  -146,    29,  -146,
     319,  -146,   295,  -146,   250,   286,  -146,  -146,  -146,   289,
     223,   178,  -146,   296,  -146,   260,   260,  -146,   260,  -146,
     260,   377,  -146,  -146,   409,  -146,  -146,  -146,  -146,  -146,
     308,  -146,  -146,   303,  -146,  -146,   377,  -146,   350,  -146,
    -146,  -146,   260,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     3,     0,     0,    53,    52,     0,   123,     0,
       0,     0,     0,    10,    12,    13,    84,   116,     0,     5,
       6,    14,     0,    15,    18,    21,    26,    29,    31,    33,
      41,     0,   119,     0,    46,    54,    11,   120,   109,   142,
     117,   110,   111,   112,   113,   139,     0,   137,   140,     0,
      45,    57,     0,     0,     0,     0,     0,   136,     0,     0,
     114,   119,     0,     0,    37,    38,    39,    40,    36,     0,
      14,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,    70,     0,    44,     0,
      47,     0,    49,    66,    67,    72,    69,   118,   138,     1,
       0,    62,    92,     0,     0,     0,    58,     0,     0,     0,
       0,   121,     0,     0,   135,     4,    72,   115,    34,    16,
      17,    19,    20,    24,    25,    22,    23,    27,    28,    30,
      32,    42,     0,     0,    43,     0,     0,   116,   143,    76,
       0,    68,    80,     8,    61,     0,    96,    93,    94,    95,
       9,     0,    56,    59,     0,    63,    65,    35,     0,     0,
       0,     0,     0,    71,    48,     0,    90,    75,    89,     0,
      85,     0,     0,     0,     0,    99,     0,     0,     0,    97,
       0,    55,     0,    60,   124,   127,   130,     0,     0,     0,
       0,   108,    51,     0,    87,    69,    88,    73,     0,    74,
       0,    77,     0,    83,     0,     0,   100,    98,   104,     0,
       0,     0,   101,     0,    64,     0,     0,   133,     0,   131,
       0,     0,    86,    91,     0,    81,    82,   105,   103,   106,
       0,   102,   125,     0,   134,   132,     0,    79,     0,   107,
     128,    78,     0,   129
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,    46,  -146,     8,   217,   292,   231,   252,
     264,   243,   -64,   240,  -146,   -10,    11,    16,  -146,   226,
    -146,    10,  -146,   262,   -74,   -36,  -146,   192,   -83,  -134,
    -146,   346,  -146,  -146,   -33,  -133,   185,   212,  -146,   -92,
    -146,  -146,  -129,  -146,  -145,   290,   369,   -20,   -49,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   343,
    -146
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   158,    69,    31,    61,   168,    89,    90,
      91,    34,    35,   105,   106,   107,   154,   155,    92,    93,
      94,   116,   141,   142,    36,   209,   170,   171,   103,   177,
     148,   149,   210,   192,    37,    38,    39,    40,    41,    42,
      53,   215,    54,   216,   242,    43,    44,    45,    46,    47,
      48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      96,    58,    59,   169,   132,   118,   173,   113,   135,    51,
     147,    32,   176,   102,    50,   186,    33,   179,    49,    97,
     131,   139,   139,    55,   156,     4,     5,     6,     7,    96,
      71,   153,    84,    84,    62,   212,     5,     6,     7,    85,
     114,   204,   217,    97,   219,   110,    52,   213,   140,   221,
       4,     5,     6,     7,    96,    62,    32,   172,    96,   101,
     176,    33,   101,   161,   162,   144,   179,   112,    70,   146,
     232,   233,    62,   234,    96,   235,   196,   153,   230,    62,
     119,   120,   133,   182,    56,   194,   145,   173,    82,   134,
     183,   238,    16,    72,    73,   100,    83,   243,    99,   156,
      96,   191,   104,    86,    76,    77,   108,    96,    78,    79,
     132,   101,   146,    86,   101,   101,    74,    75,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      87,     4,     5,     6,     7,   195,    16,   109,   172,    88,
     193,   175,    80,    81,     1,     2,    16,     3,   136,    96,
     143,   188,   190,   132,    70,    70,   150,    86,    86,   163,
     195,   101,     4,     5,     6,     7,     8,   165,     9,    10,
      11,    12,   137,    18,    13,    14,    15,    16,   115,    84,
      17,    18,    60,   174,    87,   193,     1,     2,    96,     3,
      16,    16,   178,    64,    65,    66,    67,   160,    84,     4,
       5,     6,     7,    96,     4,     5,     6,     7,     8,   229,
       9,    10,    11,    12,   166,    68,    13,    14,    15,    16,
     197,   198,    17,    18,   117,     1,     2,   180,     3,     5,
       6,     7,     4,     5,     6,     7,   199,   200,     1,     2,
     184,     3,   167,     4,     5,     6,     7,     8,   152,     9,
      10,    11,    12,   211,   228,    13,    14,    15,    16,   206,
     198,    17,    18,     1,     2,    12,     3,   185,    13,    14,
      15,    16,   218,    84,    57,   220,    84,   201,     5,     6,
       7,   225,   198,     1,     2,     8,     3,     9,    10,    11,
      12,   121,   122,    13,    14,    15,    16,   181,   202,    17,
      18,     4,     5,     6,     7,     1,     2,   207,     3,   211,
      12,   127,   128,    13,    14,    15,    16,   226,   200,   111,
     227,   198,   223,     1,     2,   224,     3,   231,   198,   240,
       1,     2,    12,     3,   129,    13,    14,    15,    16,   239,
     198,   111,     5,     6,     7,     1,     2,   130,     3,   159,
      12,   157,   157,    13,    14,    15,    16,    12,   187,   164,
      13,    14,    15,    16,     1,     2,   151,     3,   123,   124,
     125,   126,    12,   189,   214,    13,    14,    15,    16,    95,
      86,   241,   198,   222,   166,   138,   205,    63,    98,     0,
       0,    12,     0,     0,    13,    14,    15,    16,     4,     5,
       6,     7,     4,     5,     6,     7,     0,   236,   208,     0,
       0,     0,   203,    16,     4,     5,     6,     7,     4,     5,
       6,     7,     0,   145,   175,     0,     0,   178,   208,    16,
       4,     5,     6,     7,     0,     0,     0,     0,     0,     0,
     237
};

static const yytype_int16 yycheck[] =
{
      33,    11,    12,   136,    87,    69,   140,    56,    91,     3,
     102,     0,   145,    49,     4,   160,     0,   146,    30,    39,
      84,     3,     3,    30,   107,    21,    22,    23,    24,    62,
      22,   105,    32,    32,    18,    31,    22,    23,    24,    39,
      39,   174,   187,    63,   189,    55,    40,   180,    30,    30,
      21,    22,    23,    24,    87,    39,    45,   140,    91,    49,
     193,    45,    52,   112,   113,   101,   195,    56,    22,   102,
     215,   216,    56,   218,   107,   220,   168,   151,   211,    63,
      72,    73,    32,    32,    30,   168,    30,   221,    14,    39,
      39,   224,    36,    36,    37,    49,    15,   242,     0,   182,
     133,   165,    40,     3,     8,     9,    30,   140,    12,    13,
     193,   101,   145,     3,   104,   105,    34,    35,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      30,    21,    22,    23,    24,   168,    36,    30,   221,    39,
      30,    31,    10,    11,     3,     4,    36,     6,    30,   182,
      31,   161,   162,   236,   108,   109,    31,     3,     3,    31,
     193,   151,    21,    22,    23,    24,    25,    38,    27,    28,
      29,    30,    39,    40,    33,    34,    35,    36,    31,    32,
      39,    40,    41,    30,    30,    30,     3,     4,   221,     6,
      36,    36,    30,    16,    17,    18,    19,    31,    32,    21,
      22,    23,    24,   236,    21,    22,    23,    24,    25,    31,
      27,    28,    29,    30,     3,    38,    33,    34,    35,    36,
      31,    32,    39,    40,    41,     3,     4,    30,     6,    22,
      23,    24,    21,    22,    23,    24,    31,    32,     3,     4,
      31,     6,    31,    21,    22,    23,    24,    25,    41,    27,
      28,    29,    30,    30,    31,    33,    34,    35,    36,    31,
      32,    39,    40,     3,     4,    30,     6,    31,    33,    34,
      35,    36,    31,    32,    39,    31,    32,    31,    22,    23,
      24,    31,    32,     3,     4,    25,     6,    27,    28,    29,
      30,    74,    75,    33,    34,    35,    36,    41,    31,    39,
      40,    21,    22,    23,    24,     3,     4,    31,     6,    30,
      30,    80,    81,    33,    34,    35,    36,    31,    32,    39,
      31,    32,     3,     3,     4,    30,     6,    31,    32,    26,
       3,     4,    30,     6,    82,    33,    34,    35,    36,    31,
      32,    39,    22,    23,    24,     3,     4,    83,     6,   109,
      30,   108,   109,    33,    34,    35,    36,    30,    31,   133,
      33,    34,    35,    36,     3,     4,   104,     6,    76,    77,
      78,    79,    30,    31,   182,    33,    34,    35,    36,    33,
       3,    31,    32,   198,     3,    95,   174,    18,    45,    -1,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    21,    22,
      23,    24,    21,    22,    23,    24,    -1,    30,    31,    -1,
      -1,    -1,    31,    36,    21,    22,    23,    24,    21,    22,
      23,    24,    -1,    30,    31,    -1,    -1,    30,    31,    36,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    21,    22,    23,    24,    25,    27,
      28,    29,    30,    33,    34,    35,    36,    39,    40,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    57,    58,    59,    63,    64,    76,    86,    87,    88,
      89,    90,    91,    97,    98,    99,   100,   101,   102,    30,
      63,     3,    40,    92,    94,    30,    30,    39,    57,    57,
      41,    58,    59,    88,    16,    17,    18,    19,    38,    56,
      45,    47,    36,    37,    34,    35,     8,     9,    12,    13,
      10,    11,    14,    15,    32,    39,     3,    30,    39,    60,
      61,    62,    70,    71,    72,    73,    76,    89,   101,     0,
      45,    63,    67,    80,    40,    65,    66,    67,    30,    30,
      57,    39,    58,    90,    39,    31,    73,    41,    54,    47,
      47,    48,    48,    49,    49,    49,    49,    50,    50,    51,
      52,    54,    70,    32,    39,    70,    30,    39,    87,     3,
      30,    74,    75,    31,    67,    30,    76,    81,    82,    83,
      31,    65,    41,    66,    68,    69,    70,    53,    55,    55,
      31,    90,    90,    31,    61,    38,     3,    31,    59,    77,
      78,    79,    70,    71,    30,    31,    77,    81,    30,    84,
      30,    41,    32,    39,    31,    31,    86,    31,    57,    31,
      57,    54,    85,    30,    70,    76,    81,    31,    32,    31,
      32,    31,    31,    31,    77,    79,    31,    31,    31,    77,
      84,    30,    31,    77,    69,    93,    95,    86,    31,    86,
      31,    30,    78,     3,    30,    31,    31,    31,    31,    31,
      77,    31,    86,    86,    86,    86,    30,    31,    77,    31,
      26,    31,    96,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    45,    45,    45,    45,
      46,    46,    46,    46,    47,    48,    48,    48,    49,    49,
      49,    50,    50,    50,    50,    50,    51,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    61,    63,    63,    63,    64,    64,    64,    65,    65,
      66,    67,    67,    68,    68,    69,    70,    70,    71,    71,
      72,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      74,    75,    75,    75,    76,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    84,    85,    86,
      86,    86,    86,    86,    87,    87,    87,    88,    88,    89,
      89,    90,    90,    92,    93,    91,    94,    95,    96,    91,
      97,    97,    97,    97,    97,    98,    98,    99,    99,   100,
     101,   101,   101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     2,     4,     4,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     1,     1,     3,     1,
       0,     4,     1,     1,     1,     5,     4,     2,     1,     2,
       3,     2,     1,     1,     3,     1,     1,     1,     2,     1,
       1,     3,     1,     4,     4,     3,     1,     3,     6,     5,
       1,     4,     4,     3,     1,     1,     3,     2,     2,     1,
       1,     3,     1,     2,     1,     1,     1,     2,     3,     2,
       3,     3,     4,     3,     2,     3,     3,     4,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     1,     2,     1,
       1,     1,     2,     0,     0,     7,     0,     0,     0,    10,
       5,     6,     7,     6,     7,     3,     2,     1,     2,     1,
       1,     1,     1,     3
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
#line 149 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *tmp = init_stack();
			tmp->push(tmp, (yyvsp[0].string));
			(yyval.stk) = tmp;}
#line 1540 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 154 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *tmp = init_stack();
			tmp->push(tmp, (yyvsp[0].string));
			(yyval.stk) = tmp;}
#line 1548 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 159 "structfe.y" /* yacc.c:1652  */
    { (yyval.stk) = (yyvsp[-1].stk);}
#line 1554 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 164 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1560 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 193 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1566 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 196 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *tmp = init_stack();
			tmp->push(tmp, (yyvsp[-1].string));
			tmp->push_stack(tmp, (yyvsp[0].stk));
			(yyval.stk) = tmp;}
#line 1575 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 203 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "4");
			(yyval.stk) = stk;}
#line 1583 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 208 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "4");
			(yyval.stk) = stk;}
#line 1591 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 215 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "&";}
#line 1597 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 218 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1603 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 221 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "+";}
#line 1609 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 224 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "-";}
#line 1615 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 229 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1621 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 240 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1627 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 243 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "*");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1637 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 250 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "/");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1647 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 259 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1653 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 262 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "+");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1663 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 269 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "-");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1673 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 278 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1679 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 281 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1689 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 288 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1699 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 295 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1709 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 302 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1719 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 311 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1725 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 314 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1735 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 321 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1745 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 330 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1751 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 333 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1761 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 342 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1767 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 345 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1777 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 354 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1783 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 360 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, (yyvsp[-1].string));
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1793 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 369 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = (yyvsp[0].stk);}
#line 1799 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 373 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "=";}
#line 1805 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 374 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1811 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 375 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1817 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 376 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1823 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 377 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1829 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 382 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "expr");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1838 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 387 "structfe.y" /* yacc.c:1652  */
    { struct stack_t *stk = init_stack();
			stk->push(stk, "expr");
			stk->push_stack(stk, (yyvsp[-2].stk));
			stk->push(stk, ";");
			stk->push(stk, "expr");
			stk->push_stack(stk, (yyvsp[0].stk));
			(yyval.stk) = stk;}
#line 1850 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 398 "structfe.y" /* yacc.c:1652  */
    {decl->push(decl, "declaration");}
#line 1856 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 401 "structfe.y" /* yacc.c:1652  */
    {decl->push(decl, "declaration");}
#line 1862 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 419 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "=");}
#line 1868 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 424 "structfe.y" /* yacc.c:1652  */
    {decl->push(decl, "void");
		(yyval.string) = "void";}
#line 1875 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 428 "structfe.y" /* yacc.c:1652  */
    {decl->push(decl, "int");
		(yyval.string) = "int";}
#line 1882 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 432 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "struct";}
#line 1888 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 481 "structfe.y" /* yacc.c:1652  */
    {decl->push(decl, (yyvsp[0].string));}
#line 1894 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 495 "structfe.y" /* yacc.c:1652  */
    {char *tmp = (char *) calloc (strlen((yyvsp[0].string)) + 2, 1);
			sprintf(tmp, "*%s", (yyvsp[0].string));
			decl->push(decl, tmp);}
#line 1902 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 525 "structfe.y" /* yacc.c:1652  */
    {(yyval.string) = "*";}
#line 1908 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 121:
#line 621 "structfe.y" /* yacc.c:1652  */
    {(yyval.stk) = stmt;}
#line 1914 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 122:
#line 623 "structfe.y" /* yacc.c:1652  */
    { stmt->push_stack(stmt, (yyvsp[-1].stk));
			stmt->push(stmt, ";");
	    (yyval.stk) = stmt;}
#line 1922 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 123:
#line 629 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "if");}
#line 1928 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 124:
#line 630 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "then");}
#line 1934 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 125:
#line 631 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endif");}
#line 1940 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 126:
#line 633 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "ifelse");}
#line 1946 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 127:
#line 634 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "then");}
#line 1952 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 128:
#line 636 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "else");}
#line 1958 "structfe.tab.c" /* yacc.c:1652  */
    break;

  case 129:
#line 637 "structfe.y" /* yacc.c:1652  */
    {stmt->push(stmt, "endif");}
#line 1964 "structfe.tab.c" /* yacc.c:1652  */
    break;


#line 1968 "structfe.tab.c" /* yacc.c:1652  */
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
#line 695 "structfe.y" /* yacc.c:1918  */


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
	decl = init_stack();
	stmt = init_stack();
	ct = init_crpcdt();
	buf_decl = init_buf();
	buf_stmt = init_buf();
	vx = 0;
	lx = 0;

	fname = strdup(argv[1]);
	if ((yyin = fopen(argv[1], "r")) == NULL)
	{
		yyerror("[E] File not found\n");
		exit(2);
	} else {
		yyparse();
		declaration(decl, ct, buf_decl, &vx, 0);
		statements(decl, stmt, ct, buf_decl, buf_stmt, &vx, &lx, 0, stmt->size, 0);

		if (strlen(buf_decl->string))
		{
			buf_decl->add(buf_decl, "\n");
		}

		printf("\n----------------------\n%s%s", buf_decl->string, buf_stmt->string);
		printf("Success.\n");
	}
	return 0;
}
