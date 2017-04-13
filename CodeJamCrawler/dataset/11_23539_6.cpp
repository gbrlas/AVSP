#include <fstream>
using namespace std;

int gcd(int x, int y){
    if (!x || !y) return x > y ? x : y;
    for (int t; t = x % y; x = y, y = t);
    return y;
}

int main()
{
    ifstream infile("infile.txt");
    ofstream outfile("outfile.txt");
    int T;
    infile >> T;
    int t = 0;
    while (t < T)
    {
        t++;
        outfile << "Case #" << t << ": ";
        int N, D, G;
        infile >> N >> D >> G;
        if ((G == 0 &&  D != 0) || (G == 100 && D != 100))
        {
            outfile << "Broken" << endl;
            continue;
        }
        if (D == 0 || D == 100)
        {
            outfile << "Possible" << endl;
            continue;
        }
        int y = gcd(D, 100);
        y = 100 / y;
        if (N < y)
        {
            outfile << "Broken" << endl;
            continue;
        }
        outfile << "Possible" << endl;
    }
    return 0;
}