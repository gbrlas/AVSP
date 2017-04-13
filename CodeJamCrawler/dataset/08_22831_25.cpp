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


int main()
{
 int nocases;
 cin >> nocases;
 
 for(int ic=0;ic<nocases;++ic)
 { 
       //calculate  
       LL p,k,l,temp; 
       vector<LL> freq;
       cin >> p >> k >> l;
       for(LL i=0; i< l; ++i)
       {
              cin >> temp;
              freq.push_back(temp);
       }    
       sort(freq.begin(),freq.end());
       LL count =1;
       LL ans = 0;
       for(LL i=1; i< l+1; ++i)
       { 
            ans += freq[l-i]*count;  
            if(i%k==0) ++count;
       }                
       cout << "Case #" << ic+1<<": "  ;
       //print result
       cout << ans;
       cout << "\n";    
 }
 return 0;
}
