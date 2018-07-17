#include<iostream>
#include<cstdio>
using namespace std;
const int N = 25;
int f[N][N],vis[N][N],num;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n,m;

void dfs(int x,int y){
	for(int i=0;i<4;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(!f[xx][yy]||xx<1||xx>n||yy<1||yy>m||vis[xx][yy]) continue;
		else {
			vis[xx][yy]=1;
			num++;
			dfs(xx,yy);
		}
	}
}

int main(){
	int bx,by;scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	char ch;cin>>ch;
	 	if(ch=='.') f[i][j]=1;
	 	else if(ch=='#') f[i][j]=0;
	 	else if(ch=='@') f[i][j]=1,bx=i,by=j;
	 }
	 vis[bx][by]=1;num=1;
	 dfs(bx,by);
	 printf("%d",num);
	 return 0;
}
