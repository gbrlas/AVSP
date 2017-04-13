#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	double C , F , X , time = 0;
	int i , counter = 0 , n , j , k;
	vector <double> T;
	std::fstream mydata("D:\\B-small-attempt2.in", std::ios_base::in);
	ofstream myfile ("Output.txt");
	mydata >> n;
	for(j = 1 ; j <= n ; j++)
	{
		mydata >> C >> F >> X;
		for(k = 0 ; k < X ; k++)
		{
			i = 0;
			time = 0;
			while(i <= counter)
			{
				if(i == counter) time+=(X / (2+(counter*F)));
				else time+=(C / (2+(i*F)));
				i++;
			}
			T.push_back(time);
			counter++;
		}
		sort(T.begin() , T.end());
		myfile << "Case #" << j << ": " << fixed << setprecision(7) << T[0] << "\n";
		counter = 0;
		T.clear();
	}
	return 0;
}
