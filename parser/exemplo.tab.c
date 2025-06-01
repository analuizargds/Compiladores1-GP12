/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exemplo.y"

#include <stdio.h>
#include <stdlib.h>
#include "simbolos.h"

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;

#line 81 "exemplo.tab.c"

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

#include "exemplo.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_SWITCH = 6,                     /* SWITCH  */
  YYSYMBOL_CASE = 7,                       /* CASE  */
  YYSYMBOL_DEFAULT = 8,                    /* DEFAULT  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_DO = 12,                        /* DO  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_ID = 15,                        /* ID  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_MULT = 25,                      /* MULT  */
  YYSYMBOL_DIV = 26,                       /* DIV  */
  YYSYMBOL_MOD = 27,                       /* MOD  */
  YYSYMBOL_COLON = 28,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_STRING = 34,                    /* STRING  */
  YYSYMBOL_COMMA = 35,                     /* COMMA  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_INT = 37,                       /* INT  */
  YYSYMBOL_FLOAT = 38,                     /* FLOAT  */
  YYSYMBOL_CHAR = 39,                      /* CHAR  */
  YYSYMBOL_VOID = 40,                      /* VOID  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CHAR_LITERAL = 42,              /* CHAR_LITERAL  */
  YYSYMBOL_STRUCT = 43,                    /* STRUCT  */
  YYSYMBOL_UNION = 44,                     /* UNION  */
  YYSYMBOL_ENUM = 45,                      /* ENUM  */
  YYSYMBOL_TYPEDEF = 46,                   /* TYPEDEF  */
  YYSYMBOL_HEX = 47,                       /* HEX  */
  YYSYMBOL_CARACT = 48,                    /* CARACT  */
  YYSYMBOL_INCREMENT = 49,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 50,                 /* DECREMENT  */
  YYSYMBOL_PLUS_ASSIGN = 51,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 52,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 53,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 54,                /* DIV_ASSIGN  */
  YYSYMBOL_AND = 55,                       /* AND  */
  YYSYMBOL_OR = 56,                        /* OR  */
  YYSYMBOL_NOT = 57,                       /* NOT  */
  YYSYMBOL_BITAND = 58,                    /* BITAND  */
  YYSYMBOL_BITOR = 59,                     /* BITOR  */
  YYSYMBOL_BITXOR = 60,                    /* BITXOR  */
  YYSYMBOL_BITNOT = 61,                    /* BITNOT  */
  YYSYMBOL_SHIFTLEFT = 62,                 /* SHIFTLEFT  */
  YYSYMBOL_SHIFTRIGHT = 63,                /* SHIFTRIGHT  */
  YYSYMBOL_UMINUS = 64,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 65,                     /* UPLUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 66,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 67,                  /* $accept  */
  YYSYMBOL_programa = 68,                  /* programa  */
  YYSYMBOL_69_1 = 69,                      /* $@1  */
  YYSYMBOL_lista_declaracoes = 70,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 71,                /* declaracao  */
  YYSYMBOL_declaracao_tipo = 72,           /* declaracao_tipo  */
  YYSYMBOL_switch_stmt = 73,               /* switch_stmt  */
  YYSYMBOL_for_init = 74,                  /* for_init  */
  YYSYMBOL_for_parer = 75,                 /* for_parer  */
  YYSYMBOL_for_stmt = 76,                  /* for_stmt  */
  YYSYMBOL_do_stmt = 77,                   /* do_stmt  */
  YYSYMBOL_continue_stmt = 78,             /* continue_stmt  */
  YYSYMBOL_case_list = 79,                 /* case_list  */
  YYSYMBOL_case_stmt = 80,                 /* case_stmt  */
  YYSYMBOL_comandos_break = 81,            /* comandos_break  */
  YYSYMBOL_comandos_opt = 82,              /* comandos_opt  */
  YYSYMBOL_declaracao_variavel = 83,       /* declaracao_variavel  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_tipo = 85,                      /* tipo  */
  YYSYMBOL_lista_variaveis = 86,           /* lista_variaveis  */
  YYSYMBOL_variavel = 87,                  /* variavel  */
  YYSYMBOL_fun_declaracao = 88,            /* fun_declaracao  */
  YYSYMBOL_89_3 = 89,                      /* $@3  */
  YYSYMBOL_parametros = 90,                /* parametros  */
  YYSYMBOL_lista_parametros = 91,          /* lista_parametros  */
  YYSYMBOL_param = 92,                     /* param  */
  YYSYMBOL_inicializador = 93,             /* inicializador  */
  YYSYMBOL_lista_inicializadores = 94,     /* lista_inicializadores  */
  YYSYMBOL_stmt = 95,                      /* stmt  */
  YYSYMBOL_expr_stmt = 96,                 /* expr_stmt  */
  YYSYMBOL_composto_stmt = 97,             /* composto_stmt  */
  YYSYMBOL_if_stmt = 98,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 99,                /* while_stmt  */
  YYSYMBOL_return_stmt = 100,              /* return_stmt  */
  YYSYMBOL_expr = 101,                     /* expr  */
  YYSYMBOL_atrib_expr = 102,               /* atrib_expr  */
  YYSYMBOL_or_expr = 103,                  /* or_expr  */
  YYSYMBOL_and_expr = 104,                 /* and_expr  */
  YYSYMBOL_bitor_expr = 105,               /* bitor_expr  */
  YYSYMBOL_bitxor_expr = 106,              /* bitxor_expr  */
  YYSYMBOL_bitand_expr = 107,              /* bitand_expr  */
  YYSYMBOL_equal_expr = 108,               /* equal_expr  */
  YYSYMBOL_relacao_expr = 109,             /* relacao_expr  */
  YYSYMBOL_shift_expr = 110,               /* shift_expr  */
  YYSYMBOL_add_expr = 111,                 /* add_expr  */
  YYSYMBOL_mult_expr = 112,                /* mult_expr  */
  YYSYMBOL_unary_expr = 113,               /* unary_expr  */
  YYSYMBOL_fator = 114,                    /* fator  */
  YYSYMBOL_var = 115,                      /* var  */
  YYSYMBOL_chamada = 116,                  /* chamada  */
  YYSYMBOL_argumentos = 117,               /* argumentos  */
  YYSYMBOL_lista_args = 118,               /* lista_args  */
  YYSYMBOL_struct_declaracao = 119,        /* struct_declaracao  */
  YYSYMBOL_union_declaracao = 120,         /* union_declaracao  */
  YYSYMBOL_enum_declaracao = 121,          /* enum_declaracao  */
  YYSYMBOL_typedef_declaracao = 122,       /* typedef_declaracao  */
  YYSYMBOL_lista_identificadores = 123     /* lista_identificadores  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    62,    68,    69,    73,    74,    75,    76,
      80,    81,    82,    83,    87,    91,    92,    93,    97,    98,
     102,   106,   110,   115,   116,   120,   121,   125,   128,   130,
     135,   134,   142,   143,   144,   145,   146,   147,   148,   149,
     153,   154,   158,   167,   176,   188,   187,   203,   204,   208,
     209,   213,   224,   228,   229,   230,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   246,   247,   251,   252,   256,
     257,   261,   265,   266,   270,   274,   275,   276,   277,   278,
     279,   283,   284,   288,   289,   293,   294,   298,   299,   303,
     304,   308,   309,   310,   314,   315,   316,   317,   318,   322,
     323,   324,   328,   329,   330,   334,   335,   336,   337,   341,
     342,   343,   344,   345,   346,   347,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   364,   371,   375,   379,
     380,   384,   385,   389,   393,   397,   401,   405,   406
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "IF", "ELSE",
  "SWITCH", "CASE", "DEFAULT", "BREAK", "WHILE", "RETURN", "DO", "FOR",
  "CONTINUE", "ID", "GE", "LE", "GT", "LT", "NE", "EQ", "ASSIGN", "PLUS",
  "MINUS", "MULT", "DIV", "MOD", "COLON", "SEMICOLON", "LBRACE", "RBRACE",
  "LPAREN", "RPAREN", "STRING", "COMMA", "DOT", "INT", "FLOAT", "CHAR",
  "VOID", "DOUBLE", "CHAR_LITERAL", "STRUCT", "UNION", "ENUM", "TYPEDEF",
  "HEX", "CARACT", "INCREMENT", "DECREMENT", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULT_ASSIGN", "DIV_ASSIGN", "AND", "OR", "NOT", "BITAND", "BITOR",
  "BITXOR", "BITNOT", "SHIFTLEFT", "SHIFTRIGHT", "UMINUS", "UPLUS",
  "LOWER_THAN_ELSE", "$accept", "programa", "$@1", "lista_declaracoes",
  "declaracao", "declaracao_tipo", "switch_stmt", "for_init", "for_parer",
  "for_stmt", "do_stmt", "continue_stmt", "case_list", "case_stmt",
  "comandos_break", "comandos_opt", "declaracao_variavel", "$@2", "tipo",
  "lista_variaveis", "variavel", "fun_declaracao", "$@3", "parametros",
  "lista_parametros", "param", "inicializador", "lista_inicializadores",
  "stmt", "expr_stmt", "composto_stmt", "if_stmt", "while_stmt",
  "return_stmt", "expr", "atrib_expr", "or_expr", "and_expr", "bitor_expr",
  "bitxor_expr", "bitand_expr", "equal_expr", "relacao_expr", "shift_expr",
  "add_expr", "mult_expr", "unary_expr", "fator", "var", "chamada",
  "argumentos", "lista_args", "struct_declaracao", "union_declaracao",
  "enum_declaracao", "typedef_declaracao", "lista_identificadores", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -73,    20,   421,   -73,   -73,    -6,    14,    29,   116,   473,
      39,     0,    53,   566,   566,   -73,   213,   566,   -73,   -73,
      37,   -73,   -73,   -73,   -73,    71,    74,    75,     4,   -73,
      76,    76,   566,   566,   421,   -73,   -73,   -73,   -73,   -73,
     -73,    63,    78,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
      65,   -73,    61,    40,    59,    60,    64,    10,    50,    -3,
      54,   -13,   -73,   -73,   -15,   -73,   -73,   -73,   -73,   -73,
     566,   566,   566,   -73,   -73,    92,   113,   501,   -73,   566,
     -73,   -17,   -73,   -73,   265,    91,    96,    97,    98,   -73,
     114,   115,   117,   118,   -73,    99,    99,   -73,   -73,   -73,
     -73,   102,   121,   -73,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   566,   566,   566,   566,   566,   566,   566,
     566,   566,   566,   122,   -73,   -73,   566,   566,   566,   566,
     105,   108,   109,   -73,   111,   120,   -73,   -73,   -73,   -73,
     119,   124,   -73,   -73,   421,   421,   129,   -73,   -73,   -73,
     128,     4,   131,   125,   -73,    40,    59,    60,    64,    10,
      50,    50,    -3,    -3,    -3,    -3,    54,    54,   -13,   -13,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   473,
     132,   473,   566,   566,   -73,   566,   317,   369,   -73,   -20,
     -73,   136,   134,   126,   -73,   544,   121,   159,    72,   -73,
     135,   140,   -73,   -73,   142,   145,   150,   165,   -73,   -73,
       4,   566,   -73,   -73,   -73,   473,   566,   153,     9,   -73,
     154,   566,   -73,   -73,   -73,   -73,   152,   -73,    27,   -73,
     -73,   157,   421,   -73,   -73,   -73,   156,   -73,   -73,   566,
     421,   421,   -73,   177,   473,   -73,   -73,   158,   -73,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,   121,     0,     0,     0,     0,     0,
       0,     0,   126,     0,     0,    66,     0,     0,   125,    32,
     122,    34,    35,    36,   124,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     3,     5,     9,    61,    63,    62,
      64,     0,     0,     7,     8,    56,    57,    58,    59,    60,
       0,    74,    75,    81,    83,    85,    87,    89,    91,    94,
      99,   102,   105,   109,   117,   118,    10,    11,    12,    13,
       0,     0,     0,    73,   122,     0,     0,    17,    22,   130,
     115,   117,   114,    68,     0,     0,    37,    38,    39,    33,
       0,     0,     0,     0,   126,   110,   111,   112,   113,     4,
       6,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,    16,    30,    15,   132,
       0,   129,    67,   116,     0,     0,     0,    37,    38,    39,
       0,    48,    42,    31,    40,    82,    84,    86,    88,    90,
      93,    92,    97,    98,    95,    96,   100,   101,   103,   104,
     106,   107,   108,    76,   127,    77,    78,    79,    80,     0,
       0,     0,     0,    19,   128,     0,     0,     0,   137,     0,
     136,     0,     0,    47,    50,     0,     0,    69,     0,    71,
       0,     0,    18,   131,     0,     0,     0,     0,    51,    45,
       0,    55,    44,    43,    41,     0,     0,     0,     0,    24,
       0,    19,   133,   134,   135,   138,     0,    49,     0,    53,
      70,     0,    28,    14,    23,    21,     0,    46,    52,     0,
      28,    29,    26,     0,     0,    54,    25,     0,    20,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,     2,   -31,   -73,   -73,   -73,   -29,   -73,
     -73,   -73,   -73,   -27,   -50,   -73,   123,   -73,   -26,   -73,
      -2,   -73,   -73,   -73,   -73,   -14,   -73,   -73,    -9,   -73,
     -33,   -73,   -73,   -73,    -7,   -72,   -73,    93,    90,    95,
     100,    94,   -28,   -38,   -32,   -30,    -5,   -73,    -8,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   241,    35,    36,    37,   135,   201,    38,
      39,    40,   218,   219,   242,   243,    41,   102,    42,   153,
     154,    43,   226,   192,   193,   194,   212,   228,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     140,   141,    66,    67,    68,    69,   189
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    75,    93,    99,    34,    81,    81,   122,    80,    82,
      85,   206,   119,   120,   121,   207,   216,   217,    84,   123,
       3,   123,    95,    96,    81,    81,    70,    97,    98,    78,
     109,   110,   124,   125,   124,   125,   126,   127,   128,   129,
     233,    19,    89,    21,    22,    23,    71,    90,    91,    92,
     173,   137,   -33,    99,   175,   176,   177,   178,   238,   115,
     116,    72,   239,   130,   131,   132,   111,   112,   113,   114,
     138,    77,   139,   162,   163,   164,   165,   117,   118,   216,
     217,   160,   161,   166,   167,    79,    86,   168,   169,    87,
      88,    94,   100,   101,   103,   105,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,   170,   171,   172,   104,   106,     4,
     107,   133,   108,   134,   143,   191,   144,   145,   146,   147,
     148,    12,   149,   150,   151,   123,   152,   174,   179,    13,
      14,   180,   181,   182,   188,    73,   186,   187,    17,   183,
      18,   208,   184,   195,    74,    99,    99,   190,    24,   185,
     196,   210,   198,    29,   215,    30,    31,   209,   220,   221,
     197,   222,   199,    32,   223,   200,   202,    33,   203,   224,
     225,   232,    16,   235,   191,   240,   247,   249,   213,   244,
     246,   234,   236,   237,   214,   156,   227,   155,     0,     0,
     136,   157,   159,     0,   229,     0,   230,   158,     0,   231,
      99,     0,     0,     0,   202,     0,     4,     5,     0,     6,
       0,     0,     0,     7,     8,     9,    10,    11,    12,     0,
       0,     0,   245,     0,     0,   248,    13,    14,     0,     0,
       0,     0,    15,    16,    83,    17,     0,    18,     0,     0,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,     0,     0,     0,     0,     4,     5,
      32,     6,     0,     0,    33,     7,     8,     9,    10,    11,
      12,     0,     0,     0,     0,     0,     0,     0,    13,    14,
       0,     0,     0,     0,    15,    16,   142,    17,     0,    18,
       0,     0,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,    31,     0,     0,     0,     0,
       4,     5,    32,     6,     0,     0,    33,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
      13,    14,     0,     0,     0,     0,    15,    16,   204,    17,
       0,    18,     0,     0,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,    30,    31,     0,     0,
       0,     0,     4,     5,    32,     6,     0,     0,    33,     7,
       8,     9,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,    13,    14,     0,     0,     0,     0,    15,    16,
     205,    17,     0,    18,     0,     0,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,    30,    31,
       0,     0,     0,     0,     4,     5,    32,     6,     0,     0,
      33,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,     0,     0,     0,    13,    14,     0,     0,     0,     0,
      15,    16,     0,    17,     0,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    31,     0,     0,     0,     0,     4,     5,    32,     6,
       0,     0,    33,     7,     8,     9,    10,    11,    12,     0,
       0,     0,     0,     0,     0,     0,    13,    14,     0,     0,
       0,     0,    15,    16,     4,    17,     0,    18,     0,     0,
       0,    74,     0,     0,     0,    24,    12,     0,     0,     0,
      29,     0,    30,    31,    13,    14,     0,     0,     0,     0,
      32,     0,     0,    17,    33,    18,     0,     0,    19,    20,
      21,    22,    23,    24,    90,    91,    92,     4,    29,     0,
      30,    31,     0,     0,     0,     0,     0,     0,    32,    12,
       0,     0,    33,     0,     0,     0,     0,    13,    14,     4,
       0,     0,     0,     0,   211,     0,    17,     0,    18,     0,
       0,    12,    74,     0,     0,     0,    24,     0,     0,    13,
      14,    29,     0,    30,    31,     0,     0,     0,    17,     0,
      18,    32,     0,     0,    74,    33,     0,     0,    24,     0,
       0,     0,     0,    29,     0,    30,    31,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,    33
};

static const yytype_int16 yycheck[] =
{
       9,     8,    28,    34,     2,    13,    14,    22,    13,    14,
      17,    31,    25,    26,    27,    35,     7,     8,    16,    36,
       0,    36,    30,    31,    32,    33,    32,    32,    33,    29,
      20,    21,    49,    50,    49,    50,    51,    52,    53,    54,
      31,    37,    38,    39,    40,    41,    32,    43,    44,    45,
     122,    77,    15,    84,   126,   127,   128,   129,    31,    62,
      63,    32,    35,    70,    71,    72,    16,    17,    18,    19,
      77,    32,    79,   111,   112,   113,   114,    23,    24,     7,
       8,   109,   110,   115,   116,    32,    15,   117,   118,    15,
      15,    15,    29,    15,    29,    55,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   119,   120,   121,    56,    59,     3,
      60,    29,    58,    10,    33,   151,    30,    30,    30,    15,
      15,    15,    15,    15,    32,    36,    15,    15,    33,    23,
      24,    33,    33,    32,    15,    29,   144,   145,    32,    29,
      34,    15,    33,    22,    38,   186,   187,    29,    42,    35,
      35,    35,    30,    47,     5,    49,    50,    33,    33,    29,
     179,    29,   181,    57,    29,   182,   183,    61,   185,    29,
      15,    28,    30,    29,   210,    28,     9,    29,   195,    33,
     240,   218,   221,   226,   196,   105,   210,   104,    -1,    -1,
      77,   106,   108,    -1,   211,    -1,   215,   107,    -1,   216,
     241,    -1,    -1,    -1,   221,    -1,     3,     4,    -1,     6,
      -1,    -1,    -1,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,   239,    -1,    -1,   244,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,     3,     4,
      57,     6,    -1,    -1,    61,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
       3,     4,    57,     6,    -1,    -1,    61,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,     3,     4,    57,     6,    -1,    -1,    61,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,     3,     4,    57,     6,    -1,    -1,
      61,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,     3,     4,    57,     6,
      -1,    -1,    61,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,     3,    32,    -1,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    15,    -1,    -1,    -1,
      47,    -1,    49,    50,    23,    24,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    32,    61,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     3,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    15,
      -1,    -1,    61,    -1,    -1,    -1,    -1,    23,    24,     3,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    34,    -1,
      -1,    15,    38,    -1,    -1,    -1,    42,    -1,    -1,    23,
      24,    47,    -1,    49,    50,    -1,    -1,    -1,    32,    -1,
      34,    57,    -1,    -1,    38,    61,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    68,    69,     0,     3,     4,     6,    10,    11,    12,
      13,    14,    15,    23,    24,    29,    30,    32,    34,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      49,    50,    57,    61,    70,    71,    72,    73,    76,    77,
      78,    83,    85,    88,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   119,   120,   121,   122,
      32,    32,    32,    29,    38,   101,    95,    32,    29,    32,
     113,   115,   113,    31,    70,   101,    15,    15,    15,    38,
      43,    44,    45,    85,    15,   115,   115,   113,   113,    71,
      29,    15,    84,    29,    56,    55,    59,    60,    58,    20,
      21,    16,    17,    18,    19,    62,    63,    23,    24,    25,
      26,    27,    22,    36,    49,    50,    51,    52,    53,    54,
     101,   101,   101,    29,    10,    74,    83,    85,   101,   101,
     117,   118,    31,    33,    30,    30,    30,    15,    15,    15,
      15,    32,    15,    86,    87,   104,   105,   106,   107,   108,
     109,   109,   110,   110,   110,   110,   111,   111,   112,   112,
     113,   113,   113,   102,    15,   102,   102,   102,   102,    33,
      33,    33,    32,    29,    33,    35,    70,    70,    15,   123,
      29,    85,    90,    91,    92,    22,    35,    95,    30,    95,
     101,    75,   101,   101,    31,    31,    31,    35,    15,    33,
      35,    30,    93,   101,    87,     5,     7,     8,    79,    80,
      33,    29,    29,    29,    29,    15,    89,    92,    94,   101,
      95,   101,    28,    31,    80,    29,    75,    97,    31,    35,
      28,    70,    81,    82,    33,   101,    81,     9,    95,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    67,    69,    68,    70,    70,    71,    71,    71,    71,
      72,    72,    72,    72,    73,    74,    74,    74,    75,    75,
      76,    77,    78,    79,    79,    80,    80,    81,    82,    82,
      84,    83,    85,    85,    85,    85,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    89,    88,    90,    90,    91,
      91,    92,    93,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    99,   100,   100,   101,   102,   102,   102,   102,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   109,   109,   109,   109,   109,   110,
     110,   110,   111,   111,   111,   112,   112,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   117,
     117,   118,   118,   119,   120,   121,   122,   123,   123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     7,     1,     1,     0,     1,     0,
       9,     7,     2,     2,     1,     4,     3,     3,     0,     1,
       0,     3,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     3,     1,     3,     3,     0,     7,     1,     0,     3,
       1,     2,     3,     1,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     2,     5,
       7,     5,     3,     2,     1,     1,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     1,
       0,     3,     1,     6,     6,     6,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* $@1: %empty  */
