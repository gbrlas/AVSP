#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cmath>
#include<vector>
using namespace std;

void createoutput(int ostring);

vector<string>::iterator iter;
ifstream input("input.txt");
ofstream output("output.txt");

void main()
{
	string istring;

	int casecount = 0;
	int servercount = 0;
	int quariecount = 0;
	int switchcount = 0;
	// read no of cases
	input >> istring;
    casecount = atoi(istring.c_str());

	for(int i=0; i<casecount; i++)
	{
		vector<string> servlist;
		input >> istring;
		servercount = atoi(istring.c_str());
		//read servers
		for(int j=0; j<servercount; j++)
		{
			input >> istring;
			servlist.push_back(istring);
		}
		
		input >> istring;
		quariecount = atoi(istring.c_str());
		if (quariecount == 0)
		{
			switchcount = 0;
			createoutput(switchcount);
			continue;
		}
		//read and process quaries
		input >> istring;
		vector<string> tempserv;
		tempserv = servlist;

		iter = tempserv.begin();
		int j = 0;
		while(1)
		{
			if(tempserv[j] == istring)
			{
				tempserv.erase(iter);
                break;
			}
			j++;
			iter++;
		}
		int tmpsrvcnt = servercount - 1;
        switchcount = 0;
		for(int j=0; j<quariecount-1; j++)
		{
			input >> istring;
			// check in temp serverlist

		    iter = tempserv.begin();
			for(int k=0; k<tmpsrvcnt; k++,iter++)
			{
				if(tempserv[k] == istring)
				{
					tempserv.erase(iter);
					tmpsrvcnt--;
					break;
				}
			}

			if (tmpsrvcnt == 0)
			{
				switchcount++;
				tempserv = servlist;
		        int k=0;
		        iter = tempserv.begin();
		        while(1)
				{
					if(tempserv[k] == istring)
					{
						tempserv.erase(iter);
                        tmpsrvcnt = servercount - 1;
						break;
					}
    			k++;
				iter++;
				}
			}
		}
		createoutput(switchcount);
	}
}

void createoutput(int ostring)
{
	static int i=1;

	output << "case #"<<i<<": ";
	output << ostring << "\n";
	i++;
}


	



