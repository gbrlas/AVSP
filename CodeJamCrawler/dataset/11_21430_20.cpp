#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int num;

int main()
{
	ifstream in("F:\\Users\\Simy\\Downloads\\A-small-attempt1.in");
	if(in == NULL)
	{
		cout << "hello" << endl;
	}
	ofstream out("a.out");
	in >> num;
	for(int i = 0;i<num;i++)
	{
		int n = 0;
		in >> n;
		vector<float> wp(n);
		vector<float> owp(n);
		vector<float> oowp(n);
		vector <vector<char> > matrix(n,n);
		for(int j = 0;j<n;j++)
		{
			for(int k = 0;k<n;k++)
			{
				in >> matrix[j][k];
			}
		}
		out << "Case #" << i+1 << ": " << endl;
		for(int j = 0;j<n;j++)
		{
			float total = 0;
			float win = 0;
			for(int k = 0;k<n;k++)
			{
				if(matrix[j][k] == 49)
				{
					total += 1;
					win += 1;
				}
				else if(matrix[j][k] == 48)
				{
					total += 1;
				}
			}
			wp[j] = (win / total);
		}

		for(int j = 0;j<n;j++)
		{
			float p = 0;
			float tot = 0;
			vector<float> o;
			for(int k = 0;k<n;k++)
			{
				if(matrix[j][k] != 46)
				{
					p++;
					float total = 0;
					float win = 0;
					for(int l = 0;l<n;l++)
					{
						if(l != j && matrix[k][l] != 46)
						{
							total ++;
							if(matrix[k][l] == 49)
							{
								win ++;
							}
						}
					}
					o.push_back(win / total);
				}
			}
			for(int m = 0;m<p;m++)
			{
				tot += o[m];
			}
			owp[j] = (tot / p);
		}

		for(int j = 0;j<n;j++)
		{
			float p = 0;
			float tot = 0;
			vector<float> o;
			for(int k = 0;k<n;k++)
			{
				if(matrix[j][k] != 46)
				{
					p++;
					o.push_back(owp[k]);
				}
			}
			for(int m = 0;m<p;m++)
			{
				tot += o[m];
			}
			oowp[j] = (tot / p);
		}

		for(int j = 0;j<n;j++)
		{
			out << wp[j]/4+owp[j]/2+oowp[j]/4 << endl;
		}
		
	}
	return 0;
}