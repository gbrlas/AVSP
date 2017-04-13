#include <iostream.h>

#define for(i,n) for(int i=0; i<n; i++)
#define int32 long long


// bool result = true: light bulb is on
int resovle(int r, int k, int n, int* G)
{
    int32 money = 0;
    int* p, pidx = 0, pcount;
    int32 sum;

    p = G;

    for(i, r){
        sum = 0;
		pcount = 0;
        while((sum + *p <= k) && (pcount < n))
        {
            sum += *p;
			pcount++;

            p++; pidx++;

			if (pidx == n){
                p = G;
                pidx = 0;
            }
        }
        money += sum;
    }

    return money;
}

int main()
{
    int t;
    int r, k, n;
    int* G;

    cin >> t;
    for(i,t)
    {
        cin >> r >> k >> n;

        G = new int[n];

        for(j,n)
            cin >> G[j];

        long result = resovle(r, k, n, G);
        cout << "Case #" << i + 1 << ": ";
        cout << result << endl;
		delete []G;
    }
    return 0;

}
