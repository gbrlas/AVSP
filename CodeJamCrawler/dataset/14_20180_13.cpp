#include<cstdio>  
#include<cstring>  
#include<cctype>  
#include<cmath>  
#include<cstdlib>  
#include<ctime>  
#include<iostream>  
#include<iomanip>  
#include<sstream>  
#include<vector>  
#include<string>  
#include<queue>  
#include<stack>  
#include<utility>  
#include<algorithm>  
#include<map>  
#include<set>  
#include<bitset>  
#include<sstream>
#include<limits>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

int S[100000];

int main(){
	int T, N, X;
	scanf("%d",&T);
	for(int caso=1;caso<=T;caso++){
		scanf("%d%d",&N,&X);
		for(int i=0;i<N;i++){
			scanf("%d",&S[i]);
		}
		sort(S,S+N);
		int i=0, j=N-1, cnt=0;		
		while(i<j){
			if(S[j]+S[i]<=X){
					cnt++;
					i++; j--;			
			}
			else{
					cnt++;
					j--;
			}
		}
		if(i==j){cnt++;}
		printf("Case #%d: %d\n",caso,cnt);	
	}	
	return 0;
}
