#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream cin("1.txt");
	ofstream cout("out.txt");
	int casenum = 1;
	int t;

	cin >> t;
	while (t--)
	{
		int N, K;
		bool answer = true;
		cin >> N >> K;

		for (int i = 0; i < N && answer; i++)
		{
			if (!((1<<i) & K))
			answer = false;
		}

		cout << "Case #"<< casenum++<<": "<< (answer? "ON": "OFF") << endl;
	}
	cout.close();
}