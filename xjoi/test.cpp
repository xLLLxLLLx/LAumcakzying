#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-7
#define M 1000100
#define LL __int64
//#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
 
using namespace std;
 
const int maxn = 5000010;
 
int dp[30][30][30][30];
int num1[30], num2[30];
int cnt1[30], cnt2[30];
int dfs(int l1, int r1, int l2, int r2)
{
    if(dp[l1][r1][l2][r2] != 0)
        return dp[l1][r1][l2][r2];
    int sum = (cnt1[r1]-cnt1[l1-1]) + (cnt2[r2]-cnt2[l2-1]);
    if(l1 > r1 && l2 > r2)
        return 0;
    if(l1 > r1)
    {
        dp[l1][r1][l2][r2] = sum - min(dfs(l1, r1, l2+1, r2), dfs(l1, r1, l2, r2-1));
        return dp[l1][r1][l2][r2];
    }
    if(l2 > r2)
    {
        dp[l1][r1][l2][r2] = sum - min(dfs(l1+1, r1, l2, r2), dfs(l1, r1-1, l2, r2));
        return dp[l1][r1][l2][r2];
    }
    dp[l1][r1][l2][r2] = sum-(min(dfs(l1+1, r1, l2, r2),min(dfs(l1, r1-1, l2, r2), min(dfs(l1, r1, l2+1, r2), dfs(l1, r1, l2, r2-1)))));
    return dp[l1][r1][l2][r2];
}
 
int main()
{
    int T;
    cin >>T;
    while(T--)
    {
        int n;
        cin >>n;
        memset(dp, 0, sizeof(dp));
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(int i = 1; i <= n; i++)
            cin >>num1[i];
        for(int i = 1; i <= n; i++)
            cin >>num2[i];
        for(int i = 1; i <= n; i++)
        {
           cnt1[i] += cnt1[i-1]+num1[i];
           cnt2[i] += cnt2[i-1]+num2[i];
        }
        dfs(1, n, 1, n);
        cout<<dp[1][n][1][n]<<endl;
    }
    return 0;
}

