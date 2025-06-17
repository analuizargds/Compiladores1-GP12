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
#include "../ast/ast.h"
#include "../semantic/semantic.h"

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;
extern int yylineno;
ASTNode* root;

// Função para reportar erros de construções não suportadas
void report_unsupported_feature(const char* feature, int line) {
    fprintf(stderr, "Erro na linha %d: %s não é suportado nesta versão do compilador\n", line, feature);
}

#line 89 "exemplo.tab.c"

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
  YYSYMBOL_LBRACKET = 64,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 65,                  /* RBRACKET  */
  YYSYMBOL_INCLUDE = 66,                   /* INCLUDE  */
  YYSYMBOL_POINTER = 67,                   /* POINTER  */
  YYSYMBOL_AMPERSAND = 68,                 /* AMPERSAND  */
  YYSYMBOL_UMINUS = 69,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 70,                     /* UPLUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 71,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_72_ = 72,                       /* '['  */
  YYSYMBOL_73_ = 73,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_programa = 75,                  /* programa  */
  YYSYMBOL_lista_declaracoes = 76,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 77,                /* declaracao  */
  YYSYMBOL_declaracao_tipo = 78,           /* declaracao_tipo  */
  YYSYMBOL_switch_stmt = 79,               /* switch_stmt  */
  YYSYMBOL_for_stmt = 80,                  /* for_stmt  */
  YYSYMBOL_do_stmt = 81,                   /* do_stmt  */
  YYSYMBOL_continue_stmt = 82,             /* continue_stmt  */
  YYSYMBOL_case_list = 83,                 /* case_list  */
  YYSYMBOL_case_stmt = 84,                 /* case_stmt  */
  YYSYMBOL_comandos_break = 85,            /* comandos_break  */
  YYSYMBOL_comandos_opt = 86,              /* comandos_opt  */
  YYSYMBOL_declaracao_variavel = 87,       /* declaracao_variavel  */
  YYSYMBOL_tipo = 88,                      /* tipo  */
  YYSYMBOL_lista_variaveis = 89,           /* lista_variaveis  */
  YYSYMBOL_variavel = 90,                  /* variavel  */
  YYSYMBOL_fun_declaracao = 91,            /* fun_declaracao  */
  YYSYMBOL_parametros = 92,                /* parametros  */
  YYSYMBOL_lista_parametros = 93,          /* lista_parametros  */
  YYSYMBOL_param = 94,                     /* param  */
  YYSYMBOL_inicializador = 95,             /* inicializador  */
  YYSYMBOL_lista_inicializadores = 96,     /* lista_inicializadores  */
  YYSYMBOL_stmt = 97,                      /* stmt  */
  YYSYMBOL_expr_stmt = 98,                 /* expr_stmt  */
  YYSYMBOL_composto_stmt = 99,             /* composto_stmt  */
  YYSYMBOL_if_stmt = 100,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 101,               /* while_stmt  */
  YYSYMBOL_return_stmt = 102,              /* return_stmt  */
  YYSYMBOL_expr = 103,                     /* expr  */
  YYSYMBOL_atrib_expr = 104,               /* atrib_expr  */
  YYSYMBOL_or_expr = 105,                  /* or_expr  */
  YYSYMBOL_and_expr = 106,                 /* and_expr  */
  YYSYMBOL_bitor_expr = 107,               /* bitor_expr  */
  YYSYMBOL_bitxor_expr = 108,              /* bitxor_expr  */
  YYSYMBOL_bitand_expr = 109,              /* bitand_expr  */
  YYSYMBOL_equal_expr = 110,               /* equal_expr  */
  YYSYMBOL_relacao_expr = 111,             /* relacao_expr  */
  YYSYMBOL_shift_expr = 112,               /* shift_expr  */
  YYSYMBOL_add_expr = 113,                 /* add_expr  */
  YYSYMBOL_mult_expr = 114,                /* mult_expr  */
  YYSYMBOL_unary_expr = 115,               /* unary_expr  */
  YYSYMBOL_fator = 116,                    /* fator  */
  YYSYMBOL_var = 117,                      /* var  */
  YYSYMBOL_chamada = 118,                  /* chamada  */
  YYSYMBOL_argumentos = 119,               /* argumentos  */
  YYSYMBOL_lista_args = 120,               /* lista_args  */
  YYSYMBOL_typedef_declaracao = 121,       /* typedef_declaracao  */
  YYSYMBOL_lista_identificadores = 122,    /* lista_identificadores  */
  YYSYMBOL_struct_declaracao = 123,        /* struct_declaracao  */
  YYSYMBOL_union_declaracao = 124,         /* union_declaracao  */
  YYSYMBOL_enum_declaracao = 125           /* enum_declaracao  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  291

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


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
       2,    72,     2,    73,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    92,    93,    97,    98,    99,   100,   101,
     108,   109,   110,   111,   115,   116,   123,   126,   144,   145,
     152,   156,   157,   161,   162,   163,   170,   171,   175,   176,
     180,   181,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   203,   204,   208,   209,   210,   211,   218,   219,   226,
     227,   231,   232,   236,   237,   244,   245,   252,   253,   254,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     274,   275,   279,   280,   281,   288,   289,   290,   297,   298,
     305,   306,   307,   314,   318,   319,   320,   326,   332,   338,
     344,   351,   352,   356,   357,   361,   362,   366,   367,   371,
     372,   376,   377,   378,   382,   383,   384,   385,   386,   390,
     391,   392,   396,   397,   398,   402,   403,   404,   405,   409,
     410,   411,   412,   413,   414,   415,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   432,   433,   434,   441,
     442,   449,   450,   454,   455,   456,   463,   464,   471,   472,
     476,   477,   484,   485,   492,   493
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
  "BITXOR", "BITNOT", "SHIFTLEFT", "SHIFTRIGHT", "LBRACKET", "RBRACKET",
  "INCLUDE", "POINTER", "AMPERSAND", "UMINUS", "UPLUS", "LOWER_THAN_ELSE",
  "'['", "']'", "$accept", "programa", "lista_declaracoes", "declaracao",
  "declaracao_tipo", "switch_stmt", "for_stmt", "do_stmt", "continue_stmt",
  "case_list", "case_stmt", "comandos_break", "comandos_opt",
  "declaracao_variavel", "tipo", "lista_variaveis", "variavel",
  "fun_declaracao", "parametros", "lista_parametros", "param",
  "inicializador", "lista_inicializadores", "stmt", "expr_stmt",
  "composto_stmt", "if_stmt", "while_stmt", "return_stmt", "expr",
  "atrib_expr", "or_expr", "and_expr", "bitor_expr", "bitxor_expr",
  "bitand_expr", "equal_expr", "relacao_expr", "shift_expr", "add_expr",
  "mult_expr", "unary_expr", "fator", "var", "chamada", "argumentos",
  "lista_args", "typedef_declaracao", "lista_identificadores",
  "struct_declaracao", "union_declaracao", "enum_declaracao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     689,    10,   -31,   -12,   -10,    19,   184,   845,    66,    31,
     -28,  1117,  1117,   -31,   481,  1117,   -31,   -31,     8,   -31,
     -31,   -31,   -31,    89,    93,   124,    41,   -31,   135,   135,
    1117,  1117,   162,   311,   -31,   -31,   -31,   -31,   -31,   -31,
     137,    72,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   138,
     -31,   114,   -27,   112,   113,   116,    49,   130,    81,    71,
     107,   -31,   -31,   247,   -31,   -31,   -31,   -31,   -31,   -31,
     911,  1117,   939,   143,   -31,   -31,   146,   147,   167,   975,
     -31,   875,  1117,   -31,     4,   -31,    26,   -31,   533,   148,
     152,   153,   154,   150,   -31,   171,   175,   178,    -9,   129,
     160,   160,   -31,   -31,   -31,   -31,   -31,   -31,    61,   -31,
     163,   -31,   -31,  1117,  1117,  1117,  1117,  1117,  1117,  1117,
    1117,  1117,  1117,  1117,  1117,  1117,  1117,  1117,  1117,  1117,
    1117,   -31,  1117,   187,   -31,   -31,  1117,  1117,  1117,  1117,
     170,   172,   173,   176,   179,   -31,   -31,   -31,   182,   186,
     188,   190,   -31,   191,   169,   142,   -31,   -31,   -31,   741,
     793,    17,   -31,   -31,   -31,   -31,   192,   -31,  1089,    62,
     196,   -27,   112,   113,   116,    49,   130,   130,    81,    81,
      81,    81,    71,    71,   107,   107,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   845,   845,    13,   845,   845,
    1003,   845,  1117,   -31,   -31,  1039,   -31,    60,   585,   111,
     637,   189,   -31,    37,   -31,    14,   -31,   -31,   126,   194,
     193,   -31,    12,   -31,   -31,   224,   -31,   149,   -31,   -31,
     197,   199,   -31,   206,   -31,   -31,   207,   208,   209,   210,
     211,   213,   229,   216,    57,   -31,   -31,   -31,    20,    62,
     845,  1067,   221,    28,   -31,   222,   225,  1117,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,  1117,   -31,   -31,
     -31,   -31,   227,   228,   370,   -31,   -31,   -31,   -31,   217,
     -31,   -31,   370,   429,   -31,   248,   845,   -31,   230,   -31,
     -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   126,     0,     0,     0,     0,     0,     0,     0,
     136,     0,     0,    71,     0,     0,   130,    32,   127,    34,
      35,    36,   128,     0,     0,     0,     0,   129,     0,     0,
       0,     0,     0,     0,     4,     8,    65,    67,    66,    68,
       0,     0,     6,     7,    60,    61,    62,    63,    64,     0,
      83,    84,    91,    93,    95,    97,    99,   101,   104,   109,
     112,   115,   119,     0,   132,    13,    10,    11,    12,     9,
       0,     0,     0,     0,    81,   127,     0,     0,     0,     0,
      20,     0,     0,   123,   131,   122,     0,    73,     0,     0,
      37,    38,    39,     0,    33,     0,     0,     0,     0,   136,
     120,   121,   124,   125,     1,     3,     5,    31,     0,    40,
      30,    41,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    80,    69,     0,     0,
       0,     0,   144,     0,   141,     0,    74,    72,   133,     0,
       0,     0,   147,    37,    38,    39,     0,    46,     0,    50,
       0,    92,    94,    96,    98,   100,   103,   102,   107,   108,
     105,   106,   110,   111,   113,   114,   116,   117,   118,    85,
     137,    86,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   139,     0,   138,     0,     0,     0,
       0,     0,   148,     0,   146,     0,    45,    44,     0,     0,
      49,    52,     0,    42,    77,    75,    15,     0,    79,    78,
       0,     0,    17,     0,   145,   143,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    54,    53,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,   151,   150,
     153,   152,   155,   154,   149,    56,    55,     0,    48,    47,
      51,    76,     0,     0,     0,    14,    21,    19,    18,     0,
      58,    25,     0,     0,    24,    27,     0,    23,     0,    16,
      26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -31,   -31,     5,   -30,   -31,   -31,   -31,   -31,   -31,   -31,
       7,   -21,   -31,   -31,   -24,   -31,    88,   -31,   -31,   -31,
      35,   -31,   -31,    -7,   -31,    29,   -31,   -31,   -31,    -5,
      -1,   -31,   168,   174,   177,   200,   201,    40,    32,    36,
      42,     0,   -31,    -4,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    32,   283,    34,    35,    36,    37,    38,    39,   253,
     254,   284,   285,    40,    41,   110,   111,    42,   219,   220,
     221,   216,   244,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   153,   154,    65,   213,    66,
      67,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    76,    98,   105,    81,    33,   166,    84,    84,   -33,
      89,    83,    85,   167,   226,   243,   109,     2,   211,    88,
      70,   268,    71,   -33,   100,   101,    84,    84,   114,    10,
     102,   103,   212,   -33,   168,   251,   252,    11,    12,    69,
     133,   -43,    93,   227,    82,   -59,    15,   -43,    16,   -59,
      14,    72,    75,   134,   135,    69,    22,   156,   105,   275,
      80,    27,   167,    28,    29,   141,   142,   144,   241,   118,
     119,    30,   242,   107,   150,    31,   152,   155,    17,    94,
      19,    20,    21,   168,    95,    96,    97,   108,   266,    69,
     -43,   236,   267,   169,   126,   127,   -43,   109,    79,    17,
      94,    19,    20,    21,    90,    95,    96,    97,    91,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,   246,   186,   187,
     188,   189,   128,   129,   130,   191,   192,   193,   194,    92,
      69,   247,   238,   124,   125,   218,   120,   121,   122,   123,
      99,   109,   178,   179,   180,   181,   251,   252,   176,   177,
     182,   183,   104,   217,   208,   210,   106,   112,   184,   185,
     113,   115,   145,   116,   117,   146,   147,   148,   105,   162,
     105,   158,   159,   160,   161,    73,   163,     2,   224,   225,
     164,   228,   229,   165,   232,   231,   133,   233,   170,    10,
     235,    82,   190,   195,   205,   196,   197,    11,    12,   198,
     245,   222,   199,    74,   200,   206,    15,   202,    16,   201,
     240,   214,    75,   203,   204,   218,    22,   248,   249,   250,
     255,    27,   256,    28,    29,   257,   258,   259,   260,   261,
     262,    30,   263,   271,   264,    31,   273,   265,   131,   274,
     286,   277,   279,   105,   278,   281,   282,   288,   223,   290,
     276,   287,   280,  -131,  -131,  -131,  -131,  -131,  -131,   132,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,   269,  -131,   289,
    -131,   171,  -131,   133,   270,     0,     0,     0,   172,     0,
       0,     0,   173,     0,     0,     0,   134,   135,   136,   137,
     138,   139,  -131,  -131,     0,  -131,  -131,  -131,     0,  -131,
    -131,    -2,     1,     0,     2,     3,   174,     4,   175,     0,
    -131,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
      13,    14,     0,    15,     0,    16,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     1,    31,     2,     3,     0,     4,   -28,   -28,   -28,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,    13,
      14,   -28,    15,     0,    16,     0,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       1,    31,     2,     3,     0,     4,   -29,   -29,   -29,     5,
       6,     7,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,     0,     0,     0,    13,    14,
     -29,    15,     0,    16,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
       0,     0,    86,     0,     2,     3,    30,     4,     0,     0,
      31,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
      13,    14,    87,    15,     0,    16,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,     0,     0,     1,     0,     2,     3,    30,     4,
       0,     0,    31,     5,     6,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,    13,    14,   157,    15,     0,    16,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,     0,     0,     1,     0,     2,     3,
      30,     4,     0,     0,    31,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,    13,    14,   237,    15,     0,    16,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,     0,     0,     1,     0,
       2,     3,    30,     4,     0,     0,    31,     5,     6,     7,
       8,     9,    10,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,     0,    13,    14,   239,    15,
       0,    16,     0,     0,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,     0,     0,
       1,     0,     2,     3,    30,     4,     0,     0,    31,     5,
       6,     7,     8,     9,    10,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,     0,     0,     0,    13,    14,
       0,    15,     0,    16,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
       0,     0,   207,     0,     2,     3,    30,     4,     0,     0,
      31,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
      13,    14,     0,    15,     0,    16,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,     0,     0,   209,     0,     2,     3,    30,     4,
       0,     0,    31,     5,     6,     7,     8,     9,    10,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,    13,    14,     0,    15,     0,    16,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,     0,     0,    77,     0,     2,     3,
      30,     4,     0,     0,    31,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,    13,    14,   151,    15,     2,    16,
       0,     0,     0,    75,     0,     0,     0,    22,     0,     0,
      10,     0,    27,     0,    28,    29,     0,     0,    11,    12,
       0,     0,    30,     0,     0,     0,    31,    15,  -142,    16,
       0,     0,   140,    75,     2,     0,     0,    22,     0,     0,
       0,     0,    27,     0,    28,    29,    10,     0,     0,     0,
       0,     0,    30,     0,    11,    12,    31,     0,     0,     0,
     143,     0,     2,    15,     0,    16,     0,     0,     0,    75,
       0,     0,     0,    22,    10,     0,     0,     0,    27,     0,
      28,    29,    11,    12,     0,     0,     0,     0,    30,     0,
       0,    15,    31,    16,     0,     0,   149,    75,     2,     0,
       0,    22,     0,     0,     0,     0,    27,     0,    28,    29,
      10,     0,     0,     0,     0,     0,    30,     0,    11,    12,
      31,     0,     0,     0,   230,     0,     2,    15,     0,    16,
       0,     0,     0,    75,     0,     0,     0,    22,    10,     0,
       0,     0,    27,     0,    28,    29,    11,    12,     0,     0,
       0,     0,    30,     0,     0,    15,    31,    16,     0,     0,
     234,    75,     2,     0,     0,    22,     0,     0,     0,     0,
      27,     0,    28,    29,    10,     0,     0,     0,     0,     0,
      30,     0,    11,    12,    31,     0,     0,     0,   272,     0,
       2,    15,     0,    16,     0,     0,     0,    75,     0,     0,
       0,    22,    10,     0,     0,     0,    27,     0,    28,    29,
      11,    12,     2,     0,     0,     0,    30,     0,     0,    15,
      31,    16,     0,     0,    10,    75,     0,     0,     0,    22,
       0,     0,    11,    12,    27,     0,    28,    29,     0,   215,
       2,    15,     0,    16,    30,     0,     0,    75,    31,     0,
       0,    22,    10,     0,     0,     0,    27,     0,    28,    29,
      11,    12,     0,     0,     0,     0,    30,     0,     0,    15,
      31,    16,     0,     0,     0,    75,     0,     0,     0,    22,
       0,     0,     0,     0,    27,     0,    28,    29,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
       7,     6,    26,    33,    32,     0,    15,    11,    12,     1,
      15,    11,    12,     1,     1,     1,    25,     3,     1,    14,
      32,     1,    32,    15,    28,    29,    30,    31,    55,    15,
      30,    31,    15,    25,    22,     7,     8,    23,    24,    29,
      36,    29,     1,    30,    72,    31,    32,    35,    34,    35,
      30,    32,    38,    49,    50,    29,    42,    31,    88,    31,
      29,    47,     1,    49,    50,    70,    71,    72,    31,    20,
      21,    57,    35,     1,    79,    61,    81,    82,    37,    38,
      39,    40,    41,    22,    43,    44,    45,    15,    31,    29,
      29,    31,    35,    32,    23,    24,    35,    25,    32,    37,
      38,    39,    40,    41,    15,    43,    44,    45,    15,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,     1,   128,   129,
     130,   132,    25,    26,    27,   136,   137,   138,   139,    15,
      29,    15,    31,    62,    63,   169,    16,    17,    18,    19,
      15,    25,   120,   121,   122,   123,     7,     8,   118,   119,
     124,   125,     0,   168,   159,   160,    29,    29,   126,   127,
      56,    59,    29,    60,    58,    29,    29,    10,   208,    29,
     210,    33,    30,    30,    30,     1,    15,     3,   195,   196,
      15,   198,   199,    15,   201,   200,    36,   202,    35,    15,
     205,    72,    15,    33,    35,    33,    33,    23,    24,    33,
     215,    15,    33,    29,    32,    73,    32,    29,    34,    33,
      31,    29,    38,    33,    33,   249,    42,    33,    35,     5,
      33,    47,    33,    49,    50,    29,    29,    29,    29,    29,
      29,    57,    29,   250,    15,    61,   251,    31,     1,    28,
      33,    29,   257,   283,    29,    28,    28,     9,   170,    29,
     253,   282,   267,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   248,    31,   286,
      33,   113,    35,    36,   249,    -1,    -1,    -1,   114,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    -1,    62,
      63,     0,     1,    -1,     3,     4,   116,     6,   117,    -1,
      73,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,     1,    61,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
       1,    61,     3,     4,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      -1,    -1,     1,    -1,     3,     4,    57,     6,    -1,    -1,
      61,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    -1,    -1,     1,    -1,     3,     4,    57,     6,
      -1,    -1,    61,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    -1,    -1,     1,    -1,     3,     4,
      57,     6,    -1,    -1,    61,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    -1,    -1,     1,    -1,
       3,     4,    57,     6,    -1,    -1,    61,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    50,    -1,    -1,
       1,    -1,     3,     4,    57,     6,    -1,    -1,    61,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      -1,    32,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      -1,    -1,     1,    -1,     3,     4,    57,     6,    -1,    -1,
      61,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    -1,    -1,     1,    -1,     3,     4,    57,     6,
      -1,    -1,    61,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    -1,    -1,     1,    -1,     3,     4,
      57,     6,    -1,    -1,    61,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,     1,    32,     3,    34,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
      15,    -1,    47,    -1,    49,    50,    -1,    -1,    23,    24,
      -1,    -1,    57,    -1,    -1,    -1,    61,    32,    33,    34,
      -1,    -1,     1,    38,     3,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    15,    -1,    -1,    -1,
      -1,    -1,    57,    -1,    23,    24,    61,    -1,    -1,    -1,
       1,    -1,     3,    32,    -1,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    42,    15,    -1,    -1,    -1,    47,    -1,
      49,    50,    23,    24,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    32,    61,    34,    -1,    -1,     1,    38,     3,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      15,    -1,    -1,    -1,    -1,    -1,    57,    -1,    23,    24,
      61,    -1,    -1,    -1,     1,    -1,     3,    32,    -1,    34,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    15,    -1,
      -1,    -1,    47,    -1,    49,    50,    23,    24,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    32,    61,    34,    -1,    -1,
       1,    38,     3,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    15,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    23,    24,    61,    -1,    -1,    -1,     1,    -1,
       3,    32,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    15,    -1,    -1,    -1,    47,    -1,    49,    50,
      23,    24,     3,    -1,    -1,    -1,    57,    -1,    -1,    32,
      61,    34,    -1,    -1,    15,    38,    -1,    -1,    -1,    42,
      -1,    -1,    23,    24,    47,    -1,    49,    50,    -1,    30,
       3,    32,    -1,    34,    57,    -1,    -1,    38,    61,    -1,
      -1,    42,    15,    -1,    -1,    -1,    47,    -1,    49,    50,
      23,    24,    -1,    -1,    -1,    -1,    57,    -1,    -1,    32,
      61,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     6,    10,    11,    12,    13,    14,
      15,    23,    24,    29,    30,    32,    34,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    49,    50,
      57,    61,    75,    76,    77,    78,    79,    80,    81,    82,
      87,    88,    91,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   121,   123,   124,   125,    29,
      32,    32,    32,     1,    29,    38,   103,     1,    97,    32,
      29,    32,    72,   115,   117,   115,     1,    31,    76,   103,
      15,    15,    15,     1,    38,    43,    44,    45,    88,    15,
     117,   117,   115,   115,     0,    77,    29,     1,    15,    25,
      89,    90,    29,    56,    55,    59,    60,    58,    20,    21,
      16,    17,    18,    19,    62,    63,    23,    24,    25,    26,
      27,     1,    22,    36,    49,    50,    51,    52,    53,    54,
       1,   103,   103,     1,   103,    29,    29,    29,    10,     1,
     103,     1,   103,   119,   120,   103,    31,    31,    33,    30,
      30,    30,    29,    15,    15,    15,    15,     1,    22,    32,
      35,   106,   107,   108,   109,   110,   111,   111,   112,   112,
     112,   112,   113,   113,   114,   114,   115,   115,   115,   104,
      15,   104,   104,   104,   104,    33,    33,    33,    33,    33,
      32,    33,    29,    33,    33,    35,    73,     1,    76,     1,
      76,     1,    15,   122,    29,    30,    95,   103,    88,    92,
      93,    94,    15,    90,    97,    97,     1,    30,    97,    97,
       1,   103,    97,   103,     1,   103,    31,    31,    31,    31,
      31,    31,    35,     1,    96,   103,     1,    15,    33,    35,
       5,     7,     8,    83,    84,    33,    33,    29,    29,    29,
      29,    29,    29,    29,    15,    31,    31,    35,     1,    99,
      94,    97,     1,   103,    28,    31,    84,    29,    29,   103,
     103,    28,    28,    76,    85,    86,    33,    85,     9,    97,
      29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    90,    90,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,    99,   100,   100,   100,   101,   101,
     102,   102,   102,   103,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   110,   111,   111,   111,   111,   111,   112,
     112,   112,   113,   113,   113,   114,   114,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     7,     5,     9,     5,     7,     7,
       2,     2,     1,     4,     3,     3,     3,     1,     0,     1,
       2,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     3,     1,     3,     3,     2,     6,     6,     1,
       0,     3,     1,     2,     2,     3,     3,     1,     3,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     3,     2,     3,     5,     7,     5,     5,     5,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     1,     3,     4,     4,
       4,     1,     0,     3,     1,     3,     4,     3,     1,     3,
       6,     6,     6,     6,     6,     6
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
  case 2: /* programa: lista_declaracoes  */
