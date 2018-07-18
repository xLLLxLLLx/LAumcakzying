#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N][N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ex,ey,bx,by,n,m,t;

void dfs(int x,int y,int s){
	if(s==t&&x==ex&&y==ey){
		printf("YES\n");
		exit(0);
	}
	int temp=t-s-abs(x-ex)-abs(y-ey);
	if(temp<0||temp%2) return;
	for(int i=0;i<4;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m||!a[xx][yy]) continue;
		else {
			a[xx][yy]=0;
			dfs(xx,yy,s+1);
			a[xx][yy]=1;
		}
	}
	return ;
}

int main(){
	int wall=0;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	char ch;cin>>ch;
	 	if(ch=='X') wall++;
	 	else if(ch=='D') ex=i,ey=j,a[ex][ey]=1;
	 	else if(ch=='S') bx=i,by=j,a[i][j]=1;
	 	else a[i][j]=1;
	 }
	if(n*m<=wall+t) {printf("NO\n");return 0;}
	a[bx][by]=0;
	dfs(bx,by,0); 
	printf("NO\n");
	return 0;
}
