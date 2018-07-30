#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string ll,lx;
int qxl[N],qnl[N],qxx[N],qnx[N];

bool check(char ch){
	if(ch=='a') return 1;
	else return 0;
}

int main(){
	cin>>ll>>lx;
	ll='@'+ll+'@';lx='@'+lx+'@';
	int lenl=ll.size(),lenx=lx.size();
	char ch='@';ch=ll[1];
	int ans=1,cntl=0,cntx=0,suml=0,sumx=0;
	for(int i=2;i<=lenl+1;++i){
		if(ll[i]==ch) ans++;
		else {
			qxl[++cntl]=ans;
			suml+=ans;
			qnl[cnt]=check(ch);
			ans=1;ch=ll[x];		
		}
	}
	ans=1,cnt=0;ch=lx[1];
	for(int i=2;i<=lenx+1;++i){
		if(lx[i]==ch) ans++;
		else {
			qxx[++cntx]=ans;
			sumx+=ans;
			qnx[cnt]=check(ch);
			ans=1;ch=lx[x];		
		}
	}
	printf("%d\n",);
	int x=suml,y=sumx;
	if(qnx[cntx]==1) x-=qxx[cntx],cntx--;
	if(qnl[cntl]==0) y-=qxl[cntl],cntl--;
	while(x||y){
		
	}
	return 0;
}
