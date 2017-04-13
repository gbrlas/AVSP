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

int tofindLen = 19;
string tofind = "welcome to code jam";

long long getcount(const string& in, int depth)
{
    // cout << "call with in= "<<in<< " : depth= "<<depth<<" : in.len()= "<<in.length()<< "\n";
     if(in.length() < tofindLen-depth) return 0;
     if(depth==tofindLen) return 1;
     long long sum=0; 
     for(int i = 0; i< in.length()- tofindLen + depth+1; ++i)
     {  
          if(in[i] == tofind[depth])
          {
              sum += getcount(in.substr(i+1),depth+1);     
          }             
     }
     return sum;
}

int main()
{
    int n;
    cin >> n;
    string clear;
    getline(cin, clear);
    for(int i=0; i<n; ++i)
    {
        string s,temp;
        getline(cin, s);
        for(int i=0;i<s.length();++i) 
        {
            switch(s[i])
            {
                case 'w':   
                case 'e': 
                case 'l':   
                case 'c': 
                case 'o':   
                case 'm':
                case ' ':   
                case 't':  
                case 'd': 
                case 'j':   
                case 'a':
                     temp.push_back(s[i]);
                default:
                     break;
            }      
        }
        cout<<"Case #" << i+1 <<": ";
        long long lastn = 10000;
        //cout<<temp<<"\n";
        long long n = getcount(temp,0); 
        long long remin = n%lastn;
        if(remin==0) cout << "0000\n";
        else if(remin<10) cout << "000" <<remin<<"\n";
        else if(remin<100) cout << "00" <<remin<<"\n";
        else if(remin<1000) cout << "0" <<remin<<"\n";
        else if(remin<10000) cout << remin<<"\n";
    }
}
