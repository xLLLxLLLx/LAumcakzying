#include<iostream>
#include<cstdio>
using namespace std;
const int N = 155;
const int M = 100001;
int a[3],b[3],c[3],ha[M],hb[M],f[N][N];
int w=1,t=1;

void put(int i,int j){
	int v=min(c[i],a[j]-c[j]);
	c[i]-=v;c[j]+=v;
	if(!f[c[0]][c[1]]){
		f[c[0]][c[1]]=f[b[0]][b[1]]+1;
		w=(w+1)%M;
		ha[w]=c[0],hb[w]=c[1];
	}
}

int bfs(){
	f[a[0]][0]=1;sum=a[0];ha[1]=a[0];
    if (sum&1) return -1;
    while(t!=(w+1)%M){
        b[0]=ha[t];b[1]=hb[t];b[2]=sum-b[0]-b[1];
        for(int i=0;i<=2;i++)
         for(int j=0;j<=2;j++)
          if (i!=j&&b[i]==b[j]&&b[3-i-j]==0) return f[b[0]][b[1]];
        for(int i=0;i<=2;i++)
         for(int j=0;j<=2;j++)
          if (i!=j){
            c[0]=ha[t];c[1]=hb[t];c[2]=sum-c[0]-c[1];
            put(i,j);
          }
        t=(t+1)%M;
    }
    return -1;
}

int main(){
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	int ans=bfs()-1;
	if(ans==-2) printf("NO");
	else printf("%d",ans);
	return 0; 
}
