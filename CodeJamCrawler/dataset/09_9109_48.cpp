#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main ()
{
	ifstream fin("B.in");
	ofstream fout("B.out");

	int T;
	fin >> T;
	
	for (int t=1; t<=T; t++)
	{
		fout << "Case #" << t << ": ";
		cout << "Case #" << t << ": ";
		
		int x=0, y=0, z=0, vx=0, vy=0, vz=0;
		int tx, ty, tz, tvx, tvy, tvz;
		int n;
		fin >> n;
		for (int i=0; i<n; i++)
		{
			fin >> tx >> ty >> tz >> tvx >> tvy >> tvz;
			x += tx;
			y += ty;
			z += tz;
			vx += tvx;
			vy += tvy;
			vz += tvz;
		}
		//cout << x << " " << y << " " << z << endl;
		//cout << vx << " " << vy << " " << vz << endl;
		double mint;
		if ((vx*vx+vy*vy+vz*vz)==0)
		{
			mint = 0;
		} else {
			mint = - (double(vx*x+vy*y+vz*z)/(vx*vx+vy*vy+vz*vz));
		}
		if (mint<0) mint = 0;
		double mind = sqrt((x+vx*mint)*(x+vx*mint)+(y+vy*mint)*(y+vy*mint)+(z+vz*mint)*(z+vz*mint));
		cout << fixed << setprecision(8) << mind/n << " ";
		cout << fixed << setprecision(8) << mint << endl;
		fout << fixed << setprecision(8) << mind/n << " ";
		fout << fixed << setprecision(8) << mint << endl;
	}

	fout.close();
	cin.get();
	return 0;
}
