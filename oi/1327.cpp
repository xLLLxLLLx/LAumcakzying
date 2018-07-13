#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
struct data{
	int l,r;
}a[maxn];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

bool comp(data xx,data yy){
	return xx.l<yy.l;
}

int main(){
	int n=read(),flag=1;
	for(int i=1;i<=n;++i) a[i].l=read(),a[i].r=read();
	sort(a+1,a+1+n,comp);
	int left=a[1].l,right=a[1].r;
	for(int i=2;i<=n;++i){
		if(a[i].l<=right){
			right=a[i].r;
			if(i==n) printf("%d %d\n",left,right);
		}
		else {
			flag=0;
			printf("%d %d\n",left,right);
			left=a[i].l;right=a[i].r;
			if(i==n) printf("%d %d\n",left,right);
		}
	}
	if(n==1) printf("%d %d\n",left,right);
	return 0;
}
