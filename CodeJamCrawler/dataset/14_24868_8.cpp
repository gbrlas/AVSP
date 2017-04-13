#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num_of_cases = 0;

    cin >> num_of_cases;
    for (int i=0; i<num_of_cases; i++)
    {
        int A, B, K;

        cin >> A;
        cin >> B;
        cin >> K;

        //cout << "K : " << K << endl;

        int counter = 0;
        for (int j=0; j<A; j++)
        {
            for (int k=0; k<B; k++)
            {
                //cout << "j : " << j << " k : " << k << " j&k : " << (j & k) << endl;
                if ((j & k) < K)
                    counter++;
            }
        }

        printf ("Case #%d: %d\n", i+1, counter);
    }

    return 0;
}
