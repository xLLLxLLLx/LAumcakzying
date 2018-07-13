#include<iostream>
#include<cstdio>
using namespace std;
const int N = 210;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int f1[N][N],f2[N][N],a[N][N],s1[N*N][2],s2[N*N][2],vis1[N][N],vis2[N][N],fam[N*N][2],n,m,cnt=0;
int x1,y1,x2,y2;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	f1[i][j]=1000,f2[i][j]=1000;
	 	char ch;cin>>ch;
	 	if(ch=='F') a[i][j]=1,fam[++cnt][0]=i,fam[cnt][1]=j;
	 	if(ch=='@') a[i][j]=1,x1=i,y1=j;
	 	if(ch=='&') a[i][j]=1,x2=i,y2=j;
	 	if(ch=='.') a[i][j]=1;
	 }
	 int b=0,e=2;
	 s1[1][0]=x1;s1[1][1]=y1;vis1[x1][y1]=1;
	 f1[x1][y1]=0;
	 while(b++<e-1){
	 	int x=s1[b][0],y=s1[b][1];
	 	for(int i=0;i<4;++i){
	 		int xx=x+dx[i],yy=y+dy[i];
	 		if(xx<1||xx>n||yy<1||yy>m||!a[xx][yy]||vis1[xx][yy]) continue;
	 		else {
	 			vis1[xx][yy]=1;
	 			s1[e][0]=xx,s1[e++][1]=yy;
	 			f1[xx][yy]=f1[x][y]+1;
	 		}
	 	}
	 }
	 b=0,e=2;
	 s2[1][0]=x2,s2[1][1]=y2,f2[x2][y2]=0;
	 while(b++<e-1){
	 	int x=s2[b][0],y=s2[b][1];
	 	for(int i=0;i<4;++i){
	 		int xx=x+dx[i],yy=y+dy[i];
	 		if(xx<1||xx>n||yy<1||yy>m||!a[xx][yy]||vis2[xx][yy]) continue;
	 		else {
	 			vis2[xx][yy]=1;
	 			s2[e][0]=xx,s2[e++][1]=yy;
	 			f2[xx][yy]=f2[x][y]+1;
	 		}
	 	}
	 }
	 int minn=10000;
	 for(int i=1;i<=cnt;++i) minn=min(minn,f1[fam[i][0]][fam[i][1]]+f2[fam[i][0]][fam[i][1]]);
	 if(minn>=1000) printf("Meeting cancelled");
	 else printf("%d",minn);
	 return 0;
}
