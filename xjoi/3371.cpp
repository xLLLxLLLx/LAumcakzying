#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=110;
LL f[N][N];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i) f[i][1]=1,f[0][i]=1;
	for(int i=1;i<=n;++i)
	 for(int j=2;j<=m;++j){
	 	f[i][j]=f[i][j-1];
	 	if(i>=j) f[i][j]+=f[i-j][j];
	 	//printf("cs f[%d][%d]=%lld\n",i,j,f[i][j]);
	 }
	printf("%lld\n",f[n][m]);
	return 0;
}
