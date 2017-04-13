//Problem B. Cookie Clicker.

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


int main() {
	int t;
	cin >> t;
	//Observations: it never makes sense to "hoard" cookies.
	for(int ii = 1; ii <= t; ii++)
	{
		double farmcost, farmroi, goal;
		cin >> farmcost >> farmroi >> goal;
		if (farmcost >= goal)
		{
			cout << "Case #" << ii << ": ";
			printf("%8.8f",goal/2);
			cout << endl;
		}
		else
		{
			int optimalfarms = ((goal - farmcost)/(farmcost)*farmroi - 2)/(farmroi)+1;
			
			double totaltime = 0;
			for(int jj = 0; jj < optimalfarms; jj++)
			{
				totaltime += farmcost/(2.0+jj*farmroi);
			}
			totaltime += (goal)/(2.0+optimalfarms*farmroi);
		
			cout << "Case #" << ii << ": ";
			printf("%8.8f",totaltime);
			cout << endl;
		}
	}
	
	
	
	return 0;
}