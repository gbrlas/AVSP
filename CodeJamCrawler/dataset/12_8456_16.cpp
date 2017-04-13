#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
#define eps 1e-7
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
int cases;
double aux;
int arr[400];
int n;
int main(){
	cin>>cases;
	f(t,1,cases+1){
		scanf("%d",&n);	
		double sum = 0;
		f(i,0,n){
			cin >> arr[i];
			sum += arr[i];
		}
		aux = 2*sum / n;
	  	double sum2 = sum;
		int k = n;
		f(i,0,n){
			if ( arr[i] > aux ){
				k--;
				sum2 -=arr[i];
			}
		}
		double val = ( sum2 + sum ) / k;
		double res;
		printf("Case #%d:",t);
		f(i,0,n){
		 res = arr[i] > aux ? 0 : ( val - arr[i] ) / sum;
			printf(" %.5lf", res * 100 );
		}
		printf("\n");
	
	}
	return 0;
}
