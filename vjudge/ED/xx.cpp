#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt,a,b;
int head[1001],d[1001],q[1001];
int dis[1001][1001],p[1001][1001];
double f[1001][1001];
struct data{int to,next;}e[1001];
void insert(int u,int v)
{
    cnt++;e[cnt].to=v;e[cnt].next=head[u];head[u]=cnt;d[u]++;
    cnt++;e[cnt].to=u;e[cnt].next=head[v];head[v]=cnt;d[v]++;
}
double dp(int x,int y)
{
    if(f[x][y])return f[x][y];
    if(x==y)return 0;
    if(p[x][y]==y||p[p[x][y]][y]==y)return f[x][y]=1;
    double tot=dp(p[p[x][y]][y],y);
    for(int i=head[y];i;i=e[i].next)
        tot+=dp(p[p[x][y]][y],e[i].to);
    return f[x][y]=tot/(d[y]+1)+1;
}
void bfs(int x)
{
    int t=0,w=1;
    q[0]=x;dis[x][x]=0;
    while(t!=w)
    {
        int now=q[t],tmp=p[x][now];t++;if(t==1001)t=0;
        for(int i=head[now];i;i=e[i].next)
            if(dis[x][e[i].to]==-1||(1+dis[x][now]==dis[x][e[i].to]&&tmp<p[x][e[i].to]))
            {
                dis[x][e[i].to]=dis[x][now]+1;
                p[x][e[i].to]=tmp;
                if(!tmp)p[x][e[i].to]=e[i].to;
                q[w]=e[i].to;
                w++;
                if(w==1001)w=0;
            }
    }
}
int main()
{
    memset(dis,-1,sizeof(dis));
    scanf("%d%d",&n,&m);
    scanf("%d%d",&a,&b);
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        insert(u,v);
    }
    for(int i=1;i<=n;i++)bfs(i);
    printf("%.3lf",dp(a,b));
    return 0;
}
