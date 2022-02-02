C                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{C}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{

#include <stdio.h>
#include "miniC.h"


/* Ne g�re pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

%%
"/*"([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ {  }

"extern"                {  return EXTERN ; }
"int"                   {  return INT ; }
"void"                  {  return VOID ; }
"for"                   {  return FOR ; }
"while"                 {  return WHILE ; }
"if"                    {  return IF ; }
"else"                  {  return ELSE ; }
"switch"                {  return SWITCH ; }
"case"                  {  return CASE ; }
"default"               {  return DEFAULT ; }
"break"                 {  return BREAK ; }
"return"                {  return RETURN ; }

{L}({L}|{C})*           { 
				yylval.symbol = strdup(yytext);
				return IDENTIFICATEUR ; 
			 }

{C}+                    { 	
				 
				yylval.constante = atoi(yytext) ; 
				return CONSTANTE ; 
			 }


">>"                    {  return RSHIFT ; }
"<<"                    {  return LSHIFT ; }
"&&"                    {  return LAND ; }
"||"                    {  return LOR ; }
"<="                    {  return LEQ ; }
">="                    {  return GEQ ; }
"=="                    {  return EQ ; }
"!"                     {  return NOT ; }
"!="                    {  return NEQ ; }
"+"                     {  return PLUS ; }
"-"                     {  return MOINS ; }
"*"                     {  return MUL ; }
">"			 {  return GT ; }
"<" 			 {  return LT ; }
"/"                     {  return DIV ; }
"&"                     {  return BAND ; }

[ \t\v\n\f]             { /* je ne pense pas qu'il faille retourner un token ici mais faire peut être rien faire a part espace et \n pour \n */ }
.                       { return yytext[0]; }
%%