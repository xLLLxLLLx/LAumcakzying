#include<bits/stdc++.h>
using namespace std;
int a[7]={0,1,10,100,1000,10000,100000};
string lx;
int len,q[7],p[7],w[7];
int x,y,z,kq=0,kp=0,kw=0;

void work(){
	for(int i=0;i<lx.size();++i){
		while(lx[i]=='0') i++;
		while(lx[i]!='*') q[++kq]=lx[i]-'0',x+=(lx[i]-'0')*a[6-i],i++;
		while(lx[i]=='0') i++;
		while(lx[i]!='=') p[++kp]=lx[i]-'0',y+=(lx[i]-'0')*a[13-i],i++;
		while(lx[i]=='0') i++;
		while(i<len) w[++kw]=lx[i]-'0',z+=(lx[i]-'0')*a[20-i],i++;
	}
}

void dfs(1){
	
}

int main(){
	cin>>lx;
	len=lx.size();
	work();
	printf("%d %d %d\n",x,y,z);
	//printf("%d",ans);
	return 0;
}
