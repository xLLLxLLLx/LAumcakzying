#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=200010;
LL a[N],f[N];

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,k;scanf("%d%d",&n,&k);
		LL sum=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
			a[i+n]=a[i];
			sum+=a[i];
		}
		LL maxn=-1e6,maxn1=-1e6;
		for(int i=1;i<=2*n;++i){
			f[i]=max(f[i-1]+a[i],a[i]);
			if(i<=n) maxn=max(maxn,f[i]);
			else maxn1=max(maxn1,f[i]);
		}
 		if(k==1) printf("%lld\n",maxn);
		else{
			LL su=sum*(k-2)+maxn1;
			LL maxx=max(maxn1,su);
			printf("%lld\n",maxx);
		}
	}
	return 0;
}
