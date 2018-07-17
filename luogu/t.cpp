#include<stdio.h>
#define MOD 1000000007
#define ll long long
struct nana{
    ll  m[2][2];
} h,l;
 
nana juzhen(nana a,nana b){
    nana temp;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            temp.m[i][j]=0;
            for(int k=0; k<2; k++){
                temp.m[i][j]=(temp.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
            }
        }
    }
    return temp;
}
 
ll zzz(ll n){
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            h.m[i][j]=(i==j);
        }
    }
    l.m[0][0]=1;
    l.m[0][1]=1;
    l.m[1][0]=1;
    l.m[1][1]=0;
    while(n){
        if(n%2==1)
            h=juzhen(h,l);
        l=juzhen(l,l);
        n=n/2;
    }
    return h.m[0][0];
}
 
int main(){
    ll n;
    while(~scanf("%lld",&n))
        printf("%lld\n",zzz(n));
    return 0;
}
