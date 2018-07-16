#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
int a[N],b[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read();
	int ans=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
}
