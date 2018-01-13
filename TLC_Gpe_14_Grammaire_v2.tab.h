/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_TLC_GPE_14_GRAMMAIRE_V2_TAB_H_INCLUDED
# define YY_YY_TLC_GPE_14_GRAMMAIRE_V2_TAB_H_INCLUDED
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
    T_NAME = 258,
    T_INTEGER = 259,
    T_FLOAT = 260,
    T_BOOLEAN = 261,
    T_TYPEFLOAT = 262,
    T_TYPEBOOLEAN = 263,
    T_TYPEINTEGER = 264,
    T_PLUS = 265,
    T_MINUS = 266,
    T_TIMES = 267,
    T_DIVIDE = 268,
    T_POWER = 269,
    T_SQRT = 270,
    T_PLEFT = 271,
    T_PRIGHT = 272,
    T_COMMA = 273,
    T_POINT = 274,
    T_COLON = 275,
    T_SEMICOLON = 276,
    T_ASSIGNMENT = 277,
    T_CLASS = 278,
    T_EXTENDS = 279,
    T_DATA = 280,
    T_IS = 281,
    T_METHOD = 282,
    T_RETURN = 283,
    T_END = 284,
    NEG = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "TLC_Gpe_14_Grammaire_v2.y" /* yacc.c:1909  */

    int ival;
    bool bval;
    float fval;
    string sval;
		Instruction* term;
		Expression* exp;
		Class* class;
		Method* meth;
		Data* data;
		vector<Decl*> params;
		Fonction* fonc;

#line 99 "TLC_Gpe_14_Grammaire_v2.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TLC_GPE_14_GRAMMAIRE_V2_TAB_H_INCLUDED  */
