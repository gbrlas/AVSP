#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int War(vector<float> a, vector<float> b) 
{
	int count = 0;
	int i = 0, j = 0, ori_size = b.size();
	while (b.size() && j < b.size())
	{
		bool flag = false;
		for (i = a.size() - 1; i >= 0; --i)
		{
			if (b[j] > a[i])
			{
				++count;
				b.erase(b.begin() + j);
				a.erase(a.begin() + i);
				flag = true;
				break;
			}
		}
		if (flag == false) ++j;
	}
	return ori_size - count;
}

int Deceitful_War(vector<float> a, vector<float> b)
{
	int count = 0;
	int i = 0, j = b.size() - 1, ori_size = b.size();
	while (b.size() && j >= 0)
	{
		if (b[j] > a[j])
		{
			b.erase(b.begin() + j);
			a.erase(a.begin());
			--ori_size;
		}
		--j;
	}
	return ori_size;
}

int main()
{
	freopen("D-large.in", "r", stdin);  
	freopen("D-large.out", "w", stdout);  
	int T = 0, caseNum = 0;
	cin >> T;
	while (T--)
	{
		++caseNum; 
		vector<float> a, b;
		int N = 0, res1 = 0, res2 = 0;
		float temp = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> temp;
			a.push_back(temp);
		}
		for (int i = 0; i < N; ++i)
		{
			cin >> temp;
			b.push_back(temp);
		}
		if (N == 1 && a[0] > b[0])
		{
			res1 = 1;
			res2 = 1;
		}
		else if (N == 1 && a[0] < b[0])
		{
			res1 = 0;
			res2 = 0;
		}
		else
		{
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			res1 = Deceitful_War(a, b);
			res2 = War(a, b);
		}
		cout << "Case #" << caseNum << ": " << res1 << " " << res2 << endl;
	}
	return 0;
}