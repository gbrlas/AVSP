#include <iostream>
#include <fstream>

#include <string>
#include <map>

#define SSIZE 110
#define QSIZE 1100

using namespace std;

typedef map<string, int> ServerMap;

int main(int argc, char * argv[])
{
	int CountSwitch[SSIZE][QSIZE];
	int testN, testi;
	ifstream input(argv[1]);
	
	input >> testN;
	for(testi=0; testi<testN; testi++)
	{		
		//for each case
		ServerMap sm;
		int SN, QN;
		int i,j;
		
		input >> SN;

		string tmp;
		getline(input, tmp);
		for(i=0; i<SN; i++)
		{
			getline(input, tmp);
			sm[tmp] = i; 
		}
		
		//initial
		for(i=0; i<SN; i++)
				  CountSwitch[i][0]=0;
		
		input >> QN;
		getline(input, tmp); //ignore \n

		for(j=1; j<=QN; j++)
		{
			string query;
			getline(input, query);
			int server = sm[query];
			
			for(int si=0; si<SN; si++)
			{
				
				if(si!=server)
				{
					if(CountSwitch[server][j-1] + 1 < CountSwitch[si][j-1])	 //switch to si
						CountSwitch[si][j] = CountSwitch[server][j-1] + 1;
					else
						CountSwitch[si][j] = CountSwitch[si][j-1];
				}
			}
			
			CountSwitch[server][j] = CountSwitch[server][j-1]+2;	//self switch
		}		  
		
		int minSwitch = CountSwitch[0][QN];
		for(i=1; i<SN; i++)
			if(CountSwitch[i][QN] < minSwitch)
				minSwitch = CountSwitch[i][QN];
		
		cout << "Case #" <<testi+1 <<": " << minSwitch << endl;
	}/*test N*/
	
	return 0;
}