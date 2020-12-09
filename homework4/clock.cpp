#include <iostream>
#include <string.h>
using namespace std;

int cloc[10];
int clock_clone[10];
int use[10];
int mov[9][9]={{1,1,0,1,1,0,0,0,0},
                  {1,1,1,0,0,0,0,0,0},
                  {0,1,1,0,1,1,0,0,0},
                  {1,0,0,1,0,0,1,0,0},
                  {0,1,0,1,1,1,0,1,0},
                  {0,0,1,0,0,1,0,0,1},
                  {0,0,0,1,1,0,1,1,0},
                  {0,0,0,0,0,0,1,1,1},
                  {0,0,0,0,1,1,0,1,1}
				 };

bool dfs(int w)
{
	int tag = 1;
	for (int i = 0; i < 9; ++i)
	{
		clock_clone[i] = cloc[i];
	}
	for(int i = 0;i < 9; ++i)
	{
		for(int j = 0;j < 9; ++j)
		{
			clock_clone[i] = (clock_clone[i]+mov[j][i]*use[j])%4;
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		if (clock_clone[i])
		{
			tag = 0;
			break;
		}
	}
	if(tag)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < use[i]; ++j)
			{
				cout << i+1 <<" ";
			}
		}
		cout << endl;
		return true;
	}
	if (w >= 9)
	{
		return false;
	}
	for (int i = 0; i < 4; ++i)
	{
		use[w] = i;
		if (dfs(w+1))
		{
			return true;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 9; ++i)
	{
		cin >> cloc[i];
	}
	dfs(0);
	return 0;
}