#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int mod=1e6;
const int N=110;
LL f[N<<1][N<<1];

void qx(){
	for(int i=0;i<N<<1;++i) f[i][i]=1,f[i][0]=1;
	for(int i=1;i<N<<1;++i)
	 for(int j=1;j<i;++j)
	 	f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
}

int main(){
	int n,m;
	qx();
	while(scanf("%d%d",&n,&m)==2&&(n||m)){
		printf("%lld\n",f[n+m-1][m-1]);
	}
	return 0;
}
