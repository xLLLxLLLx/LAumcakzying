#include<iostream>
#include<cstdio>
#define LL long long
const int N=25;
const int mod=1e9+7;
LL f[N][N],a[N]={1};

void yyqx(){
	for(int i=1;i<N;++i) 
		a[i]=a[i-1]*i%mod;
}

int main(){
	int n,m;scanf("%d%d",&n,&m);
	yyqx();
	for(int i=0;i<=n;++i) f[i][1]=1,f[i][i]=1;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<i;++j)
	 	f[i][j]=(f[i-1][j-1]+j*f[i-1][j]%mod)%mod;
	LL sum=f[n][m]*a[m]%mod;
	printf("%lld\n",sum);
	return 0;
}
