#include<bits/stdc++.h>
using namespace std;
const int N=15;
int vis[N];
struct qx{
	int h,lev;
}a[N];
int n,m,minn=1e5;

void read(int &x){
	int f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
}

void dfs(int x,int ans){
	if(x<=0){
		minn=min(minn,ans);
		return ;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			int flag=0;
			vis[i]=1;
			if(a[i].lev>=m)
				flag=1,m-=2*a[i].h;
			else m-=a[i].h;
			dfs(m,ans+1);
			vis[i]=0;
			m+=a[i].h;
			if(flag) m+=a[i].h;
		}
	}
}

int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i){
		read(a[i].h);read(a[i].lev);
	}
	dfs(m,0);
	if(minn==1e5) printf("-1\n");
	else printf("%d\n",minn);
	return 0;	
}
