#line 3 "main.cpp"
#include  "iostream" 
#include  "vector"
#include  "string"
#include  "string.h"
#include  "algorithm" 
#include  "sstream"
#include  "set"
#include  "map"
#include  "queue"
#include  "deque"
#include  "stack"
#include "list"
#include  "bitset"
#include  "cstdio"
#include  "assert.h"
#include  "cmath"
#include  "cstdlib"
#include  "ctime"
#include  "cfloat"
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define INF 1<<28
string cad[53];
int r,c;
long long arr[103];
#define MAX 1000000
long long a[MAX+3];
long long faltan[MAX+3];
long long tiempos[MAX+3];
double Ti[1004];
int L,T,N,C;
double dame(double T,double Tant,double cur,double longi){
	double th=0;
			if(cur>T)
				th=longi;
			else if(T-cur >= Tant){
				th=0;
			}
			else if(T-cur <= Tant){
				long long t2=longi-(T-cur)/2;
				double tt=t2+T-cur;
				th=Tant-tt;
			}
	return th;
}
int main(){
	freopen ("C:\\Documents and Settings\\jpenam\\Mis documentos\\Downloads\\B-small-attempt1.in","r",stdin);
	freopen ("B22.out","w",stdout);
	int casos;
    cin>>casos;
    for(int tt = 1; tt<=casos;tt++){
        long long L,t,N,C;
        cin>>L>>t>>N>>C;
        memset(a,0,sizeof a);
        memset(tiempos,0,sizeof tiempos);
        memset(faltan,0,sizeof faltan);                
        long long s = 0;
        long long M = 0;
        for(int i = 0; i < C; i++) cin>>a[i];

        faltan[0] = 0;
        for(int i = 1, j = 0; i <= N; i++, j++){
            tiempos[i] = a[j%C];
            faltan[i] = tiempos[i] + faltan[i-1];
            s += tiempos[i];
        }
        s *= 2;
        int index = lower_bound(faltan,faltan+N,t/2) - faltan;
        vector<long long> todos;
        todos.push_back(t/2-faltan[index]);
        for(int i = index+1; i <= N; i++) 
            todos.push_back(-tiempos[i]);
        
        sort(all(todos));
        for(int i = 0, it = 0; i < L && it < todos.size(); i++, it++){
            s += todos[it];
        }
        printf("Case #%d: %lld\n",tt,s);
        
        
        
    }
	return 0;
}
//Case #1:3