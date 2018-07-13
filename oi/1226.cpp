#include<iostream>
#include<cstdio>
using namespace std;
const int N = 10;
int a[N][N],vis[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,ans=0;

void dfs(int x,int y){
	if(x==n&&y==m){
		ans++;return ;
	}
	for(int i=0;i<4;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]&&!vis[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy);
			vis[xx][yy]=0;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	char ch;cin>>ch;
	 	if(ch=='*') a[i][j]=1;
	 	else if(ch=='#') a[i][j]=0;
	 }
	 vis[1][1]=1;dfs(1,1);
	 printf("%d",ans);
	 return 0;
}
