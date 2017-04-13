#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>
using namespace std;
int main()
{
        unsigned long long int n;
        cin>>n;
        for(unsigned long long int i=0;i<n;i++)
        {
                unsigned long long int p1,k1,l1,t1;
                cin>>p1>>k1>>l1;
                vector<unsigned long long int> v;
                for( unsigned long long int j=0;j<l1;j++)
                {
                        cin>>t1;
                        v.push_back(t1);
                }
                sort(v.begin(),v.end());
                                unsigned long long int h = l1/k1,ans=0,ne = v.size();
                
                for(unsigned long long int u =0;u<=h;u++)
                {
                        for(unsigned long long int w=0;w<k1;w++)
                        {
                                if(u==h && (w+u*k1) >= ne ) break; 
                                ans+= (u+1)*v[ne-1 -(w + u*k1)];
                        }
                }
                cout<<"Case #"<<i+1<<": "<<ans<<endl;
                
        }        
        return 0;
}
