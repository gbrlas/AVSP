#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
#include  <sstream>
#include <fstream>
using namespace std;
string ITS(int Number)
{
	stringstream out;
	out<<Number;
	return out.str();
}
int STI(string M)
{
	stringstream out;
	out<<M;
	int x;
	out>>x;
	return x;
}

int main()
{
	ifstream Fin("input.txt");
	ofstream Fout("output.txt");
	int n;
	char yoo;
	Fin>>n;
	string Text;
	char Alph1[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	char Alph2[27]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q',' '};
	getline(Fin,Text);
	for (int i=0;i<n;i++)
	{
		
		getline(Fin,Text);

		for (int i=0;i<Text.size();i++)
		{
			for (int j=0;j<27;j++)
			{
			if (Text[i]==Alph1[j])
			{
				Text[i]=Alph2[j];
				j=27;
			}
			}

		
		}
			Fout<<"Case #"<<i+1<<": ";
			for (int k=0;k<Text.size();k++)
				Fout<<Text[k];
			if(i+1!=n)
			Fout<<endl;
	}
}