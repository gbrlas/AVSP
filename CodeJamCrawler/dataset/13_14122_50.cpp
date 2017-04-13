#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    
    int count = 1;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        
        cout<<"Case #"<<count<<": ";
        int a[n+2][m+2];
        int i,j;
        bool hasOne = false;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j] == 1)
                  hasOne = true;
            }
        }
        
        if(!hasOne)
          cout<<"YES"<<endl;

        else
        {
            bool pos = true;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(a[i][j] == 1)
                    {
                        int k;
                        bool p = true;
                        for(k=0;k<n;k++)
                        {
                            if(a[k][j]!=1)
                              p = false;
                        }
                        if(!p)
                        {
                          p = true;
                          for(k=0;k<m;k++)
                          {
                              if(a[i][k]!=1)
                                p = false;
                          }
                        }
                        if(!p)
                          pos = false;
                    }
                }
            }
            if(pos)
              cout<<"YES"<<endl;
            else
               cout<<"NO"<<endl;
        }

            count++;
    }
}
