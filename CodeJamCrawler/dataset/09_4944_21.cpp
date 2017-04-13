#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int c;
int n;
int x[40];
int y[40];
int r[40];

double dist(double x1,double y1,double x2,double y2) {
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main()
{
    ifstream fin("plants.in");
    ofstream fout("plants.out");
    fout.precision(6);
    fout.setf(ios::fixed,ios::floatfield);
    fin>>c;
    for (int ncase=0; ncase<c; ncase++) {
        fin>>n;
        for (int i=0; i<n; i++) {
            fin>>x[i]>>y[i]>>r[i]>>ws;
        }
        if (n>3) {
            cout<<"error n="<<n<<endl;
        }
        double mansw = 100000;
        if (n == 3) {
            double answ = dist(x[0],y[0],x[1],y[1])+r[0]+r[1];
            if (r[2]>answ)
                answ = r[2];
            if (answ < mansw) {
                mansw = answ;
            }
            answ = dist(x[1],y[1],x[2],y[2])+r[1]+r[2];
            if (r[0]>answ)
                answ = r[0];
            if (answ < mansw) {
                mansw = answ;
            }
            answ = dist(x[0],y[0],x[2],y[2])+r[0]+r[2];
            if (r[1]>answ)
                answ = r[1];
            if (answ < mansw) {
                mansw = answ;
            }
            mansw = mansw/2;
        }
        if (n == 2) {
            mansw = r[0];
            if (r[1] > mansw)
                mansw = r[1];
        }
        if (n == 1) {
            mansw = r[0];
        }
        fout<<"Case #"<<ncase+1<<": "<<mansw<<endl;
    }
    fin.close();
    fout.close();

    return 0;
}
