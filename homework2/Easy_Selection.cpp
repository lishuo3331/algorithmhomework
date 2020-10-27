#include <iostream>

using namespace std;

// int number[10008];

int easy_sele(int n)
{
	return 0;
}
int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	int n;
	int first;
	int number;
	while(k--)
	{
		cin >> n;
		cin >> first;
		for (int i = 0; i < n; ++i)
		{
			cin >> number;
		}
		if (first == 1)
		{
			cout << "lolanv" <<endl;
			/* code */
		}
		else
			cout << "wind" <<endl;

	} 
	return 0;
}