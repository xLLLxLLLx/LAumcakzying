#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5001;
const int p=998244353;
LL a,b,c,ans,C[N+1][N+1],mul[N];

LL add_up(LL a,LL b){
	if (a>b) a^=b^=a^=b;
	LL sum=0;
	for(int i=0;i<=a;i++)
	 sum=(sum+C[a+1][i+1]*C[b+1][i+1]%p*mul[i]%p)%p;
	return sum;
}

int main(){
	cin>>a>>b>>c;
	C[0][0]=1;
	for(int i=1;i<=N;i++)
	 for(int j=1;j<=N;j++)
	  C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;	
	mul[0]=1;
	for(int i=1;i<N;i++) mul[i]=mul[i-1]*i%p;
	ans=add_up(a,b)*add_up(b,c)%p*add_up(a,c)%p;
	cout<<ans;
	return 0;
}
