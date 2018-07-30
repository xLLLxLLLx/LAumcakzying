#include<iostream>
#include<cstdio>
using namespace std;
const int N=50010;
struct data{
	int next,to;
}a[N<<1];
int cnt=0,head[N<<1];

void add(int x,int y){
	a[++cnt].to=y,a[cnt].next=head[x],head[x]=cnt;
	a[++cnt].to=x,a[cnt].next=head[y],head[y]=cnt;
}

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);
	}
	
	return 0;
}
