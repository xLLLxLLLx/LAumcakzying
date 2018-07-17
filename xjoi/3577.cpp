#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2010;
char c[N],ch[N];

bool comp(int x,int y){
	if(x==y) return 1;
	for(int i=x;i<=y;++i){
		if(c[i]>c[x+y-i]) return 1;
		else if(c[i]<c[x+y-i]) return 0;
	}
	return 1;
}

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i) cin>>c[i];
	int num=0,l=1,r=n;
	while(l<=r){
		if(c[l]>c[r]) ch[++num]=c[r--];
		else if(c[l]<c[r]) ch[++num]=c[l++];
		else{
			if(comp(l,r)) ch[++num]=c[r--];
			else ch[++num]=c[l++];
		}
	}
	for(int i=1;i<=num;++i)printf("%c",ch[i]);
	return 0;
}
