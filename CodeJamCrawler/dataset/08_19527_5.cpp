#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned N;
	cin >> N;
	for(unsigned cases = 0; cases < N; cases++)
	{
		unsigned P,K,L;
		unsigned long minkey = 0;
		vector<unsigned long> frequencies;
		cin >> P >> K >> L;
		for(unsigned freq = 0; freq<L; freq++)
		{
			unsigned long curfreq;
			cin >> curfreq;
			frequencies.push_back(curfreq);
		}
		sort(frequencies.begin(),frequencies.end());
		reverse(frequencies.begin(),frequencies.end());
		for( unsigned int i = 0; i < frequencies.size(); i++ )
		{
   			minkey += frequencies[i] * (i/K+1);
 		}
		cout << "Case #" << cases+1 << ": " << minkey << endl;
	}
	return 0;
}
