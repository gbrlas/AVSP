#include <iostream>
#include <istream>
#include <fstream>
using namespace std;
int main()
{
    ifstream reader("input.txt");
	ofstream writer("output.txt");
    int T;
    double C, F, X, time, temp1, temp2, cookieVal;
    bool goOn;
    reader >> T;
    for(int i = 0; i < T; i++) {
        reader >> C >> F >> X;
        time = 0;
        cookieVal = 2;
        goOn = true;
        while(goOn) {
            temp1 = X/cookieVal + time;
            temp2 = C/cookieVal + X/(cookieVal + F) + time;
            if(temp2 < temp1) {
                time += C/cookieVal;
                cookieVal += F;
            }
            else {
                time = temp1;
                goOn = false;
            }
        }
        writer.precision(7);
        writer.setf(ios::fixed, ios::floatfield);
        writer << "Case #" << i + 1 << ": " << time << endl;
    }
    return 0;
}
