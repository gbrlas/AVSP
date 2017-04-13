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
        int p, k, l;
        cin >> p >> k >> l;

        vector<int> cnts(l);
        for(int j=0; j<l; j++)
        {
            int tmp;
            cin >> tmp;

            cnts[j]=tmp;
        }

        sort(cnts.begin(), cnts.end());
        reverse(cnts.begin(), cnts.end());

        int sum=0;
        int times=0;
        for(int j=0; j<l; j++)
        {
            if(j%k == 0)
                times++;
            sum+=cnts[j] * times;
        }
        cout << "Case #" << i+1 << ": " << sum << endl;
    }
    return 0;
}
