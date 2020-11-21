#include <iostream>
#include <iomanip>
using namespace std;
int n;
double k,a[100005];
bool check(double m)
{
    int sum=0;//记录能切出多少个长度为m的绳子
    for(int i=1;i<=n;i++)
    {
        sum+=(int)(a[i]/m);
    }
    if(sum>=k)
        return true;
    else return false;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]*=100;
    }
    int l=0,m,r=100000000;
    while(l<=r)
    {
        m=(l+r)/2;
        if(m==0)break;
        if(check(m))
          l=m+1;
        else
            r=m-1;
    }
    cout<<fixed<<setprecision(2)<<1.0*r/100<<endl;//输出时，先将其*1.0转变成浮点数，后再出去开始扩大的100倍
    return 0;
}