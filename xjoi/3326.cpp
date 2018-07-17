#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int f[N],d[N];
vector<int> a[N];

int read(){
	int x=0,k=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) k|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=k?-x:x;
	return x;
}

int main(){
	int n=read();
	for(int i=2;i<=n;++i){
		int x=read();
		a[x].push_back(i);
	}
	f[1]=1;d[1]=1;
	int b=0,e=2;
	int ans=0;
	while(b++<e-1){
		int h=f[b],flag=0;
		for(int i=0;i<a[h].size();++i){
			if(a[h][i]){
				flag=1;
				f[e++]=a[h][i];
				d[a[h][i]]=d[h]+1;
			}
		}
		if(!flag) ans=max(ans,d[h]);
	}
	printf("%d",ans);
	return 0;
}
