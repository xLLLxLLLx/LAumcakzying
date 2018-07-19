#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int f[N];
struct qx{
	int from,to;
	int w;
}a[N];

bool comp(qx xx,qx yy){return xx.w<yy.w;}

int find(int x){return f[k]==k?k:f[k]=find(f[k]);}



int main(){
	for(int i=1;i<=n;++i) f[i]=i;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].w);
	sort(a+1,a+1+m,comp);
	int num=0,ans=0;
	for(int i=1;i<=n;++i){
		int f1=find(a[i].from),f2=find(a[i].to);
		if(f1!=f2){
			num++;
			ans+=a[i].w;
			f[f1]=f2;
		}
		if(num==n-1) break;
	}
	printf("%d ",ans);
		
}
