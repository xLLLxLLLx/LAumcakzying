#include<iostream>
#include<cstdio>
using namespace std;
const int N = 110;
int vis[N][N],a[N][N],tag[N*N][2],f[N*N][2],ans=0,n,m,cnt=0;
int dx[8]={-1,0,1,1,1,0,-1,-1};
int dy[8]={1,1,1,0,-1,-1,-1,0};

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	char ch;cin>>ch;
	 	if(ch=='W') a[i][j]=1,tag[++cnt][0]=i,tag[cnt][1]=j;
	 	else if(ch=='.') a[i][j]=0;
	}
	for(int i=1;i<=cnt;++i){
		int x=tag[i][0],y=tag[i][1];
		if(!vis[x][y]){
			vis[x][y]=1;
			f[1][0]=x,f[1][1]=y;
			int b=0,e=2;
			while(b++<e-1){
				x=f[b][0],y=f[b][1];
				for(int i=0;i<8;++i){
					int xx=x+dx[i],yy=y+dy[i];
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy]&&a[xx][yy]) vis[xx][yy]=1,f[e][0]=xx,f[e++][1]=yy;
				}
			}
			ans++;
		}
		else continue;
	}
	printf("%d",ans);
	return 0;
}
