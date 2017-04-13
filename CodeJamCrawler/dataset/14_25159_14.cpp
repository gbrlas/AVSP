#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("/home/zth/下载/A-small-attempt3.in","r",stdin);
    //freopen("/home/zth/下载/m.out","w",stdout);
    int a[4][4];
    bool first[17],second[17];
    int T;
    cin >> T;
    for(int nu = 1; nu <= T; nu++)
    {
        memset(first,0,sizeof(first));
        memset(second,0,sizeof(second));
        int row;
        cin >> row;
        row--;
        for(int i = 0; i < 4; i++)
            for(int j = 0 ; j < 4; j++)
                cin >> a[i][j];
        for(int i = 0; i < 4; i++)
            first[a[row][i]] = 1;
        cin >> row;
        row--;
        for(int i = 0; i < 4; i++)
            for(int j = 0 ; j < 4; j++)
                cin >> a[i][j];
        for(int i = 0; i < 4; i++)
            second[a[row][i]] = 1;
        int sum = 0;
        for(int i = 1; i <= 16; i++)
            if(first[i] && second[i])sum++;
        cout << "Case #" << nu << ": ";
        if(sum == 1)
        {
            for(int i = 1; i < 17; i++)
                if(first[i] && second[i])
                    cout << i;
        }
        else if(sum > 1)
        {
            cout << "Bad magician!";
        }
        else cout << "Volunteer cheated!";
        cout << endl;
    }
    return 0;
}
