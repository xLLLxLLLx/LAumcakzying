#include<iostream>
#include<cstdio>
#define LL long long
const int mod=1e9+7;
const int N=2010;
LL f[N][N],yh[N][N];

void yyqx(){
    for(int i=0;i<N;++i) yh[i][0]=1,yh[i][i]=1,f[i][i]=1;
    for(int i=1;i<N;++i)
        for(int j=1;j<i;++j){
            yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%mod;
            f[i][j]=(f[i-1][j]*(i-1)%mod+f[i-1][j-1])%mod;
        }
}

int main(){
    int T;scanf("%d",&T);
    yyqx();
    while(T--){
        int n,a,b;scanf("%d%d%d",&n,&a,&b);
        if(a+b-2>n) printf("0\n");
        else{
            LL sum=yh[a+b-2][a-1]*f[n-1][a+b-2]%mod;
            printf("%lld\n",sum);
            
        }
    }
    return 0;
}
