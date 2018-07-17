#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL ans,x1,y1;

LL exgcd(LL a,LL b,LL &x1,LL &y1){
	if(!b){
		x1=1,y1=0;
		return a;
	}
	else {
		ans=exgcd(b,a%b,x1,y1);
		x1-=y1*(a/b);
		swap(x1,y1);
		return ans;
	}
}

int main(){
	LL x,y,m,n,l;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	LL a=x-y,b=n-m;
	if(b<0){
		b=-b;
		a=-a;
	}
	exgcd(b,l,x1,y1);
	//printf("%lld %lld\n",ans,x1);
	if(a%ans) printf("Impossible\n");
	else {
		LL sum=((x1*(a/ans))%(l/ans)+(l/ans))%(l/ans);
		printf("%lld\n",sum);
	}
	return 0;
}
