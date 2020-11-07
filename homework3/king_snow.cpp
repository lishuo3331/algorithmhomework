#include <iostream>
#include <algorithm>
//https://www.cnblogs.com/yalphait/p/8535495.html
using namespace std;
struct node
{
	int x,y;
	int height;
};
int h_set[505][505];
int result[505][505];
node node_list[250005];

int comp(const void *q,const void *w)
{
	return ((struct node*)q)->height - ((struct node*)w)->height;
}
int main(int argc, char const *argv[])
{
	int direr[4] = {0,0,-1,1}, direl[4] = {-1,1,0,0};
	int R,C;
	cin >> R >> C;
	int index = 0;
	for(int i = 1;i <= R;++i)
	{
		for(int j = 1;j <=C;++j)
		{
			cin >> h_set[i][j];
			node_list[index].x = i;
			node_list[index].y = j;	
			node_list[index].height = h_set[i][j];
			index++;
		}
	}
	qsort(node_list,index,sizeof(struct node),comp);
	for(int i=0;i<index;i++)
	{
		for (int j = 0; j <= 3; ++j)
		{
			if (h_set[node_list[i].x + direr[j]][node_list[i].y + direl[j]] > h_set[node_list[i].x][node_list[i].y])
			{
				result[node_list[i].x + direr[j]][node_list[i].y + direl[j]] = max(result[node_list[i].x + direr[j]][node_list[i].y + direl[j]],result[node_list[i].x][node_list[i].y]+1);
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (answer <= result[i][j])
			{
				answer = result[i][j];
			}
		}
	}
	cout << answer+1 <<endl;
	return 0;
}
