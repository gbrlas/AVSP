#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
#include <numeric>
#include <math.h>

using namespace std;

typedef long long  ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

typedef vector<string> vs;
typedef vector<vs> vvs;
typedef pair<string,string> ss;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<char,char> cc;

typedef vector<bool> vb;

#define sz(v) int((v).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define ALL(C) (C).begin(), (C).end()
#define INF numeric_limits<int>::max()
#define MINF numeric_limits<int>::min()
#define PRTV(c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++){ cout<<*i<<" "; } cout<<endl;
#define DB(C) if(1){std::cout<<#C <<" = "<< (C)<<std::endl;}

int casenum;

string doit ( ll N, ll K)
{
    ll x= (ll)pow( (double) 2, (int)N);

    ll r = K+1;
    string t ("ON");
    string f ("OFF");

    if ( r % x == 0)
        return t;

    else
        return f;

    };


int main()
{
ifstream infile ("A-large-practice.in");
ofstream outfile ("output.txt");

string line;
int linecnt =0 ;
if (infile.is_open())
	{
	    do{
			getline (infile,line);
			++linecnt;
			if (!(line.size () > 0))
				break;
				istringstream r(line);


                // from here process the input content
                if(1==linecnt){
                    r>> casenum;
                    }


                else{

                        ll N,K;

                        r>>N >> K;
                        outfile<<"Case #"<<(linecnt - 1  )<<": "<<doit(N, K)<<endl;
                    }


            }while (! infile.eof() );


	infile.close();
	};

	    outfile.close();


    return 0;
}
