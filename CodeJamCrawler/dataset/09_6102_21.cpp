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
    map<vector <string> ,bool> visi;
    struct nodo
    {
        vector <string> ve;
        int pa;
        nodo()
        {}
        nodo(vector <string> a,int b)
        {
        ve=a;
        pa=b;
        }
    
    };
    
    bool es(vector <string> v)
    {
        
        
        for(int i=0;i<v.size();i++)
        {
        
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i][j]=='1')
                return false;    
                    
            }
        
        }
        return true;
    }
   void im(vector <string> v)
   {
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            cout<<v[i][j];
        
        }
        cout<<endl;
    }
    
   }
 int T;
 int main()
 {
    cin>>T;
    int tam;
    string cad;
    for(int ii=0;ii<T;ii++)
    {
        cin>>tam;
        visi.clear();
        vector <string> v;
        for(int i=0;i<tam;i++)
        {
            cin>>cad;
            v.push_back(cad);
        }
        visi[v]=true;
        queue <nodo> q;
        q.push(nodo(v,0));
      //  imprime
        
        int res=10000000;
        
        while(!q.empty())
        {
            nodo ac=q.front();q.pop();
            if(es(ac.ve))
            {
                //cout<<ii+1<<endl;
                res=min(res,ac.pa);
                //cout<<endl;
               // im(ac.ve);
                //cout<<endl;
                continue;
            }
            vector <string> aux; 
            for(int i=0;i<tam-1;i++)
            {
                
               
                    aux=ac.ve;
                    swap(aux[i],aux[i+1]);
                    if(visi[aux])
                    continue;
                    q.push(nodo(aux,ac.pa+1));
                    visi[aux]=true;
                
           }    
        }
        printf("Case #%d: %d\n",ii+1,res);
    }
    
    return 0;
 }
