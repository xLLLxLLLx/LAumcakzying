#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=100000+10;
int d[maxn];
int B[maxn];
int path[maxn];
int num[maxn];
int n;
 
int search(int first,int end,int tmp){
	int mid;
	while(first<end){
		mid=first+(end-first)/2;
		if(B[mid]>=tmp) end=mid;
		else first=mid+1;
	}
	return first;
}
 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);
	int len = 1;
	B[1]=d[1]; 
	num[1]=1;
	for(int i=2;i<=n;i++){
		if(d[i]>B[len]){
			B[++len]=d[i];
			num[i]=len;
		}
		else {
			int j=search(1,len,d[i]);
			B[j]=d[i];
			num[i]=j;
		}
	}
	//for(int i=1;i<=n;++i) cout<<i<<" "<<B[i]<<" "<<num[i]<<endl;
	int last=maxn,l1=len;
	for(int i=n;i>=1;i--){
		if(!l1)break;
		if(num[i]==l1&&d[i]<last){
			path[l1]=d[i];
			last=d[i];
			l1--;
		}
    }
	for(int i=1;i<=len;i++) printf("%d ",path[i]);
	return 0;
}
