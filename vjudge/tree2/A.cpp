#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=30001;
struct data{
	int to,next,w;
}a[N<<1];
int head[N<<1],mx=0,maxn=0,vis[N],dis[N],cnt=0,qx=0;

void add(int x,int y,int w){
	a[++cnt].to=x,a[cnt].next=head[y],head[y]=cnt,a[cnt].w=w;
	a[++cnt].to=y,a[cnt].next=head[x],head[x]=cnt,a[cnt].w=w;
}

void bfs(int x){
	queue<int>q;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	vis[x]=1;q.push(x);
	while(!q.empty()){
		int h=q.front();q.pop();
		for(int i=head[h];i!=-1;i=a[i].next){
				if(!vis[a[i].to]){
					dis[a[i].to]=dis[h]+a[i].w;
					q.push(a[i].to);
					vis[a[i].to]=1;
				}
				if(dis[a[i].to]>maxn) maxn=dis[a[i].to],mx=a[i].to;
		}
	}
}

int main(){
	int T;scanf("%d",&T);
	for(int cse=1;cse<=T;++cse){
		memset(head,-1,sizeof(head));
		int n;scanf("%d",&n);
		cnt=0,maxn=0;
		for(int i=1;i<n;++i){
			int x,y,w;scanf("%d%d%d",&x,&y,&w);
			add(x,y,w);
		}
		bfs(0);
		dis[mx]=0,maxn=0;
		bfs(mx);
		printf("Case %d: %d\n",cse,maxn);
	}
	return 0;
}
