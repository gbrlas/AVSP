#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool print = false;

int do_it ()
{
	int s;
	int q;
	map<string, int> name_map;

	cin >> s;
	string sname;
	std::getline(cin, sname);

	for (int i = 0; i < s; i++) {
		std::getline(cin, sname);
		name_map[sname] = i;	
		//printf("%s - %d\n", sname.c_str(), i);
	}

	cin >> q;
	vector<int> qvec;
	std::getline(cin, sname);

	for (int i = 0; i < q; i++) {
		std::getline(cin, sname);
		int idx = name_map[sname];
		//printf("%d ", idx);
		qvec.push_back(idx);
	}

	int cnt = s * q;
	int * trace_matrix = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		trace_matrix[i] = -1;
	}

	for (int i = q - 1; i >= 0; i--)
	{
		int * row = trace_matrix + s * i;	
		int cur_se_id = qvec[i]; // current search engine id
		if (i == q - 1) {
			row[cur_se_id] = i;
			continue;
		}

		int * lrow = trace_matrix + s * (i+1); // last row
		memcpy (row, lrow, sizeof(int)*s);
		row[cur_se_id] = i;
	}

	if (print == true) {
		for (int i = 0; i < q; i++) {
			printf("\n");
			int * row = trace_matrix + s * i;
			for (int j = 0; j < s; j++) {
				printf ("| %d |", row[j]);
			}
		}
		printf ("\n");
	}
	
	int trace_cnt = 0;
	for (int i = 0; i < q;) {
		int * row = trace_matrix + i * s;
		int min = *min_element(row, row + s);
		int max = *max_element(row, row + s);

		if (min == -1)
			break;

		trace_cnt ++;
		i = max;
	}

	return trace_cnt;
}

int main(int argc, char ** argv)
{
	if (argc > 1 && strcmp(argv[1], "p") == 0)
	{
		print = true;
	}
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		printf ("Case #%d: %d\n", i+1, do_it());
	}
}
