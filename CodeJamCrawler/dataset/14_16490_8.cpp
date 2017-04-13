#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<iostream>

using namespace std;

int main()
{
	int t, i, j, k, a, b, p, alfa, beta, m;
	
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	in>>t;
	int v[1001];
	
	for(i=0; i<t; i++)
	{
		in>>a>>b>>k;
		
		p=0;
		
		for(alfa=0; alfa<a; alfa++)
		{
			for(beta=0; beta<b; beta++)
			{
				v[beta]=alfa&beta;
			}
			
			for(j=0; j<k; j++)
				for(m=0; m<beta; m++)
				{
					if(j==v[m])
						p++;
				}	
		}
		
		out<<"Case #"<<i+1<<": "<<p<<"\n";
	}
	
	in.close();
	out.close();
	
 system("PAUSE");
}
