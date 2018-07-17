#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N = 35;
LL f1[N]={0,1,3,12,45};
LL f2[N]={0,3,12,45};
LL c[N]={0,4,15,57,216};

int main(){
	int n;scanf("%d",&n);
	LL sum=0;
	for(int i=4;i<=n;++i){
		f1[i]=f2[i-1];
		f2[i]=f1[i-1]*3+f2[i-1]*4-f1[i];
		//cout<<i<<" "<<f1[i]<<" "<<f2[i]<<endl;
	}
	sum=f1[n]+f2[n];
	if(n<5) printf("%lld",c[n]);
	else printf("%lld",sum);
	return 0;
}
