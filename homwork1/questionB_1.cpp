#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int n;
double k;
int a[1000];
bool check(double m)
{
    int sum=0;
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
    int l=0,m,r=1000000;
    while(l< r)
    {
        m=(l+r)/2;
        if(m==0)break;
        if(check(m))
            l=m+1;
        else
            r=m-1;
    }
    cout<<fixed<<setprecision(2)<<1.0*m/100<<endl;
    return 0;
}