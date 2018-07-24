#include<iostream>
#include<cstdio>
using namespace std;
const int N=200010;
vector<int> q[N];
int n,x;
int ans=0;

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	n=read(),x=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		q[x].push_back(x);
		q[y].push_back(y);
	}
	dfs(x,y,step);
	printf("%d\n",ans);
	return 0;
}
