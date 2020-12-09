#include <bits/stdc++.h>
using namespace std;
#define for_define(i,a,b) for(int i=a;i<=b;i++)
const int N=27;
int n,f[N],eat[N],result[N];
char a[30],b[30],c[30],d[30];
void init()
{
    for_define(i,1,n)//将字符变成整数
    {
        a[i]-='A';
        b[i]-='A';
        c[i]-='A';
    }
    int cnt=0;
    for (int i=n; i; i--)
    {
        if (!eat[a[i]])//如果这个数还没有归纳进来的话,下面同理
        {
            d[cnt++]=a[i];
            eat[a[i]]=1;
        }
        if (!eat[b[i]])
        {
            d[cnt++]=b[i];
            eat[b[i]]=1;
        }
        if (!eat[c[i]])
        {
            d[cnt++]=c[i];
            eat[c[i]]=1;
        }
    }
}
bool check()
{
    int p = 0;
    for (int i=n; i>=1; i--)
    {
        if (f[a[i]]==-1 || f[b[i]]==-1 || f[c[i]]==-1)//如果有一个数字没确定
            p=-1;
        else
        {
            if (p==-1)
            {
                if ((f[a[i]]+f[b[i]])%n==f[c[i]])
                    p=(f[a[i]]+f[b[i]])/n;
                else if ((f[a[i]]+f[b[i]]+1)%n==f[c[i]])
                    p=(f[a[i]]+f[b[i]]+1)/n;
                else
                    return 1;
            }
            else
            {
                if ((f[a[i]]+f[b[i]]+p)%n==f[c[i]])
                    p=(f[a[i]]+f[b[i]]+p)/n;
                else
                    return 1;
            }
        }
    }
    return p == 1? true:false;
}
bool dfs(int x)
{
    if (x == n)
    {
        memcpy(result, f, sizeof(f));//拷贝函数,具体可以百度.
        return true;
    }
    for (int i = n - 1; i >= 0; i--)//从后到前枚举
    {
        f[d[x]]=i;
        if (eat[i] || check())
            continue;
        eat[i]=1;
        if (dfs(x + 1))
            return true;
        eat[i]=0;
    }
    f[d[x]]=-1;
    return false;
}
int main()
{
    cin >> n >> a+1 >> b+1 >> c+1;
    // scanf("%d\n%s %s %s",&n,a+1,b+1,c+1);//从第一位开始枚举
    init();
    memset(eat, 0, sizeof(eat));
    memset(f, -1, sizeof(f));//初始化
    dfs(0);
    for_define(i,0,n-2)
    {
        cout << result[i];
        cout << " ";
    }
    cout << result[n-1];
    
    // cout << ' ';
    // printf("%d ", result[i]);//输出答案
    return 0;
}

// 链接：https://www.acwing.com/solution/acwing/content/967/

