#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Helper.h"
#include "Magick.h"

using namespace std;

int main(int argc, const char* argv[]){

	string * filename;
	string line;
	ifstream file;
	vector<string> strvec;
	vector<string>::iterator svit;
	Magick* magick=0;
	int combocount;
	int opposecount;
	int elemcount;
	int casecount = 1;

	if (argc>1)
	{
		filename = new string(argv[1]);
		file.open(argv[1]);
	}
	else
	{
		filename = new string("C:\\Users\\Lotonoro\\Documents\\Visual Studio 2010\\Projects\\GoogQualify2011\\Magicka\\input.txt");
		file.open(filename->c_str());
	}

	if (!file.is_open())
	{
		cout<<"Error: cannot find file: "<< *filename << endl;
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
		magick = new Magick();
		combocount = 0;
		opposecount = 0;
		elemcount = 0;
		getline(file,line);
		if (line == "") break;
		strvec.clear();
		split(line,' ',strvec);
		svit = strvec.begin();
		//cout<<*svit<<" combos"<<endl;
		combocount = str_int(*svit);
		for (int i=0;i<combocount;++i)
		{
			++svit;
			magick->addCombo( (*svit)[0],(*svit)[1],(*svit)[2]);
		}
		++svit;
		//cout<<*svit<<" opposes"<<endl;
		opposecount = str_int(*svit);
		for (int i=0;i<opposecount;++i)
		{
			++svit;
			magick->addOppose((*svit)[0],(*svit)[1]);
		}
		++svit;
		//cout<<*svit<<" elements"<<endl;
		++svit;
		for (int i=0; i<(*svit).size(); ++i)
		{
			magick->addElem((*svit)[i]);
		}
		cout << "Case #" << casecount++ << ": "<<magick->getElemList()<<endl;
		delete magick;
		magick =0;
	}

	file.close();
	cin.get();
	return 0;
}