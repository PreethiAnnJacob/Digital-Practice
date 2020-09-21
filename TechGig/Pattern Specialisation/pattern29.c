/*
Pattern Problem - 29 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-

* * * * *
   * * * *
      * * *
         * *
            *

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{	int n;char ch='A';
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i;j++)
			printf("  ");
		for(int j=0;j<i;j++){
			if(j==i-1)
				printf("*\n");
			else
				printf("* ");
		}
	}
}
