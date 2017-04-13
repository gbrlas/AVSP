#include <iostream>
using namespace std;

int main() {
    int T;
    cin>>T;

    for (int i = 1; i <= T; i++) {
        int N;
        cin>>N;

        int minc = 1000000;
        unsigned int check = 0;
        int sum = 0;
        for (int j = 0; j < N; j++) {
            int c;
            cin>>c;

            minc = min(minc, c);
            check ^= c;
            sum += c;
        }

        sum -= minc;

        cout<<"Case #"<<i<<": ";
        if (check == 0) {
            cout<<sum;
        }
        else {
            cout<<"NO";
        }
        cout<<endl;
    }

    return 0;
}
