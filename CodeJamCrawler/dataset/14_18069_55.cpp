#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
main()
{
    ofstream outputfile("outcookie.txt");
    int counter=1,t;
    double time=0,d=2,c,f,x;
    cin>>t;

    while(counter!=(t+1))
    {
        time=0;
        d=2;
        cin>>c>>f>>x;
        while(1)
        {
            if(x/d>(x/(d+f)+c/d))
            {
                time=time+c/d;
                d=d+f;
            }
            else
            {
                time=time+x/d;
                break;
            }
        }
        outputfile<<std::setprecision(10)<<"case #"<<counter<<": "<<time<<endl;
        counter++;
    }
}
