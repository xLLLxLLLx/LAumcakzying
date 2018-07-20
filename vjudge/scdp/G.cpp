#include<iostream>
#include<cstdio>
#include<cstring>
#define INF (1<<29)
using namespace std;
const int N=16;
const int M=550;
int dp[N][1<<N];
int a[M][M],dis[M][M];

void dij(int b,int n){
	bool vis[M]={0};
	for(int i=0;i<n;++i) dis[b][i]=INF;
	dis[b][b]=0;
	for(int i=0;i<n;++i){
		int k=-1;mm=INF;
		for(int j=0;j<n;++j){
			if(!vis[j]&&mm>dis[s][j])
				mm=dis[s][j],k=j;
		}
		if(k==-1) break;
		vis[k]=1;
		for(int j=0;j<n;++j){
			if(!vis[j]&&a[k][j]!=-1&&dis[b][j]>dis[b][k]+a[k][j])
				dis[b][j]=dis[b][k]+a[k][j];
		}
	}
}

int main(){
	int T;scanf("%d",&T);
	for(int cs=1;cs<=T;++cs){
		int n,m,s;scanf("%d%d%d",&n,&m,&s);
		memset(a,-1,sizeof(a));
		for(int i=1;i<=m;++i){
			int x,y,z;scanf("%d%d%d",&x,&y,&z);
			if(a[x][y]=-1||a[x][y]>z) a[x][y]=a[y][x]=z;
		}		
		dij(0,n);
		for(int i=0;i<s;++i) scanf("%d",shop[i]);
		for(int i=0;i<s;++i) dij(shop[i],n);
		if(dij[0][n-1]==INF){
			printf("Impossible\n");
			continue;
		}
		for(int i=0;i<s;++i) dp[i][shop[i]]=dis[0][shop[i]];
		for(int i=1;i<(1<<s);++i){
			for(int j=0;j<s;++j){
				if(!(i>>j)&1) continue;
				else 
			}
		}
	}
	return 0;
}
