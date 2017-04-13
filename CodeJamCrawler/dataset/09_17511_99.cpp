#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int n;
	string s;

	ifstream fin;
	ofstream fout;

	fin.open ("input.txt");
	fout.open ("output.txt");
	
	
	fin>> n;
	getline(fin,s);
	string wel = "welcome to code jam";
	int res[20];

	for (int i=0;i<n;i++ )
	{
		for (int k = 0;k<=wel.length();k++)
			res[k]=0;

		getline(fin,s);


		int buf,buf2;
		res[0]=1; buf = 1;
		for (int j=0;j<s.length();j++)
		{
			res[0]=1; buf = 1;
			for (int k = 0;k<wel.length();k++)
			{
				buf2=res[k+1];
				if (wel[k]==s[j])
				{
					res[k+1]=(buf+res[k+1])%10000;
				}
				buf=buf2;
			}
		}
		fout<<"Case #" <<i+1<<": "<<  (res[19]/1000)%10<<  (res[19]/100)%10<<  (res[19]/10)%10<<  (res[19]/1)%10  <<endl;





	}
	
	
	fout.close();
	fin.close();
	return 0;
}