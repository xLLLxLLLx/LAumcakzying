#include<bits/stdc++.h>
using namespace std;
const int N=30;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};
int c[N*N],d[N*N],vist[N][N];
int n,m,cnt=1;

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

void dfs(int x,int y){
	if(cnt==n*m){
		for(int i=1;i<=cnt;++i)
			printf("%c%d",c[i]+'A'-1,d[i]);
		exit(0);
	}
	cnt++;
	for(int i=0;i<8;++i){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&!vist[xx][yy]){
			//printf("%d %d\n",xx,yy);
			vist[xx][yy]=1;
			c[cnt]=xx,d[cnt]=yy;
			dfs(xx,yy);
			vist[xx][yy]=0;
		}
	}
	cnt--;
}

int main(){
	m=read(),n=read();
	vist[1][1]=1;
	c[1]=1,d[1]=1;
	dfs(1,1);
	printf("impossible");
	return 0;
}
