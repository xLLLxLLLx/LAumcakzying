#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2010;
double dp[N][N];
int n,t;
double p;

int main(){
	scanf("%d%lf%d",&n,&p,&t);
	dp[0][0]=1;
	for(int i=1;i<=t;++i)
	 for(int j=0;j<=n;++j){
	 	if (j==n)dp[i][j] = dp[i-1][j];
        else dp[i][j]=(1-p)*dp[i-1][j];
        if (j) dp[i][j]+=p*dp[i-1][j-1];
	 }
	double ans=0;
	for(int i=0;i<=n;++i)
		ans+=dp[t][i]*i;
	printf("%.7lf",ans);
	return 0;
}
