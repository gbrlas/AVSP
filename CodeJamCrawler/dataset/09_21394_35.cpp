#include <fstream>
#include <string>
using namespace std;

int main ()
{
	// Generic File Instantiations
	ifstream input;
	ofstream output;
	
	string inputname, outputname;
	
	inputname = "i.in";
	outputname = "output.out";
	input.open (inputname.c_str ());
	output.open (outputname.c_str ());
	
	// Input Read & Initializations
	
	int N; // number of test cases
	input >> N;

	int i,j,k,l,m,n,x,y,z;
	int temp, temp2, big, big_in;

	string str;
	int num_arr[21];
	int num_in[21];
	
	// Fill array and print	
	for (i = 1; i <= N; i++)
	{
		input >> str;

		output << "Case #" << i << ": ";

		int len = str.length();
		for (j = 0; j < len; j++)
		{
			num_arr[j] = str[j] - 48;
			num_in[j] = num_arr[j];
		}

		bool bigger = false;

		for (k = len-2; k >= 0; k--)
		{
			for (l = k+1; l < len; l++)
			{
				if (num_arr[k] < num_arr[l])
				{
					if (!bigger)
					{
						bigger = true;
						big = num_arr[l];
						big_in  = l;
					}
					else if (num_arr[l] < big)
					{
						big = num_arr[l];
						big_in  = l;
					}
				}
			}

			if (bigger)
			{
				l = big_in;
				break;
			}
		}

		if (bigger)
		{
			temp = num_arr[k];
			num_arr[k] = num_arr[l];
			num_arr[l] = temp;

			if (k < len-2)
			{
				for (m = k+2; m<len; m++)
				{
					for (n = k+2; n<len; n++)
					{
						if (num_arr[n-1] > num_arr[n])
						{
							temp = num_arr[n];
							num_arr[n] = num_arr[n-1];
							num_arr[n-1] = temp;
						}
					}
				}
			}

		}
		else
		{
			temp = 0;
			len++;
			for (x = 1; x < len; x++)
			{
				temp2 = num_arr[x];
				num_arr[x] = temp;
				temp = temp2;
			}

			if (len > 2)
			{
				for (m = 1; m<len; m++)
				{
					for (n = 1; n<len; n++)
					{
						if (num_arr[n-1] > num_arr[n])
						{
							temp = num_arr[n];
							num_arr[n] = num_arr[n-1];
							num_arr[n-1] = temp;
						}
					}
				}

				if (num_arr[0] == 0)
				{
					z = 1;
					while (num_arr[0] == 0)
					{
						num_arr[0] = num_arr[z];
						num_arr[z] = 0;
						z++;
					}
				}
			}
		}

		for (y = 0; y < len; y++)
		{
			output << num_arr[y];
		}

		output << endl;
	}

	input.close();
	output.close();
	return 0;
}