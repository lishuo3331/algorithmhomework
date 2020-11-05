#include <iostream>
#include <algorithm>

using namespace std;
int h_set[505][505];
int result[505][505];
int max(int x,int y,int z,int m)
{
	return 0;
}
int next_step(int x,int y)
{
	return 0;
}
int main(int argc, char const *argv[])
{
	int R,C;
	for(int i = 1;i <= R;++i)
	{
		for(int j = 1;j <=C;++j)
		{
			cin >> h_set[i][j];
		}
		h_set[0][i] = 1000;
		h_set[i][0] = 1000;
		h_set[R+1][i] = 1000;
		h_set[i][R+1] = 1000;
	}
	for(int i = 1;i <= R;++i)
	{
		h_set[1][i] = 1;
		h_set[i][1] = 1;
	}
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (result[i][j] < result[i][j-1])
			{
				result[i][j] +=result[i][j-1];
			}
		}
		for(int j <= C;)	
	}
	return 0;
}
