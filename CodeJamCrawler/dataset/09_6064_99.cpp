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

map<string,bool> valido,pode;
int L,D,N,ans;
int main()
{
    cin>>L>>D>>N;
    string mios,dictionari,nepe="",auxiliar="",auxiliar2="";
    for(int i=0;i<D;i++)
    {   nepe="";
        cin>>mios;
        for(int j=1;j<=mios.size();j++)
        {   nepe+=mios[j-1];
            pode[nepe]=true;
        }
        valido[mios]=true;
        pode[mios]=true;
    }

    
    for(int i=1;i<=N;i++)
    {
        ans=0;
        cin>>mios;
        vector <string> anterior;
       
        int j;
        bool flag=false;
        auxiliar="";
        auxiliar2="";
        for(j=0;j<mios.size()&&!flag;j++)
        {
            if(mios[j]=='(')
            {
               
                while(mios[j]!=')')
                        {
                            auxiliar+=mios[j];
                            if(pode[auxiliar])
                            anterior.push_back(auxiliar);
                            auxiliar="";   
                            j++;
                        } 
                    j++;
                    break;    
            }
            else
            {
                    
                        auxiliar2+=mios[j];
                        anterior.push_back(auxiliar2);
                        j++;
                        break;
            }
        
        }
        if(anterior.size()==0)
            flag=true;
        for(;j<mios.size()&&!flag;j++){
                    if(mios[j]=='('){
                        j++;
                        vector <string> anterior2;
                        auxiliar="";
                        while(mios[j]!=')'){
                            for(int ii=0;ii<anterior.size();ii++){
                                auxiliar=(anterior[ii]+mios[j]);
                                if(pode[auxiliar]&&(auxiliar.size()<=L))
                                anterior2.push_back(auxiliar);
                                auxiliar="";
                            }
                            j++;
                        }
                        if(anterior2.size()==0)
                            flag=true;
                        else
                        anterior=anterior2;
                    }
                    else
                    {
                            auxiliar="";
                            vector <string> anterior2;
                            for(int ii=0;ii<anterior.size();ii++)
                            {   auxiliar=anterior[ii]+mios[j];
                                if(pode[auxiliar]&&auxiliar.size()<=L)
                                {
                                    anterior2.push_back(auxiliar);
                                }
                                auxiliar="";
                            }
                            if(anterior2.size()==0)
                            flag=true;
                            else
                            anterior=anterior2;  
                    }
        }
        if(!flag)
        {
            for(int k=0;k<anterior.size();k++)
                if(valido[anterior[k]])
                    ans++;
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    } 
return 0;
}
