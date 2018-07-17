#include<iostream>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
const LL M=21788233;
const LL N=1226959;
const LL K=1635947;
const LL Q=218357;
LL a1[M],b1[N],c1[K],d1[Q];
LL a2[M],b2[N],c2[K],d2[Q];
LL f[6][301];
   
LL read(){
    LL x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}
   
int main(){
    int n=read();
    for(int i=1;i<=5;++i)
     for(int j=1;j<=n;++j){
        f[i][j]=read();
    }
    for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j){
        LL sum=f[1][i]+f[2][j];
        LL x=abs(sum%M),y=abs(sum%N),z=abs(sum%K),q=abs(sum%Q);
        if(sum>0) a1[x]++,b1[y]++,c1[z]++,d1[q]++;
        else a2[x]++,b2[y]++,c2[z]++,d2[q]++;
    }
    for(int i=1;i<=n;++i)
     for(int j=1;j<=n;++j)
      for(int k=1;k<=n;++k){
        LL sum=f[3][i]+f[4][j]+f[5][k];
        LL x=abs(sum%M),y=abs(sum%N),z=abs(sum%K),q=abs(sum%Q);
        if(sum>0){
            if(a2[x]&&b2[y]&&c2[z]&&d2[q]){
                printf("Yes");
                return 0;
            }
        }
        else {
            if(a1[x]&&b1[y]&&c1[z]&&d1[q]){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;
}
