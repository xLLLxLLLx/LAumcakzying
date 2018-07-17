#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int n,k,v[maxn],w[maxn];
double y[maxn];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

bool comp(double xx,double yy){return xx>yy;}

bool check(double cnt){
	double ans=0;
	for(int i=1;i<=n;++i) y[i]=v[i]-w[i]*cnt;
	sort(y+1,y+1+n,comp);
	for(int i=1;i<=k;++i)
		ans+=y[i];
	return ans>=0;
}

int main(){
	n=read();k=read();
	for(int i=1;i<=n;++i) w[i]=read();
	for(int i=1;i<=n;++i) v[i]=read();
	double mid,l=0,r=10000000;
	for(int i=1;i<=110;++i){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.2f",mid);
	return 0;
}
