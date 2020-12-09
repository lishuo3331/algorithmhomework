//0 1 2 // 0 / 1 2 /4
//a选 b选两种状态 sort之后的排列  
//奇数2k+1

/*
最小的k+1个数 最大的k个数排序
*/
//偶数 2k
/*
差值最小的两个数 
1 3 4 6 7 9
*/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N = 0;
int num[11];
int dou_min = 100000;

int judge(int path)
{
	int n_min=0,n_max=0;
	n_min = num[path];
	n_max = num[path+1];
	int step = 1;
	for (int i = N-1;i >=0 ; --i)
	{
		if ((i!=path)&&(i!=(path+1)))
		{ 
			n_min = n_min*10+num[i];
			step ++;
			if (step == N/2)
			{
				break;
				} 
		}
	}
	step = 1;
	for (int i = 0; i < N; ++i)
	{
			
		if((i!=path)&&(i!=(path+1)))
		{
			n_max = n_max*10+num[i];
			step ++;
		}
		if (step == N/2)
		{
			break;
		}
	}
	return n_max - n_min;
}

void domain()
{
	int n_min=0,n_max=0;
	if (N%2==0)
	{
		int mmin = 10;
		int path = 0;
		for (int i = 0; i < N-1; ++i)
		{
			// if ((mmin >= (num[i+1] - num[i]))&&(num[i]!=0))
			if (num[i]!=0)
			{
				// mmin = num[i+1] - num[i];
				path = i;
				dou_min = min(dou_min,judge(path));
			}
		}
		cout << dou_min << endl;
	}
	else
	{
		if (num[0]==0)
		{
			n_max = num[1]*10;
			for(int i=2;i<N/2+1;++i)
			{
				n_max = n_max*10+num[i];
			}
			for(int i =N-1; i>N/2;--i)
			{
				n_min = n_min*10+num[i];
			}
		}
		else
		{
			// n_min = num[0];
			for (int i = 0; i < N/2+1; ++i)
			{
				n_max = n_max*10+num[i];
			}
			for(int i =N-1; i>N/2;--i)
			{
				n_min = n_min*10+num[i];
			}
		}
		cout << n_max - n_min << endl;
	}
	
}

int main(int argc, char const *argv[])
{
	int epoch = 0;
	cin >> epoch;
	while(epoch--)
	{
		// memset(num,11,sizeof(num));
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> num[i];
		}
		sort(num,num+N);
		if (N==2)
		{
			cout << num[1] - num[0] <<endl;
		}
		else
			domain();
		}
	return 0;
}

