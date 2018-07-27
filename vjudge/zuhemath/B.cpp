#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=2010;
const int mod=1e9+7;
int a[N];
LL dp[N]={1};

int main(){
	int n,tot=0,x=0;scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		if(a[i]==-1) tot++;
		else {
			if(a[a[i]]==-1) x++;
		}
	}
	int cnt=tot-x;
	for(int i=2;i<=x;++i) dp[0]=dp[0]*i%mod;
	for(int i=1;i<=cnt;++i){
		if(i-1>=0) dp[i]=(dp[i]+(x+i-1)*dp[i-1])%mod;
		if(i-2>=0) dp[i]=(dp[i]+(i-1)*dp[i-2])%mod;
	}
	printf("%lld\n",dp[cnt]);
	return 0;
}
