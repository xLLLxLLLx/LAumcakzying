#include<iostream>
#include<cstdio>
using namespace std;
const int N=100010;
int a[N];
 
int read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) f|=(ch=='-');
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
    x=f?-x:x;
    return x;
}
 
int main(){
    int mn=1000000,n=read(),s=0,sum=read();
    for(int i=1;i<=n;++i) a[i]=read();
    int cnt=0,be=0;
    for(;;){
        while(s<sum&&cnt<n) s+=a[++cnt];
        if(s<sum){
        	if(mn<1000000) break;
        	else {
        		printf("0");return 0;
        	}
        }
        while(s>=sum&&be<n){
            s-=a[++be];
            mn=min(mn,cnt-be+1);
        }
        if(cnt==n||be==n) break;
    }
    printf("%d",mn);
    return 0;
}
