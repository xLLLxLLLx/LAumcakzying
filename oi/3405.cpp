#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=5010;
const int mod=998244353;
LL f[N][N],m[N][N];
int a,b,c;

void jc(){
	for(int i=1;i<=N;++i)m[N][1]=1;
	for(int i=2;i<=N;++i)
	 for(int j=2;j<=N;++j)
	 	m[i][j]=m[i][j-1]*j%mod;
}

void zu(){
	for(int i=1;i<=N;++i) f[i][0]=1,f[i][i]=1,f[i][1]=i;
	for(int i=2;i<=N;++i)
	 for(int j=2;j<i;++j)
	 	f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
}

int main(){
	scanf("%d%d%d",&a,&b,&c);
	jc();zu();	
	LL sum=0;
	for(int i=1;i<=a;++i)
	 for(int j=1;j<=b;++j){
		sum+=(f[a][i]*m[b][i]%mod*f[b][j]*m[c][j]%mod+f[a][i]*m[c][i]%mod*f[b][j]*m)%mod;
	}
	printf("%lld\n",sum%mod);
	return 0;
}
