// Hila4321 <> gmail <> com
// Google Code Jam 2010 Round 1 - A

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("A-small-attempt0.in");
	ofstream output("A-small-attempt0.out");

	int t;

	input >> t;

	for (int tc = 1; tc <=t; tc++)
	{
		int n,k;
		input >> n >> k;

		// make new array
		char ** arr = new char*[n];
		for (int i=0;i<n;i++)
		{
			char* p = new char[n];
			arr[i]=p;
		}

		// get board
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				input >> arr[i][j];
			}
		}

		// make new array
		char ** b = new char*[n];
		for (int i=0;i<n;i++)
		{
			char* p = new char[n];
			b[i]=p;
		}

		// rotate
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				b[j][n-1-i] = arr[i][j];
			}
		}

		// delete arr
		for (int i=0;i<n;i++)
		{
			delete [] arr[i];
		}
		delete [] arr;

		// Gravity

		for (int j=0; j<n; j++)
		{
			for (int i=n-1; i>=0; i--)
			{
				int k = 1;
				if (b[i][j]!='.')
				{
					while (i+k <=n-1 && b[i+k][j]=='.')
						k++;
					if (k>1)
					{
						b[i+k-1][j]=b[i][j];
						b[i][j] = '.';
					}
				}

			}
		}


		bool flagR = false;
		bool flagB = false;


		// RED  - horizontally
		for (int i=0; i<n && !flagR; i++)
		{
			for (int j=0; j<=n-k && !flagR; j++)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i][j+p]=='R')
						count++;
				}
				if (count == k)
					flagR = true;
			}
		}

		// BLUE  - horizontally
		for (int i=0; i<n && !flagB; i++)
		{
			for (int j=0; j<=n-k && !flagB; j++)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i][j+p]=='B')
						count++;
				}
				if (count == k)
					flagB = true;
			}
		}

		// RED  - vertically
		for (int j=0; j<n && !flagR; j++)
		{
			for (int i=0; i<=n-k && !flagR; i++)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i+p][j]=='R')
						count++;
				}
				if (count == k)
					flagR = true;
			}
		}

		// BLUE  - vertically
		for (int j=0; j<n && !flagB; j++)
		{
			for (int i=0; i<=n-k && !flagB; i++)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i+p][j]=='B')
						count++;
				}
				if (count == k)
					flagB = true;
			}
		}


		// RED  - Main diags
		for (int i=0; i<=n-k && !flagR; i++)
		{
			for (int j=0; j<=n-k  && !flagR; j++)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i+p][j+p]=='R')
						count++;
				}
				if (count == k)
					flagR = true;
			}
		}

		// BLUE  - Main diags
		for (int i=0; i<=n-k && !flagB; i++)
		{
			for (int j=0; j<=n-k  && !flagB; j++)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i+p][j+p]=='B')
						count++;
				}
				if (count == k)
					flagB = true;
			}
		}


		// RED  - second diags
		for (int i=n-1; i>=k-1 && !flagR; i--)
		{
			for (int j=n-1; j>=k-1 && !flagR; j--)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i-p][j+p]=='R')
						count++;
				}
				if (count == k)
					flagR = true;
			}
		}

		// BLUE  - second diags
		for (int i=n-1; i>=k-1 &&  !flagB; i--)
		{
			for (int j=n-1; j>=k-1 && !flagB; j--)
			{
				int count = 0;
				for (int p=0; p<k; p++)
				{
					if (b[i-p][j+p]=='B')
						count++;
				}
				if (count == k)
					flagB = true;
			}
		}


		//print
		/*for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				output << b[i][j];
			}
			output << endl;
		}*/

		output << "Case #" << tc <<": ";

		if ( flagR && flagB)
			output << "Both" << endl;
		else if ( !flagR && !flagB)
			output << "Neither" << endl;
		else if ( flagR && !flagB)
			output << "Red" << endl;
		else if ( !flagR && flagB)
			output << "Blue" << endl;

		// delete b
		for (int i=0;i<n;i++)
		{
			delete [] b[i];
		}
		delete [] b;
	}

	return 0;
}