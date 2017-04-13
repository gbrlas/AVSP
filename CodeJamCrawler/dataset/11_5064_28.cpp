// seraph template //
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

using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    char arr[60][60];
    while (tc--)
    {
        cout<<"Case #"<<count++<<":"<<endl;
        int row, col;
        cin>>row>>col;
        for (int i=0;i<60;i++) for (int j=0;j<col;j++) arr[i][j]='.';
        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                cin>>arr[i][j];
        bool bisa=1;
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                if (arr[i][j]=='#')
                {
                    if (arr[i+1][j]=='#' && arr[i][j+1]=='#' && arr[i+1][j+1]=='#')
                    {
                        arr[i][j]='/';
                        arr[i+1][j]='\\';
                        arr[i][j+1]='\\';
                        arr[i+1][j+1]='/';
                    }
                    else
                    {
                        bisa=0;
                        break;
                    }
                }
                
            }
            if (!bisa) break;
        }
        if (!bisa) cout<<"Impossible"<<endl;
        else
        {
            for (int i=0;i<row;i++)
            {
                for (int j=0;j<col;j++)
                {
                    cout<<arr[i][j];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
