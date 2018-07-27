#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=100001;
const int mod=1e9+7;
LL dp[N];

/*LL yyqx(int i,int j){
	if(i<j) return 0;
	if(i==1||j==1) return 1;
	if(i<j) return yyqx(i,i);
	if(i==j) return yyqx(i,j-1)+1;
	return (yyqx(i,j-1)+yyqx(i-j,j))%mod;
}*/

int main(){
	//int T;scanf("%d",&T);
	for(int i=1;i<N;++i)
	 for(int j=i;j<N;++j)
	 	dp[j]=(dp[j]+dp[j-i])%mod;
	while(T--){
		int n;scanf("%d",&n);
		printf("%lld\n",dp[n]%mod);
	}
	return 0;
}
