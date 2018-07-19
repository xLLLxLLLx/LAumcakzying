#include <cstdio>
#include <cstring> 
#include <cstdlib> 
#include <iostream>
using namespace std;
long long dp[12][(1<<11)+1];
int m,n,k;
void dfs(int c,int s1,int s2)
{
	if(c==n) 
	{
		dp[k][s1] += dp[k-1][s2]; 
		return;
	}
	if(c+1<=n)
	{
		dfs(c+1,s1<<1,s2<<1|1);
		dfs(c+1,s1<<1|1,s2<<1);
	}
	if(c+2<=n)
		dfs(c+2,s1<<2|3,s2<<2|3);
}
int main()
{
	while(~scanf("%d%d", &m ,&n) && m)
	{
		if(n>m) swap(n,m);
		memset(dp,0,sizeof(dp));
		dp[0][(1<<n)-1]=1;
		for(k=1; k<=m; k++)
			dfs(0,0,0);
		printf("%lld\n",dp[m][(1<<n)-1]);
	}
    return 0;
}

