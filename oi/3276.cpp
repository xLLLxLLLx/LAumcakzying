#include<iostream>
#include<cstdio>
using namespace std;
const int N =10010;
int a[N];
int f[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),maxn=0;
	for(int i=1;i<=n;++i) a[i]=read(),f[i]=1;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=i;++j){
		if(a[i]>a[j]) f[i]=max(f[j]+1,f[i]);
		//cout<<i<<" "<<j<<" "<<f[i]<<endl;
		maxn=max(maxn,f[i]);
	}
	printf("%d",maxn);
	return 0;
}
