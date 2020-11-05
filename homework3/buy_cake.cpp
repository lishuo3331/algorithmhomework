// n >= 3 必然包含 1、2
// n<3  则 1 种方法 输出从1-n 
#include <iostream>
#include <cmath>
using namespace std;

int number[11][1001][1001];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int result1 = (int)log2(n)+1;
	number[1][1][1] = 1;
	for(int i = 0;i < result1;i++)
	{
		for(int j = i;j<=(1<<(i-1));++j)
		{
			for(int k = i;k<=((1<<i)-1);++k)
			{
				if (number[i][j][k])
				{
					for(int p = j+1;p<=k+1;++p)
					{
						if(p+k<=n)
							number[i+1][p][k+p]+=number[i][j][k];
						else
							number[i+1][p][n]+=number[i][j][k];
					}
				}
			}
		}
	}
	int result2 = 0;
	for (int i = 1; i <= n; ++i)
	{
		result2+=number[result1][i][n];
	}
	cout << result1 << " " <<result2<<endl;
	return 0;
}