#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace  std;
int main()
	{
	unsigned int t,a,b,k,res=0,w;
	string s;
	int r[3];
	vector<string> v;
	ifstream file;
	string line;
	int z=0, line_number=0 ;
	file.open("A-small-attempt3.txt");
	getline(file, line)	 ;
	line_number=1;
	while ( getline(file, line) ) // reads whole lines until no more lines available
		{
		std::stringstream stream(line);
		int tmp;
		z=0;
		while (stream>>tmp  ) 
			{
			r[z]=tmp;
			z++;
			}
	
		res=0;
		a=r[0];
		b=r[1];
		k=r[2];
		for(unsigned int p=0;p<a;p++)
			{
			for(unsigned  int j=0;j<b;j++)
				{
				w=p & j;
				
				 if((w)< k)
					 {
						res++;
					 }
				}
			}
		cout<<"Case #"<<line_number<<": "<<res<<"\n";
		line_number++;
	   

		}
	getchar();
	}