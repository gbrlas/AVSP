#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	ifstream fin ("a.in");
	int N;
	vector<int> v1;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		v1.clear();
		int len = 0;
		fin >> len;
		for (int j = 0; j < len; j++)
		{
			string tmpstr;
			fin >> tmpstr;
//			cout << tmpstr << endl;
			//find largest 1
			int tmp = -1;
			for (int k = 0; k < len; k++)
			{
				if (tmpstr[k] == '1')
					tmp = k;
			}
			v1.push_back(tmp);
		}
//		for (int j = 0; j < v1.size(); j++)
//			cout << v1[j] << endl;
		int ans = 0;

		for (int j = 0; j < len; j++)
		{
			if (v1[j] > j)
			{
				int k = j + 1;
				ans++;
				for (k = j + 1;v1[k] > j; k++)
				{
					ans++;
				}
				int key = v1[k];
				v1.erase(v1.begin() + k);
				v1.insert(v1.begin() + j, key);
			}
		}
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}
	return 0;
}
