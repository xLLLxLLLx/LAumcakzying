#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
const int N = 100010;
int a[N],t[N],n;

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int find(int x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(t[mid]>x) r=mid-1;  
		else if(t[mid]<x)l=mid+1;
		else {
			int k=mid;
			for(int i=mid;i>=1;--i)
				if(t[i]<x){k=i+1;break;}
				else if(t[1]==x){k=1;break;}
			return k;
		}
	}
}

int main(){
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),t[i]=a[i];
	sort(t+1,t+1+n);
	for(int i=1;i<=n;++i)
		a[i]=find(a[i]);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	return 0;
}
