#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=55;
int a[N];

int main(){//太玄学了！！
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int maxn=0;
	maxn=max(maxn,a[n]-a[n-1]);maxn=max(maxn,a[2]-a[1]);
	for(int i=3;i<=n;i+=2) maxn=max(maxn,a[i]-a[i-2]);
	for(int i=4;i<=n;i+=2) maxn=max(maxn,a[i]-a[i-2]);
	printf("%d\n",maxn);
	return 0;
}
