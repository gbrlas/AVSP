#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int t;
        cin >> t;

        vector<int> v0(t), v1(t);
        int tmp;
        for(int j=0; j<t; j++)
        {
            cin >> tmp;
            v0[j] = tmp;
        }
        
        for(int j=0; j<t; j++)
        {
            cin >> tmp;
            v1[j] = tmp;
        }

        sort(v0.begin(), v0.end());
        sort(v1.begin(), v1.end());

        int ret=0;
        for(int j=0; j<t; j++)
        {
            ret += v0[j]*v1[t-j-1];
        }

        cout << "Case #" << i+1 << ": " << ret << endl;
    }
    return 0;
}
