#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N = 100010;
LL v[N],l[N],r[N];

int main(){
	int n;scanf("%d",&n);
	LL maxn=0;
	for(int i=1;i<=n;++i) scanf("%lld",&v[i]);
	for(int i=1;i<=n;++i){
		l[i]=i;
		while(l[i]-1>=1&&v[l[i]-1]>=v[i]) l[i]=l[l[i]-1];
	}
	for(int i=n;i>=1;--i){
		r[i]=i;
		while(r[i]+1<=n&&v[r[i]+1]>=v[i]) r[i]=r[r[i]+1];
		maxn=max(maxn,v[i]*(r[i]-l[i]+1));
	}
	printf("%lld",maxn);
	return 0;
}
