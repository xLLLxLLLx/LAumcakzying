#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=70;
LL q,p,a[N];
int kq,kp;

int main(){
	a[0]=1;
	for(int i=1;i<=63;++i) a[i]=a[i-1]*2;
	scanf("%lld%lld",&q,&p);
	for(int i=1;i<=63;++i)
		if(q>=a[i]){kq=i;break;}
	for(int i=1;i<=63;++i)
		if(p>=a[i]){kp=i;break;}
	q-=(1<<kq);p-=(1<<kp);
	while(1){
		
	}
	return 0;
}
