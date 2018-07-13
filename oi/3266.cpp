#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N = 50;
LL f[N]={0,0,0,2,2,6},c[N]={0,3,6,6};

int main(){
	int n;scanf("%d",&n);
	LL sum=1,res=2;
	for(int i=4;i<=n+1;++i){
		res<<=1;
		f[i]=res-f[i-1];
	}
	sum=3*(f[n-1]*2+(f[n]));
	if(n<4)cout<<c[n];
	else cout<<sum;
	return 0;
}
