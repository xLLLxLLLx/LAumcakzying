#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int a[N],b[N];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(n<m){
		int ans=0;
		for(int i=1;i<=n;++i){
			if(a[i]!=a[i-1]){
				int p=lower_bound(b+1,b+1+m,a[i])-b;
				if(b[p]==a[i]) ans++;
			}
		}
		
		if(!ans) printf("A and B are disjoint\n");
		else if(ans==n) printf("A is a proper subset of B\n");
		else printf("I'm confused!\n");
	}
	else if(n>m){
		int ans=0;
		for(int i=1;i<=m;++i){
				int p=lower_bound(a+1,a+1+n,b[i])-a;
				if(a[p]==b[i]) ans++;
		}
			if(!ans) printf("A and B are disjoint\n");
			else if(ans==m) printf("B is a proper subset of A\n");
			else printf("I'm confused!\n");
	}
	else {
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i]){
				printf("I'm confused!\n");
				return 0;
			}
		}
		printf("A equals B\n");
	}
	return 0;
}
