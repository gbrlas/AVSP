#include<iostream>
#include<fstream>
#include<istream>
#include <sstream>

using namespace std;

fstream openInFile(string fileName)
{
	return fstream(fileName,fstream::in);
}


fstream openOutFile(string fileName)
{
	return fstream(fileName,fstream::out);
}

int main()
{
	fstream in,out;
	int numCases;
	string inToken,line;

	int key[26]={25,8,5,19,15,3,22,24,4,21,9,7,12,2,11,18,26,20,14,23,10,16,6,13,1,17};
	in = openInFile("A-small-attempt0.in");
	out = openOutFile("output.txt");
	

	in >> numCases;
	
	int counter = 1;
	bool firstTime = true;
	while(getline(in,line))
	{
		if(firstTime)
		{
			//firstTime = false;
		}
		else{
		out <<"Case #"<<counter++<<":";
		cout <<"Case #"<<counter<<":";
		}
		istringstream inLine(line);
		while(inLine >> inToken) 
		{
			//std::cout << "Token :" << token << std::endl;
			string outString(inToken);
			for(int i = 0 ;i < inToken.length();i++)
			{
				outString[i]=(char)(key[(int)(inToken[i]-96-1)]+96);
			}
			cout <<" "<< outString ;
			out << " "<< outString ;
		}
		
		if(firstTime){firstTime = false;}
		else{
		out<<endl;
		cout<<endl;}
	}	
	return 0;
}