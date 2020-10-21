#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
int a[1000];
int judge(int n, int mid, int m)
{
	int count = 0;
	for(int i = 0;i < n;i++)
	{
		count += int(a[i]/mid);
	}
	if(count >= m)
		return 1;
	// else if (count > m)
	// {
	// 	return 1;
	// }
	// else if (count < m)
	// {
	// 	return 0;
	// }
	else
		return 0;
}


int main(int argc, char const *argv[])
{
	int n, m,mid=0;
	cin >> n >> m;
	int max_length = 0;


	for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = a[i] * 100;
			if(a[i] > max_length)
				max_length = a[i];
		}
				/*二分法*/
		int left = 0, right = max_length;
		while(left <= right)
		{
			mid = (left + right) / 2;
			
			// int jud = judge(n,mid,m);
			// if (jud == -1)
			// {
			// 	break;
			// }
			if (judge(n,mid,m))
			{
				left = mid + 1;
				/* code */
			}
			else
				right = mid - 1;
			cout << left << ' ' << mid << ' ' << right << endl;
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

	cout << setiosflags(ios::fixed) << setprecision(2) << 1.0*right/100 << endl;
	return 0;
}