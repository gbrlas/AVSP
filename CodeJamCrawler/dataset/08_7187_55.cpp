#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

#define TRACE_DEBUG(s, ...) printf(s##"\n", __VA_ARGS__)

enum station_t {stationA, stationB};

typedef std::multimap<unsigned int, unsigned int> time_table_t;
typedef std::multimap<unsigned int, station_t> arrival_table_t;

inline const char* to_string(station_t station)
{
	return station == stationA ? "A" : "B";
}

class train_manager_t
{
public:
	train_manager_t() 
		: _a(0), _b(0), 
		  _a_min(0), _b_min(0) 
	{}

	void read(istream& in);

	void solve();

	size_t a_count() const { return _a_count; }
	size_t b_count() const { return _b_count; }

	void schedule_train(time_table_t::iterator& tt_it, station_t from, station_t to);
	void schedule_turnaround(unsigned int end_time, station_t dst);

	bool isArrivalTrainSmallerThenAB(time_table_t::iterator& a, time_table_t::iterator& b)
	{
		if (_arrival_table.empty()) {
			return false;
		}

		if (a != _a_table.end() && _arrival_table.begin()->first > a->first) {
			return false;
		}

		if (b != _b_table.end() && _arrival_table.begin()->first > b->first)
		{
			return false;
		}

		return true;
	}

private:
	time_table_t _a_table;
	time_table_t _b_table;
	unsigned int _turnaround;
	arrival_table_t _arrival_table;
	size_t _a_required, _b_required;
	size_t _a_count, _b_count;
	int _a, _b;
	int _a_min, _b_min;
};

void train_manager_t::solve()
{	
	time_table_t::iterator a_table_it = _a_table.begin();
	time_table_t::iterator b_table_it = _b_table.begin();
	
	while(a_table_it != _a_table.end() || b_table_it != _b_table.end())
	{
		if (isArrivalTrainSmallerThenAB(a_table_it, b_table_it))
		{
			TRACE_DEBUG("arrived train to %s", to_string(_arrival_table.begin()->second));
			if (_arrival_table.begin()->second == stationA)
			{
					_a++;
			} else if (_arrival_table.begin()->second == stationB) {
					_b++;
			} else { throw std::runtime_error("dst error"); }
			_arrival_table.erase(_arrival_table.begin());
		} else if (a_table_it == _a_table.end()) 
		{
			schedule_train(b_table_it, stationB, stationA);;
		} else if (b_table_it == _b_table.end()) 
		{
			schedule_train(a_table_it, stationA, stationB);
		} else if (a_table_it->first <= b_table_it->first)
		{
			schedule_train(a_table_it, stationA, stationB);
		} else {
			schedule_train(b_table_it, stationB, stationA);;
		}
	}

	_a_count = std::abs(std::min(_a_min, 0));
	_b_count = std::abs(std::min(_b_min, 0));
}

void train_manager_t::schedule_train(time_table_t::iterator& tt_it, station_t from, station_t to)
{
	TRACE_DEBUG("started train from %s to %s", to_string(from), to_string(to));

	schedule_turnaround(tt_it->second, to);
	tt_it++;

	if (from == stationA)
	{
		_a--;
		_a_min = std::min(_a_min, _a);
	} else {
		_b--;
		_b_min = std::min(_b_min, _b);
	}
}

void train_manager_t::schedule_turnaround(unsigned int end_time, station_t dst)
{
	_arrival_table.insert(arrival_table_t::value_type(end_time + _turnaround, dst));
}

void train_manager_t::read(istream& in)
{
	unsigned int hour, minute;
	unsigned int start, end;

	in >> _turnaround >> _a_required >> _b_required;

	for (size_t i = 0; i < _a_required; ++i)
	{
		in >> hour;
		in.ignore(1, ':');
		in >> minute;
		start = hour * 60 + minute;

		in >> hour;
		in.ignore(1, ':');
		in >> minute;
		end = hour * 60 + minute;

		_a_table.insert(time_table_t::value_type(start, end));
	}

	for (size_t i = 0; i < _b_required; ++i)
	{
		in >> hour;
		in.ignore(1, ':');
		in >> minute;
		start = hour * 60 + minute;

		in >> hour;
		in.ignore(1, ':');
		in >> minute;
		end = hour * 60 + minute;

		_b_table.insert(time_table_t::value_type(start, end));
	}
}

int main()
{
	ifstream in("train_timetable.in.dat");
	ofstream out("train_timetable.out.dat");
	size_t testCount;	

	in >> testCount;
	for (size_t i = 0; i < testCount; ++i)
	{
		train_manager_t manager;
		manager.read(in);
		manager.solve();
		out << "Case #" << i + 1 << ": " 
			<< manager.a_count() << " " << manager.b_count() << std::endl;
	}

	return 0;
}