#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1010;
const int mod=1e9+7;
LL f[N][N],yh[N][N];

void yyqx(){
	for(int i=1;i<N;++i) f[i][1]=1,f[i][i]=1,yh[i][0]=1,yh[i][i]=1;
	for(int i=1;i<N;++i)
	 for(int j=1;j<i;++j){
	 	f[i][j]=(f[i-1][j-1]+f[i-1][j]*j%mod)%mod;
		yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%mod;
	}
}

int main(){
	yyqx();
	int n,r,k,m;
	while(scanf("%d%d%d%d",&n,&r,&k,&m)==4){
		LL sum=0;
		for(int i=1;i<=m;++i) sum=(sum+f[r][i])%mod;
		if(n-(r-1)*k+r-1>=0) sum=(sum*yh[n-(r-1)*k+r-1][r])%mod;
		else sum=0;
		printf("%lld\n",sum);
	}
	return 0;
}
