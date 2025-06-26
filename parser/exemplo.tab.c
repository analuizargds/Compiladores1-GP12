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
#include "../simbolos.h"

int yylex(void);
void yyerror(const char *s);
extern FILE *yyin;
extern int yylineno;
ASTNode* root;

// Função para reportar erros de construções não suportadas
void report_unsupported_feature(const char* feature, int line) {
    fprintf(stderr, "Erro na linha %d: %s não é suportado nesta versão do compilador\n", line, feature);
}

#line 90 "exemplo.tab.c"

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
  YYSYMBOL_MOD_ASSIGN = 55,                /* MOD_ASSIGN  */
  YYSYMBOL_QUESTION = 56,                  /* QUESTION  */
  YYSYMBOL_AND = 57,                       /* AND  */
  YYSYMBOL_OR = 58,                        /* OR  */
  YYSYMBOL_NOT = 59,                       /* NOT  */
  YYSYMBOL_BITAND = 60,                    /* BITAND  */
  YYSYMBOL_BITOR = 61,                     /* BITOR  */
  YYSYMBOL_BITXOR = 62,                    /* BITXOR  */
  YYSYMBOL_BITNOT = 63,                    /* BITNOT  */
  YYSYMBOL_SHIFTLEFT = 64,                 /* SHIFTLEFT  */
  YYSYMBOL_SHIFTRIGHT = 65,                /* SHIFTRIGHT  */
  YYSYMBOL_LBRACKET = 66,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 67,                  /* RBRACKET  */
  YYSYMBOL_INCLUDE = 68,                   /* INCLUDE  */
  YYSYMBOL_POINTER = 69,                   /* POINTER  */
  YYSYMBOL_AMPERSAND = 70,                 /* AMPERSAND  */
  YYSYMBOL_UMINUS = 71,                    /* UMINUS  */
  YYSYMBOL_UPLUS = 72,                     /* UPLUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 73,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_74_ = 74,                       /* '['  */
  YYSYMBOL_75_ = 75,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_programa = 77,                  /* programa  */
  YYSYMBOL_78_1 = 78,                      /* $@1  */
  YYSYMBOL_lista_declaracoes = 79,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 80,                /* declaracao  */
  YYSYMBOL_declaracao_tipo = 81,           /* declaracao_tipo  */
  YYSYMBOL_switch_stmt = 82,               /* switch_stmt  */
  YYSYMBOL_83_2 = 83,                      /* $@2  */
  YYSYMBOL_for_stmt = 84,                  /* for_stmt  */
  YYSYMBOL_85_3 = 85,                      /* $@3  */
  YYSYMBOL_do_stmt = 86,                   /* do_stmt  */
  YYSYMBOL_87_4 = 87,                      /* $@4  */
  YYSYMBOL_continue_stmt = 88,             /* continue_stmt  */
  YYSYMBOL_case_list = 89,                 /* case_list  */
  YYSYMBOL_case_stmt = 90,                 /* case_stmt  */
  YYSYMBOL_comandos_break = 91,            /* comandos_break  */
  YYSYMBOL_comandos_opt = 92,              /* comandos_opt  */
  YYSYMBOL_declaracao_variavel = 93,       /* declaracao_variavel  */
  YYSYMBOL_tipo = 94,                      /* tipo  */
  YYSYMBOL_lista_variaveis = 95,           /* lista_variaveis  */
  YYSYMBOL_variavel = 96,                  /* variavel  */
  YYSYMBOL_fun_declaracao = 97,            /* fun_declaracao  */
  YYSYMBOL_98_5 = 98,                      /* $@5  */
  YYSYMBOL_99_6 = 99,                      /* $@6  */
  YYSYMBOL_parametros = 100,               /* parametros  */
  YYSYMBOL_lista_parametros = 101,         /* lista_parametros  */
  YYSYMBOL_param = 102,                    /* param  */
  YYSYMBOL_inicializador = 103,            /* inicializador  */
  YYSYMBOL_lista_inicializadores = 104,    /* lista_inicializadores  */
  YYSYMBOL_stmt = 105,                     /* stmt  */
  YYSYMBOL_expr_stmt = 106,                /* expr_stmt  */
  YYSYMBOL_composto_stmt = 107,            /* composto_stmt  */
  YYSYMBOL_108_7 = 108,                    /* $@7  */
  YYSYMBOL_109_8 = 109,                    /* $@8  */
  YYSYMBOL_110_9 = 110,                    /* $@9  */
  YYSYMBOL_if_stmt = 111,                  /* if_stmt  */
  YYSYMBOL_while_stmt = 112,               /* while_stmt  */
  YYSYMBOL_113_10 = 113,                   /* $@10  */
  YYSYMBOL_return_stmt = 114,              /* return_stmt  */
  YYSYMBOL_expr = 115,                     /* expr  */
  YYSYMBOL_atrib_expr = 116,               /* atrib_expr  */
  YYSYMBOL_ternary_expr = 117,             /* ternary_expr  */
  YYSYMBOL_or_expr = 118,                  /* or_expr  */
  YYSYMBOL_and_expr = 119,                 /* and_expr  */
  YYSYMBOL_bitor_expr = 120,               /* bitor_expr  */
  YYSYMBOL_bitxor_expr = 121,              /* bitxor_expr  */
  YYSYMBOL_bitand_expr = 122,              /* bitand_expr  */
  YYSYMBOL_equal_expr = 123,               /* equal_expr  */
  YYSYMBOL_relacao_expr = 124,             /* relacao_expr  */
  YYSYMBOL_shift_expr = 125,               /* shift_expr  */
  YYSYMBOL_add_expr = 126,                 /* add_expr  */
  YYSYMBOL_mult_expr = 127,                /* mult_expr  */
  YYSYMBOL_unary_expr = 128,               /* unary_expr  */
  YYSYMBOL_fator = 129,                    /* fator  */
  YYSYMBOL_var = 130,                      /* var  */
  YYSYMBOL_chamada = 131,                  /* chamada  */
  YYSYMBOL_argumentos = 132,               /* argumentos  */
  YYSYMBOL_lista_args = 133,               /* lista_args  */
  YYSYMBOL_typedef_declaracao = 134,       /* typedef_declaracao  */
  YYSYMBOL_lista_identificadores = 135,    /* lista_identificadores  */
  YYSYMBOL_struct_declaracao = 136,        /* struct_declaracao  */
  YYSYMBOL_union_declaracao = 137,         /* union_declaracao  */
  YYSYMBOL_enum_declaracao = 138           /* enum_declaracao  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  312

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


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
       2,    74,     2,    75,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    91,   103,   104,   108,   109,   110,   111,
     112,   119,   133,   147,   161,   179,   179,   188,   195,   195,
     204,   222,   222,   231,   238,   242,   243,   247,   248,   249,
     256,   257,   261,   262,   266,   297,   304,   305,   306,   307,
     308,   309,   319,   329,   339,   346,   347,   351,   354,   361,
     370,   370,   390,   390,   414,   415,   419,   420,   424,   438,
     445,   446,   453,   454,   455,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   475,   476,   480,   480,   489,
     489,   498,   498,   511,   512,   513,   520,   520,   529,   536,
     537,   538,   545,   549,   550,   562,   577,   592,   607,   622,
     637,   644,   645,   649,   650,   654,   655,   659,   660,   664,
     665,   669,   670,   674,   675,   676,   680,   681,   682,   683,
     684,   688,   689,   690,   694,   695,   696,   700,   701,   702,
     703,   707,   708,   720,   732,   733,   734,   735,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   759,   774,   784,
     796,   803,   817,   824,   825,   829,   830,   831,   838,   859,
     866,   878,   893,   905,   912,   924,   931,   943
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
  "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "QUESTION", "AND", "OR",
  "NOT", "BITAND", "BITOR", "BITXOR", "BITNOT", "SHIFTLEFT", "SHIFTRIGHT",
  "LBRACKET", "RBRACKET", "INCLUDE", "POINTER", "AMPERSAND", "UMINUS",
  "UPLUS", "LOWER_THAN_ELSE", "'['", "']'", "$accept", "programa", "$@1",
  "lista_declaracoes", "declaracao", "declaracao_tipo", "switch_stmt",
  "$@2", "for_stmt", "$@3", "do_stmt", "$@4", "continue_stmt", "case_list",
  "case_stmt", "comandos_break", "comandos_opt", "declaracao_variavel",
  "tipo", "lista_variaveis", "variavel", "fun_declaracao", "$@5", "$@6",
  "parametros", "lista_parametros", "param", "inicializador",
  "lista_inicializadores", "stmt", "expr_stmt", "composto_stmt", "$@7",
  "$@8", "$@9", "if_stmt", "while_stmt", "$@10", "return_stmt", "expr",
  "atrib_expr", "ternary_expr", "or_expr", "and_expr", "bitor_expr",
  "bitxor_expr", "bitand_expr", "equal_expr", "relacao_expr", "shift_expr",
  "add_expr", "mult_expr", "unary_expr", "fator", "var", "chamada",
  "argumentos", "lista_args", "typedef_declaracao",
  "lista_identificadores", "struct_declaracao", "union_declaracao",
  "enum_declaracao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-155)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -44,    46,   671,   -44,    23,   -44,    36,    52,    96,   204,
     833,   106,   122,   -21,  1081,  1081,   -44,    -9,  1081,   -44,
     -44,     5,   -44,   -44,   -44,   -44,   139,   140,   141,    42,
     -44,   142,   142,  1081,  1081,   333,   -44,   -44,   -44,   -44,
     -44,   -44,   129,     8,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   130,   -44,   -44,   -37,   103,   100,   101,   102,    38,
      72,    76,   119,    48,   -44,   -44,   267,   -44,   -44,   -44,
     -44,   -44,   -44,   899,  1081,   937,   135,   -44,   -44,   136,
     138,   833,   160,   965,   -44,   871,  1081,   -44,    20,   -44,
     671,   143,   170,   144,   145,   146,   148,   150,   -44,   157,
     158,   165,    25,   107,   147,   147,   -44,   -44,   -44,   -44,
     -44,    32,   -44,   149,   -44,   -44,  1081,  1081,  1081,  1081,
    1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,  1081,
    1081,  1081,  1081,  1081,  1081,   -44,  1081,   167,   -44,   -44,
    1081,  1081,  1081,  1081,  1081,   152,   154,   156,   159,   162,
     -44,   -44,   -44,   180,   166,   164,  1081,   168,   -44,   169,
     173,   116,   509,   -44,   178,   -44,   725,   779,    34,   -44,
     -44,   -44,   -44,   181,  1053,   -44,   184,   183,   103,   100,
     101,   102,    38,    72,    72,    76,    76,    76,    76,   119,
     119,    48,    48,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   833,   833,     4,   833,   -44,   182,   211,
     833,   186,   -44,   -44,  1003,   -44,   -44,   -44,    78,   563,
     108,   617,   185,   -44,     7,   -44,    13,   -44,   -44,    56,
      56,   191,   -44,  1081,   -44,   212,   -44,   -44,   -44,   833,
    1081,   187,   -44,  1081,   -44,   -44,   192,   193,   194,   195,
     196,   201,   216,   203,    26,   -44,    14,   206,   202,   -44,
     207,   -44,   833,   137,   -44,   208,   214,   215,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,  1081,   -44,   -44,
     217,    56,   244,   -44,  1031,   220,    10,   -44,   221,   -44,
    1081,   -44,   -44,   -44,   -44,   228,   229,   394,   -44,   -44,
     -44,   225,   -44,   394,   455,   -44,   240,   833,   -44,   230,
     -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,   138,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,    76,    77,     0,   142,
      36,   139,    38,    39,    40,   140,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     5,     9,    70,    72,
      71,    73,     0,     0,     7,     8,    65,    66,    67,    68,
      69,     0,    92,    93,   101,   103,   105,   107,   109,   111,
     113,   116,   121,   124,   127,   131,     0,   144,    14,    11,
      12,    13,    10,     0,     0,     0,     0,    90,   139,     0,
       0,     0,     0,     0,    24,     0,     0,   135,   143,   134,
       0,     0,     0,     0,    41,    42,    43,     0,    37,     0,
       0,     0,     0,   148,   132,   133,   136,   137,     4,     6,
      35,    47,    44,    34,    45,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    89,    74,     0,     0,     0,     0,     0,   156,     0,
     153,     0,     0,    80,     0,   145,     0,     0,     0,   159,
      41,    42,    43,     0,     0,    50,     0,     0,   104,   106,
     108,   110,   112,   115,   114,   119,   120,   117,   118,   122,
     123,   125,   126,   128,   129,   130,    94,   149,    95,    96,
      97,    98,    99,     0,     0,     0,     0,    86,     0,     0,
       0,     0,   152,   151,     0,   150,    78,    82,     0,     0,
       0,     0,     0,   160,     0,   158,     0,    49,    48,    55,
      55,    47,    46,     0,    85,    83,    17,    15,    88,     0,
       0,     0,    20,     0,   157,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,    54,    57,
       0,   102,     0,     0,    87,     0,     0,     0,   163,   162,
     165,   164,   167,   166,   161,    61,    60,     0,    59,    58,
       0,     0,     0,    84,     0,     0,     0,    26,     0,    23,
       0,    63,    51,    56,    53,     0,     0,     0,    16,    25,
      22,     0,    29,     0,     0,    28,    31,     0,    27,     0,
      19,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   -44,     2,   -33,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -25,   -43,   -44,   -44,   -26,   -44,
      86,   -44,   -44,   -44,    35,   -44,   -17,   -44,   -44,   -10,
     -44,   -14,   -44,   -44,   -44,   -44,   -44,   -44,   -44,    -8,
     -38,    37,   -44,   155,   161,   188,   153,   189,    24,     9,
      21,    22,    -2,   -44,    -7,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,   304,    36,    37,    38,   263,    39,   156,
      40,    81,    41,   286,   287,   305,   306,    42,    43,   113,
     114,    44,   229,   230,   257,   258,   259,   227,   254,    45,
      46,    47,    90,    91,    92,    48,    49,   239,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   159,   160,    68,   224,
      69,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    79,   108,   102,    35,   236,   -37,    88,    88,   110,
      93,    85,    87,    89,   253,   278,     5,   284,   285,   116,
     -37,   117,   -79,   111,   104,   105,    88,    88,    13,   279,
     -37,   106,   107,   112,   237,   222,    14,    15,   251,   112,
     173,   298,   252,    97,   -64,    18,     3,    19,   -64,   223,
     112,    78,    72,    86,   174,    25,   137,   276,   122,   123,
      30,   277,    31,    32,   175,   146,   147,   149,    73,   138,
     139,   153,    33,   132,   133,   134,    34,   158,   161,    20,
      98,    22,    23,    24,    74,    99,   100,   101,   124,   125,
     126,   127,   162,    20,    98,    22,    23,    24,   196,    99,
     100,   101,   198,   199,   200,   201,   202,    72,   177,   246,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    75,   108,
     193,   194,   195,   185,   186,   187,   188,    72,    83,   248,
     128,   129,   130,   131,   284,   285,   183,   184,   211,   189,
     190,    84,   191,   192,    94,    95,    96,   103,   109,   115,
     118,   119,   121,   120,   150,   151,   228,   152,   219,   221,
     154,   164,   170,   171,   163,   166,   167,   165,   168,   169,
     172,    86,   197,   137,   176,   203,   108,   204,   108,   205,
     208,   215,   206,   234,   235,   207,   238,   210,   209,   231,
     242,   212,   213,   256,   256,    76,   245,     5,   214,   217,
     225,   233,   241,   174,   240,   243,   250,   262,   255,    13,
     266,   268,   269,   270,   271,   272,    88,    14,    15,   264,
     273,   274,   265,    77,   275,   267,    18,   281,    19,   280,
     282,   288,    78,   289,   290,   294,    25,    17,   297,   309,
     300,    30,   283,    31,    32,   256,   302,   303,   307,   311,
     308,   299,   232,    33,   293,   260,   292,    34,   135,   291,
     261,   108,   178,   181,     0,     0,   296,     0,     0,   179,
       0,     0,   301,  -143,  -143,  -143,  -143,  -143,  -143,   136,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,   310,  -143,     0,
    -143,     0,  -143,   137,     0,     0,     0,   180,     0,     0,
     182,     0,     0,     0,     0,     0,   138,   139,   140,   141,
     142,   143,   144,  -143,  -143,  -143,     0,  -143,  -143,  -143,
       0,  -143,  -143,    -3,     4,     0,     5,     6,     0,     7,
       0,     0,  -143,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,    16,    17,     0,    18,     0,    19,     0,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     4,    34,     5,     6,     0,
       7,   -32,   -32,   -32,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,    16,    17,   -32,    18,     0,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     4,    34,     5,     6,
       0,     7,   -33,   -33,   -33,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,    16,    17,   -33,    18,     0,    19,
       0,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,     0,     0,     0,     0,
       4,     0,     5,     6,    33,     7,     0,     0,    34,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,    16,    17,
     216,    18,     0,    19,     0,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
       0,     0,     0,     0,     4,     0,     5,     6,    33,     7,
       0,     0,    34,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,    16,    17,   247,    18,     0,    19,     0,     0,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,     0,     0,     0,     0,     4,     0,
       5,     6,    33,     7,     0,     0,    34,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,    16,    17,   249,    18,
       0,    19,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    31,    32,     0,     0,
       0,     0,     4,     0,     5,     6,    33,     7,     0,     0,
      34,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
      16,    17,     0,    18,     0,    19,     0,     0,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,    32,     0,     0,     0,     0,   218,     0,     5,     6,
      33,     7,     0,     0,    34,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,    16,    17,     0,    18,     0,    19,
       0,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,     0,     0,     0,     0,
     220,     0,     5,     6,    33,     7,     0,     0,    34,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,    16,    17,
       0,    18,     0,    19,     0,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
       0,     0,     0,     0,    80,     0,     5,     6,    33,     7,
       0,     0,    34,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,    16,    17,     0,    18,     0,    19,     0,     0,
       0,    78,   157,     0,     5,    25,     0,     0,     0,     0,
      30,     0,    31,    32,     0,     0,    13,     0,     0,     0,
       0,     0,    33,     0,    14,    15,    34,     0,     0,     0,
     145,     0,     5,    18,  -154,    19,     0,     0,     0,    78,
       0,     0,     0,    25,    13,     0,     0,     0,    30,     0,
      31,    32,    14,    15,     0,     0,     0,     0,     0,     0,
      33,    18,     0,    19,    34,     0,     0,    78,   148,     0,
       5,    25,     0,     0,     0,     0,    30,     0,    31,    32,
       0,     0,    13,     0,     0,     0,     0,     0,    33,     0,
      14,    15,    34,     0,     0,     0,   155,     0,   -18,    18,
       0,    19,     0,     0,     0,    78,     0,     0,     0,    25,
     -18,     0,     0,     0,    30,     0,    31,    32,   -18,   -18,
       0,     0,     0,     0,     0,     0,    33,   -18,     0,   -18,
      34,     0,     0,   -18,   244,     0,     5,   -18,     0,     0,
       0,     0,   -18,     0,   -18,   -18,     0,     0,    13,     0,
       0,     0,     0,     0,   -18,     0,    14,    15,   -18,     0,
       0,     0,   295,     0,     5,    18,     0,    19,     0,     0,
       0,    78,     0,     0,     0,    25,    13,     0,     0,     0,
      30,     0,    31,    32,    14,    15,     5,     0,     0,     0,
       0,     0,    33,    18,     0,    19,    34,     0,    13,    78,
       0,     0,     0,    25,     0,     0,    14,    15,    30,     0,
      31,    32,     0,   226,     5,    18,     0,    19,     0,     0,
      33,    78,     0,     0,    34,    25,    13,     0,     0,     0,
      30,     0,    31,    32,    14,    15,     0,     0,     0,     0,
       0,     0,    33,    18,     0,    19,    34,     0,     0,    78,
       0,     0,     0,    25,     0,     0,     0,     0,    30,     0,
      31,    32,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,    34
};

static const yytype_int16 yycheck[] =
{
      10,     9,    35,    29,     2,     1,     1,    14,    15,     1,
      18,    32,    14,    15,     1,     1,     3,     7,     8,    56,
      15,    58,    31,    15,    31,    32,    33,    34,    15,    15,
      25,    33,    34,    25,    30,     1,    23,    24,    31,    25,
      15,    31,    35,     1,    31,    32,     0,    34,    35,    15,
      25,    38,    29,    74,    22,    42,    36,    31,    20,    21,
      47,    35,    49,    50,    32,    73,    74,    75,    32,    49,
      50,    81,    59,    25,    26,    27,    63,    85,    86,    37,
      38,    39,    40,    41,    32,    43,    44,    45,    16,    17,
      18,    19,    90,    37,    38,    39,    40,    41,   136,    43,
      44,    45,   140,   141,   142,   143,   144,    29,   116,    31,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    32,   162,
     132,   133,   134,   124,   125,   126,   127,    29,    32,    31,
      64,    65,    23,    24,     7,     8,   122,   123,   156,   128,
     129,    29,   130,   131,    15,    15,    15,    15,    29,    29,
      57,    61,    60,    62,    29,    29,   174,    29,   166,   167,
      10,     1,    15,    15,    31,    30,    30,    33,    30,    29,
      15,    74,    15,    36,    35,    33,   219,    33,   221,    33,
      10,    75,    33,   203,   204,    33,   206,    33,    32,    15,
     210,    33,    33,   229,   230,     1,   214,     3,    35,    31,
      29,    28,     1,    22,    32,    29,    31,     5,   226,    15,
      33,    29,    29,    29,    29,    29,   233,    23,    24,   239,
      29,    15,   240,    29,    31,   243,    32,    35,    34,    33,
      33,    33,    38,    29,    29,     1,    42,    30,    28,     9,
      29,    47,   262,    49,    50,   281,    28,    28,    33,    29,
     303,   286,   176,    59,   281,   230,   280,    63,     1,   277,
     233,   304,   117,   120,    -1,    -1,   284,    -1,    -1,   118,
      -1,    -1,   290,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,   307,    31,    -1,
      33,    -1,    35,    36,    -1,    -1,    -1,   119,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    61,    62,
      -1,    64,    65,     0,     1,    -1,     3,     4,    -1,     6,
      -1,    -1,    75,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,     1,    63,     3,     4,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,     1,    63,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    -1,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    59,     6,    -1,    -1,    63,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    59,     6,
      -1,    -1,    63,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,    59,     6,    -1,    -1,    63,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,    59,     6,    -1,    -1,
      63,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    32,    -1,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
      59,     6,    -1,    -1,    63,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    -1,    32,    -1,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,    59,     6,    -1,    -1,    63,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    -1,    29,    30,
      -1,    32,    -1,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,    59,     6,
      -1,    -1,    63,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    -1,    32,    -1,    34,    -1,    -1,
      -1,    38,     1,    -1,     3,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    -1,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    23,    24,    63,    -1,    -1,    -1,
       1,    -1,     3,    32,    33,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    42,    15,    -1,    -1,    -1,    47,    -1,
      49,    50,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    32,    -1,    34,    63,    -1,    -1,    38,     1,    -1,
       3,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      23,    24,    63,    -1,    -1,    -1,     1,    -1,     3,    32,
      -1,    34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      15,    -1,    -1,    -1,    47,    -1,    49,    50,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    32,    -1,    34,
      63,    -1,    -1,    38,     1,    -1,     3,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    -1,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    23,    24,    63,    -1,
      -1,    -1,     1,    -1,     3,    32,    -1,    34,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    15,    -1,    -1,    -1,
      47,    -1,    49,    50,    23,    24,     3,    -1,    -1,    -1,
      -1,    -1,    59,    32,    -1,    34,    63,    -1,    15,    38,
      -1,    -1,    -1,    42,    -1,    -1,    23,    24,    47,    -1,
      49,    50,    -1,    30,     3,    32,    -1,    34,    -1,    -1,
      59,    38,    -1,    -1,    63,    42,    15,    -1,    -1,    -1,
      47,    -1,    49,    50,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    32,    -1,    34,    63,    -1,    -1,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    77,    78,     0,     1,     3,     4,     6,    10,    11,
      12,    13,    14,    15,    23,    24,    29,    30,    32,    34,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    49,    50,    59,    63,    79,    80,    81,    82,    84,
      86,    88,    93,    94,    97,   105,   106,   107,   111,   112,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   134,   136,
     137,   138,    29,    32,    32,    32,     1,    29,    38,   115,
       1,    87,   105,    32,    29,    32,    74,   128,   130,   128,
     108,   109,   110,   115,    15,    15,    15,     1,    38,    43,
      44,    45,    94,    15,   130,   130,   128,   128,    80,    29,
       1,    15,    25,    95,    96,    29,    56,    58,    57,    61,
      62,    60,    20,    21,    16,    17,    18,    19,    64,    65,
      23,    24,    25,    26,    27,     1,    22,    36,    49,    50,
      51,    52,    53,    54,    55,     1,   115,   115,     1,   115,
      29,    29,    29,   105,    10,     1,    85,     1,   115,   132,
     133,   115,    79,    31,     1,    33,    30,    30,    30,    29,
      15,    15,    15,    15,    22,    32,    35,   115,   119,   120,
     121,   122,   123,   124,   124,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   128,   116,    15,   116,   116,
     116,   116,   116,    33,    33,    33,    33,    33,    10,    32,
      33,   115,    33,    33,    35,    75,    31,    31,     1,    79,
       1,    79,     1,    15,   135,    29,    30,   103,   115,    98,
      99,    15,    96,    28,   105,   105,     1,    30,   105,   113,
      32,     1,   105,    29,     1,   115,    31,    31,    31,    31,
      31,    31,    35,     1,   104,   115,    94,   100,   101,   102,
     100,   117,     5,    83,   105,   115,    33,   115,    29,    29,
      29,    29,    29,    29,    15,    31,    31,    35,     1,    15,
      33,    35,    33,   105,     7,     8,    89,    90,    33,    29,
      29,   115,   107,   102,     1,     1,   115,    28,    31,    90,
      29,   115,    28,    28,    79,    91,    92,    33,    91,     9,
     105,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    78,    77,    79,    79,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    83,    82,    82,    85,    84,
      84,    87,    86,    86,    88,    89,    89,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      98,    97,    99,    97,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   106,   108,   107,   109,
     107,   110,   107,   111,   111,   111,   113,   112,   112,   114,
     114,   114,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   124,   124,   124,   124,
     124,   125,   125,   125,   126,   126,   126,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   136,   136,   137,   137,   138,   138
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       2,     1,     1,     1,     1,     0,     8,     5,     0,    10,
       5,     0,     8,     7,     2,     2,     1,     4,     3,     3,
       3,     1,     0,     1,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     3,     1,     3,     3,
       0,     7,     0,     7,     1,     0,     3,     1,     2,     2,
       3,     3,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     0,     4,     0,
       3,     0,     4,     5,     7,     5,     0,     6,     5,     3,
       2,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     5,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     1,     3,
       4,     4,     4,     1,     0,     3,     1,     3,     4,     3,
       1,     3,     6,     6,     6,     6,     6,     6
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
#line 91 "exemplo.y"
    { 
        /* Inicializar tabela de símbolos no início do programa */
        iniciarTabelaSimbolos(); 
    }
