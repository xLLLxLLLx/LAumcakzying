#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int N=1000010;
LL b[N],a[N];
 
LL read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}
 
int main(){
    LL n=read();
    LL sum=0,ans=0;
    for(LL i=1;i<=n;++i){
        a[i]=read();
        sum+=a[i];
        b[a[i]]++;
        ans+=a[i]*(i-b[a[i]]-b[a[i]+1]-b[a[i]-1]);
        //printf("case1: %d %d\n",i,ans);
        ans-=sum-a[i]*b[a[i]]-(a[i]+1)*b[a[i]+1]-(a[i]-1)*b[a[i]-1];
        //printf("case2: %d %d\n",i,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
