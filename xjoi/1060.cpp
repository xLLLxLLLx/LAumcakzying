#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=100010;
int f[N];
struct qx{
	int b,e;
	LL w;
}a[N<<1];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int find(int k){
	return k==f[k]?k:f[k]=find(f[k]);
}

void add_up(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy) f[xx]=yy;
}

bool comp(qx xx,qx yy){
	return xx.w<yy.w;
}

int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=m;++i)
		a[i].b=read(),a[i].e=read(),scanf("%lld",&a[i].w);
	sort(a+1,a+1+m,comp);
	LL sum=0;
	int ans=0;
	for(int i=1;i<=m;++i){
		if(find(a[i].b)!=find(a[i].e)){
			add_up(a[i].b,a[i].e);
			sum+=a[i].w;
			ans++;
			//printf("%d %d\n",ans,a[i].w);
		}
		if(ans==n-1) break;
	}
	printf("%lld",sum);
	return 0;
}
