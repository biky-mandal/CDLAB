%{
  #include <stdio.h>
  int yylex(void);
  int flag=0;
  void yyerror(const char *s);
%}
 
%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'
 

%%
Arithmetic: E{
                printf("Result = %d\n", $$);
                return 0;
            };
 
E:
    E '+' E { $$ = $1 + $3; }
    | E '-' E { $$ = $1 - $3; }
    | E '*' E { $$ = $1 * $3; }
    | E '/' E { $$ = $1 / $3; }
    | '-' NUMBER { $$ = -$2; }
    | '(' E ')' { $$ = $2; }
    | NUMBER { $$ = $1; }
    ;
%%
 
void main() {
    printf("Enter the expression:\n");
    yyparse();
    if(flag==0)
    printf("Entered arithmetic expression is Valid\n");
    
}
void yyerror(const char *s) {
    printf("Entered arithmetic expression is Invalid\n");
    flag=1;
  
}