#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{

    ifstream be;
    be.open("B-large.in");
    ofstream ki;
    ki.open("B.txt");
    int T;
    be >>T;
    for(int t=1;t<=T;t++)
    {
        long double get1=2.0;
        long double farm,get,goal;
        be >> farm>>get>>goal;
        ki <<"Case #"<<t <<": ";
        if (farm>=goal)
        {
            ki << fixed;
            ki <<setprecision(7)<< goal/2.0 <<endl;
        }
        else
        {
            long double time=0;
            //cout << goal/get << " " <<farm/get+goal/(get+farm) <<endl;
            while(goal/get1>=farm/get1+goal/(get1+get))
            {
                time+=(farm/get1);
                get1+=get;
            }
            time+=goal/get1;
            ki << fixed;
            ki <<setprecision(7)<<time <<endl;
        }
    }
    be.close();
    ki.close();
    return 0;
}
//CodeBlocks 13.12,Win8.1
