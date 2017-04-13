#include <fstream>
#include <string>

using namespace std;

#define NMAX 31

int n,k;

int main()
{
    ifstream f("a.in");
    ofstream f2("a.out");
    int T;
    f>>T;
    for(int tt=1; tt<=T; ++tt)
    {
        long long n,k;
        f>>n>>k;
        f2<<"Case #"<<tt<<": ";
        if(k%(1<<n)==((1<<n)-1)) f2<<"ON\n";
        else f2<<"OFF\n";
    }

    return 0;
}
