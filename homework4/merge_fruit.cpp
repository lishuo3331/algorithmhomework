//每次取最小的两个合并
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int number;
	int min_1,min_2;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int> > Number_List;
	for (int i = 0; i < N; ++i)
	{
		cin >> number;
		Number_List.push(number);
	}
	for (int i = 0; i < N-1; ++i)
	{
		min_1 = Number_List.top();
		Number_List.pop();
		min_2 = Number_List.top();
		Number_List.pop();
		sum += min_1 + min_2;
		Number_List.push(min_1+min_2);
	}
	cout << sum <<endl;
	return 0;
}