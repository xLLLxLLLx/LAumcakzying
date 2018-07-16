#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=5010;
const int mod=998244353;
LL f[N][N],m[N];
LL a,b,c;

void jc(){
	m[0]=1;
	for(int i=1;i<5001;++i)
		m[i]=m[i-1]*i%mod;
}

void zu(){
	f[0][0]=1;
	for(int i=1;i<5002;++i)
	 for(int j=1;j<=i;++j)
	 	f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
}

LL _plus(LL a,LL b){
	LL ans=0;
	if(b<a) a^=b^=a^=b;
	for(int i=0;i<=a;++i){
		ans=(ans+f[a+1][i+1]*f[b+1][i+1]%mod*m[i])%mod;
	}
	return ans;
}

int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	jc();zu();	
	LL sum=0;
	sum=(_plus(a,b)*_plus(a,c)%mod*_plus(b,c))%mod;
	printf("%lld\n",sum);
	return 0;
}
