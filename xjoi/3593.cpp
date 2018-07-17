#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll a,n;

ll read(){
	ll x=-0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
	ll d=a;
	if(!b){x=1;y=0;}
	else {
		d=exgcd(b,a%b,x,y);
		x-=a/b*y;
		swap(x,y);
	}
	return x;
}

int main(){
	a=read(),n=read();
	ll x,y;
	ll x1=max(a,n),x2=min(a,n);
	if(gcd(x1,x2)>1) {
		printf("-1");
		return 0;
	}
	ll ans=exgcd(a,n,x,y);
	if(ans<0)ans+=n;
	printf("%lld",ans);
	return 0;
}
