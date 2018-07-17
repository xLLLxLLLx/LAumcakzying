#include<iostream>
#include<cstdio>
#include<map>
#define LL long long
using namespace std;
const int N=10010;
map<string,long long> qx;
string name[N];
LL a[N];

int main(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		cin>>name[i]>>a[i];
	for(int i=1;i<=k;++i){
		string lx;cin>>lx;
		LL v;scanf("%lld",&v);
		qx[lx]=v;
	}
	LL sum=0;
	for(int i=1;i<=n;++i){	
		if(!qx.count(name[i])) {printf("Unknow");return 0;}
		else sum+=a[i]*qx[name[i]];
	}
	printf("%lld",sum);
	return 0;
}
