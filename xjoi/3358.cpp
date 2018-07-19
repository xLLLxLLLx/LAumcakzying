#include <bits/stdc++.h>
using namespace std;
int p,ans=-1,a[5],aa[5];

int main(){
    scanf("%d",&p);
    for (int i=1;i<=4;i++) scanf("%d",&a[i]);
    for (int i1=a[1];i1>=0;--i1)
      for (int i2=a[2];i2>=0;--i2)
        for (int i3=a[3];i3>=0;--i3)
          for (int i4=a[4];i4>=0;--i4)
          if (i1*1+i2*5+i3*10+i4*25==p){
          		if(i1+i2+i3+i4>ans){
                	ans=i1+i2+i3+i4;
                	aa[1]=i1,aa[2]=i2,aa[3]=i3,aa[4]=i4;
               	}
            }
    if (ans==-1) printf("Charlie cannot buy coffee.");
    else printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.",aa[1],aa[2],aa[3],aa[4]);
	return 0;
}
