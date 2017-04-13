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
        string s[4];
        for (int i=0;i<4;i++)
            cin>>s[i];
        int finish=0;
        for (int i=0;i<4;i++)
        {
            int O1=0;
            int X1=0;
            int T1=0;
            int O2=0;
            int X2=0;
            int T2=0;
            int O3=0;
            int X3=0;
            int T3=0;
            int O4=0;
            int X4=0;
            int T4=0;
            for (int j=0;j<4;j++)
            {
                if (s[i][j]=='O')
                    O1++;
                else if (s[i][j]=='X')
                    X1++;
                else if (s[i][j]=='T')
                    T1++;
                if (s[j][i]=='O')
                    O2++;
                else if (s[j][i]=='X')
                    X2++;
                else if (s[j][i]=='T')
                    T2++;
                if (s[j][j]=='O')
                    O3++;
                else if (s[j][j]=='X')
                    X3++;
                else if (s[j][j]=='T')
                    T3++;
                if (s[j][3-j]=='O')
                    O4++;
                else if (s[j][3-j]=='X')
                    X4++;
                else if (s[j][3-j]=='T')
                    T4++;
                
            }
            if ((O1==3 && T1==1) || (O1==4) || (O2==3 && T2==1) || (O2==4) || (O3==3 && T3==1) || (O3==4) || (O4==3 && T4==1) || (O4==4))
            {
                finish=1;
                cout<<"O won"<<endl;
                break;
            }
            else if ((X1==3 && T1==1) || (X1==4) || (X2==3 && T2==1) || (X2==4) || (X3==3 && T3==1) || (X3==4) || (X4==3 && T4==1) || (X4==4))
            {
                finish=1;
                cout<<"X won"<<endl;
                break;
            }
        }
        if (finish==0)
        {
            int titik=0;
            for (int i=0;i<4;i++)
                for (int j=0;j<4;j++)
                    if (s[i][j]=='.')
                        titik++;
            if (titik==0)
                cout<<"Draw"<<endl;
            else
                cout<<"Game has not completed"<<endl;
        }
    }
    return 0;
}
