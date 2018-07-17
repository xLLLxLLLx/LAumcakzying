#include<iostream>
#include<cstdio>
using namespace std;
const int N = 35;
int vis1[N],vis2[N],n,k;
long long ans=0;

void dfs(int x,int y){
	if(x>k){ans++;return ;}
	dfs(x+1);
	for(int i=y;i<=n;++i)
	 for(int j=1;j<=n;++j){
		if(!vis1[i]&&!vis2[j]){
			vis1[i]=1,vis2[j]=1;
			dfs(x+1,i);
			vis1[i]=0,vis2[j]=0;
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	dfs(1,1);
	printf("%lld",ans);
	return 0;
}
