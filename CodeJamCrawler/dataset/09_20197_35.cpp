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
    string s,s2,s3;
    int i,j;
    bool flag;
    char ch;
    int aps=1;
    int hhh;
    while(T--)
    {
            cin>>s;
            j=s.length()-1;
            flag=false;
            int max=s.length()-1;
            int min=s.length()-1;
            //cout<<"s="<<s<<endl;
            while(j--)
            {
                      s3=s.substr(j+1,s.length());
                      sort(s3.begin(),s3.end());
                      //cout<<"s3...="<<s3<<endl;
                      forn(oo,s3.length())
                      {
                                          if(s3[oo]>s[j])
                                          {
                                                         flag=true;
                                                         hhh=oo;
                                                         break;
                                          }
                                          
                      }
                      if(flag)
                        break;
                      /*if(s[min]>s[j])
                      {
                                     flag=true;
                                     break;
                      }
                      else if(s[max]>s[j])
                      {
                                     flag=true;
                                     break;
                      }
                      else 
                      {
                          max=j;
                      }*/
            }
            if(flag)
            {
                      //j=j-1;
                      //if(T==2)
                        //cout<<j<<endl;
                        //cout<<"s3="<<s3<<endl;
                      ch=s[j];
                      s[j]=s3[hhh];
                      s3[hhh]=ch;
                      //cout<<"s3="<<s3<<endl;
                      //s2=s.substr(j+1,s.length());
                      //cout<<s2<<endl;
                      
                      //sort(s2.begin(),s2.end());
                      //cout<<s2<<endl;
                      int tt=0;
                      forab(k,j+1,s.length())
                      {
                                             s[k]=s3[tt];
                                             tt++;
                      }
            }
            else
            {
                sort(s.begin(),s.end());
                s='0'+s;
                ch=s[0];
                int fg;
                forn(u,s.length())
                {
                                  if(s[u]!='0')
                                  {
                                               fg=u;
                                               break;
                                  }
                }
                                               
                s[0]=s[fg];
                s[fg]=ch;
            }
            cout<<"Case #"<<aps<<": "<<s<<endl;
            aps++;
    }
    //printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    //system("pause");
    return 0;
}
