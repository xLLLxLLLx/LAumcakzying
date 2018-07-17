#include<iostream>
#include<cstdio>
using namespace std;
const int N=45;
int a[N][N],b[N];

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=n;++j){
	 	scanf("%1d",&a[i][j]);
	 }
	for(int i=1;i<=n;++i){
	 for(int j=n;j>=1;--j){
		if(a[i][j]){
			b[i]=j;
			break;
		}
	 }
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		int k=-1;
		for(int j=i;j<=n;++j){
			if(b[j]<=i){
				k=j;break;
			}
		}
		for(int j=k;j>i;--j){
			swap(b[j],b[j-1]);
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
