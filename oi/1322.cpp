#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=55;
char qx[N],zx[N];
int len,num;

int find(char x){
	for(int i=1;i<=len;++i)
		if(zx[i]==x) return i;
	return -1;
}

void search(int l1,int r1,int l2,int r2){
	int m=find(qx[l1]);
	/*if(m>l2) search(l1+1,l1+m-l2,l2,m-1);
	if(m<r2) search(m+1+r1-r2,r1,m+1,r2);*/
	 if(m>l2) search(l1+1,m-l2+1,l2,m-1);
	 if(m<r2) search(m-l2+l1+1,r1,m+1,r2);
	printf("%c",qx[l1]);
}

int main(){
	scanf("%s%s",(qx+1),(zx+1));
	len=strlen(qx+1);
	num=len;
	search(1,len,1,len);
	return 0;
}
