#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

ifstream fi("B.in");
ofstream fo("B.out");

int en(string s)
{
    int x=s[0]-'0', y=s[1]-'0', z=s[3]-'0', t=s[4]-'0';
    return (x*10+y)*60+(z*10+t);
}
int main()
{
    int t, round=0;
    fi>>t;
    while (t>0)
    {
          round++;
          t--;
          int time, a, b;
          fi>>time>>a>>b;
          int ta1[2000], ta2[2000], tb1[2000],tb2[2000];
          memset(ta1,0,sizeof(ta1));
          memset(ta2,0,sizeof(ta2));
          memset(tb1,0,sizeof(tb1));
          memset(tb2,0,sizeof(tb2));
          for (int i=0;i<a;i++)
          {
              string s;
              fi>>s;
              ta1[en(s)]++;
              fi>>s;
              ta2[en(s)+time]++;
          }
          for (int i=0;i<b;i++)
          {
              string s;
              fi>>s;
              tb1[en(s)]++;
              fi>>s;
              tb2[en(s)+time]++;
          }
          int ra=0, rb=0, cura=0, curb=0;
          for (int i=0;i<2000;i++)
          {
              if (ta2[i]>0) curb+=ta2[i];
              if (tb2[i]>0) cura+=tb2[i];
              if (ta1[i]>0)
              {
                           if (cura>=ta1[i]) cura-=ta1[i];
                           else
                           {
                               ra+=ta1[i]-cura;
                               cura=0;
                           }
              }
              if (tb1[i]>0)
              {
                           if (curb>=tb1[i]) curb-=tb1[i];
                           else
                           {
                               rb+=tb1[i]-curb;
                               curb=0;
                           }
              }
          }
          fo<<"Case #"<<round<<": "<<ra<<" "<<rb<<endl;
    }
    fi.close();
    fo.close();
}
