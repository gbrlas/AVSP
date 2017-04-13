#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 16384;

int N, X, T;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>N>>X;
        for(int i=0; i<N; i++)
            cin>>arr[i];
        sort(arr, arr+N);
        int lb = 0, rb = N;

        int ans = 0;
        while(lb < rb)
        {
            int XA = arr[rb-1], XB = arr[lb];
            if(XA + XB <= X)
            {
                lb++;
                rb--;
            }
            else
            {
                rb--;
            }
            ans++;
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }

    return 0;
}
