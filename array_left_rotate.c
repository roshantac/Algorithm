/******************************************************************************
left rotate

*******************************************************************************/
#include <stdio.h>

int main()
{
int a[20]={1,2,3,4,5,6,7},n=7,d=3,temp;
    for (int i=0;i<d;i++)
    {
        temp =a[0];
        for(int j=1;j<n;j++)
        a[j-1] =a[j];
        a[n-1] = temp;
        
    }

    for(int i=0;i<n;i++)
    printf("%d ,",a[i]);
    return 0;
}

/*
int k=0;
    for (int i=d;i<n;i++)
        b[k++]= a[i];
    for(int i=0;i<d;i++)
        b[k+i]=a[i];

*/
