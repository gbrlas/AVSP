#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
	{
	int line_number=1,z=0,inp,normal=0,deceitful=0,i,j,k,l,p=1;
	ifstream file;
	string line;
	double *a,*b;
	file.open("D-large.txt");
	getline(file, line);

	while ( getline(file, line) ) 
		{
		std::stringstream stream(line);
		double tmp;

		z=0;
		if(line_number==1)
			{  stream>>inp;
		       a=new double[inp];
			   b=new double[inp];
			}
		else if(line_number==2)
			{  z=0;
			while (stream>>tmp  ) 
				{
				a[z]=tmp;
				z++;
				}
			}
		else
			{  z=0;
			while (stream>>tmp  ) 
			{
				b[z]=tmp;
				z++;
			}
			}
		line_number++;
		if(line_number==4)
			{
			sort(a,a+inp);
			sort(b,b+inp);
			 i=0;
			 j=inp-1;
			 k=0;
			 l=inp-1;
			 normal=0;
			 deceitful=0;
			 while(i<=j&&k<=l)
				 {
				   if(a[j]>b[l])
					   {
					     normal++;
						 j--;
						 k++;
					   }
				   else 
					   {
					   j--;
					   l--;
					   }
				   
				   
				 }
			 i=0;
			 j=inp-1;
			 k=0;
			 l=inp-1;
			 while(i<=j&&k<=l)
				 {
				 if(a[i]>b[k])
					 {
					 deceitful++;
					 i++;
					 k++;
					 }
				 else 
					 {
					 i++;
					 l--;
					 }


				 }
			
			cout<<"Case #"<<p<<": "<<deceitful<<" "<<normal<<"\n";
			p=p+1;
			   line_number=1;
			}
		}
		getchar();
		
	}

		


		