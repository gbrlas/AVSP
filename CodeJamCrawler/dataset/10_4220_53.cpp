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
typedef vector<ll> vll;
#define sz(v) int((v).size())
#define FOR(i, a, b) for (int i(a), _b(b); i < _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define ALL(C) (C).begin(), (C).end()
#define INF numeric_limits<int>::max()
#define MINF numeric_limits<int>::min()
#define PRTV(c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++){ cout<<*i<<" "; } cout<<endl;
#define DB(C) if(1){std::cout<<#C <<" = "<< (C)<<std::endl;}

int casenum;

ll doitsmall ( ll R, ll K,ll N, vll & me)
{
    ll sum = 0 ;
    ll iter  =0;
    int pos  = 0;
    ll pp;
    for ( iter =0; iter <  R ; ++iter )
    {
        pp = 0;
            int added = 0;
        while ( pp + me[pos] <= K && added < N)
        {


            pp += me[pos];
            sum +=me[pos];
     //cout<<R<<K<<N<<" " <<iter<<" " <<"adding " <<pos <<" " << me[pos]<<" " << sum <<endl;
            ++pos ;
                pos = pos % N;
            added++;

        //
            }

    }
    return sum;

    }

ll doit ( ll R, ll K,ll N, vll & me)
{
    ll sum = 0 ;
    ll iter  =0;
    int pos  = 0;
    ll pp;
    for ( iter =0; iter <  R ; ++iter )
    {
        pp = 0;
            int added = 0;
        while ( pp + me[pos] <= K)
        {


            pp += me[pos];
            sum +=me[pos];
   //  cout<<R<<K<<N<<" " <<iter<<" " <<"adding " <<pos <<" " << me[pos]<<" " << sum <<endl;
            ++pos ;
                pos = pos % N;
            added++;
            if ( added >= N)
                break;
        //
            }

        if ( pos == 0)
            break;

    }

   // cout<<iter <<" out of loop " << sum<<endl;

    if ( iter == R)
        return sum;


    ll st = ( R/ (iter +1))  * sum;
    pos = 0;
    for ( iter  = R %(iter +1) ; iter >0; --iter )
    {
         pp = 0;
    int added = 0;
        while ( pp + me[pos] <= K)
        {
//            int oldp = pos;
            pp += me[pos];
            sum +=me[pos];
            ++pos ;
                pos = pos % N;

            added++;
            if ( added >= N)
                break;
            }

        };

   return st;

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

                        ll R,K,N;

                        r>>R >> K >> N;

                        getline (infile,line);
                        istringstream p(line);
                        ll s;
                        vll me;
                        while ( p >> s)
                        {
                            me.push_back(s);
                            }

                        outfile<<"Case #"<<(linecnt -1  )<<": "<<doitsmall(R, K, N, me)<<endl;
                    }


            }while (! infile.eof() );


	infile.close();
	};

	    outfile.close();


    return 0;
}
