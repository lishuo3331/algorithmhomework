#include <iostream>

using namespace std;
int n,m,k;
int people[100][15];
int people_1[100][15];
int result = 0;
int  judge()
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int k = 0;
		for (int j = 0; j < 15; ++j)
		{
			k += people_1[i][j];
		}
		if(k==0)
		{
			sum ++;
		}
	}
	return sum;
}
void dfs(int i,int sum)
{
	if (i>=n||sum>=m)
	{
		int ans = judge();
		if( ans > result)
			result = ans;
		return;
	}
	for (int j = 0; j < n; ++j)
	{
		people_1[j][i] = 0;
	}
	dfs(i+1,sum+1);
	for (int j = 0; j < n; ++j)
	{
		people_1[j][i] = people[j][i];
	}
	dfs(i+1,sum);
}
int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		for (int j = 0; j < number; ++j)
		{
			int book_index;
			cin >> book_index;
			people[i][book_index] = 1;
			people_1[i][book_index] = 1;
		}
	}
	dfs(1,0);
	cout << result;
	return 0;
}