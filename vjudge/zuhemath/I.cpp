#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=35;
LL dp[N][N];

int main(){
	int n;
	while(scanf("%d",&n)==1&&n){
		memset(dp,0,sizeof(dp));
		dp[n][n]=1;
		for(int i=n;i>=0;--i)
		 for(int j=n;j>=0;--j){
		 	if(i==n&&j==n) continue;
		 	dp[i][j]+=dp[i+1][j];
		 	if(j<i) dp[i][j]+=dp[i][j+1];
		 }
		printf("%lld\n",dp[0][0]);
	}
	return 0;
}
