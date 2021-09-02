#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0, top = 0;
char stack[20], ip[20];

void push(char c)
{
  if (top >= 20)
    printf ("Stack Overflow");
  else
    stack[top++] = c;
}

void pop(void)
{
  if (top < 0)
    printf ("Stack Underflow");
  else
    top--;
}

void invalid(void)
{
  printf ("\n INVALID\n");
  exit (0);
}


int
main ()
{
  int n;
  printf ("The given grammar is:\n\n");
  printf ("E -> TE'\n");
  printf ("E' -> +TE'| epsilon \n");
  printf ("T -> FT'\n ");
  printf ("T' -> *FT' | epsilon \n");
  printf ("F -> (E) |a | b \n");
  printf ("\nEnter the string to be passsed: \n");
  scanf ("%s", ip);
  n = strlen (ip);
  ip[n] = '$';
  ip[n + 1] = '\0';
  push ('$');
  push ('E');
  while (ip[i] !='\0')
    {
      if (ip[i] == '$' && stack[top - 1] == '$')
	    {
	        printf("\n\nVALID.\n");
	        return 1;
	    }
        else if (ip[i] == stack[top - 1])
	    {
	        printf("\nMatch of %c", ip[i]);
	        i++;
	        pop ();
	    }
        else
	    {
	        if (stack[top - 1] == 'E' && (ip[i] == 'a' || ip[i] == 'b' || ip[i] == '('))
	        {
	            printf ("\n E-> TE' ");
	            pop ();
	            push ('A');	//E'
	            push ('T');
	       }
	       else if (stack[top - 1] == 'A' && ip[i] == '+')	//E'
	       {
	            printf ("\n E' -> +TE' ");
	            pop ();
	            push ('A');
	            push ('T');
	            push ('+');
	       }
	       else if (stack[top - 1] == 'A' && (ip[i] == ')' || ip[i] == '$'))
	       {
	            printf ("\n E' -> epsilon");
	            pop ();
	       }
	       else if (stack[top - 1] == 'T' && (ip[i] == 'a' || ip[i]=='b' || ip[i] == '('))
	       {
	            printf ("\n T -> FT' ");
	            pop ();
	            push ('B');	//B is T'
	            push ('F');
	       }
	 
	       else if (stack[top - 1] == 'B' && (ip[i] == '+' || ip[i] == ')' || ip[i] == '$'))
	       {
	            printf ("\n T' -> epsilon");
	            pop ();
	       }
	        else if (stack[top - 1] == 'B' && ip[i] == '*')
	        {
	            printf ("\n T -> *FT' ");
	            pop ();
	            push ('B');
	            push ('F');
	            push ('*');
	        }
	        else if (stack[top - 1] == 'F' && ip[i] == 'a')
	        {
	            printf ("\n F -> a");
	            pop ();
	            push ('a');
	        }
	        else if (stack[top - 1] == 'F' && ip[i] == 'b')
	        {
	            printf ("\n F -> b");
	            pop ();
	            push ('b');
	        }
	        else if (stack[top - 1] == 'F' && ip[i] == '(')
	        {
	            printf ("\n F -> (E)");
	            pop ();
	            push (')');
	             push ('E');
	            push ('(');
	        }
	
	        else
	        {
	             invalid();
	        }
	    }

    }

}