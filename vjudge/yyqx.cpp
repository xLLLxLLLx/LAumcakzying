#include<bits/stdc++.h>
using namespace std;
const int N=1010;

int main(){
    int n;
   // srand((unsigned)time(NULL));
    while(cin>>n){
       // printf("Hello!%d烊千玺\n",n);
        printf("Hello! Jacson Yee's wife\n");
        if(n==1) printf("Good morning\n");
        if(n==2) printf("Good noon\n");
        if(n==3) printf("Good afternoon\n");
        if(n==4) printf("Good evening\n");
             int x=int(rand()%5)+1;
             if(x==1) printf("Dream It Possible\n");
             else if(x==2) printf("Where'd you go and How much you wana risk\n");
             else if(x==3) printf("I will run ,I will dream, I will sour\n");
             else if(x==4) printf("make the people who love me proud and impress the boy I like\n");
             else printf("just run for your bright dream\n");
    }
    return 0;
}
