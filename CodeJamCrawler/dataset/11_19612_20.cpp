#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    char game[100][100];
    double rpi[100];
    double wp[100];
    double owp[100];
    double oowp[100];
    int countall[100];
    int countwin[100];
    freopen("A-large.in", "r", stdin);
    freopen("output-small.txt", "w", stdout);
    cin >> t;
    for(int casenum = 1; casenum <= t; ++casenum) {
        int N;
        cin >> N;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> game[i][j];
        
        for(int i = 0; i < N; ++i) {
            countall[i] = 0;
            countwin[i] = 0;
            for(int j = 0; j < N; ++j) {
                if(game[i][j] == '1')
                    ++countwin[i];
                else if(game[i][j] == '.')
                    ++countall[i];
            }
            countall[i] = N - countall[i];
            wp[i] = double(countwin[i])/countall[i];
            //cout << i << ":" << wp[i] << endl;
        }
        for(int i = 0; i < N; ++i) {
            double countop = 0;
            for(int j = 0; j < N; ++j) {
                if(game[i][j] == '1')
                    countop += double(countwin[j])/(countall[j]-1);
                else if(game[i][j] == '0')
                    countop += double(countwin[j]-1)/(countall[j]-1);
            }
            owp[i] = double(countop)/countall[i];
            //cout << i << ":" << owp[i] << endl;
        }
        for(int i = 0; i < N; ++i) {
            double countoowp = 0;
            for(int j = 0; j < N; ++j) {
                if(game[i][j] == '1' || game[i][j] == '0')
                    countoowp += owp[j];
            }
            oowp[i] = double(countoowp)/countall[i];
            //cout << i << ":" << oowp[i] << endl;
            rpi[i] = 0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i];
        }
        cout << "Case #" << casenum << ":" << endl;
        cout.precision(12);
        for(int i = 0; i < N; ++i)
            cout << fixed << rpi[i] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}