#include <iostream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
using namespace std;

bool isPair( int a, int b)
{
    stringstream ssa; ssa<<a;
    stringstream ssb; ssb<<b;
    for(int i=1; i<=ssb.str().size()-1; i++)
    {
        stringstream ssc;
        ssc<<ssb.str().substr(i, ssb.str().size()-i) << ssb.str().substr(0,i);
        int c;
        ssc>>c;
        if(c==a)
            return true;
    }
    return false;
}
int work( string & in )
{
    stringstream ss(in);
    int A=0;  int B=0;
    ss>>A>>B;
    cout<<A<<"___"<<B<<endl;
    int cnt =0;
    for(int i=A;i<=B;i++)
        for(int j=i+1; j<=B; j++)
            if( isPair(i,j))
                cnt++;
    return cnt;
}

int main()
{



    fstream infile("input.txt");
    fstream outfile("output.txt");
    string line;
    int linecnt =0 ;
    int casenum=0;
    if (infile.is_open())
    {
        cout<<"read file "<<endl;
        do
        {
            getline (infile,line);
            ++linecnt;
            if (!(line.size () > 0))
                break;
            istringstream r(line);
            cout<<line<<std::endl;
            cout<<" case : "<<  linecnt-1 <<std::endl;
            std::cout<<"Case "<<(linecnt - 1  )<<": "<<(line)<<endl;
            // from here process the input content
            if(1==linecnt)
            {
                r>> casenum;
            }


            else
            {
                outfile<<"Case #"<<(linecnt - 1  )<<": "<<work(line)<<endl;
            }


        }
        while (! infile.eof() && linecnt -1 <= casenum);


        infile.close();
    }
    else
        cout<<" no file found"<<endl;
    outfile.close();
    return 0;
}
