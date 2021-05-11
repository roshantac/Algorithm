#include <stdio.h>

int main()
{
int a[20]={0,2,0,7,3,0,4,0,0,9,4,0},n=12,b[20],k=0;
    for (int i=0;i<n;i++)
    if(a[i]!=0 )
    {
        
        b[k]=a[i];k++;
    }
    for(int i=k;i<n;i++)
    b[i]=0;
    for(int i=0;i<n;i++)
    printf("%d ,",b[i]);
    return 0;
}

/*

    for (int i=0;i<n;i++)
    if(a[i]!=0 )
    {
        temp =a[i];
        a[i]= a[k];
        a[k]=temp;
        k++;
    }


*/
