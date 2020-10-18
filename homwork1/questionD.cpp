#include <iostream>

using namespace std;
//超时
void fun(int num, int *count)
{
	const int mod = 1e9+7;
	if(num == 0)
	{
		// cout << num << " " << *count << endl;
		// *count ++;
		*count = *count + 1 ; 
		*count = *count % mod;
		// cout << num << " " << *count << endl;
	}
	if(num >=3)
	{
		fun(num-1,count);
		fun(num-2,count);
		fun(num-3,count);
	}
	if (num < 3&& num >= 2)
	{
		fun(num-1,count);
		fun(num-2,count);
	}
	if (num==1)
	{
		fun(num-1,count);
	}
}

int main(int argc, char const *argv[])
{
	int num = 0;
	cin >> num;
	int count = 0;
	fun(num,&count);
	cout << count;
	return 0;
}