#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

void WriteOutput(int ostring);

vector<string>::iterator 
loop;
ifstream input("input.txt");
ofstream output("output.txt");

void main()
{
	string istring;

	int tc = 0,servers = 0, ask = 0,switches = 0;
	input >> istring;
    tc = atoi(istring.c_str());

	for(int i=0; i<tc; i++)
	{
		vector<string> servlist;
		input >> istring;
		servers = atoi(istring.c_str());
	
		for(int j=0; j<servers; j++)
		{
			input >> istring;
			servlist.push_back(istring);
		}
		
		input >> istring;
		ask = atoi(istring.c_str());
		if (ask == 0)
		{
			switches = 0;
			WriteOutput(switches);
			continue;
		}

		vector<string> tempserv;
		tempserv = servlist;
		int tmpsrvcnt = servers;
        switches = 0;

		for(j=0; j<ask; j++)
		{
			input >> istring;
	
		    loop = tempserv.begin();
			for(int k=0; k<tmpsrvcnt; k++,loop++)
			{
				if(tempserv[k] == istring)
				{
					tempserv.erase(loop);
					tmpsrvcnt--;
					break;
				}
			}

			if (tmpsrvcnt == 0)
			{
				switches++;
				tempserv = servlist;
		        int k=0;
		        loop = tempserv.begin();
		        while(1)
				{
					if(tempserv[k] == istring)
					{
						tempserv.erase(loop);
                        tmpsrvcnt = servers - 1;
						break;
					}
    			k++;
				loop++;
				}
			}
		}
		WriteOutput(switches);
	}
}

void WriteOutput(int ostring)
{
	static int i=1;

	output << "Case #"<<i<<": ";
	output << ostring << "\n";
	i++;
}


	



