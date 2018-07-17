#include<iostream>
#include<cstdio>
using namespace std;
const int M=2181271;
const int N=3877817;
const int K=1635947;
int a[M],b[N],c[K];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read();
	for(int i=1;i<=n;++i){
		int ans=read();
		int x=ans%M,y=ans%N,z=ans%K;
		if(a[x]&&b[y]&&c[z]) printf("ignored\n");
		else printf("accepted\n");
		a[x]++,b[y]++,c[z]++;
	}
	return 0;
}
