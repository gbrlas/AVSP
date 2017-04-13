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
#include <sstream>
#include <ctime>


using namespace std;

typedef long long LL;
typedef vector<LL> VLL;

bool isugly(LL i)
{
     if(i<0) i = i * -1;
     if(i==0) return true;
     if(i%2==0) return true;
     if(i%3==0) return true;
     if(i%5==0) return true;
     if(i%7==0) return true;
     return false;
}

void fillsign(vector<int> & vals,  vector<char> & signs, int depth, int limit,LL &count)
{
     if(depth==limit)
     {
        LL val=0,temp=1;
        LL current = 0;
        //print
        //printf("%d ",limit);
        for(int i=limit-1; i>=0 ; --i)
        {
          current += temp*vals[i+1];
          if(signs[i]=='n')
          {
            temp=temp*10;
            if(i==0)
            {
              current += vals[0]*temp;
              val += current;      
            }
          }
          else 
          { 
              if(i==limit-1) current = vals[limit];
              if(signs[i]=='+')
              {
                   val += current;
              }
              else if(signs[i]=='-')
              {
                   val -= current;
              }
             temp=1;current=0;
             if(i==0) val += vals[0];
          }
        }
        //printf(" val  %d ",val);
        if(isugly(val)) {count++; }
        //printf("\n");
        return;
     }
     signs[depth] = 'n';
     fillsign(vals,signs,depth+1,limit,count);
     signs[depth] = '+';
     fillsign(vals,signs,depth+1,limit,count);
     signs[depth] = '-';
     fillsign(vals,signs,depth+1,limit,count);
}

int main()
{
 int nocases;
 cin >> nocases;
 
 for(int ic=0;ic<nocases;++ic)
 { 
       //calculate  
       string s;
       cin >> s; 
       vector<int> vals;
       vector<char> signs;  
       int D = s.length();
       for(int i=0; i < D; ++i)  
       {
         vals.push_back((s.at(i)-'0'));
         //cout << vals[i];
         signs.push_back('n'); 
       }
       //cout << "\n";
       
       LL count=0;
       if(D==1)
       {
        if(isugly(vals[0])) ++count;
       }
       else
        fillsign(vals, signs, 0, D-1,count);
                      
       cout <<"Case #" <<ic+1<<": ";
       //print result
       cout << count;
       cout << "\n";    
 }
 return 0;
}
