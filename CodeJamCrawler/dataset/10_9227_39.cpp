#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T;
    cin>>T;

    for (int ncase = 1; ncase <= T; ncase++) {
        int A1, A2, B1, B2;
        cin>>A1>>A2>>B1>>B2;

        int count = 0;
        for (int a0 = A1; a0 <= A2; a0++) {
            for (int b0 = B1; b0 <= B2; b0++) {
                int a = a0;
                int b = b0;
                vector<bool> twice;
                int c;
                while(true) {
                    c = a % b;

                    if(a / b > 0) {
                        twice.push_back(a / b >= 2);
                    }
                    a = b;
                    b = c;

                    if(c == 0)
                        break;
                }

                bool win = true;
                int p = twice.size();
                while(p > 0) {
                    if(twice[p - 1]) {
                        p = p - 1;
                    }
                    else {
                        if(p - 2 < 0) {
                            win = false;
                            break;
                        }
                        p = p - 2;
                    }
                }

                if(win) {
                    count++;
                }
            }
        }

        cout<<"Case #"<<ncase<<": "<<count<<endl;
    }

    return 0;
}
