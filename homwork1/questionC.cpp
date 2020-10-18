#include <iostream>
#include <iomanip>
#include <stdlib.h>
//直接求和再取模为什么会溢出？？？
using namespace std;

int fun(int num,int *a,int mod)
{
	if(num <=1)
		return num;
	if (a[num] >= 0)
		return a[num] % mod;
	else
	{
		int temp = fun(num-1,a,mod) + fun(num-2,a,mod);
		a[num] = temp % mod;
	}
	return a[num];
}
int main(int argc, char const *argv[])
{
	int *a;
	a = (int *)malloc(sizeof(int) *100000);
	for (int i = 0; i <100000;i++)
		a[i] = -1;
	const int mod=1e9+7;
	int x_input;
	cin >> x_input;
	int y_fun = fun(x_input,a,mod);
	cout << y_fun  << endl ;
	return 0;
}