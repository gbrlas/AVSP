#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
    int t,i;
    double c,f,x,t1,t2,t0,t4;
    fstream fin,fout;
    fin.open("B-large.in", ios::in);
    fout.open("op.txt", ios::out);
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>c>>f>>x;
        t0=2;t2=t4=0;
        do
        {
            t1=t4+x/t0;
            t4+=c/t0;
            t2=t4+(x/(t0+f));
            t0+=f;

        }while(t1>t2);
        fout.setf(std::ios::fixed, std:: ios::floatfield );
        fout<<setprecision(7)<<"Case #"<<i<<": "<<t1<<'\n';
    }
    fin.close();
    fout.close();

    return 0;
}
