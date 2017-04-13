#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {


    int m;
    ifstream in(argv[1]);
    ofstream output("b.output");

    in >> m;
    for (int i = 0; i < m; ++i) {
        int N;
        in >> N;
        
        int sum = 0;
        int min = 10000000;
        int ret = 0;
        for (int j = 0; j < N; ++j) {
            int num;
            in >> num;
            ret = ret^num;
            sum += num;
            if (num < min)
                min = num;
        }

        if (ret == 0)
            output << "Case #" << i+1 << ": " << sum-min<< endl;
        else
            output << "Case #" << i+1 << ": NO"  << endl;



    
    }


    return 1;

}
