#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>

using namespace std;
typedef long long LL;

int main()
{
    ifstream fi("bottrust.in");
    ofstream fo("bottrust.out");
    int n;
    fi>>n;
    string s;
    getline(fi,s);
    for (int i=0;i<n;i++)
    {
        vector<int> po, pb;
        vector<int> x;
        vector<char> ch;
        getline(fi,s);
        int xx;
        char cch;
        stringstream ss(s);
        ss>>xx;
        while (ss>>cch>>xx)
        {
              x.push_back(xx);
              ch.push_back(cch);
              if (cch=='O') po.push_back(xx);
              else pb.push_back(xx);
        }
        int ppo=0, ppb=0, ret=0, px=0, nexto=0, nextb=0;
        while (px<x.size())
        {
              ret++;
              int xx=x[px], cch=ch[px];
              if (cch=='O' && xx==ppo)
              {
                           nexto++;
                           px++;
                           if (nextb<pb.size())
                           {
                                               if (ppb<pb[nextb]) ppb++;
                                               else if (ppb>pb[nextb]) ppb--;
                           }
              }
              else if (cch=='B' && xx==ppb)
              {
                   nextb++;
                   px++;
                   if (nexto<po.size())
                   {
                                       if (ppo<po[nexto]) ppo++;
                                       else if (ppo>po[nexto]) ppo--;
                   }
              }
              else
              {   
                  if (nextb<pb.size())
                  {
                                      if (ppb<pb[nextb]) ppb++;
                                      else if (ppb>pb[nextb]) ppb--;
                  }
                  if (nexto<po.size())
                  {
                                      if (ppo<po[nexto]) ppo++;
                                      else if (ppo>po[nexto]) ppo--;
                  }
              }
        }
        fo<<"Case #"<<i+1<<": "<<ret-1<<endl;
    }
}
