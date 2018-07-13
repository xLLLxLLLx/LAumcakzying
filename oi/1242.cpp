#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long 
using namespace std;
const int N=3010;
LL a[N],b[N];
char c[N];

int main(){
	scanf("%s",(c+1));
	int len=strlen(c+1);
	for(int i=1;i<=len;++i){	
		int l=i-1,r=i+1;
		while(l>=1&&r<=len){
			if(c[l]!=c[r]) break;
			b[l]++,a[r]++,l--,r++;
		}
		int l1=i,r1=i+1;
		while(l1>=1&&r1<=len){
			if(c[l1]!=c[r1]) break;
			else b[l1]++,a[r1]++,l1--,r1++;	
		}
		b[i]++,a[i]++;
	}
	LL sum=0;
	//for(int i=1;i<=len;++i) cout<<a[i]<<" "<<b[i]<<endl;
	for(int i=2;i<len;++i) a[i]+=a[i-1];
	for(int i=1;i<len;++i) sum+=a[i]*b[i+1];
	printf("%lld",sum);
	return 0;
}
