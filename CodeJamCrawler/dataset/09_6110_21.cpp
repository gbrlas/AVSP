#include <iostream> 
#include <vector>
#include <string>
#include <string.h>
#include <algorithm> 
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cfloat>
#include <bitset> 

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

 int T;
 bool mayor(string cad1,string cad2)
 {
    for(int i=cad1.size()-1;i>=0;i--)
    {
        if(cad1[i]=='1'&&cad1[i]!=cad2[i])
            return true;
        if(cad1[i]=='0'&&cad1[i]!=cad2[i])
            return false;
    }
    return false;
 
 }

int f(vector <int> v)
{
     int T ,N;
     
     
 N=v.size();
     int m =0 ;
     for(int i = 0 ; i < N ; i++){
          if(v[i] > i+1){
               int j = i;
               while(v[j] > i+1) j++;
               while(j != i){
                    swap(v[j],v[j-1]);
                    j--;
                    m++;
               }
          }
     }
     
     return m;
} 
 int main()
 {
    cin>>T;
    int tam;
    string cad;
    for(int ii=0;ii<T;ii++)
    {
        cin>>tam;
        
        vector <string> v;
        vector <int> v2;
        for(int i=0;i<tam;i++)
        {
            cin>>cad;
            v.push_back(cad);
            int ind=0;
            for(int j=cad.size()-1;j>=0;j--)
            {
                if(cad[j]=='1')
                {
                    ind=j+1;
                    break;
                }
            }
            v2.push_back(ind);
        }
         bool fa=false;
        int res=f(v2);
      
        
       
        printf("Case #%d: %d\n",ii+1,res);
    }
    
    return 0;
 }
