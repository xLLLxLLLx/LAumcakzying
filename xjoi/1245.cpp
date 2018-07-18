#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=100010;
LL a[N],b[N];
LL n,k;

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

bool check(LL x,LL y){
	for(int i=1;i<=n;++i){
		LL z=b[i]-x*a[i];
		if(z<0) y+=z;
		if(y<0) return false;
	}
	if(y<0) return false;
	return true;
}

int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	LL l=0,r=2e9+1;
	LL ans=0;
	while(l<=r){
		int temp=k;
		int mid=(l+r)>>1;
		//printf("%d %d\n",l,r);
		if(check(mid,temp)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}	
	printf("%lld",ans);
	return 0;
}
