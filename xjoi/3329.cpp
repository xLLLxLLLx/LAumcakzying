#include<bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int> a[N];
int dis[N],b[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=2;i<=n;++i){
		int x=read(),y=read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int s=read(),t=read();
	dis[s]=0;
	for(int i=1;i<=n;++i){
		int k=0;
		for(int j=1;j<=n;++j)
			if(!b[j]&&dis[j]<dis[k]) k=j;
		if(!k) break;
		b[k]=1;
		for(int j=0;j<a[k].size();++j){
			if(a[k][j]){
				if(!b[a[k][j]]) dis[a[k][j]]=min(dis[a[k][j]],dis[k]+1);
			}
		}
	}
	printf("%d",dis[t]);
	return 0;
}
