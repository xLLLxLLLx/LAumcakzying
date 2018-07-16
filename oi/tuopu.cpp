#include<iostream>
#include<cstdio>
using namespace std;
const int N=1010;
int k[N],a[N][N],b[N];
int cnt=0;

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

void drp(int x){
	k[++cnt]=x;
	for(int j=cnt;k[j]>k[j-1]&&j>1;--j)
		k[j]^=k[j-1]^=k[j]^=k[j-1];
}

int main(){
	int n=read(),m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		a[x][y]=1,b[y]++;
	}
	for(int i=1;i<=n;++i)
		if(!b[i]) drp(i);
	for(int i=1;i<=n;++i){
		printf("%d ",k[cnt]);cnt--;
		int q=k[cnt+1];
		for(int j=1;j<=n;++j){
			if(a[q][j]){
				//printf("case: %d %d %d %d\n",i,j,cnt,b[j]);
				a[q][j]=0;
				b[j]--;
				if(!b[j]) drp(j);
			}
		}
		if(!cnt)break;
	}
	return 0;
}
