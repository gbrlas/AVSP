#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <boost/math/constants/constants.hpp>

using namespace std;
using boost::math::constants::pi;

#define TRACE_DEBUG(s, ...) printf(s##"\n", __VA_ARGS__)
//#define TRACE_DEBUG(s, ...)

#define sqr(x) ((x) * (x))

const int MAX_LETTERS = 100;

class app_manager_t
{
public:
	app_manager_t();

	void read(istream& in);

	int countPressedLetters();
	int solve();

private:
	int _P, _K, _L;
	int _frequency[MAX_LETTERS];
};

app_manager_t::app_manager_t()
{
	std::fill(_frequency, _frequency + MAX_LETTERS, 0);
}

int app_manager_t::countPressedLetters()
{
	int count = 0;
	for (int i = 0; i < _L; ++i)
	{
		if (_frequency[i] > 0)
		{
			count++;
		}
	}
	return count;
}

int app_manager_t::solve()
{
	if (countPressedLetters() > _P * _K)
	{
		return -1;
	}

	std::sort(_frequency, _frequency + _L, std::greater<int>());
	int count = 0;
	for (int i = 0; i < _L; ++i)
	{
		int presses = i / _K + 1;
		TRACE_DEBUG("letter=%d, presses=%d", i, presses);
		count += _frequency[i] * presses;
	}
	return count;
}

void app_manager_t::read(istream& in)
{
	in >> _P >> _K >> _L;
	for (int i = 0; i < _L; ++i)
	{
		in >> _frequency[i];
	}
}

int main()
{
	ifstream in("1_problem.in");
	ofstream out("1_problem.out");
	size_t testCount;	

	in >> testCount;
	for (size_t i = 0; i < testCount; ++i)
	{
		app_manager_t manager;

		TRACE_DEBUG("Case #%d", i + 1);
		manager.read(in);

		int count = manager.solve();
		out << "Case #" << i + 1 << ": ";
		if (count == -1)
		{
			out << "Impossible" << std::endl;
		}
		else
		{
			out << count << std::endl;
		}
	}

	out.close();
	return 0;
}