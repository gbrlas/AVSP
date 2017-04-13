//Problem Bulls Eye

#include<iostream>
#include<string>
#include<fstream> 
#include<stdio.h>
#include<cmath>


using namespace std; 

int main()
{
	string line;
    int numberoftc;
	ifstream myfile("C:\\Users\\Shrumang\\downloads\\a.in");
	ofstream myfileoutput("c:\\users\\shrumang\\downloads\\output.in");
	if(myfile.is_open())
	{
		myfile>>numberoftc;
		cout<<"Number of testcases"<<numberoftc<<"\n";
		long double rangeofnumber[numberoftc*2]; 
		long int i = 1;	
		long int j = 1; 	
		while(myfile.good()|| j<=numberoftc)
		{
			myfile>>rangeofnumber[i];
			myfile>>rangeofnumber[i+1];
			long double initial_radius = rangeofnumber[i];
			long double final_quantity = rangeofnumber[i+1];
			long double calculated_quantity = 0;
			long long number_of_rings = 0; 
			calculated_quantity = pow(initial_radius + 1,2) - pow(initial_radius,2);
			while(calculated_quantity <= final_quantity)
			{	
				number_of_rings++;
				final_quantity = final_quantity - calculated_quantity;
				calculated_quantity = calculated_quantity + 4.0 ; 	
			}
			myfileoutput<<"Case #"<<j<<": "<<number_of_rings<<"\n";
            i=i+2;
            j=j+1;
		}
		myfile.close();
		myfileoutput.close();
    }
} 
