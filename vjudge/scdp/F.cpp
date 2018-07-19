#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int N=15;
LL dp[N][1<<N];
int n,m;

void dfs(int line,int check,LL mask1,LL mask2){
	//printf("%d %d %lld %lld\n",line,check,mask1,mask2);
	if(check==m){
		dp[line+1][mask2]+=dp[line][mask1];
		//printf("%d %lld %lld\n",line+1,mask2,dp[line+1][mask2]);
		return ;
	}
	if((mask1&(1<<check))>0) dfs(line,check+1,mask1,mask2);
	if((mask1&(1<<check))==0) dfs(line,check+1,mask1,mask2|(1<<check));
	if((mask1&(1<<check))==0&&check+1<m&&(mask1&(1<<(check+1)))==0) 
		dfs(line,check+2,mask1,mask2);
}

int main(){
	while(scanf("%d%d",&n,&m)==2&&n&&m){
		if(n<m) n^=m^=n^=m;
		memset(dp,0,sizeof(dp));
		dp[1][0]=1;
		for(int i=1;i<=n;++i)
		 for(int j=0;j<(1<<m);++j)
		 	if(dp[i][j]) dfs(i,0,j,0);
		printf("%lld\n",dp[n+1][0]);
		/*for(int j=0;j<=(1<<m);++j)
			printf("6 %d %lld\n",j,dp[6][j]);
		printf("cds %lld",dp[5][2046]);*/
	}
	return 0;
}
/*
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
*/
