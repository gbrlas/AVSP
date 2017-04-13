#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#define MAX(x,y) (x) > (y) ? (x) : (y)
#define MIN(x,y) (x) < (y) ? (x) : (y)
using namespace std;
int nxtNum(int num)
{
	vector<int> v1;
	while (num !=0)
	{
		v1.push_back(num%10);
		num = num / 10;
	}
	v1.push_back(0);
	reverse(v1.begin(), v1.end());
	next_permutation(v1.begin(), v1.end());
	bool b = false;
	for (int i=0; i < v1.size(); i++)
	{
		if (v1[i] == 0 && b == false)
			continue;
		cout <<v1[i];
		b = true;
	}
	cout << endl;
	return 0;
}
int main()
{
	ifstream fin ("a.in");
	//ofstream fout ("a.txt");
	int n;
	int num;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> num;
		cout << "Case #"<<i+1<<": ";
		nxtNum(num);
	}

	return 0;
}
