%{
#include <stdio.h>
%}

keywords "if"|"do"|"while"|"else"|"int"|"float"|"double"|"char"|"for"|"break"|"continue"|"void"|"break"|"continue"|"switch"|"case"|"return"
identifier [a-zA-Z_][a-zA-Z_0-9]* 
integer [0-9]+
float [0-9]*[.][0-9]+
string ["][a-zA-Z0-9,!: ]*["]


%%

#.* { printf("\n%s is a PREPROCESSOR DIRECTIVE",yytext);}
{keywords} {printf("\n%s is a KEYWORD",yytext);}
{identifier} {printf("\n%s is a IDENTIFIER",yytext);}
{integer} {printf("\n%s is an INTEGER",yytext);}
{float} {printf("\n%s is a FLOAT",yytext);}
{string} {printf("\n%s is a STRING",yytext);}
"+"|"-"|"*"|"/"|"="|"%"|"=="|"++"|"--"|"!="|">="|"<="|"&&"|"||" {printf("\n%s is a OPERATOR",yytext);}
"["|"{"|"}"|"("|")" {printf("\n%s is a PARENTHESIS",yytext);}
[;] {printf("\n%s is a SEMICOLON",yytext);}
[,] {printf("\n%s is a COMMA",yytext);}

%%

int main()
{
extern FILE *yyin;
yyin = fopen("Input.c", "r");
yylex();
return 0;
}
int yywrap()
{
return 1;
}