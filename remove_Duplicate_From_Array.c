/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int b[20], a[20]={3,4,3,6,7,0,9,7,6,6,1,45,9};
    int m =13, n,flag;
    b[0]= a[0];
    n=1;
    for(int i=1;i<m;i++)
    {
        flag=0;
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                flag =1;
                break;
            }
        }
        if(flag==0)
        {
            b[n]=a[i];
            n++;
        }
    }
    for(int i=0;i<n;i++)
    printf("%d ,",b[i]);
    return 0;
}
