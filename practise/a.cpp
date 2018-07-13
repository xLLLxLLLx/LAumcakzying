#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10;
int a[N];

int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;++i){
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
		sort(a+1,a+5);
		if(a[1]==a[2]&&a[3]==a[4]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
