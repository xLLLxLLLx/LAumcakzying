#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=25;
LL f[N][N],a[N]={1};

void yyqx(){
	for(int i=0;i<N;++i) f[i][i]=1;
	for(int i=1;i<N;++i) a[i]=a[i-1]*i;
	for(int i=1;i<N;++i)
	 for(int j=1;j<i;++j)
	 	f[i][j]=(i-1)*f[i-1][j]+f[i-1][j-1];
}

int main(){
	int T;scanf("%d",&T);
	yyqx();
	while(T--){
		int n,k;scanf("%d%d",&n,&k);
		double ans;
		LL sum=0;
		for(int i=1;i<=k;++i)
			sum+=(f[n][i]-f[n-1][i-1]);
		ans=double(sum)/double(a[n]);
		printf("%.4lf\n",ans);
	}
	return 0;
}
