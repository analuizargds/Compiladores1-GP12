/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_EXEMPLO_TAB_H_INCLUDED
# define YY_YY_EXEMPLO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    SWITCH = 261,                  /* SWITCH  */
    CASE = 262,                    /* CASE  */
    DEFAULT = 263,                 /* DEFAULT  */
    BREAK = 264,                   /* BREAK  */
    WHILE = 265,                   /* WHILE  */
    RETURN = 266,                  /* RETURN  */
    DO = 267,                      /* DO  */
    FOR = 268,                     /* FOR  */
    CONTINUE = 269,                /* CONTINUE  */
    ID = 270,                      /* ID  */
    GE = 271,                      /* GE  */
    LE = 272,                      /* LE  */
    GT = 273,                      /* GT  */
    LT = 274,                      /* LT  */
    NE = 275,                      /* NE  */
    EQ = 276,                      /* EQ  */
    ASSIGN = 277,                  /* ASSIGN  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    MULT = 280,                    /* MULT  */
    DIV = 281,                     /* DIV  */
    MOD = 282,                     /* MOD  */
    COLON = 283,                   /* COLON  */
    SEMICOLON = 284,               /* SEMICOLON  */
    LBRACE = 285,                  /* LBRACE  */
    RBRACE = 286,                  /* RBRACE  */
    LPAREN = 287,                  /* LPAREN  */
    RPAREN = 288,                  /* RPAREN  */
    STRING = 289,                  /* STRING  */
    COMMA = 290,                   /* COMMA  */
    DOT = 291,                     /* DOT  */
    INT = 292,                     /* INT  */
    FLOAT = 293,                   /* FLOAT  */
    CHAR = 294,                    /* CHAR  */
    VOID = 295,                    /* VOID  */
    DOUBLE = 296,                  /* DOUBLE  */
    CHAR_LITERAL = 297,            /* CHAR_LITERAL  */
    STRUCT = 298,                  /* STRUCT  */
    UNION = 299,                   /* UNION  */
    ENUM = 300,                    /* ENUM  */
    TYPEDEF = 301,                 /* TYPEDEF  */
    HEX = 302,                     /* HEX  */
    CARACT = 303,                  /* CARACT  */
    INCREMENT = 304,               /* INCREMENT  */
    DECREMENT = 305,               /* DECREMENT  */
    PLUS_ASSIGN = 306,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 307,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 308,             /* MULT_ASSIGN  */
    DIV_ASSIGN = 309,              /* DIV_ASSIGN  */
    AND = 310,                     /* AND  */
    OR = 311,                      /* OR  */
    NOT = 312,                     /* NOT  */
    BITAND = 313,                  /* BITAND  */
    BITOR = 314,                   /* BITOR  */
    BITXOR = 315,                  /* BITXOR  */
    BITNOT = 316,                  /* BITNOT  */
    SHIFTLEFT = 317,               /* SHIFTLEFT  */
    SHIFTRIGHT = 318,              /* SHIFTRIGHT  */
    UMINUS = 319,                  /* UMINUS  */
    UPLUS = 320,                   /* UPLUS  */
    LOWER_THAN_ELSE = 321          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "exemplo.y"

    int intValue;
    float floatValue;
    char* strValue;
    char charValue;

#line 137 "exemplo.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_EXEMPLO_TAB_H_INCLUDED  */
