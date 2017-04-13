//Code Jam "Train Timetable"

#include <iostream>
#include <vector>
#include <algorithm>

#define ALL(a) (a).begin(), (a).end()

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int T, NA, NB;
		cin >> T >> NA >> NB;
		
		vector <int> departA(NA), arriveB(NA), departB(NB), arriveA(NB);
		cin.clear();
		cin.ignore();
		char str[12];
		for(int j = 0; j < NA; j++)
		{
			cin.getline(str, 12);
			int h1, m1, h2, m2;
			sscanf(str, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
			departA[j] = h1 * 60 + m1;
			arriveB[j] = h2 * 60 + m2;
		}
		for(int j = 0; j < NB; j++)
		{
			cin.getline(str, 12);
			int h1, m1, h2, m2;
			sscanf(str, "%d:%d %d:%d", &h1, &m1, &h2, &m2);
			departB[j] = h1 * 60 + m1;
			arriveA[j] = h2 * 60 + m2;
			//cout << h1 << " "<< m1 << " " << " " << h2 << " " << m2 << endl;
		}
				
		int rakesA = 0, rakesB = 0;
		vector <bool> usedA(NB, false);
		sort(ALL(departA));
		sort(ALL(arriveA));
		
		for(int j = 0; j < NA; j++)
		{
			bool done = false;
			for(int k = 0; k < NB; k++)
			{
				if(!usedA[k] && arriveA[k] + T <= departA[j])
				{
					//jth trip from A done
					usedA[k] = true;
					done = true;
					break;
				}
			}
			if(!done)
			{
				rakesA++;
			}
		}
		
		vector <bool> usedB(NA, false);
		sort(ALL(arriveB));
		sort(ALL(departB));
		for(int j = 0; j < NB; j++)
		{
			bool done = false;
			for(int k = 0; k < NA; k++)
			{
				if(!usedB[k] && arriveB[k] + T <= departB[j])
				{
					//jth trip from B done
					usedB[k] = true;
					done = true;
					break;
				}
			}
			if(!done)
			{
				rakesB++;
			}
		}
		
		cout << "Case #" << i + 1 << ": " << rakesA << " " << rakesB;
		if(i != N - 1)
			cout << endl; 
	}
	return 0;
}
