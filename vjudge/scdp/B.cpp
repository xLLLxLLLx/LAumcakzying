#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=16;
struct qx{
	string lx;
	int ad,dd;
}a[N];
int tim[1<<N],dp[1<<N];
int print[1<<N];

void yyqx(int x){
	if(!x) return ;
	yyqx(x^(1<<print[x]));
	cout<<a[print[x]].lx<<endl;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=0;i<n;++i){
			cin>>a[i].lx;
			scanf("%d%d",&a[i].dd,&a[i].ad);
		}
		int tot=(1<<n);
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<tot;++i){
			for(int j=n-1;j>=0;--j){
				int temp=(1<<j);
				if(!(i&temp)) continue;
				//printf("cs: %d %d\n",i,temp);
				int le=tim[i^temp]+a[j].ad-a[j].dd;
				if(le<0) le=0;
				if(dp[i]>dp[i^temp]+le){
					dp[i]=dp[i^temp]+le;
					tim[i]=tim[i^temp]+a[j].ad;
					print[i]=j;
				}
			}
			//printf(" bb %d\n",dp[i]);
		}
		printf("%d\n",dp[tot-1]);
		yyqx(tot-1);
	}
	return 0;
}
/*
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3
*/