#line 1614 "exemplo.tab.c"
    break;

  case 3: /* programa: $@1 lista_declaracoes  */
#line 95 "exemplo.y"
                      { 
        root = (yyvsp[0].node); 
        /* Finalizar tabela de símbolos no final */
        finalizarTabelaSimbolos();
    }
#line 1624 "exemplo.tab.c"
    break;

  case 4: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 103 "exemplo.y"
                                 { (yyval.node) = concatenarStmt((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1630 "exemplo.tab.c"
    break;

  case 5: /* lista_declaracoes: declaracao  */
#line 104 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1636 "exemplo.tab.c"
    break;

  case 6: /* declaracao: declaracao_variavel SEMICOLON  */
#line 108 "exemplo.y"
                                  { (yyval.node) = (yyvsp[-1].node); }
#line 1642 "exemplo.tab.c"
    break;

  case 7: /* declaracao: fun_declaracao  */
#line 109 "exemplo.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1648 "exemplo.tab.c"
    break;

  case 8: /* declaracao: stmt  */
#line 110 "exemplo.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1654 "exemplo.tab.c"
    break;

  case 9: /* declaracao: declaracao_tipo  */
#line 111 "exemplo.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1660 "exemplo.tab.c"
    break;

  case 10: /* declaracao: error SEMICOLON  */
#line 112 "exemplo.y"
                      { 
        (yyval.node) = NULL; 
        yyerror("Declaração inválida"); 
    }
#line 1669 "exemplo.tab.c"
    break;

  case 11: /* declaracao_tipo: struct_declaracao  */
#line 119 "exemplo.y"
                      { 
        /* Verificar se struct já foi declarada no escopo atual */
        if ((yyvsp[0].node) && (yyvsp[0].node)->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].node)->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Struct '%s' já declarada neste escopo", (yyvsp[0].node)->valor_str);
                yyerror(erro);
            } else {
                inserirSimbolo((yyvsp[0].node)->valor_str, TIPO_STRUCT);
            }
        }
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1688 "exemplo.tab.c"
    break;

  case 12: /* declaracao_tipo: union_declaracao  */
#line 133 "exemplo.y"
                       { 
        /* Verificar se union já foi declarada no escopo atual */
        if ((yyvsp[0].node) && (yyvsp[0].node)->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].node)->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Union '%s' já declarada neste escopo", (yyvsp[0].node)->valor_str);
                yyerror(erro);
            } else {
                inserirSimbolo((yyvsp[0].node)->valor_str, TIPO_UNION);
            }
        }
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1707 "exemplo.tab.c"
    break;

  case 13: /* declaracao_tipo: enum_declaracao  */
