#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=51;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int fx[maxn][maxn][4],flag[maxn][maxn],p[maxn*maxn*10][3];
int ans=0x3f,l=0,r=0,d,n,m,bex,bey,enx,eny,de;
char dr[5];

int judge(int x,int y,int d,int dist){
	if(x<1||x>n||y<1||y>m||flag[x][y]) return 1;
	if(dist>=fx[x][y][d]) return 0;
	fx[x][y][d]=dist,p[r][0]=x,p[r][1]=y,p[r++][2]=d;
//	printf("%d %d %d %d\n",x,y,d,dist);
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	int A;scanf("%d",&A);
	 	if(A) flag[i][j]=1,flag[i-1][j]=1,flag[i-1][j-1]=1,flag[i][j-1]=1;
	}
	scanf("%d%d%d%d%s",&bex,&bey,&enx,&eny,dr);
	n--;m--;
	if(dr[0]=='E') d=0;
	else if(dr[0]=='S') d=1;
	else if(dr[0]=='W') d=2;
	else d=3;
//	cout<<dr[0]<<" "<<d<<endl;
	memset(fx,0x3f,sizeof(fx));
	fx[bex][bey][d]=0;
	p[r][0]=bex,p[r][1]=bey,p[r++][2]=d;
	while(l<r){
		int xx,yy,dd;
		int x=p[l][0],y=p[l][1],d=p[l++][2];
	//	printf("%d %d %d  %d\n", x, y, d, fx[x][y][d]);
		for(int i=1;i<=3;++i){
			xx=x+dx[d]*i,yy=y+dy[d]*i,dd=d;
			if(judge(xx,yy,dd,fx[x][y][d]+1)) break;
		}
		xx=x,yy=y,dd=(d+1)%4;
		judge(xx,yy,dd,fx[x][y][d]+1);
		dd=(d+3)%4;
		judge(xx,yy,dd,fx[x][y][d]+1);
	}
	ans=min(fx[enx][eny][0],fx[enx][eny][1]);
	ans=min(ans,min(fx[enx][eny][2],fx[enx][eny][3]));
	if(ans>=1e9) printf("-1");
	else printf("%d",ans);
	return 0;
}
