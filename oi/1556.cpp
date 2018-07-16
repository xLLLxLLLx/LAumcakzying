#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[10010];
 
int read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}
 
int main(){
    n=read();
    int maxn=0;
    for(int i=1;i<=n;++i){
        int num=read(),t=read();
        int c,temp=0;
        while(scanf("%d",&c)&&c)
            temp=max(temp,a[c]);
        a[num]=temp+t;
        maxn=max(maxn,a[num]);
    }
    printf("%d",maxn);
    return 0;
}
