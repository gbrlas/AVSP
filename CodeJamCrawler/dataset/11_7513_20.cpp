#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

int gcd(int a, int b)
{

    if(b == 0) 
    { 
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main(int argc, char* argv[]) {


    int m;
    ifstream in(argv[1]);
    ofstream output("a.output");

    in >> m;
    for (int i = 0; i < m; ++i) {
        int N, PD, PG;
        in >> N >> PD >> PG;


        int common_d = gcd(PD, 100);
        int common_g = gcd(PD, 100);

        int base_d = PD/common_d;
        int base_g = PG/common_g;

        bool ret = true;
        if (100/common_d > N)
            ret = false;

        if (PG==100 && PD!=100)
            ret = false;
        
        if (PG==0 && PD!=0)
            ret = false;

        if (ret)
            output << "Case #" << i+1 << ": " << "Possible" << endl;
        else
            output << "Case #" << i+1 << ": " << "Broken" << endl;


    
    }


    return 1;

}
