#include <iostream>
#include <algorithm>

using namespace std;

int good[31];
int min(int first,int second)
{
	return first<second?first:second;
}
//原问题可以分解为子问题--装k个good==（k-1）*good+1
//原问题的最优解依赖于子问题的最优解

int select_good(int index,int size)
{
	if(index == 0)
	{
		if(size >= good[index])
			return size - good[index];
		else
			return size;
	}
	if (good[index] > size)
	{
		return select_good(index-1,size);
	}
	if(good[index] < size)
	{
		return min(select_good(index-1,size),select_good(index-1,size-good[index]));
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	int box_size;
	int good_num;
	cin >> box_size;
	cin >> good_num;
	for(int i = 0;i < good_num;++i)
	{
		cin >> good[i];
	}
	sort(good+0,good+good_num);
	cout << select_good(good_num-1,box_size);
	return 0;
}