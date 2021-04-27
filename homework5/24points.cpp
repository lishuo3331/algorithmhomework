#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string c;
int s[5];
bool used[5];
bool dfs(int index,int x)
{
    if(index==4)
    {
        if(x==24) return 1;
        else return 0;
    }
    else 
    for(int i=0;i<4;i++)
        if(!used[i])
        {
            used[i]=1;
            if(dfs(index+1,x+s[i])) return 1;
            if(dfs(index+1,x-s[i])) return 1;
            if(dfs(index+1,s[i]-x)) return 1;
            if(x!=0&&dfs(index+1,x*s[i])) return 1;
            if(x!=0&&dfs(index+1,x/s[i])) return 1;
            if(x!=0&&dfs(index+1,s[i]/x)) return 1;
            used[i]=0;
        }
        return 0;
}
int main()
{
    for(int i=0;i<4;i++)
    {
        cin>>c;
        if(c[0]=='A') s[i]=1;
        else if(c[0]=='J') s[i]=11;
        else if(c[0]=='Q') s[i]=12;
        else if(c[0]=='K') s[i]=13;
        else if(c[0]=='1'&&c[1]=='0') s[i]=10;
        else s[i]=c[0]-'0';
    }
    if(dfs(0,0)) cout<<1<<'\n';
    else cout<<0<<'\n';
    return 0;
}
//https://blog.csdn.net/zyq_20030305/article/details/78880573
