 #include <iostream>
#include <string.h>
using namespace std;

int passenger[20][5];//1 a;2 b;3 t
int sum[20];
int team[20];
int ans;
int n ,m ,v ;

//超员check
bool check()
{
	int p = 0 ;
	for(int i=1; i <= n; ++i)
	{
		p+=sum[i];
		if (p>v)
			return false;
	}
	return true;
}

void dfs(int dep)
{
	//进入条件
	if(dep == m+1)
	{
		int an = 0;
		memset(sum,0,sizeof(sum));
		for(int i = 1; i<=m ;++i)
		{
			//?????
			if(team[i])
			{
				//更新收益
				sum[passenger[i][1]] += passenger[i][3];
				sum[passenger[i][2]] -= passenger[i][3];
				an += (passenger[i][2]-passenger[i][1])*passenger[i][3];
			}
		}
		if(check())
		{
			//获取最大可行解
			ans = max(ans,an);
		}
		return;
	}
	//??????
	dfs(dep + 1);
	team[dep] = 1;
	dfs(dep+1);
	team[dep] = 0;
	//
	return;
}
int main(int argc, char const *argv[])
{
	cin >>n >> m >>v;
	for(int i = 1; i <= m; ++i)
	{
		for (int j = 1; j < 4; ++j)
		{
			cin >> passenger[i][j];
		}
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}