#line 62 "exemplo.y"
       { iniciarTabelaSimbolos(); }
#line 1448 "exemplo.tab.c"
    break;

  case 3: /* programa: $@1 lista_declaracoes  */
#line 64 "exemplo.y"
       { imprimirTabelaSimbolos(); finalizarTabelaSimbolos(); }
#line 1454 "exemplo.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 135 "exemplo.y"
    {
        tipoDeclaracaoAtual = (yyvsp[0].intValue);
    }
#line 1462 "exemplo.tab.c"
    break;

  case 32: /* tipo: INT  */
#line 142 "exemplo.y"
                { (yyval.intValue) = TIPO_INT; }
#line 1468 "exemplo.tab.c"
    break;

  case 33: /* tipo: FLOAT  */
#line 143 "exemplo.y"
                { (yyval.intValue) = TIPO_FLOAT; }
#line 1474 "exemplo.tab.c"
    break;

  case 34: /* tipo: CHAR  */
#line 144 "exemplo.y"
                { (yyval.intValue) = TIPO_ERRO; }
#line 1480 "exemplo.tab.c"
    break;

  case 35: /* tipo: VOID  */
#line 145 "exemplo.y"
                { (yyval.intValue) = TIPO_ERRO; }
#line 1486 "exemplo.tab.c"
    break;

  case 36: /* tipo: DOUBLE  */
