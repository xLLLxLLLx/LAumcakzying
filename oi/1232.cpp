#include<iostream>
#include<cstdio>
using namespace std;

int n,a[10000010],b[10000010];

int main(){
    scanf("%d",&n);
    a[0]= 1;a[1] = 2;
    for (int i = 2; i < n; i++) {
       a[i] = (a[i - 1] + a[i - 2]) % 1000000;
    }
    for(int i=0;i<n;++i) b[a[i]]++;
    int ans=-1;
    for(int i=0;i<=10000001;++i)
    	while(b[i]) a[++ans]=i,b[i]--;
    int sum = 0;
    for (int i=0;i<n;++i) {
        sum = sum + (1LL * a[i] * i) % 1000000;
        if (sum >= 1000000) sum -= 1000000;
    }
    printf("%d",sum);
    return 0;
}
