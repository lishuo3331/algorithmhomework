#include <iostream>
#include <stdio.h>

// https://wenku.baidu.com/view/c726a2f09ec3d5bbfd0a745c.html
using namespace std;

int S[19][19] = {0};

void cul_S()
{
	for(int j = 2;j <= 18;j++)
	{
		for(int i = 1; i <= 18; i++)
		{
			if (S[i][j] == 0)
			{
				S[i][j] = S[i-1][j-1] + j*S[i-1][j];
			}

		}
	}
}
int main(int argc, char const *argv[])
{
	for(int i = 1;i <= 18;i++)
	{
		S[1][i] = 1;
		S[i][1] = 1;
	}
	cul_S();
	return 0;
}