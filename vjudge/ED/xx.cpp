#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct node
{
    int x,y,t;
    double val;
}a[1515];
double dp[1515];
int cmp(node a,node b)
{
    return a.t<b.t;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%lf",&a[i].x,&a[i].y,&a[i].t,&a[i].val);
        }
        sort(a,a+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            dp[i]=a[i].val;
            for(int j=0;j<i;j++)
            {
                long long int t1=(a[i].t-a[j].t);
                t1*=(a[i].t-a[j].t);
                long long int tmp1=(a[i].x-a[j].x);
                long long int tmp2=(a[i].y-a[j].y);
                long long int t2=tmp1*tmp1+tmp2*tmp2;
                if(t1>=t2)
                {
                    dp[i]=max(dp[i],dp[j]+a[i].val);
                }
            }
        }
        double output=0;
        for(int i=0;i<n;i++)
        {
            output=max(output,dp[i]);
        }
        printf("%lf\n",output);
    }
}

