
#include <iostream>
#include <stdio.h>
#include<sstream>
#include <string>
#include <cmath>
#include <vector>
#define NT 1000000000000000
        //   1214428244121
using namespace std;
bool is_palindrom(string s)
{
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}
bool is_palindrom(long long  N)
{
    stringstream ss;
    ss<<N;
    string str=ss.str();
    return is_palindrom(str);
}

int main(int argc, const char * argv[])
{
   freopen("/Users/igorm/Documents/1.txt","w",stdout
           );
    freopen("/Users/igorm/Documents/A.txt","r",stdin);
    vector<long long> pal;
    pal.push_back(1);
    pal.push_back(4);
    pal.push_back(9);
    pal.push_back(121);
    pal.push_back(484);
  
    long long an=0;
        for(int i=1;i<pal.size();i++)
        {
            an=pal[i]*pal[i];
            if(is_palindrom(an))
                pal.push_back(an);
            if(an>=NT)break;
        }
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=0;i<pal.size();i++)
        {
            if(pal[i]>=l)
            {
                if(pal[i]>r)break;
                ans++;
            }
                
        }
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
        //121 484 1 4 9
        
    }
   
    return 0;
}

