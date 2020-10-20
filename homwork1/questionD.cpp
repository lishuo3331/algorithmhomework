#include <iostream>
// #include <iomanip>
#include <stdlib.h>

using namespace std;
//超时
long long fun(int num, long long *A, int mod)
{
	// if(num == 0)
	// {
	// 	// cout << num << " " << *count << endl;
	// 	// *count ++;
	// 	*count = *count + 1 ; 
	// 	*count = *count % mod;
	// 	// cout << num << " " << *count << endl;
	// }
	// cout << num <<endl;
	if(num >3)
	{
		if(A[num] <= 0)
			A[num] = ((fun(num-1,A,mod)+fun(num-2,A,mod)+fun(num-3,A,mod)) % mod);
		// cout << A[num] << endl;
		return A[num];
	}
	if(num == 3)
	{
		// cout << 4 <<endl;
		return 4;
		// *count = *count + 4 ; 
		// *count = *count % mod;
	}
	if (num == 2)
	{
		return 2;
		// *count = *count + 2 ; 
		// *count = *count % mod;
	}
	if (num == 1)
	{
		return 1;
		// *count = *count + 1 ; 
		// *count = *count % mod;
	}
}

int main(int argc, char const *argv[])
{
	int num = 0;
	cin >> num;
	long long *temp;
	temp =(long long *)malloc(sizeof(long long) * num);
	for (int i = 0 ; i < num; i++)
	{
		temp[i] = -1;
	}
	const int mod = 1e9+7;
	long long count = fun(num,temp, mod);
	cout << count <<endl;
	return 0;
}