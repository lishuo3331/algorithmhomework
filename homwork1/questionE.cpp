#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int isPrime(int num)
{
	if(num ==2 || num ==3)
	{
		return 1;
	}
	if (num%6 != 1 || num %6 !=5)
	{
		return 0;
	}
	int tmp = sqrt(num) + 1;
	for (int i = 0; i < tmp; i+=6)
	{
		if(num%i == 0 || num%(i+2) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int answerE(int N,int pass)
{
	// int number = 0;
	if (N > 0)
	{
		for (int i = 2; i <=9; i++)
		{
			number = i;
			if(isPrime(number))
			{
				// cout << number;
				number = answerE(N,number) + pass * 10;
			}
		}
	}
	
	N--;
	return number;
}
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	answerE(N,0);
	return 0;
}