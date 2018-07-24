#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000010;
struct data{
	int next,to;
}a[N<<1];
int n,k,cnt=0;

void add(int x,int y){
	a[++cnt].to=y,a[cnt].next=head[x],head[x]=cnt;
	a[++cnt].to=x,a[cnt].next=head[y],head[y]=cnt;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	
	
	return 0;
}
