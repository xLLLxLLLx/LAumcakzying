#include<iostream>
#include<cstdio>
#define LL long long
const int mod=1e9+7;
struct qx{
	LL m[2][2];
}h,l;

qx jz(qx x,qx y){
	qx temp;
	for(int i=0;i<2;++i)
	 for(int j=0;j<2;++j){
	 	temp.m[i][j]=0;
	 	for(int k=0;k<2;++k)
	 		temp.m[i][j]=(temp.m[i][j]+x.m[i][k]*y.m[k][j])%mod;
	 }
	 return temp;
}

LL mul(LL n){
	for(int i=0;i<2;++i)
	 for(int j=0;j<2;++j)
	 	h.m[i][j]=(i==j);
	l.m[0][0]=1;l.m[0][1]=1;
	l.m[1][0]=1,l.m[1][1]=0;
	while(n){
		if(n%2) h=jz(h,l);
		l=jz(l,l);
		n>>=1;
	}
	return h.m[0][0]%mod;
}

int main(){
	LL n;scanf("%lld",&n);
	LL sum=mul(n-1);
	printf("%lld",sum);
	return 0;
}
