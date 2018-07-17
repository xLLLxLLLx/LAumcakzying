#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 110;
const int M = 100010;
int f[M],w[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),sum=0;
	for(int i=1;i<=n;++i) w[i]=read(),sum+=w[i];
	int k=sum/2,ans=1000000,q;
	for(int i=1;i<=n;++i)
	 for(int j=k;j>=w[i];--j)
	 	f[j]=max(f[j-w[i]]+w[i],f[j]),q=abs(2*f[j]-sum),ans=min(ans,q);
	printf("%d",ans);
	return 0;
}
