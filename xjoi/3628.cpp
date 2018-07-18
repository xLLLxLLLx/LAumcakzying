#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define maxn 100010
using namespace std;

int n, m;
int pre[maxn];
int use[40];

struct node {
    int a, b, c;
    bool operator < (const node& rhs) const {  
        return c < rhs.c;  
    } 
}cnt[maxn];

int find(int x) {
    return pre[x] == x ? x : pre[x] =  find(pre[x]);
}

bool kruskal() {
    int num = 1, ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i++) pre[i] = i;
    sort(cnt, cnt+m);
    for(int i = 0; i < m; i++) {
        int x = find(cnt[i].a);
        int y = find(cnt[i].b);
        if(x != y) {
            pre[y] = x;
            num++;
            ans1 += cnt[i].c;
        }
    }
    if(num != n) return false;
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = m-1; i >= 0; i--) {
        int x = find(cnt[i].a);
        int y = find(cnt[i].b);
        if(x != y) {
            pre[y] = x;
            ans2 += cnt[i].c;
        }
    }
    for(int i = 1; i <= 26; i++) 
        if(ans1 <= use[i] && use[i] <= ans2) return true;
    return false;
}

void init() {
    use[1] = 1, use[2] = 2;
    for(int i = 3; i <= 26; i++) use[i] = use[i-1] + use[i-2];
}

int main() {
    init();
    int t, kase = 1;
    scanf("%d %d" , &n, &m);
    for(int i = 0; i < m; i++) scanf("%d %d %d", &cnt[i].a, &cnt[i].b, &cnt[i].c);
    if(kruskal()) printf("Yes\n");
    else printf("No\n");
    return 0;
} 
