#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100000;
double dp[N+10];
int yz[N];

void yyqx(){
	dp[1]=0;
	for(int i=2;i<=N;++i){
		yz[0]=0;
		for(int j=1;j<=sqrt(i);++j){
			if(i%j==0){
				yz[++yz[0]]=j;
				if(i/j!=j) yz[++yz[0]]=i/j;
			}
		}
		double ans=yz[0];
		for(int k=1;k<=yz[0];++k)
			ans+=dp[yz[k]];
		dp[i]=ans/(yz[0]-1);
	}
}

int main(){
	yyqx();
	int T;scanf("%d",&T);
	for(int cs=1;cs<=T;++cs){
		int n;scanf("%d",&n);
		printf("Case %d: %.9lf\n",cs,dp[n]);
	}
	return 0;
}
