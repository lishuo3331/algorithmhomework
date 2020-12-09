#include <iostream>
#include <string.h>
using namespace std;

int mov[11][7] = {{},{1,2,4,5},{1,2,3},{2,3,5,6},{1,4,7},{2,4,5,6,8},{3,6,9},{4,5,7,8},{7,8,9},{5,6,8,9},{}};
int clock[11];
int clock_clone[11];
int answer[11];
int main(int argc, char const *argv[])
{
	for (int i = 1; i < 10; ++i)
	{
		cin >> clock[i];
		clock[i] = (4-clock[i])%4;
		clock_clone[i] = clock[i];
	}
	int num = 512;
	int min = 5; 
	int max = -1;
	while(num--)
	{
		memset(answer,0,sizeof(answer));
		min = 5;
		max = -1;
		for (int i = 1; i < 10; ++i)
		{
			// cout << "i:" <<i<<endl;
			int judge = 0;
			for (int j = 1;j < 6;++j)
			{
				if (mov[i][j]!=0)
				{
					if (clock_clone[mov[i][j]]>0)
						judge = 1;
					else
						judge = -1;
				}
			}
			// cout <<"judge:" <<judge<<endl;
			if (judge == -1)
				continue;
			if (judge == 1)
			{
				for (int j = 1; j < 6; ++j)
				{
					if (mov[i][j]!=0)
					{
						clock_clone[mov[i][j]]--;
					}
				}
				for (int k = 1; k < 10; ++k)
			{
				min=min<clock_clone[k]?min:clock_clone[k];
				max=max>clock_clone[k]?max:clock_clone[k];
			}
			if (min>=0)
			{ 
				answer[i]=1;
			}
			if (min==max&&min==0)
			{
				for (int j = 1; j < 10; ++j)
				{
					if (answer[j]!=0)
					{ 
						cout<<j<<" ";
					}

				}
				cout << "before return 0";
					return 0;
			}
			}

		}
		for (int i = 1; i < 10; ++i)
		{
			clock_clone[i] = clock[i];
		}
	}
	return 0;
}