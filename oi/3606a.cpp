#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int N = 100010;
ll h[N],R[N],L[N],st[N];

int main(){
        int n;scanf("%d",&n);
        for(int i=1;i<=n;++i){
            scanf("%lld",&h[i]);
        }
        int top=0,cur;
        for(int i=1;i<=n+1;++i){
            while(1){
                cur=st[top];
                if(h[cur]<=h[i]) break;
                R[cur]=i;
                top--;
            }
            cur=st[top];
            L[i]=cur;
            st[++top]=i;
        }
        ll ans=0;
        for(int i=1;i<=n;++i){
            int len=R[i]-L[i]-1;
            ans=max(ans,h[i]*len);
        }
        printf("%lld\n", ans);
        return 0;
}
