#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
double dp[N];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	dp[1]=1;
	for(int i=2;i<=m;++i){
		dp[i]=dp[i-1]+(n-dp[i-1])/n;
	}
	printf("%.10lf",dp[m]);
	return 0;
}
