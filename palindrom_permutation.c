
// Sample code to perform I/O:
/*
*check palindrom is possible on permutation of the string
*/
#include <stdio.h>
#include<string.h>
int main(){
    char S[1001];
	int count_arr[30],count=0;
	scanf("%s", S);    
	for(int i=0;i<30;i++) count_arr[i]=0;
	for(int i=0;i<strlen(S);i++)
	{
		count_arr['a'-S[i]]++;
	}  
	for(int i=0;i<27;i++)
	{
		if(count_arr[i]%2 ==1) count++;
		if(count>1) break;
	}        			// Reading input from STDIN
	if((count==0 && strlen(S)%2==0)||(strlen(S)%2==0 && count==0))
	printf("YES");
	else printf("NO");      // Writing output to STDOUT

}
