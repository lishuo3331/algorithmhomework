#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10],ct,b[10],s[10];
int mov[9][9]={{1,1,0,1,1,0,0,0,0},
                  {1,1,1,0,0,0,0,0,0},
                  {0,1,1,0,1,1,0,0,0},
                  {1,0,0,1,0,0,1,0,0},
                  {0,1,0,1,1,1,0,1,0},
                  {0,0,1,0,0,1,0,0,1},
                  {0,0,0,1,1,0,1,1,0},
                  {0,0,0,0,0,0,1,1,1},
                  {0,0,0,0,1,1,0,1,1}
				 };
void init()
{
	int i;
	for(i=0;i<9;i++) scanf("%d",&a[i]);
}
bool dfs(int w)
{
	int i,j,tag=1;
	for(i=0;i<9;i++) b[i]=a[i];
	for(j=0;j<9;j++)
		for(i=0;i<9;i++)
			b[j]=(b[j]+mov[i][j]*s[i])%4;
	for(i=0;i<9;i++)
	{if(b[i]) 
	   	{
	   		tag=0; 
	   		break;
	   	}
	}
	if(tag)
	  {for(i=0;i<9;i++)
	   for(j=0;j<s[i];j++)
	      printf("%d ",i+1);
	   printf("\n");
	   return true;  
	  }

	if(w>=9) return false;
	for(i=0;i<4;i++)
	{
	   	s[w]=i;
		if(dfs(w+1)) return true;
	}
	return false;
}
int main()
{
	init(); dfs(0);
	return 0;
}