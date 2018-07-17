#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=100010;
LL n,m,p;
LL f[N];

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

void jc(){
	f[1]=1;
	for(int i=2;i<=n;++i)
		f[i]=f[i-1]*i%p;
	/*for(int i=1;i<=n;++i)
		cout<<i<<" "<<f[i]<<endl;*/
}

void exgcd(LL a,LL b,LL &x,LL &y){
	if(!b) {
		x=1,y=0;
	//	return ;
	}
	else {
		exgcd(b,a%b,x,y);
		x-=y*(a/b);
		swap(x,y);
	}
}

LL js(LL a,LL b){
	LL x,y;
	exgcd(a,b,x,y);
	//printf("%lld %lld %lld\n",a,b,x);
	return (x+b)%b;
}

int main(){
	n=read(),m=read(),p=read();
	jc();
	LL sum=f[n]*js(f[m],p)%p*js(f[n-m],p)%p;
	printf("%lld",sum%p);
	return 0;
}//组合数取模不过如此qAq(光速逃
