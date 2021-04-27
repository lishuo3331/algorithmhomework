#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	int A,B;
}nodelist[10];
int MA,MB,n;
int result=0;
void dfs(int cur, int num)
{
	if(MB<=0||cur > n){
		if(num>result)
			result=num;
		return;
	}
	if(MA>=nodelist[cur].B)
	{
		MB-=nodelist[cur].A;
		dfs(cur+1,num+1);
		MB+=nodelist[cur].A;
	}
    dfs(cur+1,num);
}
int main(int argc, char const *argv[])
{
	cin >> MA >> MB ;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> nodelist[i].A >> nodelist[i].B;
	}
	dfs(1,0);
	cout << result ;
	return 0;
}