#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
using namespace std;

// int isPrime(int num)
// {
// 	if(num ==2 || num ==3)
// 	{
// 		return 1;
// 	}
// 	if (num%6 != 1 || num %6 !=5)
// 	{
// 		return 0;
// 	}
// 	int tmp = sqrt(num);
// 	for (int i = 0; i < tmp; i+=6)
// 	{
// 		if(num%i == 0 || num%(i+2) == 0)
// 		{
// 			return 0;
// 		}
// 	}
// 	return 1;
// }
bool isPrime(int x)
{
    if(x==0||x==1) 
    	return 0;
    for(int i=2;i<=sqrt(x);i++)
    	if(x%i==0) 
    		return 0;
    return 1;
}
// void dfs(int k,int ans,int n)
// {
//     if(k==n)
//     {
//         if(pd(ans))
//         {
//             printf("%d",ans);
//             puts("");
//         }
//     }
//     for(int i=0;i<=9;i++)
//     {
//         if(pd(ans*10+i)) 
//         dfs(k+1,ans*10+i,n);
//     }
//     return;
// }

void answerE(int N,int pass)
{
	if (N==0)
	{
		cout << pass << endl;
	}
	for (int i = 0; i <= 9;i++)
	{	
		if (isPrime(pass*10 + i))
		{
			answerE(N-1,pass*10 + i);
		}
		}
	return ;
}

	
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	answerE(N,0);
	return 0;
}