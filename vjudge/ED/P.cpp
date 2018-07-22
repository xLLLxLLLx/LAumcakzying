#include<iostream>
#include<cstdio>
using namespace std;
const int N=110;
int r,s,p;
double dp[N][N][N];

int main(){
	scanf("%d%d%d",&r,&s,&p);
	dp[r][s][p]=1;
	for(int i=r;i>=0;--i)
	 for(int j=s;j>=0;--j)
	  for(int k=p;k>=0;--k){
	  	double sum=i*j+i*k+j*k;
	  	if(i&&k) dp[i-1][j][k]+=(dp[i][j][k]*i*k)*1.0/sum;
	  	if(i&&j) dp[i][j-1][k]+=(dp[i][j][k]*i*j)*1.0/sum;
	  	if(k&&j) dp[i][j][k-1]+=(dp[i][j][k]*k*j)*1.0/sum;
	  }
	double x=0,y=0,z=0;
	for(int i=r;i>=0;--i)
		x+=dp[i][0][0];
	for(int i=s;i>=0;--i)
		y+=dp[0][i][0];
	for(int i=p;i>=0;--i)
		z+=dp[0][0][i];
	/*for(int i=0;i<=r;++i)
	 for(int j=0;j<=s;++j)
	  for(int k=0;k<=r;++k)
	  	printf("ccc %d %d %d %lf\n",i,j,k,dp[i][j][k]);*/
	printf("%.10lf %.10lf %.10lf\n",x,y,z);
	return 0;
}
