#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int N = 100010;
int f[N][15],a[N][15];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),sum=0;
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		a[y][x]++;
		sum=max(sum,y);
	}
	int maxn=0,k=0;
	f[1][4]=a[1][4],f[1][5]=a[1][5],f[1][6]=a[1][6];
	k=max(max(a[1][4],a[1][5]),a[1][6]);
	for(int i=2;i<=sum;++i)
	 for(int j=0;j<=10;++j){
	 	f[i][j]=max(f[i-1][j],f[i-1][j+1]);
	 	if(j>=1) f[i][j]=max(f[i][j],f[i-1][j-1]);
	 	if(abs(j-5)<=i) f[i][j]+=a[i][j];
		maxn=max(maxn,f[i][j]);
	}
	maxn=max(maxn,k);
	/*for(int i=1;i<=sum;++i)
	 for(int j=0;j<=10;++j)
	 	printf("%d %d %d\n",i,j,f[i][j]);*/
	printf("%d",maxn);
	return 0;
}
