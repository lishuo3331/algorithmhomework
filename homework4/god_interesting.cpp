#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int numberList[4005];
int answer[4005];
int ans = -1;
int N;
int a[1005];

//返回是否满足四种韵脚
//start->stop
/*
4同 2同2同
*/
bool judge(int start,int stop)
{
	memset(a,0,sizeof(a));
	int top_1=-1,top_2=-1;
	for(int i=start;i<=stop;++i)
	{
		a[numberList[i]]++;
	}
	for(int i=0;i<1005;++i)
	{
		if(a[i]>top_1)
		{
			top_2 = top_1;
			top_1=a[i];
		}
	}
	// cout <<"top_1:" <<top_1<<"top_2:" << top_1 <<endl;
	if((top_1>=4)||(top_1>=2&&top_2>=2))
		return 1;
	return 0;
}

//主方法 遍历numberList get max(ans)
/**************
remeber start stop
for(i in 1 to N)
if(judge) answer[i] = max(answer[i],answer[start]+1)
ans = max(ans,answer[i])
else ;
**************/

void domain()
{
	// int start = 1;
	for (int stop = 1; stop <= N; ++stop)
	{
		for (int i = 1; i <= stop; ++i)
		{
			if(judge(i,stop)&&(stop - i >= 3))
			{
				answer[stop] = max(answer[stop],answer[i]+1);
				ans = max(ans,answer[stop]);
			}
			else;
	}
	}

}
int main(int argc, char const *argv[])
{
	cin >> N;
	for(int i=1 ; i <= N ; ++i)
	{
		cin >> numberList[i];
	}
	domain();
	cout << ans;
	return 0;
}