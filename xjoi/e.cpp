#include<iostream>
#include<cstdio>
using namespace std;
const int N=5010;
int f[N][N][2];
string ll,lx;

bool check(char x,char y){
	if(x==y) return 0;
	else return 1;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int lenx,lenl;
		scanf("%d%d",&lenx,&lenl);
		cin>>lx>>ll;
		lx='#'+lx;ll='#'+ll;
		for(int i=1;i<=lenx;++i)
			f[i][0][1]=f[i][0][0]=f[i-1][0][0]+check(lx[i],lx[i-1]);
		for(int i=1;i<=lenl;++i)
			f[0][i][0]=f[0][i][1]=f[0][i-1][1]+check(ll[i],ll[i-1]);
		/*for(int i=1;i<=lenx;++i)
			cout<<i<<" "<<f[i][0][0]<<endl;
		for(int i=1;i<=lenl;++i)
			cout<<i<<" "<<f[0][i][1]<<endl;*/
		for(int i=1;i<=lenx;++i)
		 for(int j=1;j<=lenl;++j){
			f[i][j][0]=min(f[i-1][j][0]+check(lx[i],lx[i-1]),f[i-1][j][1]+check(lx[i],ll[j]));
			f[i][j][1]=min(f[i][j-1][1]+check(ll[j-1],ll[j]),f[i][j-1][0]+check(lx[i],ll[j]));
			//printf("%d %d %d %d\n",i,j,f[i][j][1],f[i][j][0]);
		}
		int minn=min(f[lenx][lenl][1],f[lenx][lenl][0]);
		printf("%d\n",minn);
		for(int i=1;i<=lenx;++i)
		 for(int j=1;j<=lenl;++j)
		 	f[i][j][0]=f[i][j][1]=0;
	}
	return 0;
}
