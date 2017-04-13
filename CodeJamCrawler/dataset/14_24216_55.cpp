#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

#define Maxsize 1005
double num[2][Maxsize];

int Deceitful(int n)
{
    int ret=0;
    int Kleft=0, Kright = n-1;
    for(int i=0; i<n; i++)
    {
        if(num[0][i]>num[1][Kright])
        {
            ret++;
            Kright--;
        }
        else
        if(num[0][i]>num[1][Kleft])
        {
            ret++;
            Kleft++;
        }
        else
        Kright--;

    }
    return ret;
}

int War(int n)
{
    int ret=0;
    int Kleft=0, Kright=n-1;
    for(int i=n-1; i>=0; i--)
    {
        if(num[0][i]>num[1][Kright])
        {
            Kleft++;
            ret++;
        }
        else
            Kright--;
    }
    return ret;
}


int main()
{
//    cout << "Hello world!" << endl;
    std::iostream::sync_with_stdio(false);
    int t, n;
    freopen("D-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> t;
    int cal=1;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> num[0][i];
        for(int i=0; i<n; i++)
            cin >> num[1][i];
        sort(num[0], num[0]+n);
        sort(num[1], num[1]+n);
//        output(n);
        int x=0, y=0;
        x = Deceitful(n);
        y = War(n);
        cout << "Case #" << cal++ <<": " << x << " " << y << endl;
    }
    return 0;
}
