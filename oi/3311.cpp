#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100010];
    
int main(){
    char ch;
    int sum=0,num,res=0,flag=0,ans1=0,flag1=0,cnt=0,ans=0;
    int n;scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;++i){
        ans=0;ans1=0;res=0;flag1=0;num=0;
        if(!flag)cnt =0;
        while((ch=getchar())!=' '&&ch!=EOF&&ch!='\n'){
            if(ch=='0'&&num==0) continue;
            else num=1;
            if(!flag)a[++cnt]=ch-48;
        //  cout<<ch<<" "<<ch-48<<endl;
        //  printf("%d",a[cnt]);
            //if(ch=='1') ans++;
            if(ch=='1') ans1++;
            else if(ch>'0'&&ch<='9') ans++;
            if(ch=='0') res++;
        }
    //  printf("%d %d\n",n,ans);
        //if(!flag)for(int i=1;i<=cnt;++i) cout<<a[i]<<" ";
        if(num==0) {printf("0");return 0;}
        if(ans>0||ans1>1||ans+ans1>1) flag1=1,flag=1;
        if(!flag1) sum+=res;
    //  cout<<res<<" "<<sum<<endl;
    }
    //cout<<cnt;
//  cout<<endl;
    if(flag||n==1) for(int i=1;i<=cnt;++i) printf("%d",a[i]);
    else printf("%d",a[1]);
    if(n!=1) for(int i=1;i<=sum;++i) printf("0");
    return 0;
}
