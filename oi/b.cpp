#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=710;
LL a[N][N];

LL read(){
	LL x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	x=f?-x:x;
	return x;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;++i){
		 for(int j=1;j<=n;++j){
		 	a[i][j]=read();
		 }
		 for(int k=1;k<=n-1;++k)
      		for(int m=1;m<=n-k;++m)
       			if(a[i][m]>a[i][m+1]){
       				LL t=a[i][m];
       				a[i][m]=a[i][m+1];
       				a[i][m+1]=t;
       			}
       //	for(int l=1;l<=n;++l) cout<<a[i][l]<<" ";
       //	cout<<endl;
		}
		LL last=a[n][n],sum=a[n][n];
		int flag=1;
		for(int i=n-1;i>=1;--i){
			flag=0;
			for(int j=n;j>=1;--j){
				if(a[i][j]<last) {
					last=a[i][j],sum+=a[i][j],flag=1;
					break;
				}
			}
			if(!flag) {printf("-1\n");break;}
		}
		if(!flag) continue;
		else printf("%lld\n",sum);
	}
	return 0;
}
