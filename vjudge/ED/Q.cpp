#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1510;
struct data{
	int x,y,t;
	double p;
}a[N];
double dp[N];

bool comp(data xx,data yy){return xx.t<yy.t;}

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%lf",&a[i].x,&a[i].y,&a[i].t,&a[i].p);
	}
	sort(a+1,a+1+n,comp);
	for(int i=1;i<=n;i++){
       dp[i]=a[i].p;
       for(int j=1;j<i;j++){
          long long t1=(a[i].t-a[j].t);
          t1*=(a[i].t-a[j].t);
          long long tmp1=(a[i].x-a[j].x);
          long long tmp2=(a[i].y-a[j].y);
          long long t2=tmp1*tmp1+tmp2*tmp2;
          if(t1>=t2) dp[i]=max(dp[i],dp[j]+a[i].p);
      }
	}
	double maxn=0;
	for(int i=1;i<=n;++i)
		maxn=max(maxn,dp[i]);
	printf("%.7lf",maxn);
	return 0;
}
