#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0,res=0;
int c[15];

int main(){
	char ch;
	int j=1,flag=0;
	while((ch=getchar())!='\n'&&ch>0){
		int x;
		if(flag) x=1;
		else {
			x=ch-48;
			if(x>1) x=1,flag=1;
			else x=min(1,x);
		}
		c[++res]=x;
	}
	for(int i=res;i>=1;--i) {
		cnt+=c[i]*j;
		j*=2;
	}
	printf("%d",cnt);
	return 0;
}
