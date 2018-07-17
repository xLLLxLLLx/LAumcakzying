#include<bits/stdc++.h>
const int N=100010;
int f[N],a[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int find(int k){
	return f[k]==k?k:f[k]=find(f[k]);
}

int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read();
		if(find(x)!=find(y)){
			f[find(x)]=find(y);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(find(i)==find(a[i])){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
