#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
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

std::string case_result(int n, std::string result)
{
	std::stringstream ss;
	ss << "Case #" << n << ": " << result << "\n";
	return ss.str();
}

std::string case_result(int n, int r)
{
	std::stringstream ss;
	ss << r;
	return case_result(n, ss.str());
}

std::string compare_results(const std::string& expected_output_path, const std::string& result_output_path)
{
	std::fstream f_exp(expected_output_path.c_str());
	std::fstream f_res(result_output_path.c_str());

	std::istream_iterator<std::string> it_exp(f_exp);
	std::istream_iterator<string> it_res(f_res);

	while(it_exp != std::istream_iterator<std::string>() &&  it_res != std::istream_iterator<std::string>())
	{
		if (*it_exp != *it_res)
		{
			stringstream ss;
			ss << "FAILED! Expected : \"" << *it_exp << "\", received \"" << *it_res << "\"\n";
			return ss.str();		
		}

		++it_exp; 
		++it_res;
	}

	if (it_exp != std::istream_iterator<std::string>() )
	{
		stringstream ss;
		ss << "FAILED! Expected result contains more data: ";
		while(it_exp != std::istream_iterator<std::string>() )
		{
			ss << *it_exp++;
		}
		ss << "\n";
		return ss.str();		
	}

	if (it_res != std::istream_iterator<std::string>() )
	{
		stringstream ss;
		ss << "FAILED! Output result contains more data: ";
		while(it_res != std::istream_iterator<std::string>() )
		{
			ss << *it_res++;
		}
		ss << "\n";

		return ss.str();		
	}

	return "PASSED";
}


int count_switches(std::vector<std::string> vs, std::vector<std::string> vq)
{
	if (vq.size() == 0)
		return 0;

	int E = vs.size();
	int Q = vq.size();

	VI queries;
	REP(i, vq.size())
		queries.push_back(find(ALL(vs), vq[i]) - vs.begin());

	VI best(E, 0);
	best[queries[0]] = -1;

	FOR(i, 1, Q-1)
	{
		VI best_(E, -1);

		int q = queries[i];
		REP(j, E)
		{
			if (j == q)
				continue;

			int min_q = 1000;
			REP(k, E)
			{
				if (best[k] == -1)
					continue;

				if (k == j)
				{
					min_q = min(min_q, best[k]);
				}
				else
				{
					min_q = min(min_q, best[k]+1);
				}
			}			
			best_[j] = min_q;
		}
		best = best_;
	}


	int min_q = 10000;
	REP(i, best.SZ)
	{
		if (best[i] != -1)
			min_q = min(min_q, best[i]);
	}


	return min_q;
}

int main(int argc, char* argv[])
{
	std::ifstream in("in");
	std::ofstream out("out");

	int N;
	in >> N;

	FOR(i, 1, N)
	{
		int S = 0, Q = 0;

		in >> S;
		VS vq, vs;
		getline(in, string());

		REP(s_, S)
		{
			string s;
			getline(in, s);
			vs.PB(s);
		}

		in >> Q;
		getline(in, string());

		REP(q_, Q)
		{
			string q;
			getline(in, q);
			vq.PB(q);
		}

		int switches = count_switches(vs, vq);
		out << case_result(i, switches);

	}
	//out << "\n";

	//std::cerr << compare_results("expected_output", "out");
	
	return 0;
}

