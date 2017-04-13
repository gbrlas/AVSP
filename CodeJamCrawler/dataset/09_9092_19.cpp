#include <iostream>
#include <fstream>

using namespace std;


int main ()
{
	ifstream fin("A.in");
	ofstream fout("A.out");
	int T;
	int s1[10];
	int s2[10];
	fin >> T;
	
	for (int t=1; t<=T; t++)
	{
	
		for (int i=0; i<10; i++)
		{
			s1[i] = 0;
			s2[i] = 0;
		}
		int sk, sk0, sk1;
		fin >> sk;
		sk0 = sk;
		sk1 = sk;
		while (sk != 0)
		{
			s1[sk%10]++;
			sk = sk / 10;
		}
		//for (int i=0; i<10; i++)
		//	cout << i << ": " << s1[i] << endl;
			
		bool radom = false;
//		sk = sk0;
		while (!radom)
		{
			for (int i=0; i<10; i++)
					s2[i] = 0;
			sk1++;
			sk = sk1;
			while (sk != 0)
			{
				s2[sk%10]++;
				sk = sk / 10;
			}
			radom = true;
			for (int i=1; i<10; i++)
			{
				if (s1[i] != s2[i])
				{
					radom = false;
					break;
				}	
			}
			//for (int i=0; i<10; i++)
			//	cout << i << ": " << s1[i] << endl;
			//cin.get();
		}
		fout << "Case #" << t << ": " <<  sk1 << endl;
		cout << "Case #" << t << ": " <<  sk1 << endl;
	}

	fout.close();
	cin.get();
	return 0;
}
