#include<bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int> a[N];
int f[N];

int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int search(int x){
	int k=0,flag=0;
	for(int i=0;i<a[x].size();++i){
		if(a[x][i]){
			flag=1;
			k++;
			if(!f[a[x][i]]) k+=search(a[x][i])-1;
			else k+=f[a[x][i]];
		}
	}
	k+=1;
	return f[x]=k;
}

int main(){
	int n=read();
	for(int i=2;i<=n;++i){
		int x=read();
		a[x].push_back(i);
	}
	/*for(int i=1;i<=n;++i)
		cout<<"case1:"<<i<<" "<<a[i].size()<<endl;*/
	for(int i=1;i<=n;++i){
		if(!f[i]) f[i]=search(i);
		printf("%d ",f[i]);
	}
	return 0;
}
