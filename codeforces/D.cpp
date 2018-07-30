#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200010;
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

int main(){
	int n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i){
		a[i].x=read(),a[i].y=read();
	}
	
}
