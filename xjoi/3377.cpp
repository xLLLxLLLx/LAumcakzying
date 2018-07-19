#include<bits/stdc++.h>
using namespace std;
const int N=25;
int a[N],b[N],ca[N],cb[N];
int f[N][N][N][N];

int dfs(int l1,int r1,int l2,int r2){
	int sum;
	if(l1==r1&&l2==r2) return f[l1][r1][l2][r2]=max(a[l1],b[l2]);
	if(f[l1][r1][l2][r2]) return f[l1][r1][l2][r2];
	if(l1>r1&&l2>r2) return 0;
	sum=(ca[r1]-ca[l1-1]+cb[r2]-cb[l2-1]);
	if(l1>r1){
		f[l1][r1][l2][r2]=sum-min(dfs(l1,r1,l2+1,r2),dfs(l1,r1,l2,r2-1));
		return f[l1][r1][l2][r2];
	}
	if(l2>r2){
		f[l1][r1][l2][r2]=sum-min(dfs(l1+1,r1,l2,r2),dfs(l1,r1-1,l2,r2));
		return f[l1][r1][l2][r2];
	}
	f[l1][r1][l2][r2]=sum-(min(dfs(l1+1, r1, l2, r2),min(dfs(l1, r1-1, l2, r2), min(dfs(l1, r1, l2+1, r2), dfs(l1, r1, l2, r2-1)))));
	return f[l1][r1][l2][r2];
}
 
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ca[i]=ca[i-1]+a[i];
	for(int i=1;i<=n;++i) scanf("%d",&b[i]),cb[i]=cb[i-1]+b[i];
	dfs(1,n,1,n);
	printf("%d",f[1][n][1][n]);
	return 0;
}
