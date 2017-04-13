#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include <iomanip>
using namespace std;



#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int main(int argc, const char * argv[])
{
    freopen("/Volumes/Mac1/Dropbox/L/GoogleCodeJam2014/QualificationRound/GCJ2014QR2014PB/GCJ2014QR2014PB/B-small-attempt0.in","r+",stdin);
    freopen("/Volumes/Mac1/Dropbox/L/GoogleCodeJam2014/QualificationRound/GCJ2014QR2014PB/GCJ2014QR2014PB/B-small-attempt0.out","w+",stdout);
    int T;
    cin>>T;
    FOR(ts,0,T){
        double C,F,X,res=0,gt;
        int N;
        cin>>C>>F>>X;
        gt=((X-C)*F)/C;
        if(gt<=0){
            cout<<"Case #"<<ts+1<<": ";
            cout<<setiosflags(ios::fixed)<<setprecision(7)<<X/2<<endl;
            continue;
            
        }
        N=(gt-2)/F+1;
        FOR(i,0,N){
            res+=C/(2+F*i);
        }
        res+=X/(2+F*N);
        cout<<"Case #"<<ts+1<<": ";
        cout<<setiosflags(ios::fixed)<<setprecision(7)<<res<<endl;
        
    }
    
	return 0;
}