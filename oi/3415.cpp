#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	LL n=read();
	LL m=sqrt(n);
	LL sum=0;
	for(LL i=2;i<=m;++i){
		LL p=i+1,q=n/i;
		sum+=i;
		if(q<p) continue;
		sum+=(q-p+1)*i;
		sum+=(p+q)*(q-p+1)/2;
	}
	printf("%lld",sum);
	return 0;
}
