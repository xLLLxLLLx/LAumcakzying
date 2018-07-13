#include<iostream>
#include<cstdio>
using namespace std;
const int N=30010;
const int M=20010;
int a[N],b[N];

int main(){
	char ch;
	int maxn=0,x=0;
	while((ch=getchar())!='\n'){
		if(ch==' ') a[x]++,maxn=max(maxn,x),x=0;
		else if(ch>='0'&&ch<='9') x=x*10+(ch-48);
	}
	a[x]++;
	x=0;
	while((ch=getchar())!='\n'&&ch!=EOF){
		if(ch==' ') b[x]++,maxn=max(maxn,x),x=0;
		else if(ch>='0'&&ch<='9') x=x*10+(ch-48);
	}
	b[x]++;
	for(int i=1;i<=maxn;++i)
		if(a[i]||b[i]) printf("%d ",i);
	printf("\n");
	for(int i=1;i<=maxn;++i)
		if(a[i]&&!b[i]) printf("%d ",i);
	printf("\n");
	for(int i=1;i<=maxn;++i)
		if(a[i]&&b[i]) printf("%d ",i);
	printf("\n");
	for(int i=1;i<=maxn;++i)
		if(!a[i]&&b[i]) printf("%d ",i);
		else if(a[i]&&!b[i]) printf("%d ",i);
	printf("\n");
	return 0;
}