#line 146 "exemplo.y"
                { (yyval.intValue) = TIPO_ERRO; }
#line 1492 "exemplo.tab.c"
    break;

  case 37: /* tipo: STRUCT ID  */
#line 147 "exemplo.y"
                { (yyval.intValue) = TIPO_ERRO; }
#line 1498 "exemplo.tab.c"
    break;

  case 38: /* tipo: UNION ID  */
#line 148 "exemplo.y"
                { (yyval.intValue) = TIPO_ERRO; }
#line 1504 "exemplo.tab.c"
    break;

  case 39: /* tipo: ENUM ID  */
#line 149 "exemplo.y"
                { (yyval.intValue) = TIPO_ERRO; }
#line 1510 "exemplo.tab.c"
    break;

  case 42: /* variavel: ID  */
#line 159 "exemplo.y"
    {
        if (buscarSimboloNoEscopoAtual((yyvsp[0].strValue)) != NULL) {
            yyerror("Erro: Redeclaração de variável no mesmo escopo");
        } else {
            inserirSimbolo((yyvsp[0].strValue), tipoDeclaracaoAtual);
        }
    }
#line 1522 "exemplo.tab.c"
    break;

  case 43: /* variavel: ID ASSIGN expr  */
#line 168 "exemplo.y"
    {
        if (buscarSimboloNoEscopoAtual((yyvsp[-2].strValue)) != NULL) {
            yyerror("Erro: Redeclaração de variável no mesmo escopo");
        } else {
            inserirSimbolo((yyvsp[-2].strValue), tipoDeclaracaoAtual);
        }
    }
