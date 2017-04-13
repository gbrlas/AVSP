#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin("in2.txt");
    ofstream cout("out2.txt");

    unsigned long long t, n, ncase, a, min, sum, yh;

    cin>>ncase;
    for (unsigned long long nc=1; nc<=ncase; nc++)
    {
        cin>>n;
        yh = 0;
        sum = 0;
        min = 1<<31;
        while (n--)
        {
            cin>>a;
            yh ^= a;
            sum += a;
            if (a < min) min = a;
        }
        cout<<"Case #"<<nc<<": ";
        if (!yh)
            cout<<sum-min<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
