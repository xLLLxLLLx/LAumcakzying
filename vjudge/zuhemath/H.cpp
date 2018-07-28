#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int mod=1e9+7;
const int N=1010;
LL dp[N][N],f[N][N];

void yyqx(){
	for(int i=0;i<N;++i) f[i][1]=1,f[i][i]=1;
	for(int i=1;i<N;++i)
	 for(int j=1;j<i;++j)
	 	f[i][j]=(f[i-1][j-1]+j*f[i-1][j]%mod)%mod;
}

int main(){
	yyqx();
	int n,r,k,m;
	while(scanf("%d%d%d%d",&n,&r,&k,&m)==4){
		LL sum=0;
		for(int i=1;i<=m;++i) sum=(sum+f[r][i])%mod;
		for(int i=1;i<=n;++i) dp[i][1]=i,dp[i][0]=1;
		for(int i=1;i<=n;++i)
		 for(int j=2;j<=r;++j){
		 	if(i>k) dp[i][j]=dp[i-k][j-1];
		 	else dp[i][j]=0;
		 	dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		 	if(j>i) dp[i][j]=0;
		 }
		/*for(int i=1;i<=n;++i)
		 for(int j=1;j<=r;++j)
		 	printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
		printf("sum=%lld\n",sum);*/
		sum=sum*dp[n][r]%mod;
		printf("%lld\n",sum);
	}
	return 0;
}
