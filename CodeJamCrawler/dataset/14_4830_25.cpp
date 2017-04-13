#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;
int main()
{

    ifstream filin;

    ofstream fout;


    filin.open("ip.in");
    fout.open("ans1.txt");


int cases;
    filin>>cases;


    for(int a =1;a<=cases;++a)
    {
        double C,F,X;

        filin>>C>>F>>X;

     double t = 0.0 , r = 2.0, curr = 0;


        while((X/r)>((C/r)+(X)/(r+F)))
        {
      //      printf("%f ", r);
            t = t + (C/r);
            r = r + F;



        }

        t = t + X/r;
        fout.precision(7);
        fout.setf(ios::fixed);
        fout.setf(ios::showpoint);

        fout<<"Case #"<<a<<": ";
        fout<<t<<endl;
    }



}