#line 147 "exemplo.y"
                      { 
        /* Verificar se enum já foi declarado no escopo atual */
        if ((yyvsp[0].node) && (yyvsp[0].node)->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].node)->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Enum '%s' já declarado neste escopo", (yyvsp[0].node)->valor_str);
                yyerror(erro);
            } else {
                inserirSimbolo((yyvsp[0].node)->valor_str, TIPO_ENUM);
            }
        }
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1726 "exemplo.tab.c"
    break;

  case 14: /* declaracao_tipo: typedef_declaracao  */
#line 161 "exemplo.y"
                         { 
        /* Verificar se typedef já foi declarado no escopo atual */
        if ((yyvsp[0].node) && (yyvsp[0].node)->valor_str) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].node)->valor_str);
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Typedef '%s' já declarado neste escopo", (yyvsp[0].node)->valor_str);
                yyerror(erro);
            } else {
                /* Para typedef, assumir o tipo base (seria determinado pela análise completa) */
                inserirSimbolo((yyvsp[0].node)->valor_str, TIPO_INT); /* Placeholder - tipo seria determinado pelo typedef */
            }
        }
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1746 "exemplo.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 179 "exemplo.y"
                                     {
        /* Iniciar novo escopo para o switch */
        iniciarEscopo();
    }
