#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const LL mod=1e9+7;
const int N=1010;
LL f[N][N];
 
int main(){
    LL n,m;scanf("%lld%lld",&n,&m);
    for(LL i=1;i<=n;++i) f[i][i]=1;
    for(LL i=2;i<=n;++i)
     for(LL j=1;j<=i&&j<=m;++j)
        f[i][j]=f[i-1][j-1]%mod+j*f[i-1][j]%mod;//printf("%lld",f[i][j]);
    printf("%lld",f[n][m]%mod);
    return 0;
}
