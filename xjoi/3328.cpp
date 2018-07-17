#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N][N];
int c[N],n,m;

void dfs(int x){
	for(int i=1;i<=n;++i){
		if(a[x][i]){
			if(c[x]==c[i]){
				printf("No\n");
				exit(0);
			}
			else if(!c[i]){
				c[i]=3-c[x];
				dfs(i);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for(int i=1;i<=n;++i)
		if(!c[i]) c[i]=1,dfs(i);
	printf("Yes\n");
	return 0;
}
