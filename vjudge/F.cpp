#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=2010;
const int mod=1e9+7;
LL yh[N][N],f[N][N],jc[N]={1};

void yyqx(){
    for(int i=0;i<N;++i) yh[i][0]=1,yh[i][i]=1,f[i][i]=1,f[i][1]=1;
    for(int i=1;i<N;++i) jc[i]=jc[i-1]*i%mod;
    for(int i=1;i<N;++i)
        for(int j=1;j<i;++j){
            yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%mod;
			if(j!=1) f[i][j]=(f[i-1][j]*j%mod+f[i-1][j-1])%mod;
	}
}

int main(){
    int T;scanf("%d",&T);
    yyqx();
    while(T--){
        int n,k;scanf("%d%d",&n,&k);
        LL sum=0;
        for(int i=1;i<=k;++i)
            for(int j=1;j<i;++j){
                sum=(sum+yh[k][i]*yh[i][j]%mod*f[n][j]%mod*jc[j]%mod*f[n][i-j]*jc[i-j]%mod)%mod;
                //printf("i=%dj=%dsum=%lld\n",i,j,sum);
            }
        printf("%lld\n",sum);
    }
    return 0;
}
