#include<iostream>
#include<cstdio>
using namespace std;
const int N = 15;
int vis[N],n,k,a[N];

void dfs(int x,int y){
	if(x==k){
		for(int i=0;i<k;++i) printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for(int i=y;i<=min(n-(x-k+1),n);++i){
		if(!vis[i]) {
			a[x]=i;
			vis[i]=1;
			dfs(x+1,i);
			vis[i]=0;
		}
	}
}


int main(){
	scanf("%d%d",&n,&k);
	dfs(0,1);
	return 0;
}
