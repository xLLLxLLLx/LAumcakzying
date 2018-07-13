#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 210
using namespace std;
int a[maxn]={0,1},b[maxn]={0,1},c[maxn];

void add(){
	for(int i=b[0];i>=0;--i) c[i]=b[i];
	b[0]=max(a[0],b[0])+1;
	for(int i=1;i<=b[0];++i){
		b[i]+=a[i];
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}
	while(b[0]&&!b[b[0]]) b[0]--;
	for(int i=c[0];i>=0;--i) a[i]=c[i]; 
}

int main(){
	int n;scanf("%d",&n);
	for(int i=2;i<=n;++i) add();
	if(n==1||n==2) printf("1");
	else for(int i=a[0];i>=1;--i)printf("%d",a[i]);
	return 0;
}
