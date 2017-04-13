#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main()
{
    int t, n;
    int a[2][100];
    int robot[100];
    int cPos[2];
    ifstream infile("A-small-attempt2.in");
    ofstream outfile("output2.txt");
    infile >> t;
    //cin >> t;
    int casenum = 1;
    while(t--) {
        infile >> n;
        // cin >> n;
        int oo = 0;
        int bb = 0;
        for(int i = 0; i < n; ++i) {
            char r; // robot hallways
            int bPos; // button position
            //cin >> r >> bPos;
            infile >> r >> bPos;
            if(r == 'O') {
                a[0][oo++] = bPos;
                robot[i] = 0;
            }
            else if(r == 'B') {
                a[1][bb++] = bPos;
                robot[i] = 1;
            }
        }
        // Logic Part
        int timeSum = 0;
        int op, bp;
        cPos[0] = cPos[1] = 1;
        int o, b;
        o = b = 0;
        for(int i = 0; i < n; ++i) {
            if(robot[i] == 0) {
                int duration = abs(a[0][o] - cPos[0]) + 1;
                if(bb != 0) {
                    int distance = a[1][b] - cPos[1];
                    int duration_t = abs(distance) + 1;
                    for(int j = 0; j < duration; ++j) {
                        if(duration_t > 1) {
                            duration_t -= 1;
                            if(distance > 0)
                                cPos[1] += 1;
                            else if(distance < 0)
                                cPos[1] -= 1;
                        }
                        timeSum += 1;
                    }
                }
                else
                    timeSum += duration;
                cPos[0] = a[0][o];
                ++o;
                --oo;
            }
            else {
                int duration = abs(a[1][b] - cPos[1]) + 1;
                if(oo != 0) {
                    int distance = a[0][o] - cPos[0];
                    int duration_t = abs(distance) + 1;
                    for(int j = 0; j < duration; ++j) {
                        if(duration_t > 1) {
                            duration_t -= 1;
                            if(distance > 0)
                                cPos[0] += 1;
                            else if(distance < 0)
                                cPos[0] -= 1;
                        }
                        timeSum += 1;
                    }
                }
                else
                    timeSum += duration;
                cPos[1] = a[1][b];
                ++b;
                --bb;
            }    
                
            //    op = a[0][o];
            //    
            //    if(i != n-1 && bb != 0) {
            //    if(duration - abs(a[1][b] - cPos[1]) < 0) {
            //        if(a[1][b] - cPos[1] > 0)
            //            cPos[1] += duration;
            //        else if(a[1][b] - cPos[1] < 0)
            //            cPos[1] -= duration;
            //        //timeSum -= duration;
            //    }
            //    else {
            //        timeSum -= abs(a[1][b] - cPos[1]);
            //    }
            //    }
            //    timeSum += duration;
            //    cPos[0] = op;
            //    ++o;
            //    --oo;    
            //}
            //else {
            //    bp = a[1][b];
            //    int duration = abs(a[1][b] - cPos[1]) + 1;
            //    if(i != n-1 && oo != 0) {
            //    if(duration - abs(a[0][o] - cPos[0]) < 0) {
            //        if(a[0][o] - cPos[0] > 0)
            //            cPos[0] += duration;
            //        else if(a[0][o] - cPos[0] < 0)
            //            cPos[0] -= duration;
            //        //timeSum -= duration;
            //    }
            //    else {
            //        timeSum -= abs(a[0][o] - cPos[0]);
            //    }
            //    }
            //    timeSum += duration;
            //    cPos[1] = bp;
            //    ++b;
            //    --bb;
            //}
        }
        //cout << "Case #" << casenum << ": " << timeSum << endl;
        outfile << "Case #" << casenum << ": " << timeSum << endl;
        ++casenum;
    }
    infile.close();
    outfile.close();
    system("pause");
    return 0;
}