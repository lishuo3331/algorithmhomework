#include <iostream>

using namespace std;

unsigned int a[20]={0};
int main(int argc, char const *argv[])
{
	unsigned int n;
	cin >> n;
	// unsigned int m = 1;
	int pass = 1;
	a[0] = 1;
	if(a[19] ==0 )
		{	
			for(int i=2;i<20;)
			{
				a[i] = a[i-2] * 18;
				a[i-1] = a[i] / 2;
				i = i+2;
			}
		}
	for(int i=0;i<20;i++)
	{
		if (n <= a[i])
		{
			pass = i;
			// cout << a[i] <<endl;
			break;
		}
		// cout << pass <<endl;
	}
	if (n == 1)
	{
		cout << "181818181818" << endl;
	}
	else if (pass%2 == 1)
	{
		cout << "181818181818" << endl;
	}
	else
	{
		cout << "ZBT" <<endl;
	}
	return 0;
}