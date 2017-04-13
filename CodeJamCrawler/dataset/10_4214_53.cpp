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


string sminus( const string a, const string  b)
{
    if ( a == b)
        return string ("0");
    string l, s;
    if ( sz(a)== sz(b) )
    {
        if ( a < b)
        {  l = b;
            s = a;
        }
        else
        {
            l = a;
            s = b;
            }
    }

    else if ( sz(a) > sz(b) ) {
        l = a;
        s = b;
        }
    else if ( sz(a) < sz(b))
    {
        l = b;
        s = a;
        }

    string rslt = l;
    int carr = 0;
    int i,j;

    reverse(l.begin(),l.end());
    reverse(s.begin(),s.end());

    REP ( i , sz(s))
    {
        int d  = l[i] - carr - s[i];
        carr =  d >=0 ? 0: 1;

        rslt[i] = (d>=0)?('0'+d):('9'+d+1);
        }
    for ( int  i = sz(s) ; i < sz(l) ; i++)
    {
        int d  = l[i] - carr -'0';
        carr =  d >=0 ? 0: 1;

        rslt[i] = (d>=0)?('0'+d):('9'+d+1);

        }
    reverse( ALL (rslt));

    while ( rslt[0] == '0')
        rslt  = rslt.substr(1);

    return rslt;



}

string doit (vs & me)
{

//REP (k , sz(me))
   // cout<< me[k] <<" ";
//cout<<endl;

if (sz(me ) == 1)
    return me[0];
else if (sz(me)==2)
    return sminus(me[0], me[1]);

vs now;

for ( int i = 0;i < sz(me)-1 ; i++)
for (int j = i+1; j< sz(me); j++)
{

    string a = me[i];
    string b = me [j];
    string c = sminus(a,b);

    if ( c.compare("1")==0)
        return string ("1");

    if ( find (now.begin(), now.end(), c)== now.end())
    {
        now.push_back(c);

        }
    }
if (sz(now) == 1)
   return now[0];
else
    return doit(now);
    };

string addwhat (string s , string gcd )
{
    cout<<"in add what "<< s <<" " << gcd<<endl;

    while ( (sz(s)> sz(gcd) ) || (sz(s)== sz(gcd) && s> gcd))
    {
      //  cout<<"in aw loop "<<  s<< "  " << gcd <<"  ";
        s = sminus(s, gcd);
      //  cout<< s << endl;
        }

    return sminus(gcd,s);
    }

int main()
{
ifstream infile ("A-large-practice.in");
ofstream outfile ("output.txt");

//cout<< sminus( "19", "91")<<endl;
//cout<< sminus( "1900", "1901")<<endl;
//cout<< sminus( "1901", "1900")<<endl;
//cout<< sminus( "1900", "12112")<<endl;
//cout<< sminus( "1900", "1900")<<endl;
//cout<< sminus( "1900", "2110")<<endl;

//return 1;
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

                    string tmp;
                    int num ;
                    r>> num;

                        vs me;
                            while ( r >> tmp)
                        {
                            me.push_back(tmp);
                            }

                        outfile<<"Case #"<<(linecnt -1  )<<": "<<addwhat(me[0], doit(me))<<endl;
                    }


            }while (! infile.eof() );


	infile.close();
	};

	    outfile.close();


    return 0;
}
