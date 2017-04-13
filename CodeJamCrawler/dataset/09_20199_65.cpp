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

int main()
{
    clock_t start=clock();
    int T;
    cin>>T;
    string s;
    bool a[36];
    int eq[36];
    int coun;
    bool done[36];
    long long result,mul;
    int base;
    int u=1;
    while(T--)
    {
             cin>>s;
             cout<<"Case #"<<u<<": ";
             u++;
             forn(i,36)
             {
                       a[i]=false;
                       eq[i]=-1;
                       done[i]=false;
             }
             forn(i,s.length())
             {
                               if(s[i]>='a'&&s[i]<='z')
                               {
                                                       a[s[i]-97]=true;
                               }
                               else
                               {
                                   a[s[i]-'0'+26]=true;
                               }
             }
             base=0;
             forn(i,36)
             {
                       if(a[i]==true)
                         base++;
             }
             //cout<<"base="<<base<<endl;
             if(base==1)
               base++;
             coun=1;
             if(s.length()==1)
             {
                              cout<<"1"<<endl;
                              continue;
             }
             forn(i,s.length())
             {
                               if(s[i]>='a'&&s[i]<='z')
                               {
                                                       if(done[s[i]-97])
                                                         continue;
                                                       eq[s[i]-97]=coun;
                                                       done[s[i]-97]=true;
                               }
                               else
                               {
                                   if(done[s[i]-'0'+26])
                                     continue;
                                   eq[s[i]-'0'+26]=coun;
                                   done[s[i]-'0'+26]=true;
                               }
                               if(coun==1)
                               {
                                          coun=0;
                                          continue;
                               }
                               if(coun==0)
                               {
                                          coun=2;
                                          continue;
                               }
                               coun++;
             }
             //cout<<"coun="<<coun<<endl;
             //cout<<eq['s'-97]<<endl;
             result=0;
             mul=1;
             for(int i=s.length()-1;i>=0;i--)
             {
                     if(s[i]>='a'&&s[i]<='z')
                     {
                                             result+=(eq[s[i]-97]*mul);
                                             
                                             //cout<<"eq="<<eq[s[i]-97]<<endl;
                                             //cout<<(eq[s[i]-97]*mul)<<endl;
                                             //cout<<result<<endl;
                     }
                     else
                     {
                         result+=eq[s[i]-'0'+26]*mul;
                     }
                     mul*=base;
             }
             cout<<result<<endl;
    }
                                
    //printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    //system("pause");
    return 0;
}
