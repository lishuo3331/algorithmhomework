#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n1,n=0;
	long long result = 1;
	while((n1 = getchar()) != EOF)
	{
		int n2 = getchar();
		if(n2 != 10)
		{
			n = (n1 - 48)*10+n2-48;
			for(int i = 0; i < n; i++)
			{
				result = result * 2;
			}
			result--;
			cout << result<<endl;
			result = 1;	
			getchar();	
		}
		else
		{
			for(int i = 0; i < n1-48; i++)
			{
				result = result * 2;
			}
			result--;
			cout << result<<endl;
			result = 1;	
		}

	}
	return 0;
}