#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
const int N=310;
const int mod=1e9+7;
LL a[N],jc[N]={1},yh[N][N],dp[N][N];
int f[N],n,vis[N];
vector<int> qx;

int find(int k){
	return f[k]==k?k:f[k]=find(f[k]);
}

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) jc[i]=jc[i-1]*i%mod;
	for(int i=0;i<=n;++i) yh[i][0]=1,yh[i][i]=1;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<i;++j)
	 	yh[i][j]=(yh[i-1][j]+yh[i-1][j-1])%mod;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i) f[i]=i;
	//cout<<111122;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<i;++j){
	 	LL sum=a[i]*a[j];
	 	LL q=sqrt(sum);
	 	if(q*q==sum){
	 		int x=find(i),y=find(j);
	 		if(x!=y) f[x]=y;
	 	}
	 }
	int ans=0;
	//cout<<11112;
	qx.push_back(0);
	for(int i=1;i<=n;++i){
		int x=find(i);
		if(!vis[x]){
			ans++,qx.push_back(x);
		}
		vis[x]++;
	}
	if(ans==n){
		printf("%lld\n",jc[n]);
		return 0;
	}
	//sort(qx.begin(),qx.end());
	//cout<<1111;
	int m=vis[qx[1]]-1;
    dp[1][m]=1;
    for(int i=2;i<=ans;m+=vis[qx[i++]]) {
        for(int j=0;j<=m;++j){
            if(!dp[i-1][j]) continue;
            for (int k=0;k<vis[qx[i]];++k){
                for (int p=0;p<=min(k+1,j);++p){ 
                    LL tmp=dp[i-1][j]*yh[vis[qx[i]]-1][k]%mod*yh[j][p]%mod*yh[m+2-j][k+1-p]%mod;
                    (dp[i][j+vis[qx[i]]-1-k-p]+=tmp)%=mod;
                }
            }
        }
    }
    LL sum=dp[ans][0];
    for (int i=1;i<=ans;++i) sum=sum*jc[vis[qx[i]]]%mod;
	printf("%lld\n",sum);
	return 0;
}
