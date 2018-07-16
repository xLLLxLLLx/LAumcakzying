#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int N=100010;
const int INF=10000010;
int n,m,s,t;
LL dis[N];
int pa[N],b[N],ans[N];
struct qx{
	int b,e;
	LL w;
}edge[N];

int main(){
	scanf("%d%d%d%d",&s,&t,&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%lld",&edge[i].b,&edge[i].e,&edge[i].w);
	for(int i=1;i<=n;++i) dis[i]=INF;
	dis[s]=0;
	for(int i=1;i<=n-1;++i){
		for(int j=1;j<=m;++j){
			if(dis[edge[j].e]>dis[edge[j].b]+edge[j].w){
				pa[edge[j].e]=edge[j].b;
				dis[edge[j].e]=dis[edge[j].b]+edge[j].w;
				//printf("cs %d %d\n",edge[j].b,edge[j].e);
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(dis[edge[i].e]>dis[edge[i].b]+edge[i].w){
			printf("You show me the wrong map!\n");
			return 0;
		}
	}
	printf("%lld\n",dis[t]);
	int root=t,cnt=0;
	while(root!=pa[root]){
		ans[++cnt]=root;
		root=pa[root];
	}
	//printf("%d\n",cnt);
	for(int i=cnt;i>1;--i) printf("%d ",ans[i]);
	printf("%d",ans[1]);
	return 0;
}
