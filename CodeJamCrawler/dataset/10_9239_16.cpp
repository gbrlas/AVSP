#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int C;
    cin>>C;

    for (int ncase = 1; ncase <= C; ncase++) {
        int R;
        cin>>R;

        vector<vector<bool> > field(101, vector<bool>(101, false));
        for (int i = 0; i < R; i++) {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;
            if (x1 > x2) {
                swap(x1, x2);
            }
            if (y1 > y2) {
                swap(y1, y2);
            }
            for (int j = x1; j <= x2; j++) {
                for (int k = y1; k <= y2; k++) {
                    field[j][k] = true;
                }
            }
        }

        int n = 0;
        for (int i = 0; i < field.size(); i++) {
            for (int j = 0; j < field[i].size(); j++) {
                if (field[i][j]) {
                    n++;
                }
            }
        }

        int c = 0;
        while (n) {
            for (int i = field.size() - 1; i >= 1; i--) {
                for (int j = field[i].size() - 1; j >= 1; j--) {
                    if (field[i][j]) {
                        if (!field[i - 1][j] && !field[i][j - 1]) {
                            field[i][j] = false;
                            n--;
                        }
                    }
                    else {
                        if (field[i - 1][j] && field[i][j - 1]) {
                            field[i][j] = true;
                            n++;
                        }
                    }
                }
            }
            c++;
        }

        cout<<"Case #"<<ncase<<": "<<c<<endl;
    }

    return 0;
}

