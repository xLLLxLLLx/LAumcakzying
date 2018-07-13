#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1010;
char lx[N];
int b[N],a[N];
int len,n;

bool fu(char ch){
	return ch=='*'||ch=='-'||ch=='+'||ch=='^'||ch=='/';
}

int work(char ch){
	if(ch=='-'||ch=='+') return 1;
	if(ch=='*'||ch=='/') return 2;
	if(ch=='^') return 3;
	return 4;
}

int js(int x,int y,char ch){
	if(ch=='+') return x+y;
	if(ch=='-') return x-y;
	if(ch=='*') return x*y;
	if(ch=='/') return x/y;
	if(ch=='^') return pow(x,y);
}

void cul(int l,int r){
	int flag=0,cnt=0,mid=l;
	if(lx[l]=='('){
		int i;
		cnt++;
		for(i=l+1;i<=r;++i){
			if(!cnt) break;
			if(lx[i]=='(') cnt++;
			if(lx[i]==')') cnt--;
		}
		if(i>r) {cul(l+1,r-1);return ;}
	}
	cnt=0;
	for(int i=l;i<=r;++i){
		if(lx[i]=='(') cnt++;
		if(lx[i]==')') cnt--;
		if(fu(lx[i])){
			flag=1;
			if(!cnt&&work(lx[i])<=work(lx[mid])) mid=i;
		}
	}
	if(!flag){
		a[++len]=lx[l]-'0';
		return ;
	}
	cul(l,mid-1);cul(mid+1,r);
	a[++len]=lx[mid],b[len]=1;
}

void print(){
	while(len>0){
		int mid=1;
		for(int i=1;i<=len;++i)
			if(b[i]) printf("%c ",a[i]);
			else printf("%d ",a[i]);
		printf("\n");
		for(mid=1;mid<=len;++mid)
			if(b[mid]) break;
		a[mid-2]=js(a[mid-2],a[mid-1],a[mid]);
		for(int i=mid-1;i<len;++i)
			a[i]=a[i+2],b[i]=b[i+2];
		len-=2;
	}
}

int main(){
	scanf("%s",lx);
	n=strlen(lx);
	cul(0,n-1);
	print();
	return 0;
}
