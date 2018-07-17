#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=370;
int k[15]={0,0,31,60,91,121,152,182,213,244,274,305,335,366};
struct data{
	int m,d;
}a[N];

bool comp(data xx,data yy){
	if(xx.m==yy.m) return xx.d<yy.d;
	else return xx.m<yy.m;
}

int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&a[i].m,&a[i].d);
	sort(a+1,a+1+n,comp);
	int maxn=0;
	a[n+1].m=13,a[n+1].d=1;
	for(int i=0;i<=n;++i){
		int ans=k[a[i+1].m]+a[i+1].d-k[a[i].m]-a[i].d-1;
		//cout<<i<<" "<<ans<<endl;
		maxn=max(maxn,ans);
	}
	
	//cout<<maxn<<endl;
	int km;
	double sum=double(maxn)/double(366)*double(3600*24);
	if(sum>=floor(sum)+0.5) km=ceil(sum);
	else km=floor(sum);
	printf("%d",km);
	return 0;
}
