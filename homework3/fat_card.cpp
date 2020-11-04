#include <iostream>
#include <algorithm>

using namespace std;

int building[102][502];
int road[101]={0};
int road_index = 0;

int* min(int first,int first_index,int second,int second_index,int third,int third_index)
{
	static int result[2];
	int temp = first<second?first:second;
	result[0] = temp<third?temp:third;
	if (result[0]==first)
	{
		result[1] = first_index;
	}
	if (result[0]==second)
	{
		result[1] = second_index;
	}
		if (result[0]==third)
	{
		result[1] = third_index;
	}
	return result;
}
int get_card(int M,int N,int x,int y)
{
	if (x>M||y>N||x<1||y<1)
	{
		return 1e9+1;
	}
	if (x<M&&y<=N)
	{
		int *a;
		a = min(get_card(M,N,x+1,y)+building[x+1][y],y,get_card(M,N,x,y-1)+building[x][y-1],y-1,get_card(M,N,x,y+1)+building[x][y+1],y+1);
		road[road_index++] = a[1];//路径填充有问题
		cout << "road_index:" << road_index <<" a:" << a[1] <<endl;
		return a[0] + building[x][y];
	}
	if(x == M)
	{
		return building[M][N];
	}
	// return road_index;
}
int main(int argc, char const *argv[])
{
	int M,N;
	cin >> M >> N;
	for(int i = 1;i <= M;++i)
	{
		for(int j = 1;j <= N;++j)
		{
			cin >> building[M][N];
		}
	}
	get_card(M,N,1,1);
	for(int i = 0;i < 101;++i)
	{
		if (road[i]!=0)
		{
			cout<<road[i] <<endl;
		}
	}
	return 0;
}