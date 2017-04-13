#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int main()
{
	
	ifstream ifs("Input.txt");
    cin.rdbuf(ifs.rdbuf());
    ofstream ofs("Output.txt");
    cout.rdbuf(ofs.rdbuf());
	
	int T, n;
	double c,f,x,d, time=0.0;
	//double speed = 2.0;
    cin >> T;
	for (int i=0; i<T; i++)
	{
		cin >>	c >> f >> x;
		/*
		while ((x-c)/speed > x/(speed+f))
		{
			time += c/speed;
			speed += f;
		}
		time += x/speed;
		*/
		d = (f*(x-c)-2*c)/f/c;
		n = d;
		if (d>n)
			n++;
		if (n<0)
			n = 0;
		for (int j=0; j<n; j++)
			time += c/(2+j*f);
		time += x/(2+n*f);
		cout << "Case #" << i+1 << ": ";
		cout << fixed << setprecision(8) << time <<endl;

		time = 0.0;
	}
 
    ifs.close();
    ofs.close();
	
	return 0;
}