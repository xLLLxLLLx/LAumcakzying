#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N],b[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int n=read(),sum=0;
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read(),b[i]=b[i]-a[i];
	for(int i=1;i<=n;++i) sum+=b[i];
	if(sum>0) printf("No\n");
	else printf("Yes\n");
	return 0;
}
