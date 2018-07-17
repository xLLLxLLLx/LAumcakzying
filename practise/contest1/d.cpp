#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int N=1000010;
int a[N];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		LL n,k;scanf("%lld%lld",&k,&n);
		LL sum=n*(n+1)/2-k;
		LL ans=sum/2;
		if(sum&1||n==2){printf("impossible\n");}
		else {
			memset(a,0,sizeof(a));
			a[k]=2;
			for(LL i=n;i>=1;--i){
				if(ans>=i&&i!=k){
					ans-=i;
					a[i]=1;
					if(ans==k){
						ans+=i;
						a[i]=0;
					}
					if(!ans)break;
				}
			}
			if(!ans){
				for(LL i=1;i<=n;++i)
					printf("%d",a[i]);
				printf("\n");
			}
			else printf("impossible\n");
		}
	}
	return 0;
}

