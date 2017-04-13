#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int make(string s)
{
    int x,y;
    x = (s[0] - '0')*10 + s[1] - '0';
    y = (s[3] - '0')*10 + s[4] - '0';
    
    return x * 60 + y;
}

int ans1,ans2,cnta,cntb,i,j,test,t,na,nb,tim;
int a1[10000],a2[10000],b1[10000],b2[10000],ca[100000],cb[100000];
string s1,s2;


int main()
{
    freopen("c:/input.txt","r",stdin);
    freopen("c:/output.txt","w",stdout);
    cin>>test;
    for (t = 0; t < test; t++)
    {
        cout<<"Case #"<<t+1<<": ";
        cin>>tim>>na>>nb;
        
        for (i = 0; i < na; i++)
        {
            cin>>s1>>s2;
            a1[i] = make(s1);
            a2[i] = make(s2);
           // cout<<a1[i]<<" "<<a2[i]<<endl;
        }
        
        for (i = 0; i < nb; i++)
        {
            cin>>s1>>s2;
            b1[i] = make(s1);
            b2[i] = make(s2);
           //  cout<<b1[i]<<" "<<b2[i]<<endl;
            
        }
        
        
        for (i = 0; i < 10000; i++)
        {
            ca[i] = 0; 
            cb[i] = 0;
        }
        
        ans1  = ans2 =  0;
        cnta = 0;
        cntb = 0;
        for (i = 0; i < 10000; i++)
        {
            cnta += ca[i];
            cntb += cb[i];
            
            for (j = 0; j < na; j++)
                if (a1[j] == i)
                {
                          
                          if (cnta == 0) ans1++; else cnta--;
                          cb[a2[j] + tim]++;
                    //   cout<<ans1<<" "<<ans2<<endl;
                }
                
            for (j = 0; j < nb; j++)
                if (b1[j] == i)
                {
                          if (cntb == 0) ans2++; else
                          cntb--;
                          ca[b2[j] + tim]++;
                    //   cout<<"cntb"<<" "<<cntb<<endl;
                    //   cout<<ans1<<" "<<ans2<<endl;                          
                       
                }    
                
        }
        
        cout<<ans1<<" "<<ans2<<endl;
        
    }
    return 0;
}
