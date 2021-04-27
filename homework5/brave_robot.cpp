//https://blog.csdn.net/weixin_45675097/article/details/109906317?utm_medium=distribute.pc_relevant_t0.none-task-blog-OPENSEARCH-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-OPENSEARCH-1.control
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>PLL;
typedef pair<int,int>PII;
typedef pair<double,double>PDD;
#define I_int ll
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
char F[200];
inline void out(I_int x)
{
    if (x == 0) return (void) (putchar('0'));
    I_int tmp = x > 0 ? x : -x;
    if (x < 0) putchar('-');
    int cnt = 0;
    while (tmp > 0)
    {
        F[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while (cnt > 0) putchar(F[--cnt]);
    //cout<<" ";
}
ll ksm(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn=1100,N=1e6+100,mod=1e9+7;
const double PI = atan(1.0)*4;
const double eps=1e-6;
int root[maxn],w[maxn],p[maxn];
int n,m,k;
vector<int>v[maxn];
int Find(int x){
    if(x!=root[x]) root[x]=Find(root[x]);
    return root[x];
}
int dp[1100];
int ww[1100][1100],pp[1100][1100];
int tot[maxn];
int main()
{
    n=read(),m=read(),k=read();
    for(int i=1;i<=n;i++) w[i]=read(),p[i]=read();
    for(int i=1;i<=n;i++) root[i]=i;
    while(k--){
        int u=read(),v=read();
        u=Find(u),v=Find(v);
        if(u!=v) root[u]=v;
    }
    for(int i=1;i<=n;i++) v[Find(i)].push_back(i);
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(i==Find(i)){
            cnt++;
            tot[cnt]=v[i].size();
            int idx=0;
            for(auto t:v[i]){
                idx++;
                ww[cnt][idx]=w[t];
                pp[cnt][idx]=p[t];
            }
        }
    for(int i=1;i<=cnt;i++)
        for(int j=m;j>=0;j--)
            for(int k=1;k<=tot[i];k++)
                if(pp[i][k]<=j)
                    dp[j]=max(dp[j],dp[j-pp[i][k]]+ww[i][k]);
    out(dp[m]);
    return 0;
}
