#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int result[100001];
int dp[100001];
int Tower[101];
int main(int argc, char const *argv[])
{
	int N;
	int h;
	int index = 0 ;
	cin >> N;
	int max_ = 0;
	// memset(Tower,0,sizeof(Tower));
	for(int i = 1; i<= N; ++i)
	{
		index = 0;
		memset(dp,0,sizeof(dp));
		int sum = 0;
		while(1)
		{
			cin >> h;
			if (h>0)
			{				
				Tower[++index] = h;
				sum += h;
			}
			else
				break;
		} 
		max_ = max(max_,sum);
		dp[0] = 1;
		result[0] = h;
		for(int k = 1; k <= index; ++k)
		{
			for(int j = sum; j>= Tower[k]; --j)
			{
				if (dp[j] == 0 && dp[j - Tower[k]] > 0)
				{
					dp[j] = 1;
					result[j]++;
				}
			}
		}
	}
	for(int i = max_; i >= 0; --i)
	{
		if(result[i] == N)
		{
			cout << i <<endl;
			return 0;
		}
	}
	cout << 0 << endl;
	/* code */
	return 0;
}