//https://blog.csdn.net/weixin_45633221/article/details/109906759?utm_medium=distribute.pc_relevant.none-task-blog-title-2&spm=1001.2101.3001.4242
int n,m,k;
int p[maxn],w[maxn];
int fa[maxn];
int tot[maxn];//每个包里有多少个数 
int dp[maxn];
int ww[maxn][maxn],pp[maxn][maxn];

int find(int x){
	if(fa[x]==x)
	return x;
	return fa[x]=find(fa[x]);
}

void Union(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
	}
}

vector<int>v[maxn];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		cin>>p[i]>>w[i];
		fa[i]=i;
	}
	int u,vv;
	for(int i=1;i<=k;i++){
		cin>>u>>vv;
		Union(u,vv);
	}
	for(int i=1;i<=n;i++){
		v[find(i)].push_back(i);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(find(i)==i){//找到一个包 
			cnt++;
			tot[cnt]=v[i].size();
			int idx=0;
			for(int j=0;j<v[i].size();j++){
				idx++;
				 pp[cnt][idx]=p[v[i][j]];
				 ww[cnt][idx]=w[v[i][j]];
			}
		}
	}
	for(int i=1;i<=cnt;i++){//cnt个包 
		for(int j=m;j>=0;j--){//代价 
			for(int k=1;k<=tot[i];k++){
				if(ww[i][k]<=j){//第i个包里的第k个物品 
					dp[j]=max(dp[j],dp[j-ww[i][k]]+pp[i][k]);
				}
			} 
		} 
	}
	printf("%d\n",dp[m]);
}
