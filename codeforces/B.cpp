#include<bits/stdc++.h>
using namespace std;
const int N=100010;
map<int,int>qx;
int a[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),x=read();
	int maxn=2*N,k;
	for(int i=0;i<=200001;++i) qx[i]=0;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i){
		int temp=a[i]&x;
		if(qx[temp]){
			maxn=min(maxn,qx[temp]);
		}
		if(qx[a[i]]){
			maxn=min(maxn,qx[a[i]]-1);
		}
		if(!qx[a[i]]){
			qx[a[i]]+=1;
		}
		if(!qx[temp]){
			qx[temp]+=2;
		} 
	}
	if(maxn==2*N)printf("-1\n");
	else printf("%d\n",maxn);
	return 0;
}