#line 88 "exemplo.y"
                      { root = (yyvsp[0].node); }
#line 1590 "exemplo.tab.c"
    break;

  case 3: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 92 "exemplo.y"
                                 { (yyval.node) = concatenarStmt((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1596 "exemplo.tab.c"
    break;

  case 4: /* lista_declaracoes: declaracao  */
#line 93 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1602 "exemplo.tab.c"
    break;

  case 5: /* declaracao: declaracao_variavel SEMICOLON  */
#line 97 "exemplo.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1608 "exemplo.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 98 "exemplo.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1614 "exemplo.tab.c"
    break;

  case 7: /* declaracao: stmt  */
#line 99 "exemplo.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1620 "exemplo.tab.c"
    break;

  case 8: /* declaracao: declaracao_tipo  */
#line 100 "exemplo.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1626 "exemplo.tab.c"
    break;

  case 9: /* declaracao: error SEMICOLON  */
#line 101 "exemplo.y"
                      { 
        (yyval.node) = NULL; 
        yyerror("Declaração inválida"); 
    }
#line 1635 "exemplo.tab.c"
    break;

  case 10: /* declaracao_tipo: struct_declaracao  */
#line 108 "exemplo.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1641 "exemplo.tab.c"
    break;

  case 11: /* declaracao_tipo: union_declaracao  */
#line 109 "exemplo.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 1647 "exemplo.tab.c"
    break;

  case 12: /* declaracao_tipo: enum_declaracao  */
#line 110 "exemplo.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1653 "exemplo.tab.c"
    break;

  case 13: /* declaracao_tipo: typedef_declaracao  */
#line 111 "exemplo.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1659 "exemplo.tab.c"
    break;

  case 14: /* switch_stmt: SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE  */
#line 115 "exemplo.y"
                                                      { (yyval.node) = criarNoSwitch((yyvsp[-4].node), (yyvsp[-1].node)); }
#line 1665 "exemplo.tab.c"
    break;

  case 15: /* switch_stmt: SWITCH LPAREN expr RPAREN error  */
#line 116 "exemplo.y"
                                      { 
        (yyval.node) = NULL; 
        yyerror("Estrutura switch incompleta ou inválida"); 
    }
#line 1674 "exemplo.tab.c"
    break;

  case 16: /* for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN stmt  */
#line 123 "exemplo.y"
                                                              {
        (yyval.node) = criarNoFor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1682 "exemplo.tab.c"
    break;

  case 17: /* for_stmt: FOR LPAREN error RPAREN stmt  */
#line 126 "exemplo.y"
                                   {
        (yyval.node) = NULL;
        yyerror("Formato inválido para estrutura for");
    }
#line 1691 "exemplo.tab.c"
    break;

  case 18: /* do_stmt: DO stmt WHILE LPAREN expr RPAREN SEMICOLON  */
#line 144 "exemplo.y"
                                               { (yyval.node) = criarNoDoWhile((yyvsp[-2].node), (yyvsp[-5].node)); }
#line 1697 "exemplo.tab.c"
    break;

  case 19: /* do_stmt: DO stmt WHILE LPAREN error RPAREN SEMICOLON  */
#line 145 "exemplo.y"
                                                  {
        (yyval.node) = NULL;
        yyerror("Expressão inválida na condição do do-while");
    }
#line 1706 "exemplo.tab.c"
    break;

  case 20: /* continue_stmt: CONTINUE SEMICOLON  */
#line 152 "exemplo.y"
                       { (yyval.node) = criarNoContinue(); }
#line 1712 "exemplo.tab.c"
    break;

  case 21: /* case_list: case_list case_stmt  */
#line 156 "exemplo.y"
                        { (yyval.node) = concatenarStmt((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1718 "exemplo.tab.c"
    break;

  case 22: /* case_list: case_stmt  */
#line 157 "exemplo.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1724 "exemplo.tab.c"
    break;

  case 23: /* case_stmt: CASE expr COLON comandos_break  */
#line 161 "exemplo.y"
                                   { (yyval.node) = criarNoCase((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1730 "exemplo.tab.c"
    break;

  case 24: /* case_stmt: DEFAULT COLON comandos_break  */
#line 162 "exemplo.y"
                                   { (yyval.node) = criarNoCase(NULL, (yyvsp[0].node)); }
#line 1736 "exemplo.tab.c"
    break;

  case 25: /* case_stmt: CASE error COLON  */
#line 163 "exemplo.y"
                       { 
        (yyval.node) = NULL; 
        yyerror("Expressão inválida em case"); 
    }
#line 1745 "exemplo.tab.c"
    break;

  case 26: /* comandos_break: comandos_opt BREAK SEMICOLON  */
#line 170 "exemplo.y"
                                 { (yyval.node) = concatenarStmt((yyvsp[-2].node), criarNoBreak()); }
#line 1751 "exemplo.tab.c"
    break;

  case 27: /* comandos_break: comandos_opt  */
#line 171 "exemplo.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1757 "exemplo.tab.c"
    break;

  case 28: /* comandos_opt: %empty  */
#line 175 "exemplo.y"
                { (yyval.node) = NULL; }
#line 1763 "exemplo.tab.c"
    break;

  case 29: /* comandos_opt: lista_declaracoes  */
#line 176 "exemplo.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1769 "exemplo.tab.c"
    break;

  case 30: /* declaracao_variavel: tipo lista_variaveis  */
#line 180 "exemplo.y"
                         { (yyval.node) = criarNoVarDecl((yyvsp[0].node)->valor_str, criarNoType((yyvsp[-1].node)->valor_str)); }
#line 1775 "exemplo.tab.c"
    break;

  case 31: /* declaracao_variavel: tipo error  */
#line 181 "exemplo.y"
                 { 
        (yyval.node) = NULL; 
        yyerror("Declaração de variável inválida"); 
    }
#line 1784 "exemplo.tab.c"
    break;

  case 32: /* tipo: INT  */
#line 188 "exemplo.y"
        { (yyval.node) = criarNoType("int"); }
#line 1790 "exemplo.tab.c"
    break;

  case 33: /* tipo: FLOAT  */
#line 189 "exemplo.y"
            { (yyval.node) = criarNoType("float"); }
#line 1796 "exemplo.tab.c"
    break;

  case 34: /* tipo: CHAR  */
#line 190 "exemplo.y"
           { (yyval.node) = criarNoType("char"); }
#line 1802 "exemplo.tab.c"
    break;

  case 35: /* tipo: VOID  */
#line 191 "exemplo.y"
           { (yyval.node) = criarNoType("void"); }
#line 1808 "exemplo.tab.c"
    break;

  case 36: /* tipo: DOUBLE  */
#line 192 "exemplo.y"
             { (yyval.node) = criarNoType("double"); }
#line 1814 "exemplo.tab.c"
    break;

  case 37: /* tipo: STRUCT ID  */
#line 193 "exemplo.y"
                { (yyval.node) = criarNoUnion("struct", (yyvsp[0].strValue)); }
#line 1820 "exemplo.tab.c"
    break;

  case 38: /* tipo: UNION ID  */
#line 194 "exemplo.y"
               { (yyval.node) = criarNoUnion("union", (yyvsp[0].strValue)); }
#line 1826 "exemplo.tab.c"
    break;

  case 39: /* tipo: ENUM ID  */
#line 195 "exemplo.y"
              { (yyval.node) = criarNoEnum((yyvsp[0].strValue)); }
#line 1832 "exemplo.tab.c"
    break;

  case 40: /* tipo: tipo MULT  */
#line 196 "exemplo.y"
                {
        (yyval.node) = NULL;
        report_unsupported_feature("Ponteiros", yylineno);
    }
#line 1841 "exemplo.tab.c"
    break;

  case 41: /* lista_variaveis: variavel  */
#line 203 "exemplo.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1847 "exemplo.tab.c"
    break;

  case 42: /* lista_variaveis: lista_variaveis COMMA variavel  */
#line 204 "exemplo.y"
                                     { (yyval.node) = concatenarStmt((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1853 "exemplo.tab.c"
    break;

  case 43: /* variavel: ID  */
#line 208 "exemplo.y"
       { (yyval.node) = criarNoVar((yyvsp[0].strValue)); }
#line 1859 "exemplo.tab.c"
    break;

  case 44: /* variavel: ID ASSIGN expr  */
#line 209 "exemplo.y"
                     { (yyval.node) = criarNoAssign('=', criarNoVar((yyvsp[-2].strValue)), (yyvsp[0].node)); }
#line 1865 "exemplo.tab.c"
    break;

  case 45: /* variavel: ID ASSIGN inicializador  */
#line 210 "exemplo.y"
                              { (yyval.node) = criarNoAssign('=', criarNoVar((yyvsp[-2].strValue)), (yyvsp[0].node)); }
#line 1871 "exemplo.tab.c"
    break;

  case 46: /* variavel: ID error  */
#line 211 "exemplo.y"
               { 
        (yyval.node) = NULL; 
        yyerror("Erro na declaração ou inicialização de variável"); 
    }
#line 1880 "exemplo.tab.c"
    break;

  case 47: /* fun_declaracao: tipo ID LPAREN parametros RPAREN composto_stmt  */
#line 218 "exemplo.y"
                                                   { (yyval.node) = criarNoFuncDecl((yyvsp[-4].strValue), (yyvsp[-5].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1886 "exemplo.tab.c"
    break;

  case 48: /* fun_declaracao: tipo ID LPAREN parametros RPAREN error  */
#line 219 "exemplo.y"
                                             { 
        (yyval.node) = NULL; 
        yyerror("Corpo de função inválido ou ausente"); 
    }
#line 1895 "exemplo.tab.c"
    break;

  case 49: /* parametros: lista_parametros  */
#line 226 "exemplo.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1901 "exemplo.tab.c"
    break;

  case 50: /* parametros: %empty  */
#line 227 "exemplo.y"
                  { (yyval.node) = NULL; }
#line 1907 "exemplo.tab.c"
    break;

  case 51: /* lista_parametros: lista_parametros COMMA param  */
#line 231 "exemplo.y"
                                 { (yyval.node) = concatenarParam((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1913 "exemplo.tab.c"
    break;

  case 52: /* lista_parametros: param  */
#line 232 "exemplo.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 1919 "exemplo.tab.c"
    break;

  case 53: /* param: tipo ID  */
#line 236 "exemplo.y"
            { (yyval.node) = criarNoParam((yyvsp[0].strValue), (yyvsp[-1].node)); }
#line 1925 "exemplo.tab.c"
    break;

  case 54: /* param: tipo error  */
#line 237 "exemplo.y"
                 { 
        (yyval.node) = NULL; 
        yyerror("Parâmetro inválido"); 
    }
#line 1934 "exemplo.tab.c"
    break;

  case 55: /* inicializador: LBRACE lista_inicializadores RBRACE  */
#line 244 "exemplo.y"
                                        { (yyval.node) = (yyvsp[-1].node); }
#line 1940 "exemplo.tab.c"
    break;

  case 56: /* inicializador: LBRACE error RBRACE  */
#line 245 "exemplo.y"
                          { 
        (yyval.node) = NULL; 
        yyerror("Lista de inicialização inválida"); 
    }
#line 1949 "exemplo.tab.c"
    break;

  case 57: /* lista_inicializadores: expr  */
#line 252 "exemplo.y"
         { (yyval.node) = criarNoInit((yyvsp[0].node), NULL); }
#line 1955 "exemplo.tab.c"
    break;

  case 58: /* lista_inicializadores: lista_inicializadores COMMA expr  */
#line 253 "exemplo.y"
                                       { (yyval.node) = criarNoInit((yyvsp[0].node), (yyvsp[-2].node)); }
#line 1961 "exemplo.tab.c"
    break;

  case 59: /* lista_inicializadores: %empty  */
#line 254 "exemplo.y"
                  { (yyval.node) = NULL; }
#line 1967 "exemplo.tab.c"
    break;

  case 60: /* stmt: expr_stmt  */
#line 258 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1973 "exemplo.tab.c"
    break;

  case 61: /* stmt: composto_stmt  */
#line 259 "exemplo.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1979 "exemplo.tab.c"
    break;

  case 62: /* stmt: if_stmt  */
#line 260 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1985 "exemplo.tab.c"
    break;

  case 63: /* stmt: while_stmt  */
#line 261 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1991 "exemplo.tab.c"
    break;

  case 64: /* stmt: return_stmt  */
#line 262 "exemplo.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1997 "exemplo.tab.c"
    break;

  case 65: /* stmt: switch_stmt  */
#line 263 "exemplo.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2003 "exemplo.tab.c"
    break;

  case 66: /* stmt: do_stmt  */
#line 264 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2009 "exemplo.tab.c"
    break;

  case 67: /* stmt: for_stmt  */
#line 265 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2015 "exemplo.tab.c"
    break;

  case 68: /* stmt: continue_stmt  */
#line 266 "exemplo.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2021 "exemplo.tab.c"
    break;

  case 69: /* stmt: error SEMICOLON  */
#line 267 "exemplo.y"
                      { 
        (yyval.node) = NULL; 
        yyerror("Comando inválido"); 
    }
#line 2030 "exemplo.tab.c"
    break;

  case 70: /* expr_stmt: expr SEMICOLON  */
#line 274 "exemplo.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 2036 "exemplo.tab.c"
    break;

  case 71: /* expr_stmt: SEMICOLON  */
#line 275 "exemplo.y"
                { (yyval.node) = NULL; }
#line 2042 "exemplo.tab.c"
    break;

  case 72: /* composto_stmt: LBRACE lista_declaracoes RBRACE  */
#line 279 "exemplo.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2048 "exemplo.tab.c"
    break;

  case 73: /* composto_stmt: LBRACE RBRACE  */
#line 280 "exemplo.y"
                    { (yyval.node) = NULL; }
#line 2054 "exemplo.tab.c"
    break;

  case 74: /* composto_stmt: LBRACE error RBRACE  */
#line 281 "exemplo.y"
                          { 
        (yyval.node) = NULL; 
        yyerror("Bloco de comandos com erro"); 
    }
#line 2063 "exemplo.tab.c"
    break;

  case 75: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 288 "exemplo.y"
                                                     { (yyval.node) = criarNoIf((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2069 "exemplo.tab.c"
    break;

  case 76: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 289 "exemplo.y"
                                           { (yyval.node) = criarNoIf((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2075 "exemplo.tab.c"
    break;

  case 77: /* if_stmt: IF LPAREN error RPAREN stmt  */
#line 290 "exemplo.y"
                                  { 
        (yyval.node) = NULL; 
        yyerror("Expressão condicional inválida no if"); 
    }
#line 2084 "exemplo.tab.c"
    break;

  case 78: /* while_stmt: WHILE LPAREN expr RPAREN stmt  */
#line 297 "exemplo.y"
                                  { (yyval.node) = criarNoWhile((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2090 "exemplo.tab.c"
    break;

  case 79: /* while_stmt: WHILE LPAREN error RPAREN stmt  */
#line 298 "exemplo.y"
                                     { 
        (yyval.node) = NULL; 
        yyerror("Expressão condicional inválida no while"); 
    }
#line 2099 "exemplo.tab.c"
    break;

  case 80: /* return_stmt: RETURN expr SEMICOLON  */
#line 305 "exemplo.y"
                          { (yyval.node) = criarNoReturn((yyvsp[-1].node)); }
#line 2105 "exemplo.tab.c"
    break;

  case 81: /* return_stmt: RETURN SEMICOLON  */
#line 306 "exemplo.y"
                       { (yyval.node) = criarNoReturn(NULL); }
#line 2111 "exemplo.tab.c"
    break;

  case 82: /* return_stmt: RETURN error SEMICOLON  */
#line 307 "exemplo.y"
                             { 
        (yyval.node) = NULL; 
        yyerror("Expressão de retorno inválida"); 
    }
#line 2120 "exemplo.tab.c"
    break;

  case 83: /* expr: atrib_expr  */
#line 314 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2126 "exemplo.tab.c"
    break;

  case 84: /* atrib_expr: or_expr  */
#line 318 "exemplo.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2132 "exemplo.tab.c"
    break;

  case 85: /* atrib_expr: var ASSIGN atrib_expr  */
#line 319 "exemplo.y"
                            { (yyval.node) = criarNoAssign('=', (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2138 "exemplo.tab.c"
    break;

  case 86: /* atrib_expr: var PLUS_ASSIGN atrib_expr  */
#line 320 "exemplo.y"
                                 { 
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("+", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2149 "exemplo.tab.c"
    break;

  case 87: /* atrib_expr: var MINUS_ASSIGN atrib_expr  */
#line 326 "exemplo.y"
                                  { 
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("-", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2160 "exemplo.tab.c"
    break;

  case 88: /* atrib_expr: var MULT_ASSIGN atrib_expr  */
#line 332 "exemplo.y"
                                 { 
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("*", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2171 "exemplo.tab.c"
    break;

  case 89: /* atrib_expr: var DIV_ASSIGN atrib_expr  */
#line 338 "exemplo.y"
                                { 
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("/", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2182 "exemplo.tab.c"
    break;

  case 90: /* atrib_expr: var error  */
#line 344 "exemplo.y"
                { 
        (yyval.node) = NULL; 
        yyerror("Operação de atribuição inválida"); 
    }
#line 2191 "exemplo.tab.c"
    break;

  case 91: /* or_expr: and_expr  */
#line 351 "exemplo.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2197 "exemplo.tab.c"
    break;

  case 92: /* or_expr: or_expr OR and_expr  */
#line 352 "exemplo.y"
                          { (yyval.node) = criarNoBinOp("||", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2203 "exemplo.tab.c"
    break;

  case 93: /* and_expr: bitor_expr  */
#line 356 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2209 "exemplo.tab.c"
    break;

  case 94: /* and_expr: and_expr AND bitor_expr  */
#line 357 "exemplo.y"
                              { (yyval.node) = criarNoBinOp("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2215 "exemplo.tab.c"
    break;

  case 95: /* bitor_expr: bitxor_expr  */
#line 361 "exemplo.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2221 "exemplo.tab.c"
    break;

  case 96: /* bitor_expr: bitor_expr BITOR bitxor_expr  */
#line 362 "exemplo.y"
                                   { (yyval.node) = criarNoBinOp("|", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2227 "exemplo.tab.c"
    break;

  case 97: /* bitxor_expr: bitand_expr  */
#line 366 "exemplo.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2233 "exemplo.tab.c"
    break;

  case 98: /* bitxor_expr: bitxor_expr BITXOR bitand_expr  */
#line 367 "exemplo.y"
                                     { (yyval.node) = criarNoBinOp("^", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2239 "exemplo.tab.c"
    break;

  case 99: /* bitand_expr: equal_expr  */
#line 371 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2245 "exemplo.tab.c"
    break;

  case 100: /* bitand_expr: bitand_expr BITAND equal_expr  */
#line 372 "exemplo.y"
                                    { (yyval.node) = criarNoBinOp("&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2251 "exemplo.tab.c"
    break;

  case 101: /* equal_expr: relacao_expr  */
#line 376 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2257 "exemplo.tab.c"
    break;

  case 102: /* equal_expr: equal_expr EQ relacao_expr  */
#line 377 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("==", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2263 "exemplo.tab.c"
    break;

  case 103: /* equal_expr: equal_expr NE relacao_expr  */
#line 378 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("!=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2269 "exemplo.tab.c"
    break;

  case 104: /* relacao_expr: shift_expr  */
#line 382 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2275 "exemplo.tab.c"
    break;

  case 105: /* relacao_expr: relacao_expr GT shift_expr  */
#line 383 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2281 "exemplo.tab.c"
    break;

  case 106: /* relacao_expr: relacao_expr LT shift_expr  */
#line 384 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2287 "exemplo.tab.c"
    break;

  case 107: /* relacao_expr: relacao_expr GE shift_expr  */
#line 385 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2293 "exemplo.tab.c"
    break;

  case 108: /* relacao_expr: relacao_expr LE shift_expr  */
#line 386 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2299 "exemplo.tab.c"
    break;

  case 109: /* shift_expr: add_expr  */
#line 390 "exemplo.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2305 "exemplo.tab.c"
    break;

  case 110: /* shift_expr: shift_expr SHIFTLEFT add_expr  */
#line 391 "exemplo.y"
                                    { (yyval.node) = criarNoBinOp("<<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2311 "exemplo.tab.c"
    break;

  case 111: /* shift_expr: shift_expr SHIFTRIGHT add_expr  */
#line 392 "exemplo.y"
                                     { (yyval.node) = criarNoBinOp(">>", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2317 "exemplo.tab.c"
    break;

  case 112: /* add_expr: mult_expr  */
#line 396 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2323 "exemplo.tab.c"
    break;

  case 113: /* add_expr: add_expr PLUS mult_expr  */
#line 397 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2329 "exemplo.tab.c"
    break;

  case 114: /* add_expr: add_expr MINUS mult_expr  */
#line 398 "exemplo.y"
                                  { (yyval.node) = criarNoBinOp("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2335 "exemplo.tab.c"
    break;

  case 115: /* mult_expr: unary_expr  */
#line 402 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2341 "exemplo.tab.c"
    break;

  case 116: /* mult_expr: mult_expr MULT unary_expr  */
#line 403 "exemplo.y"
                                { (yyval.node) = criarNoBinOp("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2347 "exemplo.tab.c"
    break;

  case 117: /* mult_expr: mult_expr DIV unary_expr  */
#line 404 "exemplo.y"
                               { (yyval.node) = criarNoBinOp("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2353 "exemplo.tab.c"
    break;

  case 118: /* mult_expr: mult_expr MOD unary_expr  */
#line 405 "exemplo.y"
                               { (yyval.node) = criarNoBinOp("%", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2359 "exemplo.tab.c"
    break;

  case 119: /* unary_expr: fator  */
#line 409 "exemplo.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 2365 "exemplo.tab.c"
    break;

  case 120: /* unary_expr: INCREMENT var  */
#line 410 "exemplo.y"
                    { (yyval.node) = criarNoUnaryOp("++", (yyvsp[0].node)); }
#line 2371 "exemplo.tab.c"
    break;

  case 121: /* unary_expr: DECREMENT var  */
#line 411 "exemplo.y"
                    { (yyval.node) = criarNoUnaryOp("--", (yyvsp[0].node)); }
#line 2377 "exemplo.tab.c"
    break;

  case 122: /* unary_expr: MINUS unary_expr  */
#line 412 "exemplo.y"
                                    { (yyval.node) = criarNoUnaryOp("-", (yyvsp[0].node)); }
#line 2383 "exemplo.tab.c"
    break;

  case 123: /* unary_expr: PLUS unary_expr  */
#line 413 "exemplo.y"
                                  { (yyval.node) = criarNoUnaryOp("+", (yyvsp[0].node)); }
#line 2389 "exemplo.tab.c"
    break;

  case 124: /* unary_expr: NOT unary_expr  */
#line 414 "exemplo.y"
                     { (yyval.node) = criarNoUnaryOp("!", (yyvsp[0].node)); }
#line 2395 "exemplo.tab.c"
    break;

  case 125: /* unary_expr: BITNOT unary_expr  */
#line 415 "exemplo.y"
                        { (yyval.node) = criarNoUnaryOp("~", (yyvsp[0].node)); }
#line 2401 "exemplo.tab.c"
    break;

  case 126: /* fator: NUM  */
#line 419 "exemplo.y"
        { (yyval.node) = criarNoInt((yyvsp[0].intValue)); }
#line 2407 "exemplo.tab.c"
    break;

  case 127: /* fator: FLOAT  */
#line 420 "exemplo.y"
            { (yyval.node) = criarNoFloat((yyvsp[0].floatValue)); }
#line 2413 "exemplo.tab.c"
    break;

  case 128: /* fator: CHAR_LITERAL  */
#line 421 "exemplo.y"
                   { (yyval.node) = criarNoChar((yyvsp[0].charValue)); }
#line 2419 "exemplo.tab.c"
    break;

  case 129: /* fator: HEX  */
#line 422 "exemplo.y"
          { (yyval.node) = criarNoHex((yyvsp[0].strValue)); }
#line 2425 "exemplo.tab.c"
    break;

  case 130: /* fator: STRING  */
#line 423 "exemplo.y"
             { (yyval.node) = criarNoString((yyvsp[0].strValue)); }
#line 2431 "exemplo.tab.c"
    break;

  case 131: /* fator: var  */
#line 424 "exemplo.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 2437 "exemplo.tab.c"
    break;

  case 132: /* fator: chamada  */
#line 425 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2443 "exemplo.tab.c"
    break;

  case 133: /* fator: LPAREN expr RPAREN  */
#line 426 "exemplo.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 2449 "exemplo.tab.c"
    break;

  case 134: /* fator: var INCREMENT  */
#line 427 "exemplo.y"
                    { (yyval.node) = criarNoUnaryOp("++", (yyvsp[-1].node)); }
#line 2455 "exemplo.tab.c"
    break;

  case 135: /* fator: var DECREMENT  */
#line 428 "exemplo.y"
                    { (yyval.node) = criarNoUnaryOp("--", (yyvsp[-1].node)); }
#line 2461 "exemplo.tab.c"
    break;

  case 136: /* var: ID  */
#line 432 "exemplo.y"
       { (yyval.node) = criarNoVar((yyvsp[0].strValue)); }
#line 2467 "exemplo.tab.c"
    break;

  case 137: /* var: var DOT ID  */
#line 433 "exemplo.y"
                 { (yyval.node) = criarNoVar((yyvsp[0].strValue)); }
#line 2473 "exemplo.tab.c"
    break;

  case 138: /* var: ID '[' expr ']'  */
#line 434 "exemplo.y"
                      {
        (yyval.node) = NULL;
        report_unsupported_feature("Arrays", yylineno);
    }
#line 2482 "exemplo.tab.c"
    break;

  case 139: /* chamada: ID LPAREN argumentos RPAREN  */
#line 441 "exemplo.y"
                                { (yyval.node) = criarNoCall((yyvsp[-3].strValue), (yyvsp[-1].node)); }
#line 2488 "exemplo.tab.c"
    break;

  case 140: /* chamada: ID LPAREN error RPAREN  */
#line 442 "exemplo.y"
                             { 
        (yyval.node) = NULL; 
        yyerror("Lista de argumentos inválida"); 
    }
#line 2497 "exemplo.tab.c"
    break;

  case 141: /* argumentos: lista_args  */
#line 449 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2503 "exemplo.tab.c"
    break;

  case 142: /* argumentos: %empty  */
#line 450 "exemplo.y"
                  { (yyval.node) = NULL; }
#line 2509 "exemplo.tab.c"
    break;

  case 143: /* lista_args: lista_args COMMA expr  */
#line 454 "exemplo.y"
                          { (yyval.node) = concatenarArg((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2515 "exemplo.tab.c"
    break;

  case 144: /* lista_args: expr  */
#line 455 "exemplo.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2521 "exemplo.tab.c"
    break;

  case 145: /* lista_args: lista_args COMMA error  */
#line 456 "exemplo.y"
                             { 
        (yyval.node) = NULL; 
        yyerror("Argumento inválido na lista"); 
    }
#line 2530 "exemplo.tab.c"
    break;

  case 146: /* typedef_declaracao: TYPEDEF tipo ID SEMICOLON  */
#line 463 "exemplo.y"
                              { (yyval.node) = criarNoVar((yyvsp[-1].strValue)); }
#line 2536 "exemplo.tab.c"
    break;

  case 147: /* typedef_declaracao: TYPEDEF error SEMICOLON  */
#line 464 "exemplo.y"
                              { 
        (yyval.node) = NULL; 
        yyerror("Declaração typedef inválida"); 
    }
#line 2545 "exemplo.tab.c"
    break;

  case 148: /* lista_identificadores: ID  */
#line 471 "exemplo.y"
       { (yyval.node) = criarNoVar((yyvsp[0].strValue)); }
#line 2551 "exemplo.tab.c"
    break;

  case 149: /* lista_identificadores: lista_identificadores COMMA ID  */
#line 472 "exemplo.y"
                                     { (yyval.node) = concatenarStmt((yyvsp[-2].node), criarNoVar((yyvsp[0].strValue))); }
#line 2557 "exemplo.tab.c"
    break;

  case 150: /* struct_declaracao: STRUCT ID LBRACE lista_declaracoes RBRACE SEMICOLON  */
#line 476 "exemplo.y"
                                                        { (yyval.node) = criarNoUnion("struct", (yyvsp[-4].strValue)); }
#line 2563 "exemplo.tab.c"
    break;

  case 151: /* struct_declaracao: STRUCT ID LBRACE error RBRACE SEMICOLON  */
#line 477 "exemplo.y"
                                              { 
        (yyval.node) = NULL; 
        yyerror("Corpo de struct inválido"); 
    }
#line 2572 "exemplo.tab.c"
    break;

  case 152: /* union_declaracao: UNION ID LBRACE lista_declaracoes RBRACE SEMICOLON  */
#line 484 "exemplo.y"
                                                       { (yyval.node) = criarNoUnion("union", (yyvsp[-4].strValue)); }
#line 2578 "exemplo.tab.c"
    break;

  case 153: /* union_declaracao: UNION ID LBRACE error RBRACE SEMICOLON  */
#line 485 "exemplo.y"
                                             { 
        (yyval.node) = NULL; 
        yyerror("Corpo de union inválido"); 
    }
#line 2587 "exemplo.tab.c"
    break;

  case 154: /* enum_declaracao: ENUM ID LBRACE lista_identificadores RBRACE SEMICOLON  */
#line 492 "exemplo.y"
                                                          { (yyval.node) = criarNoEnum((yyvsp[-4].strValue)); }
#line 2593 "exemplo.tab.c"
    break;

  case 155: /* enum_declaracao: ENUM ID LBRACE error RBRACE SEMICOLON  */
#line 493 "exemplo.y"
                                            { 
        (yyval.node) = NULL; 
        yyerror("Lista de enumeradores inválida"); 
    }
#line 2602 "exemplo.tab.c"
    break;


#line 2606 "exemplo.tab.c"

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

#line 499 "exemplo.y"

