//Problem Cookie clicker alpha


#include<iostream>
#include<string>
#include<fstream> 
#include<stdio.h>
#include<cmath>
#include<iomanip>



using namespace std; 

int main()
{
	
    int numberoftc;
	ifstream myfile("C:\\Users\\Shrumang\\downloads\\a.in");
	ofstream myfileoutput("c:\\users\\shrumang\\downloads\\output.in");
	if(myfile.is_open())
	{
		myfile>>numberoftc; 
		int test_case_no =1,total=0; 
			
		
		while(myfile.good() && test_case_no<=numberoftc)
		{
			double C,F,X;
			double T = 0.0,T2 = 0.0,T3 = 0.0,rate = 2.0;
			
			myfile>>C;
			myfile>>F;
			myfile>>X;
			
			
			
			if(C>X)
			{
				T2 = X/rate;
				myfileoutput<<"Case #"<<test_case_no<<": "<<std::setprecision(20)<<showpoint<<T2<<"\n";
				
			}
			else
			{
				do
				{
					T2 = T + X/rate;
					T = T + C/rate;
					rate = rate + F;
					T3 = T + X/rate;
					
				}
				while(T2>T3);
				
				myfileoutput<<"Case #"<<test_case_no<<": "<<std::setprecision(20)<<showpoint<<T2<<"\n";
			}
				
			test_case_no +=1;
		}
		myfile.close();
		myfileoutput.close();
    }
    return 0; 
} 

