#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
int a[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),size=read(),m=read();
	int flag=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]==m) flag=1;
	}
	if(flag){printf("1\n");return 0;}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=n;i>=1;--i){
		if(a[i]>m) continue;
		ans++;
		if(size*(n-i+1)+a[i]-1==n*size) break;
		if(i*size==a[i]-1) continue;
	}
	printf("%d",ans);
	return 0;
}
