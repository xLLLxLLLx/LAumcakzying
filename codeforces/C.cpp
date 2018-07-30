#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100010;
int a[N<<1];
struct data{
	int num,k;
}qx[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

bool comp(data xx,data yy){return xx.num>yy.num;}

int main(){
	int n=read();
	for(int i=1;i<=n<<1;++i){
		a[i]=read();
	}
	sort(a+1,a+1+2*n);
	int ans=1,maxn=0,last=a[1];
	for(int i=2;i<=2*n;++i){
		if(a[i]!=last){
			maxn=max(maxn,ans);
			ans=1;
			last=a[i];
		}
		else ans++;
	}
	LL sum=1e18;
	if(n==1) {printf("0\n");return 0;}
	for(int i=1;i<=n;++i){
		LL x1=a[i+n-1]-a[i],y1;
		if(i==1) y1=a[2*n]-a[n+1];
		else y1=a[2*n]-a[1];
		LL m=x1*y1;
		sum=min(sum,m);
	}
	printf("%lld\n",sum);
	return 0;
}
