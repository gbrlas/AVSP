#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

class alien{
      public:
      void getpossibles(vector<string>& brokenstring, vector< set<string> > & alldic, int depth, int l, string& inmaking, int& count);
      void main1();
};

void alien::getpossibles(vector<string>& brokenstring,  vector< set<string> > & alldic, int depth, int l, string& inmaking, int& count)
{
    if(depth>0 && depth <l)
    {
        if(alldic[depth].find(inmaking.substr(0,depth)) == alldic[depth].end())
        {
            return;
        }
    } 
    else if(depth == l)
    {
       if(alldic[l].find(inmaking) != alldic[l].end())
       {
           ++count;
       }
       return;
    }
    for(int i=0; i< brokenstring[depth].length(); ++i)
    {
       inmaking[depth] = brokenstring[depth][i];
       getpossibles(brokenstring, alldic, depth+1, l, inmaking, count);
    }
}

void alien::main1()
{
    int l,d,n;
    vector<string>  dic;
    vector< set<string> > alldic;
    cin >> l >> d >> n;
    for(int i=0;i<d;++i)
    {
        string s;
        cin >> s;
        dic.push_back(s);    
    }
    for(int i=0; i<l+1; ++i)
    {    
        set<string> dicleni;
        for(int j=0; j<d; ++j)
        {
           dicleni.insert(dic[j].substr(0,i));
        }
        alldic.push_back(dicleni);
    }
    
    for(int i=0; i<n; ++i)
    {
        string test;
        cin >> test;
        vector<string> brokentest;
        for(int j=0; j< test.length();++j)
        {
            string temp;     
            if(test[j]=='(')
            {
              ++j;            
              while(test[j] != ')')
              {
                 temp.push_back(test[j]);
                 ++j;           
              }
            }
            else
            {
                temp.push_back(test[j]);
            }
            //cout << temp << "  ";
            brokentest.push_back(temp);
        }
        //cout<<"\n";
        
        int n=0;
        string inmaking;
        inmaking.resize(l);
        getpossibles(brokentest, alldic, n, l, inmaking, n);
        cout << "Case #"<<i+1<<": "<<n<<"\n"; 
    }
}

int main()
{
    alien c;
    c.main1();
    return 0;
}
