#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=25;
LL a[N]={0,0,1},f[N][N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

void zuhe(){
	for(int i=0;i<N;++i) f[i][0]=1,f[i][i]=1;
	for(int i=1;i<N;++i)
	 for(int j=1;j<i;++j)
	 	f[i][j]=f[i-1][j]+f[i-1][j-1];
}

void yyqx(){
	for(int i=3;i<N;++i)
		a[i]=(i-1)*(a[i-1]+a[i-2]);
}

int main(){
	int T=read();
	zuhe();
	yyqx();
	while(T--){
		int n=read(),m=read();
		LL sum=f[n][m]*a[m];
		printf("%lld\n",sum);
	}
	return 0;
}
