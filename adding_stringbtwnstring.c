
#include <stdio.h>
#include<string.h>
int main()
{
    char s[29]="mr john smit hellow";
    int count=0;
    for(int i=0;s[i]!='\0';i++ )
    {
        if(s[i]==' ') count++;
    }
    int length = strlen(s);
    int newlength = length-count+3*count;
    s[newlength]='\0';
    for(int i=newlength-1;i>=0;i--)
    {
        if(s[length]==' ')
       {
           s[newlength--]='0';
           s[newlength--]='2';
           s[newlength--]='%';
           i=i-2;
           
       }
       else{
           s[newlength--]=s[length];
       }
       length--;
    }
    printf("%s",s);

    return 0;
}
