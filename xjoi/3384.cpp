#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=100010;
int ha[N];
int yz[N];

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&ha[i]);
	for(int i=1;i<=sqrt(n);++i){
		if(n%i==0) {
			yz[++yz[0]]=i;
			if(n/i!=i) yz[++yz[0]]=n/i;
		}
	}
	for(int i=1;i<=yz[0];++i){
		for(int j=0;j<yz[i];++j){
			int flag=1,res=0;
			for(int k=1;k<=n;k+=yz[i]){
				if(!ha[(k+j-1)%n+1]){flag=0;break;}
				else res++;
			}
			if(flag&&res>=3){printf("YES\n");return 0;}
		}
	}
	printf("NO\n");
	return 0;
}
