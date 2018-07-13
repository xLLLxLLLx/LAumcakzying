#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 310;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int f[N*N][2],a[N][N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),bx=read(),by=read(),ex=read(),ey=read();
	int b=0,e=2;
	memset(a,0xff,sizeof(a));
	f[1][0]=bx;f[1][1]=by;
	a[bx][by]=0;
	while(b++<e-1){
		int x=f[b][0],y=f[b][1];
		for(int i=0;i<8;++i){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=0&&xx<=n-1&&yy>=0&&yy<=n-1&&a[xx][yy]==-1){
				f[e][0]=xx,f[e][1]=yy,e++;
				a[xx][yy]=a[x][y]+1;
			}
		}
	}
	printf("%d",a[ex][ey]);
	return 0;
}
