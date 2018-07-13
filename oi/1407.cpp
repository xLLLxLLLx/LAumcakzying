#include<bits/stdc++.h>
using namespace std;
int ma[100000];
int n,x,ans=1;
string s;

void swap(int a,int b){
    int t=a;
    a=b;
    b=t;
}

int main(){
    scanf("%d",&n);
    ma[1]=1;ma[2]=2;ma[3]=3;ma[4]=4;ma[5]=5;ma[6]=6;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='N'){
            int t1=ma[5]; ma[5]=ma[6]; ma[6]=t1;
            int t2=ma[5]; ma[5]=ma[1]; ma[1]=t2;
            int t3=ma[1]; ma[1]=ma[2]; ma[2]=t3;
        }
        else if(s[0]=='S'){
            int t1=ma[5]; ma[5]=ma[6]; ma[6]=t1;
            int t2=ma[6]; ma[6]=ma[2]; ma[2]=t2;
            int t3=ma[2]; ma[2]=ma[1]; ma[1]=t3;
        }
        else if(s[0]=='E'){
            int t1=ma[1]; ma[1]=ma[3]; ma[3]=t1;
            int t2=ma[1]; ma[1]=ma[4]; ma[4]=t2;
            int t3=ma[4]; ma[4]=ma[6]; ma[6]=t3;
        }
        else if(s[0]=='W'){
            int t1=ma[1]; ma[1]=ma[4]; ma[4]=t1;
            int t2=ma[1]; ma[1]=ma[3]; ma[3]=t2;
            int t3=ma[3]; ma[3]=ma[6]; ma[6]=t3;
        }
        else if(s[0]=='R'){
            int t1=ma[2]; ma[2]=ma[4]; ma[4]=t1;
            int t2=ma[2]; ma[2]=ma[3]; ma[3]=t2;
            int t3=ma[3]; ma[3]=ma[5]; ma[5]=t3;
        }
        else if(s[0]=='L'){
            int t1=ma[2]; ma[2]=ma[3]; ma[3]=t1;
            int t2=ma[2]; ma[2]=ma[4]; ma[4]=t2;
            int t3=ma[4]; ma[4]=ma[5]; ma[5]=t3;
        }
        ans+=ma[1];
    }
    printf("%d",ans);
    return 0;
}
