// Template By Fendy Kosnatha (Seraph)
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
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        int a,b;
        cin>>a>>b;
        int arr[101][101];
        for (int j=0;j<a;j++)
            for (int k=0;k<b;k++)
                cin>>arr[j][k];
        int gagalSeluruh=0;
        for (int j=0;j<a;j++)
        {
            for (int k=0;k<b;k++)
            {
                int gagal=0;
                for (int l=0;l<a;l++)
                {
                    if (arr[l][k]>arr[j][k])
                    {
                        gagal=1;
                        break;
                    }
                }
                
                if (gagal==0) continue;
                gagal=0;
                
                for (int l=0;l<b;l++)
                {
                    if (arr[j][l]>arr[j][k])
                    {
                        gagal=1;
                        break;
                    }
                }
                
                if (gagal==0) continue;
                
                gagalSeluruh=1;
                break;
            }
            if (gagalSeluruh==1)
                break;
        }
        if (gagalSeluruh==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
