#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,sum,tot,maxn;
int ans[100001],dp[100001];
int a[101];

int main(int argc, char const *argv[])
{
	cin >> n;
	for(int i = 1; i<=n; ++i)
	{
		memset(dp,0,sizeof(dp));
		tot = sum = 0;
		int h;
		while(1)
		{
			cin >> h;
			if(h<0)
				break;
			a[++tot] = h;
			sum += h; 
		}
		dp[0] = 1;
		a[0] = h;
		maxn = max(maxn,sum);
		for (int k = 1; k <= tot; ++k)
		{
			for(int j = sum; j >= a[k]; --j)
			{
				if(dp[j] == 0 && dp[j-a[k]] == 1)
				{
					dp[j] = 1;
					ans[j]++;
				}
			}
		}
	}
	for(int i = maxn; i >= 0; --i)
	{
		if(ans[i] == n)
		{
			cout << i <<endl;
			return 0;
		}
	}
	cout << 0 <<endl;
	return 0;
}