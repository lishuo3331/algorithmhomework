#include<cstdio>
#include<algorithm>
#include<cmath>
#include <iostream>
#define ll long long
#define N 108888
using namespace std;
char c[20];
ll n;
int m;
int cnt = 1;
struct node
{
    int l;
    int r;
    int num;
    int even;
    int p;
}NodeList[N+N+N];
int f[N];
int g[N];
int cmp(node a,node b)
{
    return a.p < b.p;
}
void init()
{
    for(int i = 1;i<=m;i++)
    {
        int x,y;
        cin >> x >> y >> c;
        NodeList[i].p = x;
        NodeList[i+m].p = y;
        NodeList[i].num = i;
        NodeList[i+m].num = i;
        NodeList[i].l = -1;
        NodeList[i+m].l = -1;
        if(c[0]=='e')
        {
            NodeList[i+m+m].even = 0;
        }else
        {
            NodeList[i+m+m].even = 1;
        }
    }
}
void Separate()
{
    for(int i = 1;i<=2*m;i++)
    {
        if(NodeList[NodeList[i].num].l==-1)
        {
            NodeList[NodeList[i].num].l = cnt-1;
        }else 
        {
            NodeList[NodeList[i].num].r = cnt;
        }
        if(NodeList[i+1].p!=NodeList[i].p)
        {
            cnt++;    
        }
    }
    for(int i = 1;i<=m;i++)
    {
        NodeList[i].even = NodeList[i+m+m].even;
    }
}
int fiNodeList(int x)
{
    if(f[x]==x)
    {
        return f[x];
    }
    int fx = fiNodeList(f[x]);
    g[x] = (g[f[x]]+g[x])%2;
    return f[x] = fx;
}
int ans;
bool flag;
void uion(int x,int y,int i)
{
    int fx = fiNodeList(x);
    int fy = fiNodeList(y);
    if(fx==fy)
    {
        if((NodeList[i].even==1&&g[x]==g[y])||(NodeList[i].even==0&&g[x]!=g[y]))
        {
            ans = i-1;
            flag = 1;
            return ;
        }
        fiNodeList(y);
        fiNodeList(x);
    }else
    {
        f[fy] = fx;
        g[fy] = (g[x]+g[y]+NodeList[i].even)%2;
        fiNodeList(x);
        fiNodeList(y);        
    }
}
void solve()
{
    for(int i = 1;i<=cnt;i++)
    {
        f[i] = i;
    }
    for(int i = 1;i<=m;i++)
    {
        int l = NodeList[i].l;
        int r = NodeList[i].r;
        uion(l,r,i);
        if(flag==1)
        {
            cout << ans << endl;
            return ;
        }
    }
    cout << m << endl;
}
int main()
{
    cin >> n >> m;
    init();
    sort(NodeList+1,NodeList+1+m+m,cmp);
    Separate();
    solve();
    return 0;
}
