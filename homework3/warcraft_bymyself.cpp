#include <iostream>
#include <cstring>
#define LL long long 
#define mod 7777777

using namespace std;

struct Matrix
{
	int row,column;
	LL  a[12][12];
	Matrix()
	{
		row = column = 0;
		memset(a,0,sizeof(a));
	}
};

//矩阵乘法
Matrix operator * (Matrix x,Matrix y)
{
	Matrix ans;
	ans.row = x.row;
	ans.column = y.column;
	for (int i = 1; i <= x.row; ++i)
	{
		for(int j = 1; j <=y.column; ++j)
		{
			for(int k = 1; k <= y.row; ++k)
			{
				ans.a[i][j] =(ans.a[i][j] + x.a[i][k]*y.a[k][j]) % mod;
			}
		}
	}
	return ans;
}

//矩阵乘方
Matrix operator ^ (Matrix x, int y)
{
	Matrix ans;
	ans.row = ans.column = x.row;
	for (int i = 1; i <= ans.row; ++i)
	{
		ans.a[i][i] = 1;
	}
	for(;y; y >>= 1)
	{
		if (y & 1)//位运算符
		{
			ans = ans * x;
		}
		x = x*x;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int k,n;
	cin >>k >>n;
	Matrix ans,sum;
	ans.column = ans.a[1][1] = 1;
	sum.row = sum.column = ans.row = k;
	for (int i = 1; i <= k; ++i)
	{
		sum.a[1][i] =1; 
	}
	for (int i = 2; i <= k; ++i)
	{
		sum.a[i][i-1] = 1;
	}
	sum = sum ^n;//为什么^n
	ans = ans * sum;
	cout << ans.a[1][1] <<endl;
	return 0;
}