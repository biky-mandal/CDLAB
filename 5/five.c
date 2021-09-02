/**
   C program to implement LALR(1) parser for the grammar :
   S -> CC
   C -> cC | d

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

char stack[N];
int top = -1;
void push(char i)
{
    if(top==N-1)
        return;
    top +=1;
    stack[top] = i;
}

void pop()
{
    if(top==-1)
        return;
    top -=1;
}

int mapCharToInt(char i)
{
    if(i=='c')    return 0;
    else if(i=='d') return 1;
    else if(i=='$') return 2;
    else if(i=='S') return 3;
    else if(i=='C') return 4;
    else return -1;
}

int main()
{
    char productions[3][5] = {"CC","cC","d"};
    int LALR1_parsing_table[7][5] = {{30,40,-1,1,2},
                                {-1,-1,0,-1,-1},
                                {30,40,-1,-1,5},
                                {30,40,-1,-1,6},
                                {-30,-30,-30,-1,-1},
                                {-1,-1,-10,-1,-1},
                                {-20,-20,-20,-1,-1}};
    char str[40];
    int i = 0;
    printf("Enter the string: ");
    scanf("%s",str);

    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]!='c' && str[i]!='d')
        {
            printf("INVALID \n");
            return -1;
        }
    }
    strcat(str,"$");



    push('0');
    while(LALR1_parsing_table[atoi(&stack[top])][mapCharToInt(str[i])]!=0)
    {

            int prod_num = LALR1_parsing_table[atoi(&stack[top])][mapCharToInt(str[i])];
            if(prod_num==-1)
            {
                printf("INVALID\n");
                return -1;
            }
            else if(prod_num>0 && prod_num%10==0)
            {
                push(str[i]);
                push((char)(prod_num/10+48));
                i+=1;
            }
            else if(prod_num<0 && prod_num%10==0)
            {
                int pops = strlen(productions[prod_num/10*(-1) - 1]);
                for(int i=0;i<2*pops;i++)
                {
                    pop();
                }
                char lhs_prod;
                switch(prod_num/10*(-1))
                {
                    case 1: lhs_prod = 'S';
                    break;
                    case 2: lhs_prod = 'C';
                    break;
                    case 3: lhs_prod = 'C';
                    break;
                }
                char next_state = (char)(LALR1_parsing_table[atoi(&stack[top])][mapCharToInt(lhs_prod)]+48);
                push(lhs_prod);
                push(next_state);
            }
    }
    printf("VALID\n");
    return 0;
}
