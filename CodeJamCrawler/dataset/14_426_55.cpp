#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

vector<double> InsertionSort(vector<double> nums)
{
	int capacity = nums.size();
	double sorted[capacity];
	int size = 1;
	sorted[0] = nums[0];
	for (int j = 1; j < capacity; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (sorted[i] > nums[j])
			{
				for (int k = size-1; k >=i; k--)
				{
					sorted[k+1] = sorted[k];
				}
				sorted[i] = nums[j];
				size++;
				break;
			}
			else if (i == size-1)
			{
				size++;
				sorted[size-1] = nums[j];
				break;
			}
		}
	}
	for (int i = 0; i < capacity; i++)
	{
		nums[i] = sorted[i];
	}
	return nums;
}


int main() {
	ifstream in("D-large.in");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf()); 

	int cases;
	int turns;
	int normTurns;
	int start = 0;
	int count = 0;
	int count1 = 0;
	int chosenIndex = 0;
	double max = 0;
	double min = 0;
	double told = 0;
	double chosen = 0;
	int caseNo = 0;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		caseNo++;
		int nIndex = 0;
		cin >> turns;
		normTurns = turns;
		vector<double> v1;
		vector<double> v2;
		vector<double> v3;
		vector<double> v4;

		for (int k = 0; k < turns; k++) {
			double num;
			cin >> num;
			v1.push_back(num);
			v3.push_back(num);
		}

		for (int k = 0; k < turns; k++) {
			double num;
			cin >> num;
			v2.push_back(num);
			v4.push_back(num);
		}

		v1 = InsertionSort(v1);
		v2 = InsertionSort(v2);
		v3 = InsertionSort(v3);
		v4 = InsertionSort(v4); 

		for (int j = 0; j < normTurns; j++)
		{
			for (int jk = nIndex; jk < normTurns; jk++)
			{
				if (v1[jk] > v2[j])
				{
					count++;
					nIndex = jk+1;
					break;
				}
			}
		}
		cout << "Case #" << caseNo << ": " << count << " ";
		count = 0;
		count1 = 0;
		start = 0;
		chosen = 0;
		chosenIndex = 0;
		double kens = 0;
		double small = 0;
		

		for (int ii = normTurns-1; ii >= 0; ii--)
		{
			bool flg = false;
			for (int jj = 0; jj < normTurns; jj++)
			{
				if (v3[ii] < v4[jj])
				{
					v4[jj] = -1;
					flg = true;
					break;
				}
			}

			if (flg == false)
			{
				for (int kk = 0; kk < normTurns; kk++)
				{
					if (v4[kk] > 0)
					{
						v4[kk] = -1;
						count++;
						break;
					}
				}	
			}
		}

		cout << count << endl;
		count = 0;
		count1 = 0;
		start = 0;
		chosenIndex = 0;

	}

	return 0;
}