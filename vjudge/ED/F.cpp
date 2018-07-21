#include<iostream>
#include<cstdio>
using namespace std;
const int N=1010;
double dp[N][N];

int main(){
	int w,b;scanf("%d%d",&w,&b);
	for(int i=1;i<=w;++i) dp[i][0]=1;
	for(int i=1;i<=w;++i)
	 for(int j=1;j<=b;++j){
	 	 dp[i][j]+=(double)i/(i+j);
         if(j>=3) dp[i][j]+=(double)j/(i+j)*((double)(j-1)/(i+j-1))*((double)(j-2)/(i+j-2))*dp[i][j-3];
         if(j>=2) dp[i][j]+=((double)j/(i+j))*((double)(j-1)/(i+j-1))*((double)i/(i+j-2))*dp[i-1][j-2];
     }
	printf("%.10lf",dp[w][b]);
	return 0;
}
