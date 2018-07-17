#include<iostream>
#include<cstdio>
using namespace std;
const int N=100001;
int f[N],d[N],a[N];
int ans=0;

int read(){
	int x=0,k=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) k|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=k?-x:x;
	return x;
}

int main(){
	int n=read();
	for(int i=1;i<n;++i){
		int x=read();
		a[i+1]=x;
		//a[x][++a[x][0]%70]=i+1;
	}
	int l=0,r=2;
	f[1]=1;
	d[1]=1;
	while(l++<r-1){
		int h=f[l],flag=0;
		for(int i=1;i<=n;++i){
			if(a[i]==h){
				flag=1;
				d[i]=d[l]+1;
				f[r++]=i;
			}
		}
		if(!flag) ans=max(ans,d[h]);
	}
	printf("%d",ans);
	return 0;
}
