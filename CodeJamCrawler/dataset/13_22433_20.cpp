#include<iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
char won='n';

int match(string pat)
{
	if( (pat.compare(0,4,"XXXX") == 0) ||
		(pat.compare(0,4,"TXXX") == 0) ||
		(pat.compare(0,4,"XTXX") == 0) ||
		(pat.compare(0,4,"XXTX") == 0) ||
		(pat.compare(0,4,"XXXT") == 0) 
	   )
	   { won='X'; return 1; }
	else 
	if( (pat.compare(0,4,"OOOO") == 0) ||
		(pat.compare(0,4,"TOOO") == 0) ||
		(pat.compare(0,4,"OTOO") == 0) ||
		(pat.compare(0,4,"OOTO") == 0) ||
		(pat.compare(0,4,"OOOT") == 0) 
	   ) 
	   { won='O'; return 1; }
	return 0;
}
	
int main()
{
	ifstream in("A-small-attempt2.in");
	ofstream out ("res_chico.txt");

	char m[4][4];
	int T;
	in>>T;
	
	for(int x=1; x<=T; x++)
	{
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				in>>m[i][j];
		won='n';
		stringstream ss;
		string patron;
		ss << m[0][0]<<m[1][1]<<m[2][2]<<m[3][3];
		ss >> patron;
		if(!match(patron))
		{
			stringstream ss;
			string patron;
			ss << m[0][3]<<m[1][2]<<m[2][1]<<m[3][0];
			ss >> patron;
			if(!match(patron))
			{
				for(int i=0; i<4; i++)
				{
					stringstream ss;
					string patron;
					ss << m[i][0]<<m[i][1]<<m[i][2]<<m[i][3];
					ss >> patron;
					if(match(patron))break;//{ cout<<"fila "<<i<<": "<<won<<endl; break; }
					
					stringstream ss1;
					string patron1;
					ss1 << m[0][i]<<m[1][i]<<m[2][i]<<m[3][i];
					ss1 >> patron1;
					if(match(patron1))break;//{ cout<<"columna "<<i<<": "<<won<<endl; break; }
				}
			}
		}
		//cout<<won<<endl;
		if(won=='n' && m[3][3]!='.') out<<"Case #"<<x<<": Draw"<<endl;		
		else if(won=='n' && m[3][3]=='.') out<<"Case #"<<x<<": Game has not completed"<<endl;
		else out<<"Case #"<<x<<": "<<won<<" won"<<endl;			
		
	}
	out.close();
	return 0;
}


