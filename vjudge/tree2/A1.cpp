#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=30001;
struct data{
	int w,to,next;
}a[N<<1];
int head[N],vis[N],cnt=0,maxx=0,mx;

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

void add(int x,int y,int w){
	a[++cnt].to=y,a[cnt].next=head[x],a[cnt].w=w,head[x]=cnt;
	a[++cnt].to=x,a[cnt].next=head[y],a[cnt].w=w,head[y]=cnt;
}

void dfs(int x,int dis){
	vis[x]=1;
	for(int i=head[x];i!=-1;i=a[i].next){
		if(!vis[a[i].to]){
			int temp=dis+a[i].w;
			dfs(a[i].to,temp);
			vis[a[i].to]=1;
		}
	}
	if(dis>maxx){maxx=dis,mx=x;}
}

int main(){
	int T=read();
	for(int cse=1;cse<=T;++cse){
		int n=read();
		memset(head,-1,sizeof(head));
		cnt=0;maxx=0;
		for(int i=1;i<n;++i){
			int x=read(),y=read(),w=read();
			add(x,y,w);
		}
		memset(vis,0,sizeof(vis));
		dfs(0,0);
		maxx=0;
		memset(vis,0,sizeof(vis));
		dfs(mx,0);
		printf("Case %d: %d\n",cse,maxx);
	}
	return 0;
}
