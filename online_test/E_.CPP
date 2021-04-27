// https://blog.csdn.net/qq_29980371/article/details/76826514?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-2&spm=1001.2101.3001.4242
#include<bits/stdc++.h>
using namespace std;
int v[500];
int n[10];
int dp[1000000];
int main()
{
    fill(dp,dp+1000000,0);
    int sum=0;
    for(int i=1;i<=6;i++){
        scanf("%d",&n[i]);
        sum+=n[i]*i;
    }
 
    int meng=sum/2;
    if(sum%2!=0) printf("Can't be divided.\n");
    else{
        int num=1;
        for(int i=1;i<=6;i++){
            int k=1,tmp=n[i];
            for(k=1;k<=tmp;k=k*2){//直接对n[i]进行分配，然后重新确定v[i]与w[i]，因为这里v[i]与w[i]相同所以w[i]不作处理
                v[num++]=i*k;
                tmp-=k;
            }
            if(tmp>0)
                v[num++]=i*tmp;
        }
        for(int i=1;i<=num-1;i++)
        for(int j=meng;j>=v[i];j--){
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
        }
        if(dp[meng]==meng) printf("Can be divided.\n");
        else printf("Can't be divided.\n");
    }
 
    return 0;
 
}