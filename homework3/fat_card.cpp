#include <iostream>
#include <algorithm>

using namespace std;

int building[102][502];
int road[102][502];

int min(int x,int y)
{
	return x<y?x:y;
}

void print(int x,int y)
{
	if(x==1)
	{
		cout << y <<endl;
		return ;
	}
	else
	{
		if(road[x-1][y]+building[x][y] == road[x][y])
			print(x-1,y);
		else if(road[x][y-1]+building[x][y] == road[x][y])
			print(x,y-1);
		else print(x,y+1);
	}
	cout << y <<endl;
}
// double get_card(int M,int N,int x,int y)
// {

// }
int main(int argc, char const *argv[])
{
	int M,N;
	cin >> M >> N;
	for(int i = 1;i <= M;++i)
	{
		for(int j = 1;j <= N;++j)
		{
			cin >> building[i][j];
		}
	}
//第一个签证
	for(int i =1; i <= N;++i)
	{
		road[1][i] = building[1][i];
	}

	for(int i=2;i <= M;++i)
	{
		for(int j = 1;j<=N;++j)
		{
			road[i][j] = road[i-1][j]+building[i][j];
		}
		for(int j = 2;j <=N ;++j)
		{
			road[i][j] = min(road[i][j],road[i][j-1]+building[i][j]);
		}
		for(int j =N-1;j >=1 ;--j)
		{
			road[i][j] = min(road[i][j],road[i][j+1]+building[i][j]);
		}
	}
	int ans = 1<<30;
	int xi;
	for(int i = 1;i <= N;++i)
	{
		if(road[M][i]<ans)
		{
			xi = i;
		}
		ans = min(road[M][i],ans);
	}
	print(M,xi);
	return 0;
}