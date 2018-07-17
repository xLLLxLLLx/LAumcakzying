#include<iostream>
#include<cstdio>
#define LL long long 
using namespace std;
struct qx{
	LL m[121][121];
}h,l;
int n,k;
LL mod;

void work(){
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=n;++j)
		scanf("%lld",&l.m[i][j]);
	for(int i=1;i<=n;++i)
	// for(int j=n+1;j<=2*n;++j)
		l.m[i][i+n]=1;
	/*for(int i=n+1;i<=2*n;++i)
	 for(int j=1;j<=n;++j)
	 	l.m[i][j]=0;*/
	for(int i=n+1;i<=2*n;++i)
	// for(int j=n+1;j<=2*n;++j)
	 	l.m[i][i]=1;
}

qx jz(qx q,qx p){
	qx temp;
	for(int i=1;i<=2*n;++i)
	 for(int j=1;j<=2*n;++j){
	 	temp.m[i][j]=0;
	 	for(int k=1;k<=2*n;++k)
	 		temp.m[i][j]=(temp.m[i][j]+q.m[i][k]*p.m[k][j])%mod;
	 }
	return temp;
}

void js(int x){
	for(int i=1;i<=2*n;++i)
	 for(int j=1;j<=2*n;++j)
	 	h.m[i][j]=(i==j);
	while(x){
		if(x%2) h=jz(h,l);
		l=jz(l,l);
		x>>=1;
	}
}

int main(){
	scanf("%d%d%lld",&n,&k,&mod);
	work();
	js(k+1);
	for(int i=1;i<=n;++i){
		h.m[i][i+n]--;
		if(h.m[i][i+n]<0) h.m[i][i+n]+=mod; 	
	}
	for(int i=1;i<=n;++i)
	 for(int j=n+1;j<=2*n;++j){
	 	printf("%lld ",h.m[i][j]);
	 	if(j==2*n) printf("\n");
	 }
	return 0;
}
