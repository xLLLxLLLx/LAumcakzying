/*#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 500010;
double w[N],v[N];
double ans,sumw,sumv;
int n,k;
struct data{
	double s;
	int rank;
}y[N];

bool comp(data xx,data yy){return xx.s>yy.s;}

void find(){
	double x=1000010;
	for(int i=1;i<=10;++i){
		x=0;
		for(int i=1;i<=n;++i)
			y[i].s=v[i]-ans*w[i];
		sort(y+1,y+1+n,comp);
		double sumw=0,sumv=0;
		for(int i=1;i<=k;++i) x+=y[i].s,sumw+=w[y[i].rank],sumv+=v[y[i].rank];
		if(fabs(x)<1e-6) break;
		ans=sumv/sumw;
	}
}

int main(){
	scanf("%d%d",&n,&k);
	int cnt;
	for(int i=1;i<=n;++i){
		if(cnt>k) scanf("%lf",&w[i]);
		else{scanf("%lf",&w[i]);sumw+=w[i];cnt++;}
	}
	cnt=0;
	for(int i=1;i<=n;++i){
		if(cnt>k) scanf("%lf",&v[i]);
		else{scanf("%lf",&v[i]);sumv+=v[i];cnt++;}
	}
	ans=sumv/sumw;
	for(int i=1;i<=n;++i) y[i].rank=i;
	find();
	printf("%.2lf",ans);
	return 0;
}*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=500010;
int n,k,v[maxn],w[maxn];
double y[maxn];
 
int read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}
 
bool comp(double xx,double yy){return xx>yy;}
 
bool check(double cnt){
    double ans=0;
    for(int i=1;i<=n;++i) y[i]=v[i]-w[i]*cnt;
    sort(y+1,y+1+n,comp);
    for(int i=1;i<=k;++i)
        ans+=y[i];
    return ans>1e-6;
}
 
int main(){
    n=read();k=read();
    double sumw=0,sumv=0;
    for(int i=1;i<=n;++i) w[i]=read(),sumw+=w[i];
    for(int i=1;i<=n;++i) v[i]=read(),sumv+=v[i];
    double mid,l=sumv/sumw,r=10000010;
    while(fabs(l-r)>1e-6){
        mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    printf("%.2f",mid);
    return 0;
}
