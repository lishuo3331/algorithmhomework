#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

double MAX = 1e10;
int a,b;
struct Node
{
	double x,y;
};

Node ax[100005],bx[100005];
bool cmpx(Node a,Node b)
{
	return a.x < b.x;
}
bool cpmy(Node a, Node b)
{
	return a.y < b.y;
}

double min(double a, double b)
{
	return a<b?a:b;
}

double dist(Node a, Node b)
{
	return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}

double cal(int s,int e)
{
	int mid,index=0;
	double d;
	if(s == e)
		return MAX;
	mid = (s + e)/2;
	d = min(cal(s,mid),cal(mid+1,e));
	for(int i = mid;i>=s&&(ax[mid].x-ax[i].x<d);i--)
	{
		bx[index++] = ax[i]; 
	}
	for (int i = mid+1; i<e&&(ax[i].x -ax[mid].x<d); ++i)
	{
		bx[index++] = ax[i];
	}
	sort(bx,bx+index,cpmy);
	for(int i = 0;i < index;++i)
	{
		for (int j = i+1; j < index&&(bx[j].y-bx[i].y < d); ++j)
		{
			double d_r = dist(bx[i],bx[j]);
			if(d > d_r)
			{
				d = min(d,d_r);
			}
		}
	}
	return d;
}
int main(int argc, char const *argv[])
{
	int n = 0;
	while(cin >> n)
	{
		for(int i = 0; i < n ;i++)
		{
			cin >> ax[i].x >> ax[i].y;
		}
		sort(ax,ax+n,cmpx);
		double d = cal(0,n);
		printf("%.2lf\n",d);
	}
	return 0;
}