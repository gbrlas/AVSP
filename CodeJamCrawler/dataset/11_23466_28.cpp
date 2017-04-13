#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(int t)
{
    int n, l, h;
    cin >> n;
    cin >> l;
    cin >> h;
    vector<int> f(n);
    for(int i = 0; i < n; ++i)
        cin >> f[i];
    for(int i = l; i <=h; ++i)
    {
        bool ok = true;
        for(int p = 0; p < n; ++p)
        {
            if ( (f[p]%i != 0) && (i%f[p] != 0) )
            {
                ok = false;
                break;
            }                
        }
        if (ok)
        {
            cout << "Case #" << t+1 << ": "<< i << endl;
            return;
        }
        
    }
    cout << "Case #" << t+1 << ": NO"<< endl;
}


int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        solve(i);
}