#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
const int N=1000001;
const int mod=1e9+7;
LL jc[N]={1},ans[N]={1};
char lx[N];

LL inv(LL a,LL m){
    LL p=1,q=0,b=m,c,d;
    while(b>0){
        c=a/b;
        d=a;a=b;b=d%b;
        d=p;p=q;q=d-c*q;
    }
    return p<0?p+m:p;
}

void yyqx(){
	for(int i=1;i<N;++i) jc[i]=jc[i-1]*i%mod,ans[i]=inv(jc[i],mod);
}

LL C(LL n,LL x){
    if(x<0||n<0||n<x) return 0;
    return jc[n]*ans[x]%mod*ans[n-x]%mod;
}

int main(){
	int n;
	yyqx();
	while(~scanf("%d%s",&n,lx)){
		int len=strlen(lx);
		if(n&1) {printf("0\n");continue;}
		int ansl=0,ansr=0,flag=0;
		for(int i=0;i<len;++i){
			if(lx[i]=='(') ansl++;
			else ansr++;
			if(ansr>ansl) {flag=1;printf("0\n");break;}
		}
		if(flag) continue;
		if(ansr>ansl) {printf("0\n");continue;}
		ansl=n/2-ansl;ansr=n/2-ansr;
		LL sum=C(ansl+ansr,ansl)+mod-C(ansl+ansr,ansl-1)%mod;
		printf("%lld\n",sum%mod);
	}
	return 0;
}
