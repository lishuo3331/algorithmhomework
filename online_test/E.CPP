#include <iostream>

using namespace std;

// int weight[6001];
int a[8];
bool result = 0;
int nnum = 0;


void dfs(int i,int sum,int ans)
{
	if (sum>ans||i>6)
	{
		return;
	}
	if (i<=6&&sum==ans)
	{
		result=1;
		return;
	}
	// if (sum>ans-weight[i])
	// {
	// 	return;
	// }
	for (int j = 0; j <= a[i]; ++j)
	{
		if (sum+j*i<=ans)
		{
			dfs(i+1,sum+j*i,ans);
		}
	}
}
int init()
{
	int ans = 0;
	for (int i = 1; i < 7; ++i)
	{
		cin >> a[i];
		ans += a[i]*i;
		// for (int j = nnum-a[i]+1; j <= nnum; ++j)
		// {
		// 	weight[j] = i;
		// }
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int ans = init();
	if(ans%2==0)
	{
		dfs(1,0,ans/2);
		if (result)
		{
			cout << "Can be divided.";
		}
		else{
			cout << "Can't be divided.";
		}
	}
	else
	{
		cout << "Can't be divided.";
	}
	return 0;
}