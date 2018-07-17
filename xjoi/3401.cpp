#include<iostream>
#include<cstdio>
using namespace std;
const int N = 110;
int cnt=0,a[N];

int work(){
	int ans=0;
	char ch;
	while((ch=getchar())!='\n'&&ch>0){
		int x;
		if(ch=='(') x=0; else if(ch==')') x=1;
		else if(ch=='{') x=2; else if(ch=='}') x=3;
		else if(ch=='[') x=4; else if(ch==']') x=5;
		else if(ch=='<') x=6; else if(ch=='>') x=7;
		if(x&1){
			if(!cnt) return -1;
			else if((x-1)!=a[cnt]) ans++;
			cnt--;
		} else a[++cnt]=x;
	}
	if(cnt) return -1;
	else return ans;
}

int main(){
	int ans=work();
	if(ans==-1) printf("Impossible");
	else printf("%d",ans);
	return 0;
}
