#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
int f[N];

int find(int k){
	return f[k]==k?k:f[k]=find(f[k]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) f[i]=i;
	int sum=n;
	for(int i=1;i<=m;++i){
		int x,y;scanf("%d%d",&x,&y);
		if(find(x)!=find(y)){
			sum--;
			f[find(x)]=find(y);
		}
	}
	printf("%d",sum);
	return 0;
}
