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

const string coded[]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};

const string orig[]={"our language is impossible to understand","there are twenty six factorial possibilities","so it is okay if you want to just give up"};

 map<char,char> charmap;

 string convert(const string  & in)
{
    stringstream ret;
    forn(i,in.size())
        ret<<charmap[in[i]];
    return ret.str();
}
int main()
{

    if(1)
    {
        forn(i,3)
            forn(j,coded[i].size())
               {
                 charmap[coded[i][j]]=orig[i][j];

               }
        charmap['q']='z';
        charmap['z']='q';
        cout<<charmap.size()<<endl;
        cout<< charmap.count('z')<<endl;

        set<char> seen;
        for( char a='a';a<='z';a++)
            seen.insert(a);
        for(map<char,char>::iterator it = charmap.begin(); it != charmap.end(); it ++)
        {
             cout<< it->first  <<"   "<<it->second <<std::endl;
            seen.erase(it->second);
        }
        cout<<" seen size = "<<seen.size()<<"   ="<< *seen.begin()<<endl;
    }

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
                outfile<<"Case #"<<(linecnt - 1  )<<": "<<convert(line)<<endl;
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
