#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
    int t;
    std::iostream::sync_with_stdio(false);
     freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    int a, b, k;

    int cnt=1;
    while(t--)
    {
        cin >> a >> b >> k;
        int ans=0;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                if((i&j) < k)
                ans++;
            }
        }
        cout << "Case #" << cnt++ << ": ";
        cout << ans << endl;
    }
    return 0;
}
