#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int compare (const void * x, const void * y);

int main() {
    ifstream in;
    ofstream out;

    in.open("input.txt");
    out.open("output.txt");

    int F;
    in >> F;
    for (int ind = 0; ind< F; ind++) {
        int OO , S , L;
        in >> OO >> S >> L;

        int * Z = new int[OO];

        for (int var = 0; var < OO; ++var) {
            in >> Z[var];
            }

        for (int v = 0; v < OO; ++v) {
            cout<< Z[v]<<" ";
            }

        int count = 0;
        for (int i = 0; i < OO; ++i) {
            if((Z[i]< (L*3 - 4)) || (Z[i]==0 && L>0)) {
                break;
                }
            if((Z[i]< (L*3 - 2))) {
                S--;
                count++;
                }
            if(Z[i] > (L*3 -3)) count++;
            }
        out<<"Case #"<<ind+1<<": " <<count << endl;
        }

    return 0;
    }

int compare (const void * x, const void * y) {
    return ( *(int*)y - *(int*)x );
    }
