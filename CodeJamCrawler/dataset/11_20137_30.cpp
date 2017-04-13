
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Bot.h"
#include "Controller.h"
#include "Helper.h"

using namespace std;

int main(int argc, const char* argv[]){
	Controller* control=0;
	int counter = 1;
	string *filename;
	string line;
	vector<string> strvec;
	vector<string>::iterator svit;
	int button,colorid;
	char color;
	ifstream file;

	if (argc>1)
	{
		filename = new string(argv[1]);
		file.open(argv[1]);
	}
	else
	{
		filename = new string("C:\\Users\\Lotonoro\\Documents\\Visual Studio 2010\\Projects\\GoogQualify2011\\input.txt");
		file.open(filename->c_str());
	}

	if (!file.is_open())
	{
		//cout<<"Error: cannot find file: "<< *filename << endl;
		return 1;
	}
	else
	{
		cout<< "file found: " << *filename <<endl;
	}
	if (!file.eof())
	{
		getline(file,line);
		//cout<< line << " cases" <<endl;
	}
	while (!file.eof())
	{
		control = new Controller();
		getline(file,line);
		if (line == "") break;
		//cout<<line<<endl;
		strvec.clear();
		split(line,' ',strvec);
		svit = strvec.begin();
		//cout<<*svit<<" steps"<<endl;
		svit++;
		while (svit != strvec.end())
		{
			if(*svit == "O")
				colorid = 1;
			else
				colorid = 2;
			++svit;
			button = str_int(*svit);
			++svit;
			control->addAction(button,colorid);
		}
		int steps = control->start();
		cout<<"Case #"<<counter++<<": "<< steps<<endl;
		delete control;
		control = 0;
	}
	file.close();
	

	cin.get();
	return 0;
}







