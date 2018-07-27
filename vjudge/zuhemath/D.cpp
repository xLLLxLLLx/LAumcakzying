#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=110;
const int mod=20090126;
LL a[N]={1};
LL dp[N][N],f[N];

void qx(){
    for(int i=1;i<N;++i) a[i]=a[i-1]*i%mod;
}

int main(){
    int T;scanf("%d",&T);
    qx();
    for(int i=1;i<N;++i) dp[i][i]=a[i],dp[i][1]=1;
    for(int i=1;i<N;++i)
     for(int j=1;j<i;++j){
        dp[i][j]=(dp[i-1][j]*j%mod+j*dp[i-1][j-1])%mod;
     }
    /*for(int i=1;i<5;++i)
       for(int j=1;j<=i;++j)
           printf("%d %d %lld\n",i,j,dp[i][j]);
   */
    for(int i=1;i<N;++i)
     for(int j=1;j<N;++j)
         f[i]=(f[i]+dp[i][j]%mod)%mod;
    while(T--){
        int n;scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    return 0;
}
//真令人害怕......QAQ

