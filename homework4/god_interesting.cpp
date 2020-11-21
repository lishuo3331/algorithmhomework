#include <iostream>

using namespace std;
int numberList[4005];
int answer[4005];
int ans;

//返回是否满足四种韵脚
//start->stop
/*
4同 2同2同
*/
bool judge()
{

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

}
int main(int argc, char const *argv[])
{
	cin >> N;
	for(int i=1 ; i <= N ; ++i)
	{
		cin >> numberList[i];
	}

	return 0;
}