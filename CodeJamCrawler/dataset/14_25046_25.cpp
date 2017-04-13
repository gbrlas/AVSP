#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  

using namespace std;

int main(){
	ofstream out;
	out.open("magout.txt", ios::out);
	ifstream in;
	in.open("magin.txt", ios::in);

	int n;
	double t, c, f, x, v;
	in >> n;
	for(int it=1;it<=n;it++){
		in >> c >> f >> x;
		t = 0;
		v = 2;
	zac:
		//cout << (x) / (double)v <<" "<< (double)c / v + (double)x / (v + f)<<endl;
		if ((x) / (double)v < (double)c/v + (double)x / (v + f)){
			t += (x) / (double)v;
			out << setprecision(10) << "Case #" << it << ": " << t<<endl; 
			continue;
		}
		else{
			t += (double)c / v;
			v += f;
			goto zac;
		}
	}
	system("pause");
}
