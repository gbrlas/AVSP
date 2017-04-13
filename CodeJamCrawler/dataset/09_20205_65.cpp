/* Author: Piyush Sachdeva */

#include<iostream>
#include<vector>
#include<cmath>
#include<time.h>
#include<fstream>
#include<queue>
#include<utility>

#define forn(i,n) for(int i=0;i<n;i++)
#define forab(i,a,b) for(int i=a;i<b;i++)
#define pb(t) push_back(t)
#define vi vector<int>
#define pq priority_queue
#define mp(t1,t2) make_pair(t1,t2)

using namespace std;

int a[200];
int main()
{
    clock_t start=clock();
    int n;
    cin>>n;
    int p,q;
    bool pr[100];
    string s;
    int oo=1;
    while(n--)
    {
              
            cin>>p>>q;
            forn(i,100)
              pr[i]=false;
            forn(i,q)
            {
                     cin>>a[i];
                     a[i]--;
            }
            s="";
            forn(i,q)
            {
                     s+=(char)(i+48);
            }
            int res=10000000,temp,t2;
            do
            {
                     //cout<<"s="<<s<<endl;
                     temp=0;
                     forn(i,p)
                       pr[i]=false;
                     forn(i,s.length())
                     {
                                       t2=a[s[i]-48];
                                       for(int j=t2-1;j>=0;j--)
                                       {
                                               if(pr[j]==true)
                                                 break;
                                               temp++;
                                       }
                                       for(int j=t2+1;j<p;j++)
                                       {
                                               if(pr[j]==true)
                                                 break;
                                               temp++;
                                       }
                                       pr[t2]=true;
                     }
                     //cout<<temp<<endl;
                     if(temp<res)
                       res=temp;
            }while(next_permutation(s.begin(),s.end()));
            
            cout<<"Case #"<<oo<<": "<<res<<endl;
            oo++;
    }                      
    //printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    //system("pause");
    return 0;
}
