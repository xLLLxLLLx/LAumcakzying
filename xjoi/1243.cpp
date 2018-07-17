#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
char c[N];

int main(){
	int n,m;scanf("%d%d%s",&n,&m,c);
	int sum=0,sum2=0;
	if(m>2){
		for(int i=0;i<n;++i){
			int j;
			for(j=i+1;j<n;++j)
				if(c[j]!=c[i]) break;
			sum+=(j-i)>>1;
			i=j-1;
		}
		printf("%d",sum);
		return 0;
	}
	else {
		for(int i=0;i<n;++i)
			if(c[i]=='A'+i%2) sum++;
			else sum2++;
		printf("%d",min(sum,sum2));
		return 0;
	}
}
