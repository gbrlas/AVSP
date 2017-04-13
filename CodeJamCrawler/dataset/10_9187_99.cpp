#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin>>t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin>>n>>k;
        int mask = (1 << n) - 1;
        cout<<"Case #"<<i + 1<<": ";
        if ((mask & k) == mask) {
            cout<<"ON"<<endl;
        }
        else {
            cout<<"OFF"<<endl;
        }
    }

    return 0;
}
