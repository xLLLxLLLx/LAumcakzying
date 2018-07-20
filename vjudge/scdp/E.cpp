#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define LL long long
using namespace std;
const int N=22,M=110;
const LL INF=7e18;
LL dp[1<<N];
int n,m;
LL b;
struct qx{
	LL pr;
	LL num;
	LL ct,k;
}a[M];

bool comp(qx xx,qx yy){
	return xx.k<yy.k;
}

int main(){
	scanf("%d%d%lld",&n,&m,&b);
	for(int i=0;i<n;++i){
		scanf("%lld%lld%lld",&a[i].ct,&a[i].k,&a[i].num);
		for(int j=0;j<a[i].num;++j){
			int x;scanf("%d",&x);
			a[i].pr|=(1<<(x-1));
		}
	}
	sort(a,a+n,comp);
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	LL minn=INF,tot=(1<<m)-1;
	for(int i=0;i<n;++i){
		for(int j=0;j<=tot;++j){
			if(dp[j]==-1) continue;
			LL w=a[i].pr|(j);
			if(dp[w]==-1) dp[w]=dp[j]+a[i].ct;
			else dp[w]=min(dp[w],dp[j]+a[i].ct);
		}
		if(dp[tot]!=-1) minn=min(minn,dp[tot]+a[i].k*b);
	}
	if(minn==INF) printf("-1\n");
	else printf("%lld\n",minn);
	return 0;
}
