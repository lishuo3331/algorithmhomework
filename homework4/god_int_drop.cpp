#include <iostream>
#include <string>

using namespace std;

int numberList[4005];



int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for(int i=1 ; i <= N ; ++i)
	{
		cin >> numberList[i];
	}
	int start = 1;
	int ans = 0;
	int judge = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = start; j < i; ++j)
		{
			if(numberList[i] == numberList[j])
			{
				judge++;
				numberList[i] = numberList[j] =-1;
				break;
			}
		}
		if (judge == 2)
		{
			judge = 0;
			ans ++;
			start = i;
		}
	}
	cout << ans;
	return 0;
}