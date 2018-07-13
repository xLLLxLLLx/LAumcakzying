#include<iostream>
#include<cstdio>
using namespace std;
const int N = 210;
const int M = 100010;
int f[N][N],a[N][N],l[N*N][2];
int n,m,bx,by,ex,ey;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	char ch;cin>>ch;
	 	f[i][j]=M;
	 	if(ch=='#') a[i][j]=0;
	 	if(ch=='.') a[i][j]=1;
	 	if(ch=='G') a[i][j]=2;
	 	if(ch=='@') a[i][j]=1,bx=i,by=j,f[i][j]=0;
	 	if(ch=='M') a[i][j]=1,ex=i,ey=j;
	}
	int b=0,e=2;
	l[1][0]=bx,l[1][1]=by;
	while(b++<e-1){
		int x=l[b][0],y=l[b][1];
		for(int i=0;i<4;++i){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||!a[xx][yy]) continue;
			if(f[xx][yy]>f[x][y]+a[xx][yy]) l[e][0]=xx,l[e++][1]=yy,f[xx][yy]=min(f[xx][yy],f[x][y]+a[xx][yy]);
		}
	}
	if(f[ex][ey]==100010) printf("You can't save Mengxin");
	else printf("%d",f[ex][ey]);
	return 0;
}
