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

	int n, r1, r2, i, j;
	int c1[4], c2[4], ct[4][4];
	double t, c, f, x, v;
	in >> n;
	int p,h;

	for(int it=1;it<=n;it++){
		out << "Case #" << it <<": ";
		p = 0;
		in >> r1;
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				in >> ct[i][j];
				if (i == r1 - 1){
					c1[j] = ct[i][j];
				}
			}
		}
		in >> r2;
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				in >> ct[i][j];
				if (i == r2 - 1){
					c2[j] = ct[i][j];
				}
			}
		}
		for (i = 0; i < 4; i++){
			cout << c1[i] << " ";
		}
		cout << endl;
		for (i = 0; i < 4; i++){
			cout << c2[i] << " ";
		}
		cout << endl;
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++){
				if (c1[i] == c2[j]){
					h = c1[i];
					p++;
				}
			}
		}
		if (p == 0)
			out << "Volunteer cheated!" << endl;
		if (p == 1)
			out << h << endl;
		if (p > 1)
			out << "Bad magician!" << endl;

	}
	system("pause");
}
