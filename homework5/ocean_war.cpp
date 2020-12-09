// https://www.cnblogs.com/mjtcn/p/7044630.html
#include<iostream>
using namespace std;

int R,C,result,ex,ey,s;
char mapp[1005][1005];
int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};
void dfs(int a,int b)
{
    for (int i=0; i<4; ++i)
    {
        int x_x = a+x[i];
        int y_y = b+y[i];
        if (x_x>0&&x_x<=R&&y_y>0&&y_y<=C&&mapp[x_x][y_y]=='#')
        {
            s++;
            if (x_x>ex||y_y>ey) ex=x_x, ey=y_y; 
            mapp[x_x][y_y] = '.';
            dfs(x_x,y_y);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>R>>C;
    for (int i=1; i<=R; ++i)
        for (int j=1; j<=C; ++j)
            cin>>mapp[i][j];
    for (int i=1; i<=R; ++i)   
        for (int j=1; j<=C; ++j)
            if (mapp[i][j]=='#')
            {
                s = 1;ex = i;ey = j;
                result++;
                mapp[i][j] = '.';
                dfs(i,j);
                if ((ex-i+1)*(ey-j+1)!=s)
                {
                    cout<<"Bad placement.";
                    return 0;
                }
            }
    cout<<"There are "<<result<<" ships.";
    return 0;
}
