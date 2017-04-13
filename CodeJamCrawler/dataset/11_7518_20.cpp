#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

long long gcd(long long a, long long b)
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
        long long N, PD, PG;
        in >> N >> PD >> PG;


        long long common_d = gcd(PD, 100);
        long long common_g = gcd(PD, 100);

        long long base_d = PD/common_d;
        long long base_g = PG/common_g;

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
