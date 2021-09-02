/***

Write a C/C++ program to implement a recognizer for the regular
expression:
a*b+aa
Construct a DFA for the regular expression and then simulate the DFA as
explained in your theory class. The output of the program should be either ‘valid’
or ‘invalid’ depending on whether the input string belongs to the language
specified by the regular expression or not.

***/

#include <stdio.h>
#include <string.h>


// a Pointer variable That Points To a Particuler State.
int state = 1;
// All exception Will Be Sent to State 0


// Function of Starting State..
void stateOne(char c){
    if (c == 'a'){
        state = 1;
    }
    else if (c == 'b'){
        state = 2;
    }
    else{
        state = 0;
    }
}

// Function Of 2nd Stat
void stateTwo(char c){
    if (c == 'b'){
        state = 2;
    }
    else if (c == 'a'){
        state = 3;
    }
    else{
        state = 0;
    }
}

// Function Of 3rd State 
void stateThree(char c){
    if (c == 'a'){
        state = 4;
    }
    else if (c == 'b'){
        state = 0;
    }
    else{
        state = 0;
    }
}
// Function For Third State
void stateFour(char c){
    if (c == 'b'){
        state = 0;
    }
    else if (c == 'a'){
        state = 0;
    }
    else{
        state = 0;
    }
}


int isValid(char inptStr[]){
    int inptStrLength = strlen(inptStr);

    for (int i = 0; i < inptStrLength; i++){
        switch (state){
        case 1:
            stateOne(inptStr[i]);
            break;
        case 2:
            stateTwo(inptStr[i]);
            break;
        case 3:
            stateThree(inptStr[i]);
            break;
        case 4:
            stateFour(inptStr[i]);
            break;
        default:
            return 0;
            break;
        }
    }
    if (state == 4){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    while(1){
        char inptStr[120];
        printf("\nEnter the String you Want to Validate:\t");
        scanf("%s", inptStr);

        //  Calling The Function in the Condition
        if (isValid(inptStr)){
            printf("Valid\n");
            printf("Press ctrl + c to Exit the Loop\n\n");
        }
        else{
            printf("Invalid\n");
            printf("Press ctrl + c to Exit the Loop\n\n");
        }

    }
    return 0;
}