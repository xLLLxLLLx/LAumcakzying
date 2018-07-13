#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
const int N=1000010;
LL f[N]={0,0,1,3,5,9};
 
LL wow(LL n){
    LL res=n,a=n;
    for(LL i=2;i<=sqrt(n);++i){
        if(a%i==0){
            res=res/i*(i-1);
            while(a%i==0) a/=i;
        }
        if(a==1) break;
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
 
int main(){
    LL n;scanf("%lld",&n);
    if(n<=5) printf("%lld",f[n]);
    else {
        for(int i=6;i<=n;++i)
            f[i]=f[i-1]+wow(i);
        printf("%lld",f[n]);
    }
    return 0;
}
