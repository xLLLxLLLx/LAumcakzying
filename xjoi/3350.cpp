#include<iostream>
#include<cstdio>
#define LL long long 
using namespace std;
const int N=100010;
LL a[N],f[N][2];

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	LL x,n=read(),maxn=0,maxx=0;
	for(int i=1;i<=n;++i)
		x=read(),a[x]++,maxx=max(x,maxx);
	for(int i=1;i<=maxx;++i){
		f[i][1]=max(f[i-1][0]+a[i]*i,f[i][1]);
		f[i][0]=max(max(f[i-1][1],f[i-1][0]),f[i][0]);
		maxn=max(max(f[i][1],f[i][0]),maxn);
	}
	printf("%lld",maxn);
	return 0;
}
