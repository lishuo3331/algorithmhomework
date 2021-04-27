#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	long long n;
	cin >> n;
	int ans = 0;
	while(n!=1)
	{
		ans++;
		if (n%2!=0)
		{
			n-=7;
		}
		else
		{
			n=n/2;
		}
	}
	cout << ans;
	return 0;
}