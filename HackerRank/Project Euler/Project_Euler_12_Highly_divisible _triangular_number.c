/*Project Euler #12: Highly divisible triangular number - Easy
The sequence of triangle numbers is generated by adding the natural numbers. So the 7'th triangle number would be 1+2+3+4+5+6+7=28. The first ten terms would be:1,3,6,10,15,2128,36,45,55,...

Let us list the factors of the first seven triangle numbers:
1:1
3:1,3
6:1,2,3,6
10:1,2,5,10
15:1,3,5,15
21:1,3,7,21
28:1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.
What is the value of the first triangle number to have over N divisors?

Input Format
First line T, the number of testcases. Each testcase consists of N in one line.

Constraints
1<=T<10^3
1<=N<=10^3

Output Format
For each testcase, print the required answer in one line.

Sample Input

4
1
2
3
4
Sample Output

3
6
6
28
Explanation

Explained in statement.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Try 1: 4/8. TC#4#5,#6,#7 failed due to TLE
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int t;
//     scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n;
//         scanf("%d",&n);
//         int tn;
//         if(n<=0)    tn=1;
//         else if(n==1)   tn=3;
//         else
//         {   tn=3;                   //trianglenumber=3 if we already considered natural numbers 1,2
//             for(int i=3;i>-1;i++)   //i for natural number
//             {   tn=tn+i;
//                 int nf=2;
//                 for(int j=2;j<=tn/2;j++)
//                 {   if (tn%j==0)
//                     {   nf++;
//                         if(nf>n)    {i=-2;break;}  //Break from i and j loop
//                     }
//                 }
//             }
//         }
//         printf("%d\n",tn);
//     }      
//     return 0;
// }

//Try 2: 6/8. TC#6,#7 failed due to TLE. Modified Try 1 to change factor checking space from tn/2 to sqrt(tn)
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int t;
//     scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n;
//         scanf("%d",&n);
//         int tn;
//         if(n<=0)    tn=1;
//         else if(n==1)   tn=3;
//         else
//         {   tn=3;   //trianglenumber=3 if we already considered natural numbers 1,2
//             for(int i=3;i>-1;i++)   //i for natural number
//             {   tn=tn+i;
//                 int nf=2;
//                 for(int j=2;j*j<=tn;j++)      //Change from Try1
//                 {   if (tn%j==0)
//                     {   nf++;
//                         if(tn/j!=j) nf++;     //Change from Try 1
//                         if(nf>n)    {i=-2;break;}
//                     }
//                 }
//             }
//         }
//         printf("%d\n",tn);
//     }  
//     return 0;
// }

//Try 3: 8/8 passed
int factorCount(int num)        //Function to count the number of factors
{   if (num<1)  return 0;
    if (num==1) return 1;
    if (num<=3) return 2;
    int nf=2;
    for(int j=2;j*j<=num;j++)   //Count time complexity = O(sqrt(num))     
    {   if (num%j==0)
        {   nf++;
            if(num/j!=j) nf++;
        }
    }
    return nf;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n;
        scanf("%d",&n);
        int tn;
        for(int i=1;;i++)       //i for natural number
        {   tn=(i*(i+1))/2;     //Triangle number tn formula = sum of n numbers = n(n+1)/2
            int nf_tn;          
            //No of factors of tn = no of factors(n/2) * no of factors(n+1) OR no of factors(n) * no of factors((n+1)/2) 
            //e.g. triangular number = 28 = 7*4. Factors of 28 = 1,2,4,7,14,28. ie 6 factors.
            //7 has 2 factors(1 and 7). 4 has 3 factors(1,2,4). No of factors of 28=2*3=6
            if (i%2==0)     nf_tn=factorCount(i/2)*factorCount(i+1);
            else            nf_tn=factorCount(i)*factorCount((i+1)/2);
            if (nf_tn>n)    break; 
        }
        printf("%d\n",tn);
    }  
    return 0;
}

