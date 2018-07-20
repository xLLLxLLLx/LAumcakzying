#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N],b[N];
int f[N][N],vis[N];
string ll,lx;

int main(){
	while(cin>>ll>>lx){
		memset(vis,0,sizeof(vis));
		int lenl=ll.size(),lenx=lx.size();
		for(int i=0;i<lenl;++i) a[i]=ll[i]-'0',b[i]=lx[i]-'0',a[i]-=b[i];
		for(int i
	}
	return 0;
}

//DP is too dificult!!!!!!rt
