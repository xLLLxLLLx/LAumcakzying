#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const long long mod=1e9+7;
const int N=100010;
LL f[N],n;

void jc(){
	f[1]=1;
	for(LL i=2;i<=2*n;++i)
		f[i]=f[i-1]*i%mod;
}

void exgcd(LL a,LL b,LL &x,LL &y){
	if(!b) x=1,y=0;
	else {
		exgcd(b,a%b,x,y);
		x-=y*(a/b);
		swap(x,y);
	}
}

LL js(LL a,LL b){
	LL x,y;
	exgcd(a,b,x,y);
	return (x+b)%b;
}

int main(){
	scanf("%lld",&n);
	jc();
	LL sum=f[2*n]%mod*js(f[n],mod)%mod*js(f[n],mod)%mod*js(n+1,mod)%mod;
	printf("%lld",sum%mod);
	return 0;
}
