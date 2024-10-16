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

#ifndef YY_RULE_RULE_PARSER_TAB_H_INCLUDED
# define YY_RULE_RULE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef RULE_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define RULE_DEBUG 1
#  else
#   define RULE_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define RULE_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined RULE_DEBUG */
#if RULE_DEBUG
extern int rule_debug;
#endif

/* Token kinds.  */
#ifndef RULE_TOKENTYPE
# define RULE_TOKENTYPE
  enum rule_tokentype
  {
    RULE_EMPTY = -2,
    RULE_EOF = 0,                  /* "end of file"  */
    RULE_error = 256,              /* error  */
    RULE_UNDEF = 257,              /* "invalid token"  */
    NTERM = 258,                   /* NTERM  */
    TERM = 259,                    /* TERM  */
    SEP = 260,                     /* SEP  */
    OR = 261,                      /* OR  */
    LB = 262,                      /* LB  */
    TOKEN_ERROR = 263              /* TOKEN_ERROR  */
  };
  typedef enum rule_tokentype rule_token_kind_t;
#endif

/* Value type.  */
#if ! defined RULE_STYPE && ! defined RULE_STYPE_IS_DECLARED
typedef char const* RULE_STYPE;
# define RULE_STYPE_IS_TRIVIAL 1
# define RULE_STYPE_IS_DECLARED 1
#endif


extern RULE_STYPE rule_lval;


int rule_parse (void);


#endif /* !YY_RULE_RULE_PARSER_TAB_H_INCLUDED  */
