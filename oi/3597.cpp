#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const LL mod=1e9+7;
const int N=1010;
LL f[N][N],a[N];
 
int main(){
    LL n,m;scanf("%lld%lld",&n,&m);
    f[1][1]=1;
    for(int i=2;i<=n;++i)
     for(int j=1;j<=i&&j<=m;++j)
     	f[i][j]=f[i-1][j-1]%mod+(i-1)*f[i-1][j]%mod;
    printf("%lld",f[n][m]%mod);
    return 0;
}
