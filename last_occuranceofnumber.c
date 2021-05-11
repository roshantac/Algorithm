/******************************************************************************
find the last occurance of given number

*******************************************************************************/
#include <iostream>
using namespace std;
int lastOcc(int arr[], int n, int x)
{
    int low=0, high =n;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>x)
        high =mid-1;
        else if(arr[mid]<x)
        low = mid +1;
        else
        {//mid is equal to given value
            if(mid==0 || arr[mid]!=arr[mid+1])
            return mid;
            else
            low= mid+1;
            
        }
    }
    return -1;
}


int main() {
    
   int arr[] = {5, 10, 10, 10, 10, 20, 20}, n = 7;

	int x = 10;

    cout << lastOcc(arr, n, x);
	return 0;
}


