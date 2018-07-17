#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=30;
int n,m;
int dp[N*N][N][N],a[N][N];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool check(int x,int y){
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	memset(dp,50,sizeof(dp));
	char ch;
	int ans=0;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=m;++j){
	 	cin>>ch;
	 	if(ch=='#') ans++;
	 	else a[i][j]=1;
	 }
	if(ans<n+m-1){
		printf("-1\n");
		return 0;
	}
	int minn=n*m;
	dp[0][1][1]=a[1][1];
	for(int step=1;step<ans;++step){
		for(int i=1;i<=n;++i)
		 for(int j=1;j<=m;++j){
		 	for(int k=0;k<4;++k){
		 		int x=i+dx[k],y=j+dy[k];
		 		if(check(x,y)){
		 			dp[step][i][j]=min(dp[step][i][j],dp[step-1][x][y]+a[i][j]);
		 		}
		 	}
		 }
		minn=min(minn,dp[step][n][m]); 
	}
	printf("%d\n",minn);
	return 0;
}
