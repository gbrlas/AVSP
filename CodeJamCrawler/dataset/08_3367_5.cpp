// using MS VC++ 2005
#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <tchar.h>
#include <assert.h>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <functional>
using namespace std;

#ifdef _DEBUG
#define DEBUG
#endif

const size_t NOT_USED = 1000000;

size_t indexOf(string item, vector<string>& items) {
	for (size_t i = 0; i < items.size(); ++i) {
		if (item == items[i]) {
			return i;
		}
	}
	throw exception(string("item '" + item + "' is not found").c_str());
}

void countUsage(size_t start, vector<pair<size_t,size_t>>& usage, vector<string>& engines, vector<string>& queries) {
	usage.resize(engines.size());
	fill(usage.begin(), usage.end(), make_pair(NOT_USED, 0));
	while (start < queries.size()) {
		string query = queries[start];
		size_t index = indexOf(query, engines);
		if (usage[index].first == NOT_USED) {
		  usage[index].first = start;
		}
		++start;
	}
}

bool UDgreater(pair<size_t,size_t> a, pair<size_t,size_t> b) {
	return a.first > b.first;
}

void solve(int& currentSolution, size_t level, vector<string>& engines, vector<string>& queries, size_t currentEngine, size_t pos, int changes) {
	assert(level < queries.size());
#ifdef DEBUG
	printf("%*c %d:solve current=%s pos=%d changes=%d\n", level + 1, ' ', level, currentEngine == NOT_USED ? "NONE" : engines[currentEngine].c_str(), pos, changes);
#endif
	if (pos < queries.size()) {
		const int nextChanges = changes + (currentEngine == NOT_USED ? 0 : 1);
		if (nextChanges >= currentSolution) return;
		vector<pair<size_t,size_t>> usage;
		countUsage(pos, usage, engines, queries);
		size_t currentQuery = indexOf(queries[pos], engines);
		for (size_t i = 0; i < engines.size(); ++i) {
			usage[i].second = i;
		}
		sort(usage.begin(), usage.end(), UDgreater);
		for (size_t i = 0; i < engines.size(); ++i) {
			size_t next = usage[i].second;
			if (next == currentQuery) continue;
			size_t nextPos = usage[i].first == NOT_USED ? queries.size() : usage[i].first;
			solve(currentSolution, level + 1, engines, queries, next, nextPos, nextChanges);
			break;
		}
#ifdef DEBUG
		printf("%*c %d:result(%s)=%d\n", level + 1, ' ', level, currentEngine == NOT_USED ? "NONE" : engines[currentEngine].c_str(), currentSolution);
#endif
	}
	else {
#ifdef DEBUG
		printf("%*c %d:result(%s)=%d\n", level + 1, ' ', level, currentEngine == NOT_USED ? "NONE" : engines[currentEngine].c_str(), changes);
#endif
		if (changes < currentSolution) {
			currentSolution = changes;
		}
	}
}

void execute() {
	char buffer[1024];
	gets(buffer);
	int numberOfCases;
	if (sscanf(buffer, "%d", &numberOfCases) != 1) {
		throw exception("wrong number of cases");
	}
	for (int i = 0; i < numberOfCases; ++i) {
		int numberOfEngines;
		gets(buffer);
		if (sscanf(buffer, "%d", &numberOfEngines) != 1) {
			throw exception("wrong number of engines");
		}
		vector<string> engines;
		for (int j = 0; j < numberOfEngines; ++j) {
			gets(buffer);
			engines.push_back(buffer);
		}
		int numberOfQueries;
		gets(buffer);
		if (sscanf(buffer, "%d", &numberOfQueries) != 1) {
			throw exception("wrong number of queries");
		}
		vector<string> queries;
		for (int j = 0; j < numberOfQueries; ++j) {
			gets(buffer);
			queries.push_back(buffer);
		}
		fprintf(stderr, "== CASE %d (engines %d, queries %d)==\n", i + 1, numberOfEngines, numberOfQueries);
		int solution = NOT_USED;
		solve(solution, 0, engines, queries, NOT_USED, 0, 0);
		printf("Case #%d: %d\n", i + 1, solution);
	}
}

int main(int argc, char* argv[]) {
	try {
		execute();
	}
	catch (exception& e) {
		printf("Error: %s\n", e.what());
	}
	return 0;
}
