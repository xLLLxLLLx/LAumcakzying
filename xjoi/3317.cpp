#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
string sum[N],ch[N],lx,ll;

int main(){
	sum[0]="http://www.hzxjhs.com/";
	int num=0,res=0,top;
	while(1){
		cin>>lx;
		num++;
		if(lx[0]=='B'){
			if(res==0){
				ch[num]="Ignored";
			}
			else {
				ch[num]=sum[--res];	
			}
		}
		if(lx[0]=='F'){
			if(res>=top){
				ch[num]="Ignored";
			}
			else {
				res++;
				ch[num]=sum[res];
			}
		}
		if(lx[0]=='V'){
			cin>>sum[++res];
			ch[num]=sum[res];
			top=res;
		}
		if(lx[0]=='Q') break;
	}
	for(int i=1;i<=num;++i) cout<<ch[i]<<endl;
	return 0;
}
