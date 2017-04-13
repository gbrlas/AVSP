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
#define pq priority_quque
#define mp(t1,t2) make_pair(t1,t2)

using namespace std;

int main()
{
    clock_t start=clock();
    int len=19;
    int a[len];
    int n;
    cin>>n;
    string s;
    int j=0;
    string chk="welcome to code jam";
    //cout<<chk.length();
    int ans,ans2,t,t2;
    while(j<=n)
    {
             getline(cin,s);
             if(j==0)
             {
                     j++;
                     continue;
             }
             //cout<<s<<endl;
             
             forn(i,len)
             {
                        a[i]=0;
             }
             forn(k,s.length())
             {
                               forn(i,chk.length())
                               {
                                                   if(chk[i]==s[k])
                                                   {
                                                                   if(i>0)
                                                                   {
                                                                          a[i]+=a[i-1];
                                                                          a[i]=a[i]%10000;
                                                                   }
                                                                   else
                                                                     a[i]++;
                                                   }
                               }
                               /*if(s[k]=='w')
                                 a[0]++;
                               else if(s[k]=='e')
                                 a[1]+=a[0];*/
             }
             ans=a[18];
             cout<<"Case #"<<j<<": ";
             ans2=0;
             t=4;
             while(ans)
             {
                       ans2=(ans2*10)+(ans%10);
                       ans/=10;
                       t--;
             }
             t2=4;
             while(t--)
             {
                       cout<<'0';
                       t2--;
             }
             while(t2--)
             {
                        cout<<ans2%10;
                        ans2/=10;
             }
             cout<<endl;      
             j++;
    } 
    //printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    //system("pause");
    return 0;
}
