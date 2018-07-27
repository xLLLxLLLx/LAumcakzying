#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=2010;
const int mod=1e9+7;
LL a[N]={1};

void yyqx(){
	for(int i=1;i<N;++i) a[i]=a[i-1]*i%mod;
}

int main(){
	int T;scanf("%d",&T);
	yyqx();
	while(T--){
		int n,m;scanf("%d%d",&n,&m);
		
	}
	return 0;
}
