#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n);
	int maxn=0;
	for(int i=1;i<=n;++i){
		if(i==1||a[i]!=a[i-1]){
			int j=a[i]+a[i];
			while(j<=a[n]){
				int p=lower_bound(a+1,a+1+n,j)-a;
				if(p>0) maxn=max(maxn,a[p-1]%a[i]);
				j+=a[i];
			}
			maxn=max(maxn,a[n]%a[i]);
		}
	}
	printf("%d\n",maxn);
	return 0;
}
