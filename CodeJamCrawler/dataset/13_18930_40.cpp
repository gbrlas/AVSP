//Problem C Fair Square

#include<iostream>
#include<string>
#include<fstream> 
#include<stdio.h>
#include<cmath>


using namespace std; 
int palindrome(float num);

int main()
{
	string line;
    int numberoftc;
	ifstream myfile("C:\\Users\\Shrumang\\Downloads\\a.in");
	ofstream myfileoutput("c:\\users\\shrumang\\downloads\\output.in");

	if(myfile.is_open())
	{
		myfile>>numberoftc;
		int rangeofnumber[numberoftc*2];
		char ch; 
		int i = 1;		
		while(myfile.good())
		{
			myfile>>rangeofnumber[i];
			myfile>>rangeofnumber[i+1];
			i=i+2;
		}
		
		for(int count = 1,j=1; count <= numberoftc,j<numberoftc*2; count++,j=j+2)
		{
			int counter = 0;
			for(float palin_no = rangeofnumber[j]; palin_no <= rangeofnumber[j+1]; palin_no++)
			{
				
				int result = palindrome(palin_no);
				if(result)
				{
					if (!(sqrt(palin_no)-floor(sqrt(palin_no))))
					{
						int result2 = palindrome((sqrt(palin_no)));
						if(result2)
						{
							counter++;
						}
					}
				}
				
			
			}
			myfileoutput<<"Case #"<<count<<": "<<counter<<"\n"; 
			
		}
		myfile.close(); 
		myfileoutput.close();
	}
	else 
		cout<<"File not found"<<"\n";
	
	return 0; 	
}
	
int palindrome(float palin_no)
{
				
	int sum=0;
	int r;
    int temp = palin_no;
	while(temp)
	{
			r=temp%10;
			temp = temp/10;
			sum = sum*10 + r;
	}			
	if(sum==palin_no)
	{		
		return 1; 
	}				
	else
	{
		return 0;
	}
				
} 
