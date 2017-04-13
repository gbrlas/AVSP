#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string line;
int bases[10];
int happy[11][20000000];//0 undef 1 nu 2 da 3 processing

bool ishappy(int num,int base) {
    if (num>20000000)
        cerr<<"out of range"<<num<<endl;
    if (num == 1)
        return true;
    if (happy[base][num] == 3)
        return false;
    if (happy[base][num] == 2)
        return true;
    if (happy[base][num] == 1)
        return false;
    happy[base][num] = 3;
    int newnum = 0;
    int anum =num;
    while (anum>0) {
        newnum += (anum%base)*(anum%base);
        anum/=base;
    }
    bool bhappy = ishappy(newnum,base);
    if (bhappy)
        happy[base][num] = 2;
    else
        happy[base][num] = 1;
    //cout<<"ih "<<num<<" "<<base<<" "<<bhappy<<endl;
    return bhappy;
}

int t,nb;

int main()
{
    ifstream fin("mbh.in");
    ofstream fout("mbh.out");

    fin>>t>>ws;
    for (int ncase=0; ncase<t; ncase++) {
        getline(fin,line);
        cout<<"fggdfgd"<<endl;
        cout<<"lineeeieeeeeeeee="<<line<<endl;
        istringstream sin(line);
        int nb=0;
        while (!sin.eof()) {
            sin>>bases[nb]>>ws;
            cout<<bases[nb]<<" ";
            nb++;
        }
        cout<<endl;
        int num=1;
        bool happy = false;
        while (!happy) {
            num++;
            happy = true;
            //cout<<"t="<<num<<endl;
            for (int i=0; i<nb; i++)
                happy &= ishappy(num,bases[i]);
        }
        fout<<"Case #"<<ncase+1<<": "<<num<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}

