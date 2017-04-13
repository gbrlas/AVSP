#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	
	ifstream ifs("Input.txt");
    cin.rdbuf(ifs.rdbuf());
    ofstream ofs("Output.txt");
    cout.rdbuf(ofs.rdbuf());
	
	int T, a, grb, num=0;
	int b1[4],b2[4];
	int	buf;
    cin >> T;
	for (int i=0; i<T; i++)
	{
		cin >> a;
		for (int j=0; j<a-1; j++)
			for (int k=0; k<4; k++)
				cin >> grb;
		for (int k=0; k<4; k++)
			cin >> b1[k];
		for (int j=a; j<4; j++)
			for (int k=0; k<4; k++)
				cin >> grb;

		cin >> a;
		for (int j=0; j<a-1; j++)
			for (int k=0; k<4; k++)
				cin >> grb;
		for (int k=0; k<4; k++)
			cin >> b2[k];
		for (int j=a; j<4; j++)
			for (int k=0; k<4; k++)
				cin >> grb;

		for (int j=0; j<4; j++)
			for (int k=0; k<4; k++)
				if (b1[j] == b2[k])
				{
					num++;
					buf = b1[j];
				}

		cout << "Case #" << i+1 << ": ";
		if (num == 0)
			cout << "Volunteer cheated!" << endl;
		else if (num == 1)
			cout << buf << endl;
		else
			cout << "Bad magician!" << endl;
		num = 0;
	}


    ifs.close();
    ofs.close();
	
	return 0;
}