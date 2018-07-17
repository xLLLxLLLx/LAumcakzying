#include<iostream>
#include<cstdio>
#include<cstring>
#define LL unsigned long long
using namespace std;
const int N=100010;
LL a[N]={0};
char c[N];

int main(){
	LL k;
	scanf("%lld",&k);
	LL x,sum=0,cnt=0;
	scanf("%s",c);
	LL len=strlen(c);
	for(LL i=0;i<len;++i)
		if(c[i]=='1') a[++cnt]=i+1;
	a[cnt+1]=len+1;
	LL ans=0;
	if(!k){
		for(LL i=1;i<=cnt+1;++i){
			LL res1=a[i]-a[i-1];
			if(res1>1){
				//res1--;
				ans+=res1*(res1-1)/2;
			}
		}
		//ans++;
	}
	else{
		for(LL i=1;i<=cnt-k+1;++i){
			LL res1=a[i]-a[i-1],res2=a[i+k]-a[i+k-1];
			ans+=res1*res2;
		}
	}
	printf("%lld",ans);
	return 0;
}
