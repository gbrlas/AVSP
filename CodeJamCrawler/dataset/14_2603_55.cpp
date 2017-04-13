#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#define fr(i,n)	for(int i=0;i<n;i++)
using namespace std;
int main()
{
		int a[4][4],b[4][4],count=0,val=0,p=1,ans1,ans2,line_number=1;
		ifstream file;
	     string line;
		 int z=0;
		file.open("A-small-attempt3.txt");
		getline(file, line)	 ;
		
		while ( getline(file, line) ) // reads whole lines until no more lines available
			{
			std::stringstream stream(line);
			int tmp;
			
			z=0;
			if(line_number==1)
				{  stream>>ans1;
				}
			else if(line_number>=2&&line_number<=5)
				{
				  while (stream>>tmp  ) 
					{
						a[line_number-2][z]=tmp;
						z++;
					}
				}
				else if(line_number==6)
					{
					   stream>>ans2;
					}
				else
					{

					
					while (stream>>tmp  ) 
						{
						b[line_number-7][z]=tmp;
						z++;
						}
					}
			++line_number;
			if(line_number==11)
				{

			
		
			 count=0;
			 fr(i,4)
			 {
				fr(j,4)
				{
					if(a[ans1-1][i]==b[ans2-1][j])
					{
						val= a[ans1-1][i];
						count++;
					}
			    }
		   }
		   if(count==0)
		   {
				cout<<"Case #"<<p<<": "<<"Volunteer cheated!"<<"\n";
		   }
		   else if(count==1)
		   {
				cout<<"Case #"<<p<<": "<<val<<"\n";
		   }
		   else
				cout<<"Case #"<<p<<": "<<"Bad magician!"<<"\n";
		   p++;
		   line_number=1;
		 }
	  
		   
	
			}
		 getchar();
}