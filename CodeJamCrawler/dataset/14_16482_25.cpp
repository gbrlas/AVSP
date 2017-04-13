#include<fstream>
#include<iostream>
#include <iomanip>
using namespace std;

main()
{
	int t, ti, k, j;
	long double c, f, x, s, d, i, q;
	
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	in>>t;
	
	for(ti=0; ti<t; ti++)
	{
		in>>c>>f>>x;
		
		i=2;
		d=0;
		j=0;
		s=0;
		
		while(d<x)
		{
			d=d+i;
			//s++;
			
			if(d>=c)
			
				if((x-c)/i>(x/(i+f)))
					{
						//if(d>c)
							//q=q+(d-c)/i;
							
						d=0;
						i=i+f;
						j++;
					}	
		}
		
		for(k=0; k<j; k++)
			s=s+c/(2+k*f);
		
		s=s+x/(2+j*f);//-q
		
		out.precision(7);
		out<<"Case #"<<ti+1<<": ";
		out<<fixed<<s<<"\n";
		
	}
	
in.close();
out.close();	
	
cin.get();
}
