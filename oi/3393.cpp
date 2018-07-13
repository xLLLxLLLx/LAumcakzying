#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;

const int MAXN=100010;
LL f[MAXN];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read();
	LL maxn=0;
	for(int i=1;i<=n;++i){
		int x=read();
		int ans=0;
		while(x){
			if(x&1) ans++;
			x/=2; 
		}
		f[ans]++;
		maxn=max(maxn,f[ans]);
	}
	LL sum=0;
	for(int i=0;i<=maxn;++i)
		if(f[i]>=2) sum+=(f[i]*(f[i]-1))/2;
	printf("%lld",sum);
	return 0;
}
