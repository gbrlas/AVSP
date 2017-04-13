#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<set>
#include<iostream>
using namespace std;

int main ()
{
	int cases,size,wAnswer,dAnswer;
	double tmp;
	string ifile = "D-small-attempt1.in",ofile = "output.txt";
	set<double> nSetw,nSetd,kSetw,kSetd;
	stringstream ss;
	ifstream input;
	input.open(ifile);
	input>>cases;
	for(int c = 1 ; c <= cases ; ++c)
	{
		nSetw.clear();kSetw.clear(),nSetd.clear(),kSetd.clear();wAnswer=0;
		input>>size;
		for(int i = 0 ; i < size ; ++i)
		{
			input>>tmp;
			nSetd.insert(tmp);
			nSetw.insert(tmp);
		}
		for(int i = 0 ; i < size ; ++i)
		{
			input>>tmp;
			kSetd.insert(tmp);
			kSetw.insert(tmp);
		}
		set<double>::iterator itn ,itk;
		while(nSetw.size()>0)
		{
			itn=--nSetw.end();
			itk=--kSetw.end();
			if(*itn>*itk)
			{
				wAnswer++;
				nSetw.erase(itn);
				kSetw.erase(itk);
			}
			else
			{
				nSetw.erase(nSetw.begin());
				kSetw.erase(itk);
			}
		}
		for(itn = nSetd.begin() ; itn != nSetd.end() ; )
		{
			for(itk = kSetd.begin() ; itk != kSetd.end() ; itk ++)
			{
				if(*itk>*itn)break;
			}
			if(itk==kSetd.end())break;
			nSetd.erase(itn++);
			kSetd.erase(itk);
		}
		dAnswer = nSetd.size();
		ss<<"Case #"<<c<<": "<<wAnswer<<" "<<dAnswer<<"\n";
	}
	input.close();
	ofstream output;
	output.open(ofile);
	output<<ss.rdbuf();
	output.flush();
	output.close();
	return 0;
}