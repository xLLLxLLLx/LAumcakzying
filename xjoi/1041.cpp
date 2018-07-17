#include<iostream>
#include<cstdio>
using namespace std;
int l[110],r[110];

void qx(int x){
	printf("%d ",x);
	if(l[x])qx(l[x]);
	if(r[x])qx(r[x]);
}

void zx(int x){
	if(l[x])zx(l[x]);
	printf("%d ",x);
	if(r[x])zx(r[x]);
}

void hx(int x){
	if(l[x])hx(l[x]);
	if(r[x])hx(r[x]);
	printf("%d ",x);
}

int main(){
	int n,cnt=1;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x; 
		scanf("%d",&x);
		scanf("%d%d",&l[x],&r[x]);
	}
	qx(1);cout<<endl;
	zx(1);cout<<endl;
	hx(1);
	return 0;
}
