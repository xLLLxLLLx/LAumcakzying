#include<bits/stdc++.h>
using namespace std;
string lx;
int t=1,cnt=1;
int m[50];
int a[50],ans[50];
int b[50][4];
bool p[50][4];

int main(){
    getline(cin, lx);
    memset(b,0,sizeof(b));
    memset(ans,0,sizeof(ans));
    memset(m,0,sizeof(m));
    memset(a,0,sizeof(a));
    int len=lx.length();
    for(int i=0;i<len;i++){
        if(lx[i]==' '){t=1;continue;}
        if(lx[i]=='/'){
            a[cnt]=10;
            if(t==2)
            b[cnt][t]=10-b[cnt][1];
            else b[cnt][t]=10;
            p[cnt][t]=true;
            if(t==1){
                m[cnt]=1;
            }else if(t==2){
                m[cnt]=2;
            }
            t=1;
            cnt++;
            continue;
        }
        if(lx[i]>='0'&&lx[i]<='9'){
        	b[cnt][t]=lx[i]-'0';
       		p[cnt][t]=true;
        }
        t++;
        if(t==3){
            t=1;
            int e=lx[i]-'0';
            int f=lx[i-1]-'0';
            a[cnt]=e+f;
            cnt++;
        }
    }
    cnt--;
    for(int i=1;i<=min(cnt,10);i++){
        if(m[i]==2)a[i]+=b[i+1][1];
        if(m[i]==1){
            a[i]+=b[i+1][1];
            if(p[i+1][2])a[i]+=b[i+1][2];
            else if(p[i+2][1])a[i]+=b[i+2][1];
        }
    }
    int y=0;
    for(int i=1;i<=min(cnt,10);i++){
       ans[i]=ans[i-1]+a[i];
       if(m[i]==2&&!p[i+1][1])continue;
       if(m[i]==1&&(!p[i+1][1]||(!p[i+1][2]&&!p[i+2][1])))continue;
       cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=min(cnt,10);i++){
       if(m[i]==2&&!p[i+1][1])continue;
       if(m[i]==1&&(!p[i+1][1]||(!p[i+1][2]&&!p[i+2][1])))continue;
       cout<<ans[i]<<" ";
    }
    return 0;
}
