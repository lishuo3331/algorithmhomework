#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a < b)swap(a, b);
	if (b == 0)
		return a;
	else return gcd(b, a%b);
}

int main(int argc, char *argv[])
{
	double x0, y0;
	cin >> x0 >> y0;
	int ans = 0;

	for (int i = 1;i*x0 <= y0; i++)
	{
		for (int j = i;j * x0 <= y0; j++)
		{
			if(i*j*x0 == y0 &&gcd(i,j) ==1 ){
				if ( i == j)
					ans ++;
				else
					ans = ans + 2;
				}

			}

		}
	cout << ans <<endl;
	return 0;
}
