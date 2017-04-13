#include <iostream>
#include <fstream>
#include <iomanip>
#define min(a,b) ( (a>b)?b:a )
#define max(a,b) ( (a>b)?a:b )
using namespace std;
int main()
{
	
	ifstream ifs("Input.txt");
    cin.rdbuf(ifs.rdbuf());
    ofstream ofs("Output.txt");
    cout.rdbuf(ofs.rdbuf());
	
	int T, n;
	int r,c,m;
	int t,d;
	bool flag = false;
    cin >> T;
	for (int i=0; i<T; i++)
	{
		cin >>	r >> c >> m;
		n = r*c-m;
		if (r == 1)
		{
			cout << "Case #" << i+1 << ":" << endl;
			cout << 'c';
			for (int j=0; j<c-m-1; j++)
				cout << '.';
			for (int j=0; j<m; j++)
				cout << '*';
			cout << endl;
		}
		else if (c == 1)
		{
			cout << "Case #" << i+1 << ":" << endl;
			cout << 'c' << endl;
			for (int j=0; j<r-m-1; j++)
				cout << '.' << endl;
			for (int j=0; j<m; j++)
				cout << '*' << endl;
		}
		else
		{
			if (n==1)
			{
				cout << "Case #" << i+1 << ":" << endl;
				cout << 'c';
				for (int k=1; k<c; k++)
					cout << '*';
				cout << endl;
				for (int j=1; j<r; j++)
				{
					for (int k=0; k<c; k++)
						cout << '*';
					cout << endl;
				}
			}
			else if (n==2 || n==3 || n==5 || n==7)
				cout << "Case #" << i+1 << ":" << endl << "Impossible" << endl;
			else if (n/min(r,c) < 2)
			{
				if (n%2 == 0)
				{
					cout << "Case #" << i+1 << ":" << endl;

					cout << 'c';
					for (int k=1; k<n/2; k++)
						cout << '.';
					for (int k=n/2; k<c; k++)
						cout << '*';
					cout << endl;

					for (int k=0; k<n/2; k++)
						cout << '.';
					for (int k=n/2; k<c; k++)
						cout << '*';
					cout << endl;

					for (int j=2; j<r; j++)
					{
						for (int k=0; k<c; k++)
							cout << '*';
						cout << endl;
					}
				}
				else
				{
					cout << "Case #" << i+1 << ":" << endl;

					cout << 'c';
					for (int k=1; k<n/2-1; k++)
						cout << '.';
					for (int k=n/2-1; k<c; k++)
						cout << '*';
					cout << endl;

					for (int k=0; k<n/2-1; k++)
						cout << '.';
					for (int k=n/2-1; k<c; k++)
						cout << '*';
					cout << endl;

					for (int k=0; k<3; k++)
						cout << '.';
					for (int k=3; k<c; k++)
						cout << '*';
					cout << endl;

					for (int j=3; j<r; j++)
					{
						for (int k=0; k<c; k++)
							cout << '*';
						cout << endl;
					}
				}
			}
			else
			{
				cout << "Case #" << i+1 << ":" << endl;
				t = n/min(r,c);
				d = n - t*min(r,c);

				if (r == min(r,c) && d!=1)
				{
					cout << 'c';
					for (int k=1; k<t; k++)
							cout << '.';
					if (d)
					{
						d--;
						cout << '.';
						for (int k=t+1; k<c; k++)
							cout << '*';
					}
					else
						for (int k=t; k<c; k++)
							cout << '*';
					cout << endl;

					for (int j=1; j<r; j++)
					{
						for (int k=0; k<t; k++)
							cout << '.';
						if (d)
						{
							d--;
							cout << '.';
							for (int k=t+1; k<c; k++)
								cout << '*';
						}
						else
							for (int k=t; k<c; k++)
								cout << '*';
						cout << endl;
					}
				}
				else if (c == min(r,c) && d!=1)
				{
					cout << 'c';
					for (int k=1; k<c; k++)
						cout << '.';
					cout << endl;

					for (int j=1; j<t; j++)
					{
						for (int k=0; k<c; k++)
							cout << '.';
						cout << endl;
					}

					if (t < r)
					{
						for (int k=0; k<d; k++)
							cout << '.';
						for (int k=d; k<c; k++)
							cout << '*';
						cout << endl;
					}
					for (int j=t+1; j<r; j++)
					{
						for (int k=0; k<c; k++)
							cout << '*';
						cout << endl;
					}
				}
				else if ((r==2 || c==2) && n%2)
				{
					cout << "Impossible" << endl;
				}
				else if (r==min(r,c))
				{
					cout << 'c';
					for (int k=1; k<t+1; k++)
							cout << '.';
					for (int k=t+1; k<c; k++)
						cout << '*';
					cout << endl;

					for (int k=0; k<t+1; k++)
							cout << '.';
					for (int k=t+1; k<c; k++)
						cout << '*';
					cout << endl;

					if (t!=2)
					{
						for (int j=2; j<r-1; j++)
						{
							for (int k=0; k<t; k++)
								cout << '.';
							for (int k=t; k<c; k++)
								cout << '*';
							cout << endl;
						}

						for (int k=0; k<t-1; k++)
								cout << '.';
						for (int k=t-1; k<c; k++)
							cout << '*';
						cout << endl;
					}
					else
					{
						for (int k=0; k<t+1; k++)
							cout << '.';
						for (int k=t+1; k<c; k++)
							cout << '*';
						cout << endl;

						for (int j=3; j<r-1; j++)
						{
							for (int k=0; k<t; k++)
								cout << '.';
							for (int k=t; k<c; k++)
								cout << '*';
							cout << endl;
						}

						for (int k=0; k<c; k++)
							cout << '*';
						cout << endl;
					}
				}
				else if (c == min(r,c))
				{
					cout << 'c';

					if (t!=2)
					{
						for (int k=1; k<c; k++)
							cout << '.';
						cout << endl;

						for (int j=1; j<t-1; j++)
						{
							for (int k=0; k<c; k++)
								cout << '.';
							cout << endl;
						}

						for (int k=0; k<c-1; k++)
							cout << '.';
						cout << '*';
						cout << endl;

						for (int k=0; k<2; k++)
							cout << '.';
						for (int k=2; k<c; k++)
							cout << '*';
						cout << endl;

						for (int j=t+1; j<r; j++)
							for (int k=0; k<c; k++)
								cout << '*';
						cout << endl;
					}
					else
					{
						for (int k=1; k<c-1; k++)
							cout << '.';
						cout << '*';
						cout << endl;

						for (int j=1; j<t; j++)
						{
							for (int k=0; k<c-1; k++)
								cout << '.';
							cout << '*';
							cout << endl;
						}

						for (int k=0; k<3; k++)
							cout << '.';
						for (int k=3; k<c; k++)
							cout << '*';
						cout << endl;

						for (int j=t+1; j<r; j++)
						{
							for (int k=0; k<c; k++)
								cout << '*';
							cout << endl;
						}
					}
				}
			}

		}
	}
 
    ifs.close();
    ofs.close();
	
	return 0;
}