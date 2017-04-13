#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define VT vector
typedef VT<int> VI;
typedef VT<VI> VVI;
typedef VT<string> VS;
typedef VT<double> VD;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define FS first
#define SC second
#define SZ size() 


using namespace std;

double read_double(const std::string & data, int& pos)
{
	string str;
	while(pos < data.size() && (data[pos] != ' ' && data[pos] != '(' && data[pos] != ')'))
		str += data[pos++];

	return atof(str.c_str());
}

string read_string(const std::string& data, int& pos)
{
	string str;
	while(pos < data.size() && (data[pos] != ' ' && data[pos] != '(' && data[pos] != ')'))
		str += data[pos++];

	return str;
}


struct node
{
	double p;
	string f;

	node* right;
	node* left;

	void read(const std::string & data, int& pos)
	{
		while(pos < data.size() && (data[pos] != '(')) pos++;

		if (pos >= data.size())
			return;


		if (data[pos] == '(')
		{
			pos++;
			while(pos < data.size() && (data[pos] == ' ')) pos++;
			if (pos >= data.size())
				return;

			p = read_double(data, pos);
			while(pos < data.size() && (data[pos] == ' ')) pos++;

			if (pos >= data.size())
				return;


			if (data[pos] != '(' && data[pos] != ')')
				f = read_string(data, pos);

			while(pos < data.size() && (data[pos] == ' ')) pos++;

			if (pos >= data.size())
				return;

			if (data[pos] == '(')
			{
				right = new node();
				right->read(data, pos);
				

				left = new node();
				left->read(data, pos);
			}

		}

	}

	double prob(set<string>& fs, double prob)
	{
		prob *= p;

		if (f.size())
		{
			if (fs.find(f) != fs.end())
				return right->prob(fs, prob);
			else
				return left->prob(fs, prob);
		}

		return prob;
	}

	node() : right(0), left(0) {}

	~node() { delete right; delete left; }
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int N;
	string str;
	getline(cin, str);
	stringstream ss;
	ss << str;
	ss >> N;

	REP(n,N)
	{
		int M;
		string str;
		getline(cin, str);
		stringstream ss;
		ss << str;
		ss >> M;

		if (M==1000000)
		{
			cout << "Case #" << (n+1) << ": " << 10000000 << "\n";
			continue;
		}


		int m_ = M;

		

		VI orig(10);

		while(m_)
		{
			if (m_%10)
				orig[m_%10]++;
			m_/=10;
		}

		for(int m = M+1; m < 100000000; ++m)
		{
			VI orig_match(10);

			int m_ = m;
			while(m_)
			{
				if (m_%10)
					orig_match[m_%10]++;
				m_/=10;
			}

			bool match = 1;
			REP(i, 10)
			{
				if (orig[i] != orig_match[i])
				{
					match = 0;break;
				}
			}

			if (match)
			{
				cout << "Case #" << (n+1) << ": " << m << "\n";
				break;
			}

		}
		

	}

}