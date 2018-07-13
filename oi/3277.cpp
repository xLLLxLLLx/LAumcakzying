#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int a[N],f[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),maxn=-1000000000;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) f[i]=max(f[i-1]+a[i],a[i]),maxn=max(maxn,f[i]);
	printf("%d",maxn);
	return 0;
}
