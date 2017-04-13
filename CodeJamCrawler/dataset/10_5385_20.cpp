#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream fin("C-small.in", ios_base::in);
	fstream fout("C-small.out", ios_base::out);

	int cases = 0;

	fin >> cases;
	cout << cases << " cases follow." << endl;

	for(int caseId = 1; caseId <= cases; caseId++)
	{
		int rides, capacity, groupCount;
		fin >> rides >> capacity >> groupCount;
		int* groups = new int[groupCount];
		for(int i = 0; i < groupCount; i++)
		{
			fin >> groups[i];
		}

		int income = 0;
		int firstGroup = 0;
		int remainingSeats;
		for(int ride = 0; ride < rides;)
		{
			remainingSeats = capacity;
			int group;
			for(int offset = 0; offset < groupCount; offset++)
			{
				group = (firstGroup + offset) % groupCount;
				int peopleInGroup = groups[group];
				if(peopleInGroup <= remainingSeats)
				{
					remainingSeats -= peopleInGroup;
					income += peopleInGroup;
				}
				else
				{
					break;
				}
			}

			ride++;

			firstGroup = group;
			if(firstGroup == 0)
			{
				int multiplier = rides/ride;

				ride *= multiplier;
				income *= multiplier;
			}
		}

		cout << "Case #" << caseId << ": " << income << endl;
		fout << "Case #" << caseId << ": " << income << endl;
	}

	fout.close();
	cin.ignore();

	return 0;
}
