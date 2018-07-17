#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
const int N=1000010;
int f[6]={0,0,1,3,5,9};
LL a[N];

void work(LL n){
	for(LL i=1;i<=n;++i)
		a[i]=i;
	for(LL i=2;i<=n;++i)
		if(a[i]==i){
			//printf("%lld\n",i);
			for(LL j=i;j<=n;j+=i)
				a[j]=a[j]/i*(i-1);
		}
}

int main(){
	LL n;scanf("%lld",&n);
	if(n<=5) printf("%d",f[n]);
	else {
		work(n);
		LL sum=f[5];
		for(int i=6;i<=n;++i)
			sum+=a[i];
		printf("%lld",sum);
	}
	//for(int i=1;i<=n;++i) printf("%lld ",a[i]);
	return 0;
}
