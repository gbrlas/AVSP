#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;

    for (int tt = 1; tt <= T; tt++) {
        int N;
        cin>>N;

        vector<string> schedule(N);
        for (int i = 0; i < N; i++) {
            cin>>schedule[i];
        }

        vector<double> wp(N);
        for (int i = 0; i < N; i++) {
            int total = 0;
            int win = 0;
            for (int j = 0; j < N; j++) {
                if (schedule[i][j] == '.') {
                    continue;
                }
                if (schedule[i][j] == '1') {
                    win++;
                }
                total++;
            }
            wp[i] = (double)win / total;
        }
        vector<double> owp(N);
        for (int i = 0; i < N; i++) {
            int total = 0;
            double p = 0;
            for (int j = 0; j < N; j++) {
                if (schedule[i][j] == '.') {
                    continue;
                }
                int ototal = 0;
                int owin = 0;
                for (int k = 0; k < N; k++) {
                    if (k == i || schedule[j][k] == '.') {
                        continue;
                    }
                    if (schedule[j][k] == '1') {
                        owin++;
                    }
                    ototal++;
                }
                p += (double)owin / ototal;
                total++;
            }
            owp[i] = p / total;
        }
        vector<double> oowp(N);
        for (int i = 0; i < N; i++) {
            int total = 0;
            double p = 0;
            for (int j = 0; j < N; j++) {
                if (schedule[i][j] == '.') {
                    continue;
                }
                p += owp[j];
                total++;
            }
            oowp[i] = p / total;
        }

        cout<<"Case #"<<tt<<":"<<endl;
        for (int i = 0; i < N; i++) {
            printf("%.12f\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
        }
    }

    return 0;
}
