#include<iostream>
#include<cstdio>
#define LL long long

int main(){
	LL n;scanf("%lld",&n);
	LL k=n+1,q;
	if((n+1)%2==0){
		if((n+1)%4==0) q=n+1;
		else q=2*n+1;
	}
	else q=4*n+1;
	printf("%lld",q);
	return 0;
}
