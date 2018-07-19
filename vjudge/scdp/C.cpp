#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=25;
double dp[1<<N];
double p[N];

int main(){
	int n;
	while(scanf("%d",&n)==1){
		double qwq=0;
		for(int i=0;i<n;++i){
			scanf("%lf",&p[i]);
			qwq+=p[i];
		}
		//memset(dp,0,sizeof(dp));
		//qwq=1-qwq;
		dp[(1<<n)-1]=0;
		for(int i=(1<<n)-2;i>=0;--i){
			double qx=0,sum=1;
			for(int j=0;j<n;++j)
				if(i&(1<<j)) qx+=p[j];
				else sum+=p[j]*dp[i|(1<<j)];
			dp[i]=sum/(qwq-qx);
		}
		printf("%.3lf\n",dp[0]);
	}
	return 0;
}
