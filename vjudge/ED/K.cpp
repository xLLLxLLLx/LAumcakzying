#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
const int N=1000;
struct edge{
    int to,next;
}a[N<<1];
int p[N+10][N+10],head[N+10],dis[N],f[N+10],t[N+10];
double dp[N+10][N+10];
int n,m,b,e,cnt=0;

void add(int x,int y){
    a[++cnt].to=y,a[cnt].next=head[x],head[x]=cnt,t[x]++;
    a[++cnt].to=x,a[cnt].next=head[y],head[y]=cnt,t[y]++;
}

void bfs(int x){
    //printf("cscs %d\n",x);
    memset(dis,-1,sizeof(dis));
    int l=0,r=1;
    f[0]=x;
    dis[x]=0;
    while(l!=r){
        int h=f[l],temp=p[x][h];
        l=(l+1)%N;
        for(int i=head[h];i;i=a[i].next){
            if(dis[a[i].to]==-1||(dis[a[i].to]==1+dis[h]&&temp<p[x][a[i].to])){
                if(!temp) p[x][a[i].to]=a[i].to;
                else p[x][a[i].to]=temp;
                dis[a[i].to]=dis[h]+1;
                f[r]=a[i].to;
                r=(r+1)%N;
            }
        }
    }
}

double yyqx(int x,int y){
    //printf("xxx %d %d\n",x,y);
    if(dp[x][y]) return dp[x][y];
    if(x==y) return 0;
    if(p[x][y]==y||p[p[x][y]][y]==y) return dp[x][y]=1;
    double tot=yyqx(p[p[x][y]][y],y);
    for(int i=head[y];i;i=a[i].next)
        tot+=yyqx(p[p[x][y]][y],a[i].to);
    return dp[x][y]=tot/(t[y]+1)+1;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&b,&e);
    for(int i=1;i<=m;++i){
        int x,y;scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;++i) bfs(i);
    yyqx(b,e);
    cout<<fixed<<setprecision(3)<<yyqx(b,e)<<endl;
}
