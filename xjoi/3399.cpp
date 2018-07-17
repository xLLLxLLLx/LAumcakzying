#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=100010;
LL a[N];

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	LL n=read(),A=read();
	LL sum=0;
	for(LL i=1;i<=n;++i){
		a[i]=read();
		sum+=a[i];
	}
	LL p=1;
	for(LL i=1;i<=n;++i){
		LL mx=min(A-(n-1),a[i]),mn=max(p,a[i]-(sum-A));
		LL k=a[i]-(mx-mn+1);
		printf("%lld",k);
		if(i!=n) printf(" ");	 
	}
	return 0;
}
