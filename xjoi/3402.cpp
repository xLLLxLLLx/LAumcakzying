#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int mod=1e9+7;
const int N=100010;
LL a[N]={0};

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

LL kuai(LL x,LL k){
    LL ans=1;
    while(k){
        if(k&1) ans=(ans*x)%mod;
        k>>=1;
        x=(x*x)%mod;
    }
    return ans%mod;
}

int main(){   
	LL n=read();
	for(int i=1;i<=n;++i){
		LL x=read();
		a[x]++;
	}
	LL qx=1;
	for(int i=2;i<100000;++i){
		if(a[i]){
			LL szk=(n-a[i]+1)*(a[i]*(a[i]+1))/2;
			qx=(qx*kuai(i,szk))%mod;
		}
	}
	printf("%lld\n",qx%mod);
	return 0;
}
