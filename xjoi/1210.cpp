#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=35;
LL f[35][35];
int n;

void zuhe(){
	for(int i=1;i<=n;++i) f[1][i]=i,f[i][i]=1,f[0][i]=1;
	for(int i=1;i<=n;++i)
	 for(int j=2;j<i;++j)
	if(!f[j][i]) f[j][i]=f[j-1][i-1]+f[j][i-1];
	/*for(int i=1;i<=n;++i)
	 for(int j=1;j<=i;++j)
	 cout<<j<<" "<<i<<" "<<f[j][i]<<endl;*/
}

int main(){
	scanf("%d",&n);
	zuhe();
	printf("(a+b)^%d = ",n);
	if(n==0){cout<<"1";return 0;}
	for(int i=0;i<=n;++i){
		if(i) cout<<"+ ";
		if((n-i)){if(f[i][n]>1) cout<<f[i][n]<<"*";cout<<"a";if(n-i>1)cout<<"^"<<n-i; }
		if(i) {
			if(i!=n)cout<<"*";
			cout<<"b";
			if(i>1) cout<<"^"<<i;
		}
		cout<<" ";
	}
	return 0;
}
