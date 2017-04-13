// p1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, _TCHAR* argv[])
{
	int i;
    int t;
    int n;
    int k;
    int p;
    bool ans=false;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>t;
    for (i=0; i<t; i++) {
        ans=false;
        fin>>n;
        fin>>k;
        p=1;
        p=(p<<n);
        if (k==0) {
                  ans=false;
        }
        else {
             k=(k % (p));
             if (k==(p-1)) ans=true;
        }
        fout<<"Case #"<<(i+1)<<": ";
        if (ans) fout<<"ON\n";
           else fout<<"OFF\n";
    }
    system("pause");
    fout.close();
    fin.close();
	return 0;
}

