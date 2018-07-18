#include<bits/stdc++.h>
using namespace std;
const int M=1010;
vector<int> a[M];
int f[M],vis[M];

void add(int x,int y){
	if(x==y) return ;
	a[x].push_back(y);
}

void check(int x){
	int b=0,e=1;
	f[1]=x;
	while(b<=e){
		b=(b+1)%M;
		int h=f[b];
		for(int i=0;i<a[h].size();++i){
			e=(e+1)%M;
			f[e]=a[h][i];
			if(a[h][i]==x){
				printf("Impossible\n");
				exit(0);
			}
		}
	}
}

int main(){
	string lx;
	while(cin>>lx){
		int len=lx.size();
		for(int i=0;i<len-1;++i){
			vis[lx[i]-'a'+1]=1;
			add(lx[i]-'a'+1,lx[i+1]-'a'+1);
		}
	}
	for(int i=1;i<=26;++i){
		if(vis[i]){
			memset(f,0,sizeof(f));
			check(i);
		}
	}
	printf("Possible\n");
	return 0;
}
