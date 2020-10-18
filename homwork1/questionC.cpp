#include <iostream>

using namespace std;

int fun(int num)
{
	if(num <=1)
		return num;
	else
		return fun(num-1) + fun(num-2);
}
int main(int argc, char const *argv[])
{
	int x_input;
	cin >> x_input;
	int y_fun = fun(x_input);
	
	return 0;
}