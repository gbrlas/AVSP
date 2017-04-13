#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<set>
#include<map>
#include<fcntl.h>
#include<stack>
#include<queue>
#include<iostream>

using namespace std ;
int N ;
#define MAX 101
typedef pair<int,int> pi ;

string c[MAX] ;
//int cnt[MAX][MAX] ;
vector<pi> cnt[MAX] ;
int avg [MAX] ;
int ans ;
int logic(){
	int len ;
	int x ;
	for(int i=1;i<=N;i++){
		len = c[i].size() ;
		int prev = 0 ;
		for(int j=0;j<len;j++){
			
			
			if(c[i][j]!=c[i][prev] )
			{
				cnt[i].push_back(pi(c[i][prev]-'a',j-prev)) ;
				prev = j;
			}
			if(j==len-1 &&c[i][j]==c[i][prev]){
				cnt[i].push_back(pi(c[i][prev]-'a',j-prev+1)) ;
			}
			//if(j==len-1 && j==prev)
			//	cnt[i].push_back(pi(c[i][j]-'a',1)) ;
			//cout<<c[i][j]<<endl ;
		}
		if(i==1)
			x = cnt[1].size() ;
		else
			{
				if(x!=cnt[i].size())
					return -1 ;
			}
	}
	
	//cout<<x<<endl ;
	//cout<<cnt[1][0].first<<" "<<cnt[1][0].second<<endl ;
//cout<<cnt[1][1].first<<" "<<cnt[1][1].second<<endl ;
	//cout<<cnt[1][2].first<<" "<<cnt[1][2].second<<endl ;
	
	for(int j=0;j<x;j++){
		int mc = 0 ;
		int f ;
		for(int i=1;i<=N;i++){
			if(i==1)
				f = cnt[i][j].first ;
			else{
				if(f!=cnt[i][j].first)
					return -1 ;
			}
		}
	}
	
	for(int j=0;j<x;j++){
		for(int i=1;i<=N;i++){
			if(cnt[i][j].second)
				avg[j]+=cnt[i][j].second ;
			
		}
		avg[j]/=N ;
	}
	for(int j=0;j<x;j++){
		for(int i=1;i<=N;i++){
				ans += abs(cnt[i][j].second-avg[j]) ;
			}
		}
	return ans ;
	}
	



int init1(){
	for(int i=1;i<=N;i++){
		cnt[i].clear() ;
	}
	for(int i=0;i<MAX;i++)
		avg[i]=0;
	ans =0 ;
}

int read_inp(){
	cin>>N ;
	for(int i=1;i<=N;i++)
		cin>>c[i] ;
	
}

int main(){
	FILE *fp = freopen("1.in","r",stdin) ;
FILE *fp1 =freopen("1.out","w",stdout) ;
	int test ;
	scanf("%d",&test) ;
	for(int i=1;i<=test;i++){
		printf("Case #%d: ",i) ;
		read_inp() ;
		int a = logic() ;
		if(a==-1){
			cout<<"Fegla Won"<<endl ;
		}
		else{
			cout<<a<<endl ;
		}
		init1() ;
	
		
	}
}
