/*
The program will print the reverse of given string, implemeted using stack similar operation.
input : hello welcome to programing
ouput : programing to welcome hello
*/
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

char string_stack[20][20];
int count = 0;
void push(char *str)
{
    strcpy(string_stack[count],str);
    count++;
}

int main()
{
    char string1[50] ;
    char strbuff[15];
    int stridx=0,bufidx=0,i=0;
    printf("\n Enter the string: ");
    gets(string1);
    while(string1[stridx] != '\0')
    {

        if(string1[stridx] != ' ')
        {
            strbuff[bufidx++] = string1[stridx];
        }
        else
        {
            strbuff[bufidx] ='\0';
            bufidx = 0;
            push(strbuff);
        }
        stridx++;
    }
    strbuff[bufidx] ='\0';
    push(strbuff);
    printf("\n");
for(i=count+1;i>=0;i--)
{
    printf("%s ",string_stack[i]);
}
    return 0;
}



}
    return 0;
}
