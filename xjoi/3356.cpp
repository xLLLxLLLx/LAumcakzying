#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=10010;
int v[N],w[N],f[M];

int read(){
	int x=0,q=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) q|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=q?-x:x;
	return x;
}

int main(){
	int E=read(),F=read();F-=E;
	int n=read();
	for(int i=1;i<=n;++i){
		v[i]=read(),w[i]=read();
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;++i)
	 for(int j=w[i];j<=F;++j)
	 	f[j]=min(f[j],f[j-w[i]]+v[i]);
	if(f[F]>=f[10001]) printf("This is impossible.\n");
	else printf("The minimum amount of money in the piggy-bank is %d.\n",f[F]);
	return 0;
}
