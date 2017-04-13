#include "iostream"
#include "fstream"
#include <string>
using namespace std;

struct KeyFone
{
	string str;
	int group;
}
typedef KEYFONE;

void init();

KEYFONE a[26];

void main()
{
	ifstream fin;
	ofstream fout;
	int numTest;

	fin.open("C-large-practice.in", ios_base::in);
	fout.open("C-large-practice.out", ios_base::out);
	
	fin>>numTest;
	init();
	string tmp;
	getline(fin, tmp);
	
	for(int i=1; i<=numTest; i++)
	{
		int old = -1;
		getline(fin, tmp);
		fout<<"Case #"<<i<<": ";
		for(unsigned j=0; j<tmp.length(); j++)
		{
			char c = (char)tmp[j];
			if(c == ' ')
			{
				if(old == 0)
					fout<<" ";
				old = 0;
				fout<<"0";
			}
			else
			{
				int index = (int)c - 97;

				if(old == a[index].group)
					fout<<" ";

				fout<<a[index].str;
				old = a[index].group;
			}
		}
		if(i<numTest)
			fout<<endl;
	}
	
	

	fin.close();
	fout.close();


}

void init()
{
	//Phim A
	a[0].group = 2;
	a[0].str = "2";
	
	//Key B
	a[1].group = 2;
	a[1].str = "22";

	//Key C
	a[2].group = 2;
	a[2].str = "222";

	//Key D
	a[3].group = 3;
	a[3].str = "3";

	//Key E
	a[4].group = 3;
	a[4].str = "33";

	//Key F
	a[5].group = 3;
	a[5].str = "333";

	//Key G
	a[6].group = 4;
	a[6].str = "4";

	//Key H
	a[7].group = 4;
	a[7].str = "44";

	//Key I
	a[8].group = 4;
	a[8].str = "444";

	//Key J
	a[9].group = 5;
	a[9].str = "5";

	//Key K
	a[10].group = 5;
	a[10].str = "55";

	//Key L
	a[11].group = 5;
	a[11].str = "555";

	//Key M
	a[12].group = 6;
	a[12].str = "6";

	//Key N
	a[13].group = 6;
	a[13].str = "66";

	//Key O
	a[14].group = 6;
	a[14].str = "666";

	//Key P
	a[15].group = 7;
	a[15].str = "7";

	//Key Q
	a[16].group = 7;
	a[16].str = "77";

	//Key R
	a[17].group = 7;
	a[17].str = "777";

	//Key S
	a[18].group = 7;
	a[18].str = "7777";

	//Key T
	a[19].group = 8;
	a[19].str = "8";

	//Key U
	a[20].group = 8;
	a[20].str = "88";

	//Key V
	a[21].group = 8;
	a[21].str = "888";

	//Key W
	a[22].group = 9;
	a[22].str = "9";
	//Key X
	a[23].group = 9;
	a[23].str = "99";
	//Key Y
	a[24].group = 9;
	a[24].str = "999";
	//Key Z
	a[25].group = 9;
	a[25].str = "9999";
}