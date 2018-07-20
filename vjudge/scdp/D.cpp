#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=15,M=60000;
const int INF=0x3f3f3f3f;
int dp[M][N];
int a[N][N];
int bit[N],num[M][N];

void jac(){
    bit[0]=1;
    for(int i=1;i<=10;++i) bit[i]=(bit[i-1]<<1)+bit[i-1];
    for(int i=0;i<bit[10];++i){
        int k=i;
        for(int j=0;j<10;++j){
            num[i][j]=k%3;
            k/=3;
        }
    }
}

int main(){
    int n,m;
    jac();
    while(scanf("%d%d",&n,&m)==2){
        memset(a,-1,sizeof(a));
        for(int i=1;i<=m;++i){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            x--;y--;
            if(a[x][y]==-1||a[x][y]>z) a[x][y]=a[y][x]=z;
        }
        memset(dp,INF,sizeof(dp));
        int minn=INF;
        for(int i=0;i<n;++i)
            dp[bit[i]][i]=0;
        for(int i=0;i<bit[n];++i){
            int flag=1;
            for(int j=0;j<n;++j){
                if(num[i][j]==0) flag=0;
                //if(num[i][j]>=2) continue;
                if(dp[i][j]>=INF) continue;
                for(int k=0;k<n;++k){
                    if(j==k||num[i][k]>=2||a[j][k]==-1) continue;
                    else dp[i+bit[k]][k]=min(dp[i+bit[k]][k],dp[i][j]+a[j][k]);
                } 
            }
            if(flag){
                for(int k=0;k<n;++k)
                    minn=min(minn,dp[i][k]);
                //printf("css minn=%d\n",minn);
            }
        }
        if(minn>=INF) printf("-1\n");
        else printf("%d\n",minn);
    }
    return 0;
}
