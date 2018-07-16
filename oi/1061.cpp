#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1001;
int a[N][N],dis[N],b[N];
int pa[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int s=read(),t=read(),n=read(),m=read();
	memset(dis,0x3f,sizeof(dis));
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;++i) pa[i]=n+1;
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),z=read();
		if(z<a[x][y]) a[x][y]=z,a[y][x]=z;
	}
	dis[t]=0;
	for(int i=1;i<=n;++i){
		int k=0;
		for(int j=1;j<=n;++j)
			if(!b[j]&&dis[j]<=dis[k])
				k=j;
		b[k]=1;
		for(int j=1;j<=n;++j){
			if(!b[j]&&dis[j]>dis[k]+a[k][j])
				dis[j]=dis[k]+a[k][j],pa[j]=k;
			else if(dis[k]+a[k][j]==dis[j]&&j<=pa[k])
				pa[j]=k;
		}
	}
	printf("%d\n",dis[s]);
	for(int i=s;i<=n;i=pa[i]) printf("%d ",i);
	return 0;
}
