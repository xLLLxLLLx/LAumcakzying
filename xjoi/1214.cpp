#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N = 210;
LL f[N][N];

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	LL n=read(),m=read(),x,q;
	for(LL i=1;i<=n;++i)
	 for(LL j=1;j<=m;++j)
	 	x=read(),q=max(q,x),f[i][j]=f[i][j-1]+x;
	LL maxn=0;
	if(q<0){printf("%lld",q);return 0;}
	for(LL i=0;i<=m;++i)
	 for(LL j=i+1;j<=m;++j){
	 	LL sum=0;
	 	for(LL k=1;k<=n;++k){
	 		if(sum<0) sum=0;
	 		sum+=f[k][j]-f[k][i];
	 		//cout<<i<<" "<<j<<" "<<k<<" "<<f[k][j]-f[k][i]<<" "<<sum<<endl;
	 		maxn=max(maxn,sum);
	 	}
	 }
	printf("%lld",maxn);
	return 0;
}
