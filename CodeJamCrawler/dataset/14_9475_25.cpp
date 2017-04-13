#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int t;
    fin >> t;
     if (! fin.good()) {
        cout << " problem with input file" << endl;
        return -1;
    }
    for (int ncase = 0; ncase < t; ncase++) {
        double c, f, x;
        fin >> c >> f >> x;
        double cprod = 2;
        double mintime = x / 2;
        double invtime = 0;
        double remtime;
        bool searchon = true;
        do {
            double cpftime = c / cprod;
            cprod += f;
            remtime = x / cprod;
            invtime += cpftime;
            cout << "C " << ncase + 1 << " buy at " << invtime << endl;

            if (mintime > (invtime + remtime)) {
                mintime = invtime + remtime;
            }
            else {
                cout << "not because " << mintime << " better than " << invtime + remtime << endl;
                searchon = false;
            }
        } while(searchon);
        fout.setf(ios::fixed, ios::floatfield);
        fout << "Case #" << ncase + 1 << ": " << setprecision(7) << mintime << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
