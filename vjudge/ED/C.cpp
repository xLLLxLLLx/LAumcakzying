#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=510;
const int M=40;
double p[M];
double pa[N],pb[N];
int n,k1,k2,k3,a,b,c;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
		memset(p,0,sizeof(p));
		memset(pa,0,sizeof(pa));
		memset(pb,0,sizeof(pb));
		double p0=1.0/k1/k2/k3;		
		for(int i=1;i<=k1;++i)
		 for(int j=1;j<=k2;++j)
		  for(int k=1;k<=k3;++k)
		  	if(i!=a||j!=b||k!=c)
		  		p[i+j+k]+=p0;
		for(int i=n;i>=0;--i){
			pa[i]=p0;
			pb[i]=1;
			for(int k=3;k<=k1+k2+k3&&i+k<=n;++k){
				pa[i]+=pa[i+k]*p[k];
				pb[i]+=pb[i+k]*p[k];
			}
		}
		printf("%.10lf",pb[0]/(1-pa[0]));
	}
	return 0;
}
