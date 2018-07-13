#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
int n,m,num=0,inf,qx[50],que[200],pa[50],fx[50][50],ans[50][50][50];
bool vis[50];
 
void bfs(int s,int t){
    int head=0,tail=1;
    memset(vis,0,sizeof(vis));
    memset(pa,0,sizeof(pa));
    que[tail]=s; vis[s]=1;
    while(head!=tail){
        head=(head+1)%50;
        if(que[head]==t) break;
        for(int i=1;i<=26;++i){
            if(!vis[i]&&fx[que[head]][i]!=inf){
                pa[i]=que[head];
                vis[i]=1;tail=(tail+1)%50;que[tail]=i;
            }
        }
    }
    for(int i=t;i!=s;i=pa[i]) ans[s][t][++ans[s][t][0]]=i;
    ans[s][t][++ans[s][t][0]]=s;
}
 
int main(){
    scanf("%d%d",&m,&n);
    memset(fx,63,sizeof(fx)); inf=fx[0][0];
    for(int i=1;i<=m;++i){
        char ch=getchar(),_ch;
        while(ch<'A'||ch>'Z') ch=getchar();
        qx[ch-'A'+1]++; if(qx[ch-'A'+1]==1) num++;
        _ch=getchar();
        while(_ch<'A'||_ch>'Z') _ch=getchar();
        qx[_ch-'A'+1]++; if(qx[ch-'A'+1]==1) num++;
        fx[_ch-'A'+1][ch-'A'+1]=1;fx[ch-'A'+1][_ch-'A'+1]=1;
    }
     
    for(int i=1;i<=26;++i)
     for(int j=1;j<=26;++j)
        if(i!=j&&qx[i]&&qx[j]) bfs(i,j);
      
    for(int i=1;i<=n;++i){
        char ch=getchar(),_ch;
        while(ch<'A'||ch>'Z') ch=getchar();
        _ch=getchar();
        while(_ch<'A'||_ch>'Z') _ch=getchar();
        int x=ch-'A'+1,y=_ch-'A'+1;
        for(int i=ans[x][y][0];i>=1;--i) printf("%c",ans[x][y][i]+'A'-1);
        printf(" ");
    }
    return 0;
}
