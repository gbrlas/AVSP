
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include "Helper.h"

using namespace std;

int main(int argc, const char* argv[]){
	int counter = 1;
	string *filename;
	string line;
	vector<string> strvec;
	vector<string>::iterator svit;
	char color;
	ifstream file;
	double n,pd,pg,g,d,tmp;
	bool possible;

	if (argc>1)
	{
		filename = new string(argv[1]);
		file.open(argv[1]);
	}
	else
	{
		filename = new string("C:\\Users\\Lotonoro\\Documents\\Visual Studio 2010\\Projects\\GoogleCodeJam20110520\\input.txt");
		file.open(filename->c_str());
	}

	if (!file.is_open())
	{
		//cout<<"Error: cannot find file: "<< *filename << endl;
		return 1;
	}
	else
	{
		//cout<< "file found: " << *filename <<endl;
	}
	if (!file.eof())
	{
		getline(file,line);
		//cout<< line << " cases" <<endl;
	}
	while (!file.eof())
	{
		n=0;
		pg=0;
		pd=0;
		g=1;
		d=1;
		possible=false;
		tmp=0;
		getline(file,line);
		if (line == "") break;
		//cout<<"input line: "<<line<<endl;
		strvec.clear();
		split(line,' ',strvec);
		svit = strvec.begin();
		n=str_int(*svit);
		//cout<<"N="<<n<<endl;
		++svit;
		pd = str_int(*svit);
		++svit;
		pg = str_int(*svit);
		//cout<<"Pg="<<pg<<endl;
		//cout<<"Pd="<<pd<<endl;
		/*
		// calcs
		for(g=1; g>0; ++g)
		{
			if(fmod(tmp++,10000000)==0)
				cout<<"tmp="<<tmp<<endl;
			if( fmod(g * pg, 100.) != 0.)
				continue;
			for(d=1; (d<=n && d<=g); ++d)
			{
				if( fmod(d * pd , 100.) == 0.
					&& pg*g >= d*pd && pg*g <= d*pd +g*100 -d*100)
				{
					possible = true;
					break;
				}
			}
			if(possible)
				break;
		}
		*/
		for(d=1; d<=n ; ++d)
			{
				if(fmod(d * pd , 100.) == 0.)
				{
					if ( pd > 0 && pg==0) break;
					if ( pd < 100 && pg==100) break;
					possible = true;
					break;
				}
			}
		if(possible)
		{
			cout<<"Case #"<<counter<<": "<< "Possible"<<endl;
			//cout<<"g="<<g<<"\td="<<d<<endl;
		}
		else
		{
			cout<<"Case #"<<counter<<": "<< "Broken"<<endl;
			//cout<<"g="<<g<<"\td="<<d<<endl;
		}
		++counter;
	}
	file.close();
	

	cin.get();
	return 0;
}







