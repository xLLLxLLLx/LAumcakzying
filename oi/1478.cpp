#include<iostream>
#include<cstdio>
using namespace std;
const int N = 110;
const int M = 1010;
int v[N],w[N],f[M];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int m,n;scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i) w[i]=read(),v[i]=read();
	for(int i=1;i<=n;++i)
	 for(int j=m;j>=w[i];--j)
	 	f[j]=max(f[j],f[j-w[i]]+v[i]);
	 printf("%d",f[m]);
	 return 0;
}
