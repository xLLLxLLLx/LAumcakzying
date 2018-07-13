#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int N = 10010;
struct data{
	char c[15];
	LL num,p;
	int m;
}a[N];
char ch[15];

int main(){
	LL n,k; scanf("%lld%lld",&n,&k);
	for(LL i=1;i<=n;++i){
		scanf("%s",(a[i].c+1));
		a[i].m=strlen(a[i].c+1);
		scanf("%lld",&a[i].num);
		a[i].p=-1000;
	}
	for(LL i=1;i<=k;++i){
		LL x;
		int flag=1;
		scanf("%s%lld",(ch+1),&x);
		int ans=strlen(ch+1);
		for(int i=1;i<=n;++i){
			flag=1;
			if(a[i].m!=ans) continue;
			else {
				for(int j=1;j<=ans;++j)
					if(ch[j]!=a[i].c[j]){
						flag=0;break;
					}
				if(flag) {a[i].p=x;break;}
			}
		}
	}
	LL sum=0;
	for(int i=1;i<=n;++i)
		if(a[i].p==-1000){
			printf("Unknow");
			return 0;
		}
		else sum+=a[i].p*a[i].num;
	printf("%lld",sum);
	return 0;
}
