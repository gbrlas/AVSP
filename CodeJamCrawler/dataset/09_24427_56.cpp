#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>

#define SZ(a) (int)(a).size()
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define INF (int)1e9

#define ll long long
#define vi vector<int>
#define vs vector<string>

using namespace std;

vector <string> splitString(string a, char c)
{
	vector <string> res;
	string buff = "";
	a += c;
	
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == c)
		{
			if(buff.size() > 0)
				res.push_back(buff);
			buff = "";
		}	
		else
			buff.push_back(a[i]);
	}
	return res;
}


double evaluate(int index, int last, string tree, vs &features, double prob)
{
	string t1;
	
	/*cout << "prob = " << prob << endl;
	for(int i = index; i < last; i++)
		cout << tree[i];
	cout << endl;*/
	
	bool wtstart = false;
	int i;
	for(i = index + 1; i < last; i++)
	{
		if((tree[i] == ' ' || tree[i] == '(') && !wtstart)
			continue;
		else if(tree[i] == ' ' && wtstart)
			break;
		else
		{
			t1.PB(tree[i]);
			wtstart = true;
		}
	}
	
	stringstream ss;
	ss << t1;
	double weight;
	ss >> weight;
	
	//cout << weight << endl;
	
	string f = "";
	for(; i < last; i++)
	{
		if(tree[i] == ' ')
			continue;
		else if(tree[i] >= 'a' && tree[i] <= 'z')
			f += tree[i];
		else if(tree[i] == '(')
		{
			vector <string>::iterator found = find(ALL(features), f);
			if(found == features.end())
			{
				int open = 1;
				while(open != 0 && i < last)
				{
					i++;
					if(tree[i] == '(')
						open++;
					else if(tree[i] == ')')
						open--;
				}
				return evaluate(i + 1, last, tree, features, weight * prob);
			}
			else
			{
				int j = i + 1, open = 1;
				while(open != 0 && j < last)
				{
					j++;
					if(tree[j] == '(')
						open++;
					else if(tree[j] == ')')
						open--;
				}
				return evaluate(i, j, tree, features, weight * prob);
			}
		}
		
	}
	
	return weight * prob;
}

int main()
{
	int N;
	cin >> N;
	
	for(int cas = 1; cas <= N; cas++)
	{
		int L;
		cin >> L;
		cin.ignore();
		
		vs temptree(L);
		char t[100];
		for(int i = 0; i < L; i++)
		{
			cin.getline(t, 100);
			temptree[i] = t;
		}
		
		string ftree = (string)accumulate(ALL(temptree), string());
		
		//cout << ftree << endl;
		
		//vs features;
		//ftree = "(0.34 amit (0.8)(0.5 cool (0.43 ) ( 0.44 ) ))";
		//cout << evaluate(0, SZ(ftree), ftree, features, 1.0);
		int A;
		int nf;
		
		cout << "Case #" << cas << ": " << endl;
		cin >> A;
		cin.ignore();
		for(int i = 0; i < A; i++)
		{
			char temp[1500];
			cin.getline(temp, 1500);
			string ipp = temp;
			//cout << ipp << endl;
			
			vs features = splitString(ipp, ' ');
			features.erase(features.begin());
			features.erase(features.begin());
			
			printf("%.7lf\n", evaluate(0, SZ(ftree), ftree, features, 1.0));
			
		}
		
	}
	return 0;
}
