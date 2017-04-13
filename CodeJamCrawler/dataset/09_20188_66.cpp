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

int a[100][100];
int ans[100][100];
char sol[100][100];
int ival[10000],kval[10000];
int len;
char ch[26];
int chh;
int main()
{
    clock_t start=clock();
    int T;
    int j=1;
    cin>>T;
    int h,w;
    int allot,toallot;
    int icopy,kcopy,mini,mink;
    bool flag;
    while(T--)
    {
            cout<<"Case #"<<j<<":"<<endl;
            cin>>h>>w;
            forn(i,h)
            {
                     forn(k,w)
                     {
                              cin>>a[i][k];
                              ans[i][k]=-1;
                     }
            }
            
            allot=0;
            forn(i,h)
            {
                     forn(k,w)
                     {
                              if(ans[i][k]!=-1)
                                continue;
                              len=0;
                              icopy=i,kcopy=k;
                              toallot=-1;
                              //flag=false;
                              while(1)
                              {
                                      flag=false;
                                      mini=icopy,mink=kcopy;
                                      
                                      ival[len]=icopy;
                                      kval[len]=kcopy;
                                      len++;
                                      
                                      if(icopy>0) {
                                      if(a[mini][mink]>a[icopy-1][kcopy])
                                      {
                                                                         mini=icopy-1;
                                                                         mink=kcopy;
                                                                         flag=true;
                                      }
                                      }
                                      
                                      if(kcopy>0) {
                                      if(a[mini][mink]>a[icopy][kcopy-1])
                                      {
                                                                         mini=icopy;
                                                                         mink=kcopy-1;
                                                                         flag=true;
                                      }
                                      }
                                      
                                      if(kcopy<w-1) {
                                      if(a[mini][mink]>a[icopy][kcopy+1])
                                      {
                                                                         mini=icopy;
                                                                         mink=kcopy+1;
                                                                         flag=true;
                                      }
                                      }
                                      
                                      if(icopy<h-1) {
                                      if(a[mini][mink]>a[icopy+1][kcopy])
                                      {
                                                                         mini=icopy+1;
                                                                         mink=kcopy;
                                                                         flag=true;
                                      }
                                      }
                                      
                                      if(flag==false)
                                        break;
                                      
                                      if(ans[mini][mink]!=-1)
                                      {
                                                             toallot=ans[mini][mink];
                                                             break;
                                      }
                                      
                                      icopy=mini;
                                      kcopy=mink;
                              }
                              
                              if(toallot==-1)
                              {
                                             toallot=allot;
                                             allot++;
                              }
                              
                              forn(r,len)
                              {
                                         ans[ival[r]][kval[r]]=toallot;
                              }
                     }
            }
            
            forn(i,26)
              ch[i]=48;
            chh=97;
            forn(i,h)
            {
                     forn(k,w)
                     {
                              if(ch[ans[i][k]]==48)
                              {
                                                   ch[ans[i][k]]=(char)chh;
                                                   sol[i][k]=ch[ans[i][k]];
                                                   chh++;
                              }
                              else
                              {
                                  sol[i][k]=ch[ans[i][k]];
                              }
                     }
            }
                              
            forn(i,h)
            {
                     forn(k,w)
                       cout<<sol[i][k]<<" ";
                     cout<<endl;
            }
            j++;
    }
                                      
            
    //printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    //system("pause");
    return 0;
}
