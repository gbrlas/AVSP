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
    ifstream fi("hot dogs.in");
    ofstream fo("hot dogs.out");
    int nt;
    fi>>nt;
    for (int tc=1;tc<=nt;tc++)
    {
        fo<<"Case #"<<tc<<": ";
        int c, d;
        fi>>c>>d;
        vector<int> pos, num;
        for (int i=0;i<c;i++)
        {
            int x, y;
            fi>>x>>y;
            pos.push_back(x);
            num.push_back(y);
        }
        double low=0.0, hi=1000000.;
        hi*=hi;
        for (int b=0;b<500;b++)
        {
            double mid=(low+hi)/2., prev=0;
            bool kt=true;
            for (int i=0;i<pos.size();i++)
                for (int j=0;j<num[i];j++)
                {
                    if (i==0 && j==0) prev=pos[i]-mid;
                    else
                    {
                        double nn=prev+d;
                        if (pos[i]<nn)
                        {
                                      if (nn-pos[i]>mid) kt=false;
                                      else prev=nn;
                        }
                        else
                        {
                            if (pos[i]-nn<=mid) prev=nn;
                            else prev=pos[i]-mid;
                        }
                    }
                }
            if (kt) hi=mid;
            else low=mid;
        }
        fo<<low<<endl;
    }
}
