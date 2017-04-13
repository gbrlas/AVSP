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
    freopen("/Volumes/Mac1/Dropbox/L/GoogleCodeJam2014/QualificationRound/QualificationRound2014PA/A-small-attempt1.in","r+",stdin);
    freopen("/Volumes/Mac1/Dropbox/L/GoogleCodeJam2014/QualificationRound/QualificationRound2014PA/A-small-attempt1.out","w+",stdout);
    int tc;
    cin>>tc;
    FOR(cs,0,tc){
       
        int tes1,tes2;
        int t1[4][4],t2[4][4];
        cin>>tes1;
        FOR(i, 0, 4){
            FOR(j,0,4){
                cin>>t1[i][j];
            }
        }
        cin>>tes2;
        FOR(i, 0, 4){
            FOR(j,0,4){
                cin>>t2[i][j];
            }
        }
        vector<int> res;
        FOR(i,0,4){
            int tmp=t1[tes1-1][i];
            FOR(j,0,4){
                if(tmp==t2[tes2-1][j])
                    res.push_back(tmp);
            }
        }
        cout<<"Case #"<<cs+1<<": ";
        if(res.size()==0){
            cout<<"Volunteer cheated!";
        }
        else if(res.size()==1){
            cout<<res[0];
        }
        else
            cout<<"Bad magician!";
        
        cout<<endl;
    }
	return 0;
}