/*
* * * *** *
* * * * * *
* * * * * *
*** *** ***
*/

#include <stdio.h>
#define ROW 5
#define COL 3
int main()
{
int a[ROW][COL]={{1,2,3},
                {4,5,6},
                {7,8,9},
                {10,11,12},
                {13,14,15}
};
int flg=0;
for (int i=0;i<COL;i++)
{
    if(flg==0)
    {
        for (int j=0;j<ROW;j++)
            printf("%d ",a[j][i]);
        flg=1;
    }
    else
    {
        for (int j=ROW-1;j>=0;j--)
            printf("%d ",a[j][i]);
        flg=0;
    }
}

    return 0;
}
