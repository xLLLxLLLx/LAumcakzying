#include<iostream>
#include<cstdio>
using namespace std;
const int N=1010;
double dp[N][N];

int main(){
	int n,s;scanf("%d%d",&n,&s);
	dp[n][s]=0;
	for(int i=n;i>=0;--i)
	 for(int j=s;j>=0;--j){
	 	if(i==n&&j==s) continue;
	 	else dp[i][j]=(n*s+(n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1]+(n-i)*(s-j)*dp[i+1][j+1])/(n*s-i*j);
	 }
	printf("%.4lf\n",dp[0][0]);
	return 0;
}
