#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int N, L1, L2;
string S1 = "welcome to code jam";
int **aa;

string str;

string readinput()
{
	string str;
	getline(cin >> ws, str);
	return str;
}


void processcase()
{
	for(int l1=0; l1<L1; l1++)
	{
		aa[l1] = new int[L2];
		//for (int i=0; i<L2; i++)
		//	aa[l1][i] = 0;

		for (int l2=0; l2<L2; l2++)
		{
			int aa_l = l2>0 ? aa[l1][l2-1] : 0;
			int aa_d = l1>0 && l2>0 ? aa[l1-1][l2-1] :
				l1>0 ? 0 : 1;

			if (S1[l1] == str[l2])
			{
				aa[l1][l2] = (aa_l + aa_d) % 10000;
			}
			else
			{
				aa[l1][l2] = aa_l;
			}
		}
	}
}


int getresult()
{
	return aa[L1-1][L2-1];
}

int main()
{
	L1 = S1.length();
	aa = new int*[L1];

	cin >> N;

	for(int n=0; n<N; n++)
	{
		str = readinput();
		L2 = str.length();
		processcase();
		int res = getresult();
		cout << "Case #" << n+1 << ": ";
		cout << setw(4) << setfill('0') << res << endl;
		
	}
	return 0;
}
