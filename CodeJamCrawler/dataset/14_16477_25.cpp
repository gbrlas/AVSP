#include<fstream>
#include<iostream>
using namespace std;

main()
{
	int t, n1, n2, i, j, ti, k, s;
	
	int m[4][4], mm[4][4];
	
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	
	in>>t;
	
	for(ti=0; ti<t; ti++)
	{
		in>>n1;
		
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				in>>m[i][j];
		
		in>>n2;
		
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				in>>mm[i][j];

	k=0;
	
	for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
				if(m[n1-1][i]==mm[n2-1][j])
				{
					k++;
					s=m[n1-1][i];
				}			
		}
		
	out<<"Case #"<<ti+1<<": ";
	
	if(k==1)
		out<<s<<"\n";	
	else if(k==0)
		out<<"Volunteer cheated!\n";	
	else
		out<<"Bad magician!\n";
	}
	
	in.close();
	out.close();
	
cin.get();
}
