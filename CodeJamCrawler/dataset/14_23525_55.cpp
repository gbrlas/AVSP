#include <iostream>
#include <vector>
#include <algorithm>
const double elipse = 0.00001;
using namespace std;
int main()
{
    int T, N, y, z;
    double tmp;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        y = z = 0;
        cin >> N;
        vector<double>VN(N);
        vector<double>VK(N);
        for(int j = 0; j < N; ++j) {
            cin >> tmp;
            VN[j] = tmp;
        }
        for(int j = 0; j < N; ++j) {
            cin >> tmp;
            VK[j] = tmp;
        }
        sort(VN.begin(), VN.end());
        sort(VK.begin(), VK.end());

        //get z
        int indexn = 0, indexk = 0;
        while(indexn < N && indexk < N) {
            for(indexk; indexk < N; ) {
                if(VK[indexk++] - VN[indexn] >= elipse) {
                    indexn++;
                    break;
                }
            }
        }
        z = N - indexn;

        //get y
        int lown = 0, lowk = 0, highn = N - 1, highk = N - 1;
        while(lown <= highn) {
            if(VK[lowk] - VN[lown] >= elipse) {
                highk--;
                lown++;
            } else {
                lown++;
                lowk++;
                y++;
            }
        }

        //print
        cout << "Case #" << i + 1 << ": " << y << " " << z << endl;

    }
    return 0;
}