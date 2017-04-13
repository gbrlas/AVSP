#include<iostream>
#include<fstream>
#include<strstream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

void main()
{
	ifstream input("test");
	ofstream output("result");

	int nCase;
	//string firstline;
	//getline(input, firstline);
	//nCase = atoi(firstline.c_str());
	
	input>>nCase;

	for(int nc = 1; nc <= nCase; nc++)
	{
		//string temp;
		//getline(input, temp);
		//istrstream ost(temp.c_str());
		int P, K, L;
		input>>P>>K>>L;

		vector<long> freq;
		for(int i = 0; i < L; i++)
		{
			long temp;
			input>>temp;
			freq.push_back(temp);
		}

		sort(freq.begin(), freq.end(), greater<long>());

		long long result = 0;
		for(int i = 0; i < L; i++)
		{
			int m = i / K;
			result += (m+1) * freq[i];
		}

		output<<"Case #"<<nc<<": "<<result<<endl;
	}
}