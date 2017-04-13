#include <cstdio>
#include <iostream>
#include <algorithm>

#define eps 1e-9
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int cas;
    for(cas=1;cas<=t;cas++)
    {
        cout<<"Case #"<<cas<<": ";    
    
        int n;
        double na[1005],ke[1005];
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
          scanf("%lf",&na[i]);
        for(i=0;i<n;i++)
          scanf("%lf",&ke[i]);
        
        bool used[1005];
        for(i=0;i<n;i++)
          used[i] = false;
        
        int j;
        int sc = 0;
        for(i=0;i<n;i++)
        {
            int pos = -1;
            double val = 2;
            for(j=0;j<n;j++)
            {
                if(!used[j])
                {
                    if(eps>na[i]-ke[j] && (ke[j]-val)<eps) 
                    {
                        val = ke[j];
                        pos=j;
                    }
                }
            }
            if(pos!=-1)
            {
                used[pos]=true;
                sc++;
            }
            else
            {
            
              int pos = -1;
              double val = 2;
              for(j=0;j<n;j++)
              {
                if(!used[j])
                {
                    if((ke[j]-val)<eps) 
                    {
                        val = ke[j];
                        pos=j;
                    }
                }
              }
              used[pos]=true;
            }
        }
        sort(na,na+n);
        sort(ke,ke+n);
        int cnt = 0;
        j = 0;
        for(i=0;i<n;i++)
        {
            if((na[i]-ke[j])<eps)
              cnt++;
            else
              j++;
        }
        cout<<n-cnt<<" "<<n-sc<<endl;
    }
}
