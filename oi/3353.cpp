#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int N=100010;
const int M=110;
struct data{
	string ll,lx;
	LL v;
}a[N];
LL f[N][2];

LL read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}
/*
string drp(string s){
	string q;
	for(int i=0;i<s.size();++i)
		q[i]=s[s.size()-i];
	return q;
}*/

int main(){
	LL n=read();
	for(int i=1;i<=n;++i) f[i][1]=1e11,f[i][0]=1e11,a[i].v=read();
	for(int i=1;i<=n;++i){
		cin>>a[i].lx;
		a[i].ll=a[i].lx;
		reverse(a[i].ll.begin(),a[i].ll.end());
		//cout<<a[i].lx<<" "<<a[i].ll<<endl;
	} 
	LL minn=0;
	f[1][0]=0,f[1][1]=a[1].v;
	for(int i=2;i<=n;++i){
		if(a[i].lx>=a[i-1].lx) f[i][0]=min(f[i][0],f[i-1][0]);
		if(a[i].lx>=a[i-1].ll) f[i][0]=min(f[i][0],f[i-1][1]);
		if(a[i].ll>=a[i-1].lx) f[i][1]=f[i-1][0]+a[i].v;
		if(a[i].ll>=a[i-1].ll) f[i][1]=min(f[i][1],f[i-1][1]+a[i].v);
	}
	minn=min(f[n][0],f[n][1]);
	if(minn>=1e11) printf("-1");
	else printf("%lld",minn);
	return 0;
}
