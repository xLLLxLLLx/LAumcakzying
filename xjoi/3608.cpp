#include<bits/stdc++.h>
using namespace std;
const int N=510;
int a[N],b[N],f[N];

int read(){
	/*int x=0,w=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) w|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=w?-x:x;
	return x;*/
	int x;
	scanf("%d",&x);
	return x;
}

int main(){
	int n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int m=read();
	for(int i=1;i<=m;++i) b[i]=read();
	int maxn=0,ans=0;
	for(int i=1;i<=n;++i){
		maxn=0;	
		for(int j=1;j<=m;++j){
			if(a[i]>b[j]) maxn=max(maxn,f[j]);
			if(a[i]==b[j]) f[j]=maxn+1;
			ans=max(ans,f[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
