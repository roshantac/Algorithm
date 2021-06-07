/*
The program will print the reverse of given string, implemeted using stack similar operation.
input : hello welcome to programing
ouput : programing to welcome hello
*/

#include <stdio.h>
#include <string.h>

static char string_stack[20][20];
static int count = 0;
void push(char *str)
{
    strcpy(string_stack[count++],str);
}

int main()
{
    char string[30] ;//= {"hello how are you"};
    char strbuff[15];
    int stridx=0,bufidx=0,i=0;
    printf("\n Enter the string: ");
   scanf("%s",string);
    while(string[stridx] != '\0')
    {
        if(string[stridx]!=" ")
        {
            strbuff[bufidx++] = string[stridx];
        }
        else
        {
            strbuff[bufidx] ='\0';
            bufidx = 0;
            push(strbuff);
        }
    }
    printf("\n");
for(i=count-1;i>0;i--)
{
    printf("%s ",string_stack[i]);
}
    return 0;
}
