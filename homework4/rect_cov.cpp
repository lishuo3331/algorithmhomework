#include<cstdio>
#include<iostream>
using namespace std;

struct map
{
    int x,y;
} maps[51];
struct ss
{
    int l,r,u,d;
    bool flag;
} p[5];

int n,m,ans=0x7f7f7f7f;

//判断是否在矩形内部 
bool in(ss a, int x, int y)
{
    if (x>=a.l&&x<=a.r&&y>=a.d&&y<=a.u) return 1;
    return 0;
}

//两个矩形是否交 
bool judge(ss a, ss b)
{
    if (in(a,b.l,b.u)) return 1;
    if (in(a,b.l,b.d)) return 1;
    if (in(a,b.r,b.u)) return 1;
    if (in(a,b.r,b.d)) return 1;
    return 0;
}

void dfs(int num)
{
    int value=0;
    for (int i=1; i<=m; i++)
    {
      if (p[i].flag)
      {
        for (int j=i+1; j<=m; j++)
            //部分重合
          if (judge(p[i],p[j])) return;
      }
      //面积叠加
      value+=(p[i].r-p[i].l)*(p[i].u-p[i].d);
    }
    //不可越界
    if (value>=ans) return;
    //dfs超过矩阵的数量 返回原始值
    if (num>n){
        ans=value;
        return;
    }

    for (int i=1; i<=m; i++)
    {
        //将点加入矩形
        ss tmp=p[i];
        if (p[i].flag==0)
        {
            p[i].flag=1;
            p[i].l=p[i].r=maps[num].x;
            p[i].u=p[i].d=maps[num].y;
            dfs(num+1); p[i]=tmp;
            break;
        }
        else 
        {
            p[i].r=max(p[i].r,maps[num].x); 
            p[i].l=min(p[i].l,maps[num].x);
            p[i].u=max(p[i].u,maps[num].y); 
            p[i].d=min(p[i].d,maps[num].y);
            dfs(num+1);
            p[i]=tmp;
        }    
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    	cin >> maps[i].x>>maps[i].y;

    dfs(1);

    cout << ans <<endl;
    return 0;
}