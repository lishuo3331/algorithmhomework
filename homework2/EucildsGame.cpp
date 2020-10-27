#include <iostream>

using namespace std;
int a = 0;

int game(long long max,long long min)
{
	if(min == 0)
	{
		return a;
	}
	long long mid = 0;
	if (max%min && max/min == 1)
	{
		mid = max % min;
	}
	a++;
	if (mid > min)
	{
		return game(mid,min);
		/* code */
	}
	else
	{
		return game(min,mid);
	}
}

int main(int argc, char const *argv[])
{
	int Group;
	cin >> Group;
	long long max,min;
	long long return_value;
	while(Group){
		a = 0;
		cin >> max >> min;
		if(max >= min)
		{
			return_value = game(max, min);
		}
		else
		{
			return_value = game(min,max);
		}
		if (return_value%2 == 0)
		{
			cout << "Ollie wins" <<endl;
		}
		else
		{
			cout << "Stan wins" <<endl;
		}
		Group--;
	}
	return 0;
}