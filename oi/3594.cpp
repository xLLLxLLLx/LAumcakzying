#include<iostream>
#include<cstdio>
using namespace std;
const int N=10000010;
int flag[N],p[N];
int tot=0;

int main(){
	int n;scanf("%d",&n);
	for(int i=2;i<=n;++i){
		if(!flag[i])
			p[++tot]=i;
		for(int j=1;j<=tot;++j){
			if(i*p[j]>n) break;
			flag[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	printf("%d",tot);
	return 0;
}
