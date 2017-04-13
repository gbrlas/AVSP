#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef std::map<string, unsigned int> engine_scores_t;

bool value_comparer(const engine_scores_t::value_type& s1, const engine_scores_t::value_type& s2)
{
	return s1.second < s2.second;
}

class engine_manager_t
{
public:

	void read(istream& in);

	unsigned int eval_switches();

	engine_scores_t eval_scores(vector<string>::const_iterator queries_start);

private:
	std::vector<string> _engines;
	std::vector<string> _queries;
};

unsigned int engine_manager_t::eval_switches()
{
	unsigned int switches = 0;
	size_t current_pos = 0;
	vector<string>::const_iterator& current_query = _queries.begin();

	if (_queries.empty())
	{
		return 0;
	}

	while(current_query != _queries.end() - 1)
	{
		engine_scores_t scores = eval_scores(current_query);
		engine_scores_t::iterator max_it = std::max_element(scores.begin(), scores.end(), value_comparer);
		unsigned int step = max_it->second;
		if (current_pos + step >= _queries.size())
		{
			break;
		}
		current_pos += step;
		current_query += step;
		switches++;
	}

	return switches;
}

engine_scores_t engine_manager_t::eval_scores(vector<string>::const_iterator queries_start)
{
	engine_scores_t scores;
	unsigned int currentScore = 0;

	for (vector<string>::const_iterator& it = queries_start; it != _queries.end(); ++it, ++currentScore)
	{
		if (scores.count(*it) == 0)
		{
			scores[*it] = currentScore;
		}
	}

	for (vector<string>::const_iterator& it = _engines.begin(); it != _engines.end(); ++it)
	{
		if (scores.count(*it) == 0)
		{
			scores[*it] = _queries.size();
		}
	}

	return scores;
}

void engine_manager_t::read(istream& in)
{
	char buf[100];
	size_t s, q;

	in >> s;
	in.ignore(1, '\n');
	for (size_t i = 0; i < s; ++i)
	{
		in.getline(buf, 100);
		_engines.push_back(string(buf));
	}

	in >> q;
	in.ignore(1, '\n');
	for (size_t i = 0; i < q; ++i)
	{
		in.getline(buf, 100);
		_queries.push_back(string(buf));
	}
}

int main()
{
	ifstream in("saving_universe.in.dat");
	ofstream out("saving_universe.out.dat");
	size_t testCount;	

	in >> testCount;
	for (size_t i = 0; i < testCount; ++i)
	{
		engine_manager_t manager;
		manager.read(in);
		out << "Case #" << i + 1 << ": " << manager.eval_switches() << std::endl;
	}

	return 0;
}
