/*
The program will print the reverse of given string, implemeted using stack similar operation.
input : hello welcome to programing
ouput : programing to welcome hello
*/

#include <stdio.h>
#include <string.h>

#define SOLUTION 1

#ifdef SOLUTION
int main()
{
    char string1[50];
    int i=0;
    printf("\n Enter the string: ");
    gets(string1);
    for(i= strlen(string1)-1;i >=0 ;i--)
    {
        if(string1[i]==' '|| i==0)
        {
            if(i==0) i--;
            for (int j=i+1;string1[j]!=' ' && string1[j]!='\0';j++)
                printf("%c",string1[j]);
            printf(" ");
        }
    }
    return 0;
}

#else


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
#endif

