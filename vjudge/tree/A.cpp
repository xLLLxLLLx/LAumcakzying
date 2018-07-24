#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=300010;
int s[N],f[N],dis[N];
int n,m;
vector<int> q[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

void dfs(int x){
	s[x]=1;dis[x]=x;
	for(int i=0;i<q[x].size();++i){
		dfs(q[x][i]);
		s[x]+=s[q[x][i]];
	}
	for(int i=0;i<q[x].size();++i){
		if(s[q[x][i]]*2>s[x])
			dis[x]=dis[q[x][i]];
	}
	while(s[x]>2*s[dis[x]])
		dis[x]=f[dis[x]];
}

int main(){
	n=read(),m=read();
	for(int i=2;i<=n;++i){
		f[i]=read();
		q[f[i]].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=m;++i){
		int ans=read();
		printf("%d\n",dis[ans]);
	}
	return 0;
}