#line 1534 "exemplo.tab.c"
    break;

  case 44: /* variavel: ID ASSIGN inicializador  */
#line 177 "exemplo.y"
    {
        if (buscarSimboloNoEscopoAtual((yyvsp[-2].strValue)) != NULL) {
            yyerror("Erro: Redeclaração de variável no mesmo escopo");
        } else {
            inserirSimbolo((yyvsp[-2].strValue), tipoDeclaracaoAtual);
        }
    }
#line 1546 "exemplo.tab.c"
    break;

  case 45: /* $@3: %empty  */
#line 188 "exemplo.y"
    {
        if (buscarSimboloNoEscopoAtual((yyvsp[-3].strValue)) != NULL) {
            yyerror("Erro: Função já declarada");
        } else {
            inserirSimbolo((yyvsp[-3].strValue), (yyvsp[-4].intValue)); // $1 = tipo de retorno
        }
        iniciarEscopo();
    }
#line 1559 "exemplo.tab.c"
    break;

  case 46: /* fun_declaracao: tipo ID LPAREN parametros RPAREN $@3 composto_stmt  */
#line 197 "exemplo.y"
    {
        finalizarEscopo();
    }
#line 1567 "exemplo.tab.c"
    break;

  case 51: /* param: tipo ID  */
#line 214 "exemplo.y"
    {
        if (buscarSimboloNoEscopoAtual((yyvsp[0].strValue)) != NULL) {
            yyerror("Erro: Parâmetro já declarado");
        } else {
            inserirSimbolo((yyvsp[0].strValue), (yyvsp[-1].intValue)); // $1 = tipo do parâmetro
        }
    }
#line 1579 "exemplo.tab.c"
    break;

  case 126: /* var: ID  */
#line 365 "exemplo.y"
    {
        if (buscarSimbolo((yyvsp[0].strValue)) == NULL) {
            yyerror("Erro: Variável usada sem declaração");
        }
    }
#line 1589 "exemplo.tab.c"
    break;


#line 1593 "exemplo.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 410 "exemplo.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}
