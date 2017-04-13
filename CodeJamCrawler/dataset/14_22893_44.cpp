#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;


    ifstream fin("B-small-attempt0.in");
    FILE* output = fopen("output.txt", "w");
    fin >> T;
    for (int t = 1; t <= T; t++) {
        double time = 0;
        double C, F, X;

        fin >> C >> F >> X;

        double cps = 2;

        while (X/cps - X/(cps + F) > C/cps ) {
            time += C/cps;
            cps += F;
        }
        time += X/cps;


        fprintf(output, "Case #%d: %.7lf\n",t,time);
        fprintf(stdout, "Case #%d: %.7lf\n",t,time);



    }

    fin.close();


    return 0;
}