#line 1755 "exemplo.tab.c"
    break;

  case 16: /* switch_stmt: SWITCH LPAREN expr RPAREN LBRACE $@2 case_list RBRACE  */
#line 183 "exemplo.y"
                     { 
        /* Finalizar escopo do switch */
        finalizarEscopo();
        (yyval.node) = criarNoSwitch((yyvsp[-5].node), (yyvsp[-1].node)); 
    }
#line 1765 "exemplo.tab.c"
    break;

  case 17: /* switch_stmt: SWITCH LPAREN expr RPAREN error  */
#line 188 "exemplo.y"
                                      { 
        (yyval.node) = NULL; 
        yyerror("Estrutura switch incompleta ou inválida"); 
    }
#line 1774 "exemplo.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 195 "exemplo.y"
               {
        /* Iniciar novo escopo para o for */
        iniciarEscopo();
    }
#line 1783 "exemplo.tab.c"
    break;

  case 19: /* for_stmt: FOR LPAREN $@3 expr SEMICOLON expr SEMICOLON expr RPAREN stmt  */
#line 199 "exemplo.y"
                                                   {
        /* Finalizar escopo do for */
        finalizarEscopo();
        (yyval.node) = criarNoFor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1793 "exemplo.tab.c"
    break;

  case 20: /* for_stmt: FOR LPAREN error RPAREN stmt  */
#line 204 "exemplo.y"
                                   {
        (yyval.node) = NULL;
        yyerror("Formato inválido para estrutura for");
    }
#line 1802 "exemplo.tab.c"
    break;

  case 21: /* $@4: %empty  */
#line 222 "exemplo.y"
       {
        /* Iniciar novo escopo para o do-while */
        iniciarEscopo();
    }
#line 1811 "exemplo.tab.c"
    break;

  case 22: /* do_stmt: DO $@4 stmt WHILE LPAREN expr RPAREN SEMICOLON  */
#line 226 "exemplo.y"
                                            { 
        /* Finalizar escopo do do-while */
        finalizarEscopo();
        (yyval.node) = criarNoDoWhile((yyvsp[-2].node), (yyvsp[-5].node)); 
    }
#line 1821 "exemplo.tab.c"
    break;

  case 23: /* do_stmt: DO stmt WHILE LPAREN error RPAREN SEMICOLON  */
#line 231 "exemplo.y"
                                                  {
        (yyval.node) = NULL;
        yyerror("Expressão inválida na condição do do-while");
    }
#line 1830 "exemplo.tab.c"
    break;

  case 24: /* continue_stmt: CONTINUE SEMICOLON  */
#line 238 "exemplo.y"
                       { (yyval.node) = criarNoContinue(); }
#line 1836 "exemplo.tab.c"
    break;

  case 25: /* case_list: case_list case_stmt  */
#line 242 "exemplo.y"
                        { (yyval.node) = concatenarStmt((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1842 "exemplo.tab.c"
    break;

  case 26: /* case_list: case_stmt  */
#line 243 "exemplo.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1848 "exemplo.tab.c"
    break;

  case 27: /* case_stmt: CASE expr COLON comandos_break  */
#line 247 "exemplo.y"
                                   { (yyval.node) = criarNoCase((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1854 "exemplo.tab.c"
    break;

  case 28: /* case_stmt: DEFAULT COLON comandos_break  */
#line 248 "exemplo.y"
                                   { (yyval.node) = criarNoCase(NULL, (yyvsp[0].node)); }
#line 1860 "exemplo.tab.c"
    break;

  case 29: /* case_stmt: CASE error COLON  */
#line 249 "exemplo.y"
                       { 
        (yyval.node) = NULL; 
        yyerror("Expressão inválida em case"); 
    }
#line 1869 "exemplo.tab.c"
    break;

  case 30: /* comandos_break: comandos_opt BREAK SEMICOLON  */
#line 256 "exemplo.y"
                                 { (yyval.node) = concatenarStmt((yyvsp[-2].node), criarNoBreak()); }
#line 1875 "exemplo.tab.c"
    break;

  case 31: /* comandos_break: comandos_opt  */
#line 257 "exemplo.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1881 "exemplo.tab.c"
    break;

  case 32: /* comandos_opt: %empty  */
#line 261 "exemplo.y"
                { (yyval.node) = NULL; }
#line 1887 "exemplo.tab.c"
    break;

  case 33: /* comandos_opt: lista_declaracoes  */
#line 262 "exemplo.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1893 "exemplo.tab.c"
    break;

  case 34: /* declaracao_variavel: tipo lista_variaveis  */
#line 266 "exemplo.y"
                         { 
        /* Processar cada variável na lista com o tipo especificado */
        ASTNode *current = (yyvsp[0].node);
        TipoSimbolo tipo_var = TIPO_ERRO;
        
        /* Converter string do tipo para TipoSimbolo */
        if ((yyvsp[-1].node) && (yyvsp[-1].node)->valor_str) {
            if (strcmp((yyvsp[-1].node)->valor_str, "int") == 0) tipo_var = TIPO_INT;
            else if (strcmp((yyvsp[-1].node)->valor_str, "float") == 0) tipo_var = TIPO_FLOAT;
            else if (strcmp((yyvsp[-1].node)->valor_str, "char") == 0) tipo_var = TIPO_CHAR;
            else if (strcmp((yyvsp[-1].node)->valor_str, "double") == 0) tipo_var = TIPO_DOUBLE;
            else if (strcmp((yyvsp[-1].node)->valor_str, "void") == 0) tipo_var = TIPO_VOID;
        }
        
        /* Percorrer lista de variáveis e inserir na tabela de símbolos */
        while (current != NULL) {
            if (current->valor_str) {
                Simbolo *existente = buscarSimboloNoEscopoAtual(current->valor_str);
                if (existente != NULL) {
                    char erro[256];
                    snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' já declarada neste escopo", current->valor_str);
                    yyerror(erro);
                } else {
                    inserirSimbolo(current->valor_str, tipo_var);
                }
            }
            current = current->prox;
        }
        
        (yyval.node) = criarNoVarDecl((yyvsp[0].node)->valor_str, criarNoType((yyvsp[-1].node)->valor_str)); 
    }
#line 1929 "exemplo.tab.c"
    break;

  case 35: /* declaracao_variavel: tipo error  */
#line 297 "exemplo.y"
                 { 
        (yyval.node) = NULL; 
        yyerror("Declaração de variável inválida"); 
    }
#line 1938 "exemplo.tab.c"
    break;

  case 36: /* tipo: INT  */
#line 304 "exemplo.y"
        { (yyval.node) = criarNoType("int"); }
#line 1944 "exemplo.tab.c"
    break;

  case 37: /* tipo: FLOAT  */
#line 305 "exemplo.y"
            { (yyval.node) = criarNoType("float"); }
#line 1950 "exemplo.tab.c"
    break;

  case 38: /* tipo: CHAR  */
#line 306 "exemplo.y"
           { (yyval.node) = criarNoType("char"); }
#line 1956 "exemplo.tab.c"
    break;

  case 39: /* tipo: VOID  */
#line 307 "exemplo.y"
           { (yyval.node) = criarNoType("void"); }
#line 1962 "exemplo.tab.c"
    break;

  case 40: /* tipo: DOUBLE  */
#line 308 "exemplo.y"
             { (yyval.node) = criarNoType("double"); }
#line 1968 "exemplo.tab.c"
    break;

  case 41: /* tipo: STRUCT ID  */
#line 309 "exemplo.y"
                { 
        /* Verificar se struct foi declarada */
        Simbolo *struct_sym = buscarSimbolo((yyvsp[0].strValue));
        if (struct_sym == NULL || struct_sym->tipo != TIPO_STRUCT) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Struct '%s' não declarada", (yyvsp[0].strValue));
            yyerror(erro);
        }
        (yyval.node) = criarNoUnion("struct", (yyvsp[0].strValue)); 
    }
#line 1983 "exemplo.tab.c"
    break;

  case 42: /* tipo: UNION ID  */
#line 319 "exemplo.y"
               { 
        /* Verificar se union foi declarada */
        Simbolo *union_sym = buscarSimbolo((yyvsp[0].strValue));
        if (union_sym == NULL || union_sym->tipo != TIPO_UNION) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Union '%s' não declarada", (yyvsp[0].strValue));
            yyerror(erro);
        }
        (yyval.node) = criarNoUnion("union", (yyvsp[0].strValue)); 
    }
#line 1998 "exemplo.tab.c"
    break;

  case 43: /* tipo: ENUM ID  */
#line 329 "exemplo.y"
              { 
        /* Verificar se enum foi declarado */
        Simbolo *enum_sym = buscarSimbolo((yyvsp[0].strValue));
        if (enum_sym == NULL || enum_sym->tipo != TIPO_ENUM) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enum '%s' não declarado", (yyvsp[0].strValue));
            yyerror(erro);
        }
        (yyval.node) = criarNoEnum((yyvsp[0].strValue)); 
    }
#line 2013 "exemplo.tab.c"
    break;

  case 44: /* tipo: tipo MULT  */
#line 339 "exemplo.y"
                {
        (yyval.node) = NULL;
        report_unsupported_feature("Ponteiros", yylineno);
    }
#line 2022 "exemplo.tab.c"
    break;

  case 45: /* lista_variaveis: variavel  */
#line 346 "exemplo.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2028 "exemplo.tab.c"
    break;

  case 46: /* lista_variaveis: lista_variaveis COMMA variavel  */
#line 347 "exemplo.y"
                                     { (yyval.node) = concatenarStmt((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2034 "exemplo.tab.c"
    break;

  case 47: /* variavel: ID  */
#line 351 "exemplo.y"
       { 
        (yyval.node) = criarNoVar((yyvsp[0].strValue)); 
    }
#line 2042 "exemplo.tab.c"
    break;

  case 48: /* variavel: ID ASSIGN expr  */
#line 354 "exemplo.y"
                     { 
        ASTNode *var = criarNoVar((yyvsp[-2].strValue));
        ASTNode *assign = criarNoAssign('=', var, (yyvsp[0].node));
        // Manter o nome da variável no nó principal para facilitar o processamento
        assign->valor_str = strdup((yyvsp[-2].strValue));
        (yyval.node) = assign;
    }
#line 2054 "exemplo.tab.c"
    break;

  case 49: /* variavel: ID ASSIGN inicializador  */
#line 361 "exemplo.y"
                              { 
        ASTNode *var = criarNoVar((yyvsp[-2].strValue));
        ASTNode *assign = criarNoAssign('=', var, (yyvsp[0].node));
        // Manter o nome da variável no nó principal para facilitar o processamento
        assign->valor_str = strdup((yyvsp[-2].strValue));
        (yyval.node) = assign;
    }
#line 2066 "exemplo.tab.c"
    break;

  case 50: /* $@5: %empty  */
#line 370 "exemplo.y"
                   {
        /* Verificar se função já foi declarada no escopo atual */
        if ((yyvsp[-1].strValue)) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[-1].strValue));
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Função '%s' já declarada neste escopo", (yyvsp[-1].strValue));
                yyerror(erro);
            } else {
                inserirSimbolo((yyvsp[-1].strValue), TIPO_FUNCAO);
            }
        }
        /* Iniciar novo escopo para parâmetros e corpo da função */
        iniciarEscopo();
    }
#line 2086 "exemplo.tab.c"
    break;

  case 51: /* fun_declaracao: tipo ID LPAREN $@5 parametros RPAREN composto_stmt  */
#line 385 "exemplo.y"
                                    { 
        /* Finalizar escopo da função */
        finalizarEscopo();
        (yyval.node) = criarNoFuncDecl((yyvsp[-5].strValue), (yyvsp[-6].node), (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2096 "exemplo.tab.c"
    break;

  case 52: /* $@6: %empty  */
#line 390 "exemplo.y"
                     {
        /* Verificar se função já foi declarada no escopo atual */
        if ((yyvsp[-1].strValue)) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[-1].strValue));
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Função '%s' já declarada neste escopo", (yyvsp[-1].strValue));
                yyerror(erro);
            } else {
                inserirSimbolo((yyvsp[-1].strValue), TIPO_FUNCAO);
            }
        }
        /* Iniciar novo escopo para parâmetros */
        iniciarEscopo();
    }
#line 2116 "exemplo.tab.c"
    break;

  case 53: /* fun_declaracao: tipo ID LPAREN $@6 parametros RPAREN error  */
#line 405 "exemplo.y"
                            { 
        /* Finalizar escopo mesmo com erro */
        finalizarEscopo();
        (yyval.node) = NULL; 
        yyerror("Corpo de função inválido ou ausente"); 
    }
#line 2127 "exemplo.tab.c"
    break;

  case 54: /* parametros: lista_parametros  */
#line 414 "exemplo.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2133 "exemplo.tab.c"
    break;

  case 55: /* parametros: %empty  */
#line 415 "exemplo.y"
                  { (yyval.node) = NULL; }
#line 2139 "exemplo.tab.c"
    break;

  case 56: /* lista_parametros: lista_parametros COMMA param  */
#line 419 "exemplo.y"
                                 { (yyval.node) = concatenarParam((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2145 "exemplo.tab.c"
    break;

  case 57: /* lista_parametros: param  */
#line 420 "exemplo.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2151 "exemplo.tab.c"
    break;

  case 58: /* param: tipo ID  */
#line 424 "exemplo.y"
            { 
        /* Verificar se parâmetro já foi declarado no escopo atual */
        if ((yyvsp[0].strValue)) {
            Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].strValue));
            if (existente != NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Parâmetro '%s' já declarado neste escopo", (yyvsp[0].strValue));
                yyerror(erro);
            } else {
                inserirSimbolo((yyvsp[0].strValue), TIPO_VARIAVEL);
            }
        }
        (yyval.node) = criarNoParam((yyvsp[0].strValue), (yyvsp[-1].node)); 
    }
#line 2170 "exemplo.tab.c"
    break;

  case 59: /* param: tipo error  */
#line 438 "exemplo.y"
                 { 
        (yyval.node) = NULL; 
        yyerror("Parâmetro inválido"); 
    }
#line 2179 "exemplo.tab.c"
    break;

  case 60: /* inicializador: LBRACE lista_inicializadores RBRACE  */
#line 445 "exemplo.y"
                                        { (yyval.node) = (yyvsp[-1].node); }
#line 2185 "exemplo.tab.c"
    break;

  case 61: /* inicializador: LBRACE error RBRACE  */
#line 446 "exemplo.y"
                          { 
        (yyval.node) = NULL; 
        yyerror("Lista de inicialização inválida"); 
    }
#line 2194 "exemplo.tab.c"
    break;

  case 62: /* lista_inicializadores: expr  */
#line 453 "exemplo.y"
         { (yyval.node) = criarNoInit((yyvsp[0].node), NULL); }
#line 2200 "exemplo.tab.c"
    break;

  case 63: /* lista_inicializadores: lista_inicializadores COMMA expr  */
#line 454 "exemplo.y"
                                       { (yyval.node) = criarNoInit((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2206 "exemplo.tab.c"
    break;

  case 64: /* lista_inicializadores: %empty  */
#line 455 "exemplo.y"
                  { (yyval.node) = NULL; }
#line 2212 "exemplo.tab.c"
    break;

  case 65: /* stmt: expr_stmt  */
#line 459 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2218 "exemplo.tab.c"
    break;

  case 66: /* stmt: composto_stmt  */
#line 460 "exemplo.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2224 "exemplo.tab.c"
    break;

  case 67: /* stmt: if_stmt  */
#line 461 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2230 "exemplo.tab.c"
    break;

  case 68: /* stmt: while_stmt  */
#line 462 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2236 "exemplo.tab.c"
    break;

  case 69: /* stmt: return_stmt  */
#line 463 "exemplo.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2242 "exemplo.tab.c"
    break;

  case 70: /* stmt: switch_stmt  */
#line 464 "exemplo.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2248 "exemplo.tab.c"
    break;

  case 71: /* stmt: do_stmt  */
#line 465 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2254 "exemplo.tab.c"
    break;

  case 72: /* stmt: for_stmt  */
#line 466 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2260 "exemplo.tab.c"
    break;

  case 73: /* stmt: continue_stmt  */
#line 467 "exemplo.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2266 "exemplo.tab.c"
    break;

  case 74: /* stmt: error SEMICOLON  */
#line 468 "exemplo.y"
                      { 
        (yyval.node) = NULL; 
        yyerror("Comando inválido"); 
    }
#line 2275 "exemplo.tab.c"
    break;

  case 75: /* expr_stmt: expr SEMICOLON  */
#line 475 "exemplo.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 2281 "exemplo.tab.c"
    break;

  case 76: /* expr_stmt: SEMICOLON  */
#line 476 "exemplo.y"
                { (yyval.node) = NULL; }
#line 2287 "exemplo.tab.c"
    break;

  case 77: /* $@7: %empty  */
#line 480 "exemplo.y"
           {
        /* Iniciar novo escopo para bloco composto */
        iniciarEscopo();
    }
#line 2296 "exemplo.tab.c"
    break;

  case 78: /* composto_stmt: LBRACE $@7 lista_declaracoes RBRACE  */
#line 484 "exemplo.y"
                             { 
        /* Finalizar escopo do bloco composto */
        finalizarEscopo();
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2306 "exemplo.tab.c"
    break;

  case 79: /* $@8: %empty  */
#line 489 "exemplo.y"
             {
        /* Iniciar novo escopo para bloco vazio */
        iniciarEscopo();
    }
#line 2315 "exemplo.tab.c"
    break;

  case 80: /* composto_stmt: LBRACE $@8 RBRACE  */
#line 493 "exemplo.y"
           { 
        /* Finalizar escopo do bloco vazio */
        finalizarEscopo();
        (yyval.node) = NULL; 
    }
#line 2325 "exemplo.tab.c"
    break;

  case 81: /* $@9: %empty  */
#line 498 "exemplo.y"
             {
        /* Iniciar novo escopo mesmo com erro */
        iniciarEscopo();
    }
#line 2334 "exemplo.tab.c"
    break;

  case 82: /* composto_stmt: LBRACE $@9 error RBRACE  */
#line 502 "exemplo.y"
                 { 
        /* Finalizar escopo mesmo com erro */
        finalizarEscopo();
        (yyval.node) = NULL; 
        yyerror("Bloco de comandos com erro"); 
    }
#line 2345 "exemplo.tab.c"
    break;

  case 83: /* if_stmt: IF LPAREN expr RPAREN stmt  */
#line 511 "exemplo.y"
                                                     { (yyval.node) = criarNoIf((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2351 "exemplo.tab.c"
    break;

  case 84: /* if_stmt: IF LPAREN expr RPAREN stmt ELSE stmt  */
#line 512 "exemplo.y"
                                           { (yyval.node) = criarNoIf((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2357 "exemplo.tab.c"
    break;

  case 85: /* if_stmt: IF LPAREN error RPAREN stmt  */
#line 513 "exemplo.y"
                                  { 
        (yyval.node) = NULL; 
        yyerror("Expressão condicional inválida no if"); 
    }
#line 2366 "exemplo.tab.c"
    break;

  case 86: /* $@10: %empty  */
#line 520 "exemplo.y"
                             {
        /* Iniciar novo escopo para o while */
        iniciarEscopo();
    }
#line 2375 "exemplo.tab.c"
    break;

  case 87: /* while_stmt: WHILE LPAREN expr RPAREN $@10 stmt  */
#line 524 "exemplo.y"
         { 
        /* Finalizar escopo do while */
        finalizarEscopo();
        (yyval.node) = criarNoWhile((yyvsp[-3].node), (yyvsp[0].node)); 
    }
#line 2385 "exemplo.tab.c"
    break;

  case 88: /* while_stmt: WHILE LPAREN error RPAREN stmt  */
#line 529 "exemplo.y"
                                     { 
        (yyval.node) = NULL; 
        yyerror("Expressão condicional inválida no while"); 
    }
#line 2394 "exemplo.tab.c"
    break;

  case 89: /* return_stmt: RETURN expr SEMICOLON  */
#line 536 "exemplo.y"
                          { (yyval.node) = criarNoReturn((yyvsp[-1].node)); }
#line 2400 "exemplo.tab.c"
    break;

  case 90: /* return_stmt: RETURN SEMICOLON  */
#line 537 "exemplo.y"
                       { (yyval.node) = criarNoReturn(NULL); }
#line 2406 "exemplo.tab.c"
    break;

  case 91: /* return_stmt: RETURN error SEMICOLON  */
#line 538 "exemplo.y"
                             { 
        (yyval.node) = NULL; 
        yyerror("Expressão de retorno inválida"); 
    }
#line 2415 "exemplo.tab.c"
    break;

  case 92: /* expr: atrib_expr  */
#line 545 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2421 "exemplo.tab.c"
    break;

  case 93: /* atrib_expr: ternary_expr  */
#line 549 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2427 "exemplo.tab.c"
    break;

  case 94: /* atrib_expr: var ASSIGN atrib_expr  */
#line 550 "exemplo.y"
                            { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoAssign('=', (yyvsp[-2].node), (yyvsp[0].node)); 
    }
#line 2444 "exemplo.tab.c"
    break;

  case 95: /* atrib_expr: var PLUS_ASSIGN atrib_expr  */
#line 562 "exemplo.y"
                                 { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("+", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2464 "exemplo.tab.c"
    break;

  case 96: /* atrib_expr: var MINUS_ASSIGN atrib_expr  */
#line 577 "exemplo.y"
                                  { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("-", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2484 "exemplo.tab.c"
    break;

  case 97: /* atrib_expr: var MULT_ASSIGN atrib_expr  */
#line 592 "exemplo.y"
                                 { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("*", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2504 "exemplo.tab.c"
    break;

  case 98: /* atrib_expr: var DIV_ASSIGN atrib_expr  */
#line 607 "exemplo.y"
                                { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("/", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2524 "exemplo.tab.c"
    break;

  case 99: /* atrib_expr: var MOD_ASSIGN atrib_expr  */
#line 622 "exemplo.y"
                                { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoAssign('=', 
            (yyvsp[-2].node), 
            criarNoBinOp("%", (yyvsp[-2].node), (yyvsp[0].node))
        ); 
    }
#line 2544 "exemplo.tab.c"
    break;

  case 100: /* atrib_expr: var error  */
#line 637 "exemplo.y"
                { 
        (yyval.node) = NULL; 
        yyerror("Operação de atribuição inválida"); 
    }
#line 2553 "exemplo.tab.c"
    break;

  case 101: /* ternary_expr: or_expr  */
#line 644 "exemplo.y"
            { (yyval.node) = (yyvsp[0].node); }
#line 2559 "exemplo.tab.c"
    break;

  case 102: /* ternary_expr: or_expr QUESTION expr COLON ternary_expr  */
#line 645 "exemplo.y"
                                               { (yyval.node) = criarNoTernario((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2565 "exemplo.tab.c"
    break;

  case 103: /* or_expr: and_expr  */
#line 649 "exemplo.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2571 "exemplo.tab.c"
    break;

  case 104: /* or_expr: or_expr OR and_expr  */
#line 650 "exemplo.y"
                          { (yyval.node) = criarNoBinOp("||", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2577 "exemplo.tab.c"
    break;

  case 105: /* and_expr: bitor_expr  */
#line 654 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2583 "exemplo.tab.c"
    break;

  case 106: /* and_expr: and_expr AND bitor_expr  */
#line 655 "exemplo.y"
                              { (yyval.node) = criarNoBinOp("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2589 "exemplo.tab.c"
    break;

  case 107: /* bitor_expr: bitxor_expr  */
#line 659 "exemplo.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2595 "exemplo.tab.c"
    break;

  case 108: /* bitor_expr: bitor_expr BITOR bitxor_expr  */
#line 660 "exemplo.y"
                                   { (yyval.node) = criarNoBinOp("|", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2601 "exemplo.tab.c"
    break;

  case 109: /* bitxor_expr: bitand_expr  */
#line 664 "exemplo.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 2607 "exemplo.tab.c"
    break;

  case 110: /* bitxor_expr: bitxor_expr BITXOR bitand_expr  */
#line 665 "exemplo.y"
                                     { (yyval.node) = criarNoBinOp("^", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2613 "exemplo.tab.c"
    break;

  case 111: /* bitand_expr: equal_expr  */
#line 669 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2619 "exemplo.tab.c"
    break;

  case 112: /* bitand_expr: bitand_expr BITAND equal_expr  */
#line 670 "exemplo.y"
                                    { (yyval.node) = criarNoBinOp("&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2625 "exemplo.tab.c"
    break;

  case 113: /* equal_expr: relacao_expr  */
#line 674 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2631 "exemplo.tab.c"
    break;

  case 114: /* equal_expr: equal_expr EQ relacao_expr  */
#line 675 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("==", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2637 "exemplo.tab.c"
    break;

  case 115: /* equal_expr: equal_expr NE relacao_expr  */
#line 676 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("!=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2643 "exemplo.tab.c"
    break;

  case 116: /* relacao_expr: shift_expr  */
#line 680 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2649 "exemplo.tab.c"
    break;

  case 117: /* relacao_expr: relacao_expr GT shift_expr  */
#line 681 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2655 "exemplo.tab.c"
    break;

  case 118: /* relacao_expr: relacao_expr LT shift_expr  */
#line 682 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2661 "exemplo.tab.c"
    break;

  case 119: /* relacao_expr: relacao_expr GE shift_expr  */
#line 683 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2667 "exemplo.tab.c"
    break;

  case 120: /* relacao_expr: relacao_expr LE shift_expr  */
#line 684 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2673 "exemplo.tab.c"
    break;

  case 121: /* shift_expr: add_expr  */
#line 688 "exemplo.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 2679 "exemplo.tab.c"
    break;

  case 122: /* shift_expr: shift_expr SHIFTLEFT add_expr  */
#line 689 "exemplo.y"
                                    { (yyval.node) = criarNoBinOp("<<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2685 "exemplo.tab.c"
    break;

  case 123: /* shift_expr: shift_expr SHIFTRIGHT add_expr  */
#line 690 "exemplo.y"
                                     { (yyval.node) = criarNoBinOp(">>", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2691 "exemplo.tab.c"
    break;

  case 124: /* add_expr: mult_expr  */
#line 694 "exemplo.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2697 "exemplo.tab.c"
    break;

  case 125: /* add_expr: add_expr PLUS mult_expr  */
#line 695 "exemplo.y"
                                 { (yyval.node) = criarNoBinOp("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2703 "exemplo.tab.c"
    break;

  case 126: /* add_expr: add_expr MINUS mult_expr  */
#line 696 "exemplo.y"
                                  { (yyval.node) = criarNoBinOp("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2709 "exemplo.tab.c"
    break;

  case 127: /* mult_expr: unary_expr  */
#line 700 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2715 "exemplo.tab.c"
    break;

  case 128: /* mult_expr: mult_expr MULT unary_expr  */
#line 701 "exemplo.y"
                                { (yyval.node) = criarNoBinOp("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2721 "exemplo.tab.c"
    break;

  case 129: /* mult_expr: mult_expr DIV unary_expr  */
#line 702 "exemplo.y"
                               { (yyval.node) = criarNoBinOp("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2727 "exemplo.tab.c"
    break;

  case 130: /* mult_expr: mult_expr MOD unary_expr  */
#line 703 "exemplo.y"
                               { (yyval.node) = criarNoBinOp("%", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2733 "exemplo.tab.c"
    break;

  case 131: /* unary_expr: fator  */
#line 707 "exemplo.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 2739 "exemplo.tab.c"
    break;

  case 132: /* unary_expr: INCREMENT var  */
#line 708 "exemplo.y"
                    { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[0].node) && (yyvsp[0].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[0].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[0].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoUnaryOp("++", (yyvsp[0].node)); 
    }
#line 2756 "exemplo.tab.c"
    break;

  case 133: /* unary_expr: DECREMENT var  */
#line 720 "exemplo.y"
                    { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[0].node) && (yyvsp[0].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[0].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[0].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoUnaryOp("--", (yyvsp[0].node)); 
    }
#line 2773 "exemplo.tab.c"
    break;

  case 134: /* unary_expr: MINUS unary_expr  */
#line 732 "exemplo.y"
                                    { (yyval.node) = criarNoUnaryOp("-", (yyvsp[0].node)); }
#line 2779 "exemplo.tab.c"
    break;

  case 135: /* unary_expr: PLUS unary_expr  */
#line 733 "exemplo.y"
                                  { (yyval.node) = criarNoUnaryOp("+", (yyvsp[0].node)); }
#line 2785 "exemplo.tab.c"
    break;

  case 136: /* unary_expr: NOT unary_expr  */
#line 734 "exemplo.y"
                     { (yyval.node) = criarNoUnaryOp("!", (yyvsp[0].node)); }
#line 2791 "exemplo.tab.c"
    break;

  case 137: /* unary_expr: BITNOT unary_expr  */
#line 735 "exemplo.y"
                        { (yyval.node) = criarNoUnaryOp("~", (yyvsp[0].node)); }
#line 2797 "exemplo.tab.c"
    break;

  case 138: /* fator: NUM  */
#line 739 "exemplo.y"
        { (yyval.node) = criarNoInt((yyvsp[0].intValue)); }
#line 2803 "exemplo.tab.c"
    break;

  case 139: /* fator: FLOAT  */
#line 740 "exemplo.y"
            { (yyval.node) = criarNoFloat((yyvsp[0].floatValue)); }
#line 2809 "exemplo.tab.c"
    break;

  case 140: /* fator: CHAR_LITERAL  */
#line 741 "exemplo.y"
                   { (yyval.node) = criarNoChar((yyvsp[0].charValue)); }
#line 2815 "exemplo.tab.c"
    break;

  case 141: /* fator: HEX  */
#line 742 "exemplo.y"
          { (yyval.node) = criarNoHex((yyvsp[0].strValue)); }
#line 2821 "exemplo.tab.c"
    break;

  case 142: /* fator: STRING  */
#line 743 "exemplo.y"
             { (yyval.node) = criarNoString((yyvsp[0].strValue)); }
#line 2827 "exemplo.tab.c"
    break;

  case 143: /* fator: var  */
#line 744 "exemplo.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 2833 "exemplo.tab.c"
    break;

  case 144: /* fator: chamada  */
#line 745 "exemplo.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2839 "exemplo.tab.c"
    break;

  case 145: /* fator: LPAREN expr RPAREN  */
#line 746 "exemplo.y"
                         { (yyval.node) = (yyvsp[-1].node); }
#line 2845 "exemplo.tab.c"
    break;

  case 146: /* fator: var INCREMENT  */
#line 747 "exemplo.y"
                    { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-1].node) && (yyvsp[-1].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-1].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-1].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoUnaryOp("++", (yyvsp[-1].node)); 
    }
#line 2862 "exemplo.tab.c"
    break;

  case 147: /* fator: var DECREMENT  */
#line 759 "exemplo.y"
                    { 
        /* Verificar se variável foi declarada */
        if ((yyvsp[-1].node) && (yyvsp[-1].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-1].node)->valor_str);
            if (sym == NULL) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[-1].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoUnaryOp("--", (yyvsp[-1].node)); 
    }
#line 2879 "exemplo.tab.c"
    break;

  case 148: /* var: ID  */
#line 774 "exemplo.y"
       { 
        /* Verificar se variável foi declarada */
        Simbolo *sym = buscarSimbolo((yyvsp[0].strValue));
        if (sym == NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Variável '%s' não declarada", (yyvsp[0].strValue));
            yyerror(erro);
        }
        (yyval.node) = criarNoVar((yyvsp[0].strValue)); 
    }
#line 2894 "exemplo.tab.c"
    break;

  case 149: /* var: var DOT ID  */
#line 784 "exemplo.y"
                 { 
        /* Para acesso a membros, verificar se o tipo é struct/union */
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
            Simbolo *sym = buscarSimbolo((yyvsp[-2].node)->valor_str);
            if (sym != NULL && sym->tipo != TIPO_STRUCT && sym->tipo != TIPO_UNION) {
                char erro[256];
                snprintf(erro, sizeof(erro), "Erro semântico: '%s' não é uma struct ou union", (yyvsp[-2].node)->valor_str);
                yyerror(erro);
            }
        }
        (yyval.node) = criarNoVar((yyvsp[0].strValue)); 
    }
#line 2911 "exemplo.tab.c"
    break;

  case 150: /* var: ID '[' expr ']'  */
#line 796 "exemplo.y"
                      {
        (yyval.node) = NULL;
        report_unsupported_feature("Arrays", yylineno);
    }
#line 2920 "exemplo.tab.c"
    break;

  case 151: /* chamada: ID LPAREN argumentos RPAREN  */
#line 803 "exemplo.y"
                                { 
        /* Verificar se função foi declarada */
        Simbolo *sym = buscarSimbolo((yyvsp[-3].strValue));
        if (sym == NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Função '%s' não declarada", (yyvsp[-3].strValue));
            yyerror(erro);
        } else if (sym->tipo != TIPO_FUNCAO) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: '%s' não é uma função", (yyvsp[-3].strValue));
            yyerror(erro);
        }
        (yyval.node) = criarNoCall((yyvsp[-3].strValue), (yyvsp[-1].node)); 
    }
#line 2939 "exemplo.tab.c"
    break;

  case 152: /* chamada: ID LPAREN error RPAREN  */
#line 817 "exemplo.y"
                             { 
        (yyval.node) = NULL; 
        yyerror("Lista de argumentos inválida"); 
    }
#line 2948 "exemplo.tab.c"
    break;

  case 153: /* argumentos: lista_args  */
#line 824 "exemplo.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2954 "exemplo.tab.c"
    break;

  case 154: /* argumentos: %empty  */
#line 825 "exemplo.y"
                  { (yyval.node) = NULL; }
#line 2960 "exemplo.tab.c"
    break;

  case 155: /* lista_args: lista_args COMMA expr  */
#line 829 "exemplo.y"
                          { (yyval.node) = concatenarArg((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2966 "exemplo.tab.c"
    break;

  case 156: /* lista_args: expr  */
#line 830 "exemplo.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 2972 "exemplo.tab.c"
    break;

  case 157: /* lista_args: lista_args COMMA error  */
#line 831 "exemplo.y"
                             { 
        (yyval.node) = NULL; 
        yyerror("Argumento inválido na lista"); 
    }
#line 2981 "exemplo.tab.c"
    break;

  case 158: /* typedef_declaracao: TYPEDEF tipo ID SEMICOLON  */
#line 838 "exemplo.y"
                              { 
        /* Verificar se o identificador já existe no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[-1].strValue));
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Identificador '%s' já declarado neste escopo", (yyvsp[-1].strValue));
            yyerror(erro);
        } else {
            /* Determinar o tipo baseado no nó AST */
            TipoSimbolo tipoSimbolo = TIPO_ERRO;
            if ((yyvsp[-2].node) && (yyvsp[-2].node)->valor_str) {
                if (strcmp((yyvsp[-2].node)->valor_str, "int") == 0) tipoSimbolo = TIPO_INT;
                else if (strcmp((yyvsp[-2].node)->valor_str, "float") == 0) tipoSimbolo = TIPO_FLOAT;
                else if (strcmp((yyvsp[-2].node)->valor_str, "char") == 0) tipoSimbolo = TIPO_CHAR;
                else if (strcmp((yyvsp[-2].node)->valor_str, "double") == 0) tipoSimbolo = TIPO_DOUBLE;
                else if (strcmp((yyvsp[-2].node)->valor_str, "void") == 0) tipoSimbolo = TIPO_VOID;
            }
            inserirSimbolo((yyvsp[-1].strValue), tipoSimbolo);
        }
        (yyval.node) = criarNoVar((yyvsp[-1].strValue)); 
    }
#line 3007 "exemplo.tab.c"
    break;

  case 159: /* typedef_declaracao: TYPEDEF error SEMICOLON  */
#line 859 "exemplo.y"
                              { 
        (yyval.node) = NULL; 
        yyerror("Declaração typedef inválida"); 
    }
#line 3016 "exemplo.tab.c"
    break;

  case 160: /* lista_identificadores: ID  */
#line 866 "exemplo.y"
       { 
        /* Para enums, inserir o identificador como TIPO_ENUM */
        Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].strValue));
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enumerador '%s' já declarado neste escopo", (yyvsp[0].strValue));
            yyerror(erro);
        } else {
            inserirSimbolo((yyvsp[0].strValue), TIPO_ENUM);
        }
        (yyval.node) = criarNoVar((yyvsp[0].strValue)); 
    }
#line 3033 "exemplo.tab.c"
    break;

  case 161: /* lista_identificadores: lista_identificadores COMMA ID  */
#line 878 "exemplo.y"
                                     { 
        /* Para enums, inserir o identificador como TIPO_ENUM */
        Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[0].strValue));
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enumerador '%s' já declarado neste escopo", (yyvsp[0].strValue));
            yyerror(erro);
        } else {
            inserirSimbolo((yyvsp[0].strValue), TIPO_ENUM);
        }
        (yyval.node) = concatenarStmt((yyvsp[-2].node), criarNoVar((yyvsp[0].strValue))); 
    }
#line 3050 "exemplo.tab.c"
    break;

  case 162: /* struct_declaracao: STRUCT ID LBRACE lista_declaracoes RBRACE SEMICOLON  */
#line 893 "exemplo.y"
                                                        { 
        /* Verificar se struct já foi declarada no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[-4].strValue));
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Struct '%s' já declarada neste escopo", (yyvsp[-4].strValue));
            yyerror(erro);
        } else {
            inserirSimbolo((yyvsp[-4].strValue), TIPO_STRUCT);
        }
        (yyval.node) = criarNoUnion("struct", (yyvsp[-4].strValue)); 
    }
#line 3067 "exemplo.tab.c"
    break;

  case 163: /* struct_declaracao: STRUCT ID LBRACE error RBRACE SEMICOLON  */
#line 905 "exemplo.y"
                                              { 
        (yyval.node) = NULL; 
        yyerror("Corpo de struct inválido"); 
    }
#line 3076 "exemplo.tab.c"
    break;

  case 164: /* union_declaracao: UNION ID LBRACE lista_declaracoes RBRACE SEMICOLON  */
#line 912 "exemplo.y"
                                                       { 
        /* Verificar se union já foi declarada no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[-4].strValue));
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Union '%s' já declarada neste escopo", (yyvsp[-4].strValue));
            yyerror(erro);
        } else {
            inserirSimbolo((yyvsp[-4].strValue), TIPO_UNION);
        }
        (yyval.node) = criarNoUnion("union", (yyvsp[-4].strValue)); 
    }
#line 3093 "exemplo.tab.c"
    break;

  case 165: /* union_declaracao: UNION ID LBRACE error RBRACE SEMICOLON  */
#line 924 "exemplo.y"
                                             { 
        (yyval.node) = NULL; 
        yyerror("Corpo de union inválido"); 
    }
#line 3102 "exemplo.tab.c"
    break;

  case 166: /* enum_declaracao: ENUM ID LBRACE lista_identificadores RBRACE SEMICOLON  */
#line 931 "exemplo.y"
                                                          { 
        /* Verificar se enum já foi declarado no escopo atual */
        Simbolo *existente = buscarSimboloNoEscopoAtual((yyvsp[-4].strValue));
        if (existente != NULL) {
            char erro[256];
            snprintf(erro, sizeof(erro), "Erro semântico: Enum '%s' já declarado neste escopo", (yyvsp[-4].strValue));
            yyerror(erro);
        } else {
            inserirSimbolo((yyvsp[-4].strValue), TIPO_ENUM);
        }
        (yyval.node) = criarNoEnum((yyvsp[-4].strValue)); 
    }
#line 3119 "exemplo.tab.c"
    break;

  case 167: /* enum_declaracao: ENUM ID LBRACE error RBRACE SEMICOLON  */
#line 943 "exemplo.y"
                                            { 
        (yyval.node) = NULL; 
        yyerror("Lista de enumeradores inválida"); 
    }
#line 3128 "exemplo.tab.c"
    break;


#line 3132 "exemplo.tab.c"

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

#line 949 "exemplo.y"

