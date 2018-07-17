#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n;scanf("%d",&n);
	int res=n,a=n;
	for(int i=2;i<=sqrt(n);++i){
		if(a%i==0){
			res=res/i*(i-1);
			while(a%i==0) a/=i;
		}
		if(a==1) break;
	}
	if(a>1) res=res/a*(a-1);
	printf("%d",res);
	return 0;
}
