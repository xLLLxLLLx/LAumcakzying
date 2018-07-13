#include<iostream>
#include<cstdio>
using namespace std;
const int N=1010;
string lx;
int dp[N];

bool check(int x,int y){
	for(int i=x;i<=y;++i)
		if(lx[i]!=lx[y+x-i]) return false;
	return true;
}

int main(){
	cin>>lx;
	int len=lx.size();
	for(int i=0;i<len;++i){
		if(i>0) dp[i]=dp[i-1]+1;
		else dp[i]=1;
		if(check(0,i)) dp[i]=1;
		for(int j=1;j<i;++j){
			if(check(j,i)) dp[i]=min(dp[i],dp[j-1]+1);
		}
	}
	//for(int i=0;i<len;++i)cout<<i<<" "<<dp[i]<<endl;
	printf("%d",dp[len-1]);
	return 0;
}
