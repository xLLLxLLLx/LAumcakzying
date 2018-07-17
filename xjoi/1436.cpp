#include<iostream>
#include<cstdio>
using namespace std;
const int N = 10;
int a[N][N],n,m,vis[N],ans=0,maxn=0;

void dfs(int x){
	if(x==m+1){
		maxn=max(maxn,ans);
		return ;
	}
	dfs(x+1);
	for(int i=1;i<=n;++i){
		if(vis[i]<2){
			vis[i]++;
			ans+=a[i][x];
			dfs(x+1);
			ans-=a[i][x];
			vis[i]--;
		}
	}
	for(int i=1;i<=n;++i)
	 for(int j=i+1;j<=n;++j){
	 	if(vis[i]<2&&vis[j]<2){
	 		vis[i]++,vis[j]++;
	 		ans+=(a[i][x]+a[j][x]);
	 		dfs(x+1);
	 		ans-=(a[i][x]+a[j][x]);
	 		vis[i]--,vis[j]--;
	 	}
	 }
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j)
	 	scanf("%d",&a[i][j]);
	dfs(1);
	printf("%d",maxn);
	return 0;
}
