#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int judge(int *a, int n, int mid, int m)
{
	int count = 0;
	for(int i = 0;i < n;i++)
	{
		count += int(a[i]/mid);
	}
	if(count == m)
		return 2;
	else if (count > m)
	{
		return 1;
	}
	else
		return 0;
}


int main(int argc, char const *argv[])
{
	int n, m;
	int *a;
	cin >> n >> m;
	float max_length = 0;
	a = (int *)malloc(sizeof(int) *n);
	for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = a[i] * 100;
			if(a[i] > max_length)
				max_length = a[i];
		}
		/*暴力搜索*/
	// while(max_length > 0)
	// {
	// 	int count =0;
	// 	for(int i = 0;i < n;i++)
	// 	{
	// 		if (max_length <= a[i])
	// 		{
	// 			count += int(a[i]/max_length);
	// 		}
	// 	}
	// 	if (count ==m)
	// 	{
	// 		cout << setiosflags(ios::fixed) << setprecision(2) << max_length << endl;
	// 		return 1;
	// 	}
	// 	else
	// 	{
	// 		max_length = max_length-0.01;
	// 	}
	// }
		/*二分法*/
		double left = 0, right = max_length;
		while(left <= right)
		{
			double mid = (left + right) / 2.00;
			int jud = judge(a,n,mid,m);
			if (jud == 2)
			{
				cout << setiosflags(ios::fixed) << setprecision(2) << mid/100 << endl;
				return 1;
			}
			else if (jud == 1)
			{
				right = mid+1;
			}
			else
			{
				left = mid-1;
			}
		}
	return 0;
}