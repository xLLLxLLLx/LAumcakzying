#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s,t,n,m;
int xt[1001],dis[1001],a[1001][1001];
int b[1001]={0};

int read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}

int main(){
    s=read();t=read();n=read();m=read();
    memset(a,0x3f,sizeof a);//
    memset(dis,0x3f,sizeof dis);//初始化
    dis[t]=0;//
    for(int i=1;i<=n;++i) xt[i]=n+1;
    for(int i=1;i<=m;++i){
        int x=read(),y=read(),z=read();
        if(a[x][y]>z) a[x][y]=z,a[y][x]=z;//记录边权
    }
    for(int i=1;i<=n;++i){//直到把所有点放入 每次一个点
        int k=0;
        for(int j=1;j<=n;++j)
            if(b[j]==0&&dis[j]<=dis[k]) k=j;
        b[k]=1;//放入集合
        for(int j=1;j<=n;++j){
            if(b[j]==0&&dis[k]+a[j][k]<dis[j]){//如果j没有被访问到
                dis[j]=dis[k]+a[j][k];
                xt[j]=k;
            } else if(dis[k]+a[j][k]==dis[j]&&j<=k) xt[j]=k;
        }
    }
    printf("%d\n",dis[s]);
    for(int i=s;i<=n;i=xt[i]) printf("%d ",i);
    return 0;
}
