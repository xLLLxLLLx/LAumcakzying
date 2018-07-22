#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n,m;scanf("%d%d",&n,&m);
	double sum=0;
	for(int i=1;i<=n;++i)
		sum+=(pow(i/double(n),m)-pow((i-1)/double(n),m))*i;
	printf("%.5lf",sum);
	return 0;
}
