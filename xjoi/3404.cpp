#include<iostream>
#include<cstdio>
#define LL unsigned long long
using namespace std;
  
LL read(){
    LL x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}
  
LL GCD(LL b,LL a){ return b? GCD(a%b,b):a;}  
  
int main(){
    LL n=read(),a=read(),b=read(),p=read(),q=read();
//  cout<<n<<a<<b<<p<<q<<endl;
    LL maxn=max(p,q);
    if(n==a&&n==b) printf("%lld",maxn);
    else if(a==b) printf("%lld",maxn*(n/a));
    else {
    	LL x=min(a,b),y=max(a,b);
    	LL ans=n/(x*y/GCD(x,y));
    	LL sum=(n/a-ans)*p+(n/b-ans)*q+(ans*maxn);
  //  	printf("%lld",sum);
    //	cout<<ans<<" ";
    	cout<<sum;
    }
    return 0;
}
