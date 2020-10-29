#include <iostream>
#include <stdio.h>

// https://wenku.baidu.com/view/c726a2f09ec3d5bbfd0a745c.html
using namespace std;

long long  S[19][19] = {0};

void cul_S()
{
	for(int i = 2;i <= 18;i++)
	{
		for(int j = 2; j <= i; j++)
		{
			if (i == j)
			{
				S[i][j] = 1;
			}
			if (S[i][j] == 0)
			{
				S[i][j] = S[i-1][j-1] + j*S[i-1][j];
			}
			// cout << "S " << i << " "<< j << " "<< S[i][j] <<endl;
		}
	}
}
int main(int argc, char const *argv[])
{
	int n1,n;
	for(int i = 1;i <= 18;i++)
	{
		S[1][i] = 1;
		S[i][1] = 1;
	}
	cul_S();
	long long result = 0;
	while((n1 = getchar()) != EOF)
	{
		int n2 = getchar();
		if(n2 != 10)
		{
			n = (n1 - 48)*10+n2-48;
			getchar();	
		}
		else
		{
			n = n1-48;
		}
		for(int i = 1;i <= n;i++)
		{

			result += S[n][i];
			// cout << "S " << n << " "<< i << " "<< S[n][i] <<endl;
		}
		cout << result << endl;
		result = 0;
	}
	return 0;
}