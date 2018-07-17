#include<iostream>
#include<cstdio>
#define LL long long
const LL mod=1e9+7;

LL kuai(LL a,LL k){
    LL ans=1;
    LL b=a%mod;
    while(k!=0){
        if(k&1) ans=(ans*b)%mod;
        k>>=1;
        b=(b*b)%mod;
    }
    return ans%mod;
}

bool check(LL x){
	if(x%2!=0) return 1;
	else return 0;
}

int main(){
	LL n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
	if(k==1){
		//LL sum=(n-1)%mod*((m-1)%mod)%mod;
		LL ans=kuai(kuai(2,n-1),m-1)%mod;
		printf("%lld",ans);
	}
	else {
		bool q=check(n),p=check(m);
		if(q==p){
			//LL sum=(n-1)%mod*((m-1)%mod)%mod;
			LL ans=kuai(kuai(2LL,n-1),m-1)%mod;
			printf("%lld",ans);
		}
		else printf("0");
	}
	return 0;
}
