#include <iostream>
// #include <cstdio>
#include <cstring>
using namespace std;
//https://blog.csdn.net/adx33526/article/details/102029671?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param
#define mod  7777777
#define LL long long

int k,n;

struct Matrix
{
	//n为行  m为列
	int n,m;
	LL a[11][11];
	//构造函数
	Matrix()
	{
		n = m = 0;
		memset(a,0,sizeof(a));
	}
};

//矩阵乘法
inline Matrix operator * (Matrix x, Matrix y)
{
	Matrix ans;//n*m
	ans.n = x.n;
	ans.m = y.m;
	for (int i = 1; i <= x.n; ++i)
	{
		for (int j = 1; j <= y.m; ++j)
		{
			for (int k = 1; k <= y.n; ++k)
			{
				ans.a[i][j] = (ans.a[i][j] + x.a[i][k]*y.a[k][j]) % mod;
			}
		}
	}
	return ans;
}

inline Matrix operator ^ (Matrix x, int y)
{
	Matrix ans;
	ans.n = ans.m =k;
	for (int i = 1; i <= k; ++i)
	{
		ans.a[i][i] = 1;
	}
	for(;y;y >>= 1)
	{
		if(y & 1) 
			ans = ans * x;
		x = x*x;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	cin >> k;
	cin >> n;
	Matrix ans,sum;
	ans.m = ans.a[1][1] = 1;
	sum.n = sum.m = ans.n = k;
	for (int i = 1; i <= k; ++i)
	{
		sum.a[1][i] =1;
	}
	for (int i = 2; i <= k; ++i)
	{
		sum.a[i][i-1] = 1;
	}
	sum = sum ^ n;
	ans = sum * ans;
	cout << ans.a[1][1] <<endl;
	return 0;
}