// small test only
#include <iostream>
using namespace std;

typedef unsigned long long int huge;

int main() {
    int i,T;
    huge j,k,A,B,K,D,count;
    cin >> T;
    for (i=0; i<T; i++) {
        count=0;
        cout << "Case #" << i+1 << ": ";
        cin >> A >> B >> K;
        for (j=0; j<A; j++) {
            for (k=0; k<B; k++) {
                if ((j&k)<K) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}