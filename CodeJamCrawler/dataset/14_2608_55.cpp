#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main()
	{
		double c,f,x,final=0,cfinal=2;
		   double a[3];
			int line_number=0,z=0;
			ifstream file;
			string line;
		file.open("B-small-attempt0.in.txt");
		getline(file, line);
		line_number=1;
		while ( getline(file, line) ) 
			{
			final=0;
			
					
			std::stringstream stream(line);
			double tmp;

			z=0;
			cfinal=2;
			final=0;

				while (stream>>tmp  ) 
					{
					a[z]=tmp;
					z++;
					}
				
		         			
				  c=a[0];
				  f=a[1];
				  x=a[2];
				  
			while(final+x/cfinal > final + c/cfinal + x/(cfinal+f)  )
				{
				final+=c/cfinal;

				cfinal+=f;
				}
			printf("Case #%d: %.7f\n",line_number,final +x/cfinal);
			++line_number;
	}

getchar();

	}