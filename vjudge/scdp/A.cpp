#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=15;
int dis[N][N],a[N][N];
int dp[1<<N][N];

int read(){
	/*int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;*/
	int x;scanf("%d",&x);
	return x;
}

int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		memset(dis,0x3f,sizeof(dis));
		for(int i=0;i<=n;++i)
	 	 for(int j=0;j<=n;++j)
	 		dis[i][j]=a[i][j]=read();
	 	for(int i=0;i<=n;++i)
	 	 for(int j=0;j<=n;++j)
	 	 	for(int k=0;k<=n;++k)
	 	 		dis[i][j]=min(dis[i][k]+a[k][j],dis[i][j]);
	 	/*for(int i=0;i<=n;++i)
	 	 for(int j=0;j<=n;++j)
	 	 	printf("case: %d\n",dis[i][j]);*/
		memset(dp,-1,sizeof(dp));
		dp[0][1]=0;
		for(int j=0;j<1<<(n+1);++j){
			j=j|1;
			for(int i=0;i<=n;++i){
				if(dp[i][j]!=-1){
					for(int k=0;k<=n;++k){
						if(i!=k&&(dp[k][j|(1<<k)]==-1||dp[k][j|(1<<k)]>dp[i][j]+dis[i][k]))
						dp[k][j|(1<<k)]=dp[i][j]+dis[i][k];
					}
				}
			}
		}
		printf("%d\n",dp[0][(1<<(n+1))-1]);
	}
	return 0;
}
