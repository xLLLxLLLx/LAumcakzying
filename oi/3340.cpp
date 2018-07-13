#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10;
string name[N];
string em[N][N];
int my[N],ta[N],n,num[N];

//next_permutation
bool win(int x,int y){
	for(int i=1;i<=num[y];++i) if(name[x]==em[y][i]) return false;
	return true;
}

bool ok(){
	int hm=1,ht=1;
	while(1){
		if(win(my[hm],ta[ht])) ht++;
		else hm++;
		if(hm==n+1) return false; 
		if(ht==n+1) return true;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) cin>>name[i];
	for(int i=1;i<=n;++i){
		scanf("%d",&num[i]);
		for(int j=1;j<=num[i];++j){
			cin>>em[i][j];
		}
	}
	sort(name+1,name+1+n);
	for(int i=1;i<=n;++i) my[i]=i;
	while(1){
		bool beat=1;
		for(int i=1;i<=n;++i) ta[i]=i;
		while(1){
			if(!ok()){
				beat=0;
				break;
			}
			if(!next_permutation(ta+1,ta+1+n)) break;
		}
		if(beat){
			printf("Yes\n");
			for(int i=1;i<=n;++i)
				cout<<name[my[i]]<<" ";
			break;
		}
		if(!next_permutation(my+1,my+1+n)){
			printf("No");
			return 0;
		}
	}
	return 0;
}
