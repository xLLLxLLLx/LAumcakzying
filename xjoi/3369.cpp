#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=25;
LL f[N][N];

int main(){
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i) f[i][1]=1,f[i][i]=1;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<i;++j)
	 	f[i][j]=j*f[i-1][j]+f[i-1][j-1];
	LL sum=0;
	for(int i=1;i<=m;++i)
		sum+=f[n][i];
	printf("%lld\n",sum);
	return 0;
}
