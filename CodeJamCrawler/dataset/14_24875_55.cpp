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

int slv1(vector<double> a, vector<double>b){
    int res=0;
    int sz=a.size();
    int i,j=0;
    for(i=0;i<sz;i++){
        
        for(;j<sz;j++){
            //cout<<a[i]<<" "<<b[j]<<endl;
            if(b[j]>a[i]){
                res++;
                j++;
                break;
            }
        }
        if(j==sz)
            break;
    }
    return res;
}

int slv2(vector<double> a, vector<double>b){
    int res=0;
    int sz=a.size();
    int i,j=0;
    for(i=0;i<sz;i++){
        
        for(;j<sz;j++){
            //cout<<a[i]<<" "<<b[j]<<endl;
            if(b[j]>a[i]){
                res++;
                j++;
                //i++;
                break;
            }
        }
        
        if(j==sz)
            break;
    }

    return res;
}


int main(int argc, const char * argv[])
{
    freopen("/Volumes/Mac1/Dropbox/L/GoogleCodeJam2014/QualificationRound/GCJ2014QR2014PC/GCJ2014QR2014PC/D-small-attempt0.in","r+",stdin);
    freopen("/Volumes/Mac1/Dropbox/L/GoogleCodeJam2014/QualificationRound/GCJ2014QR2014PC/GCJ2014QR2014PC/D-small-attempt0.out","w+",stdout);
    int T;
    cin>>T;
    FOR(ts,0,T){
        int N;
        cin>>N;
        int res1,res2;
        vector<double> no,kn;
        no.resize(N);
        kn.resize(N);
        FOR(i,0,N){
            cin>>no[i];
        }
        FOR(i,0,N){
            cin>>kn[i];
        }
        SORT(no);
        SORT(kn);
        
        
        res1=slv1(kn,no);
        res2=slv2(no,kn);
        
        cout<<"Case #"<<ts+1<<": ";
        cout<<res1<<" "<<N-res2<<endl;
        
    }
    
	return 0;
}