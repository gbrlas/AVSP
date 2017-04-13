#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
    ifstream in;
    in.open("in.in");
    int t; in >> t;

    ofstream out;
    out.open("output.out");
    out << setiosflags(ios::fixed) << setprecision(7);

    for(int k = 0; k < t; ++k)
    {
        double c, f, x; in >> c >> f >> x;
        out << setprecision(7);

        double cookiesPerSec = 2;
        double timeLapsed = c/cookiesPerSec;


        while(true)
        {
            if((x - c)/cookiesPerSec > x/(cookiesPerSec + f))
            {
                cookiesPerSec += f;
                timeLapsed += c/cookiesPerSec;
            }
            else
                break;

        }
        timeLapsed+=(x - c)/cookiesPerSec;
        out << "Case #" << (k+1) << ": " << timeLapsed << endl;

    }
    return 0;
}



