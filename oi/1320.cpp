#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010;

struct data{
	int x,y;
}a[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

bool comp(data xx,data yy){
	if(xx.x==yy.x) return xx.y<yy.y;
	else return xx.x<yy.x;
}

int main(){
	int n=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	sort(a+1,a+1+n,comp);
	for(int i=1;i<=n;++i) printf("%d %d\n",a[i].x,a[i].y);
	return 0;
}
