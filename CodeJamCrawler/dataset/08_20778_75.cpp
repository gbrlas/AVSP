#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/* Used for every case on time. */
int everycase (fstream &fs)
{
	stringstream ss;
	string s;
	int search, query, turn = 0;
	vector <string> search_v, query_v;
	vector <int> q_s_v;
	vector <bool> matched_searches;

	getline (fs, s);
	ss << s;
	ss >> search;


	for (int i = 0; i < search; i++)
	{
		getline (fs, s);
		search_v.push_back (s);
		matched_searches.push_back (false);
	}

	ss.clear ();
	getline (fs, s);
	ss << s;
	ss >> query;


	for (int i = 0; i < query; i++)
	{
		getline (fs, s);
		query_v.push_back (s);
		q_s_v.push_back (-1);

		for (int j = 0; j < search; j++)
		{
			if (query_v[i] == search_v[j])
					q_s_v[i] = j;
		}
	}

	int current_match = 0;

	for (int i = 0; i < query; i++)
	{
		if (q_s_v[i] != -1)
		{
			int k = q_s_v[i];
			if (!matched_searches[k])
			{
				matched_searches[k] = true;
				current_match++;
				if (current_match == search)
				{
					turn++;
					for (int j = 0; j < search; j++)
							matched_searches[j] = false;
					matched_searches[k] = true;	
					current_match = 1;

				}
							
			}
		}
	}

	return turn;
}

/*The main program. */

int main (int argc, char **argv)
{
	fstream fs, fs_out;
	stringstream ss;
	string s;
	int num_cases;
	fs.open (argv[1], fstream::in);
	getline (fs, s);
	ss << s;
	ss >> num_cases;
	fs_out.open ("output", fstream::out);
	for (int i = 0; i < num_cases; i++)
	{
		int k = everycase (fs);
		fs_out << "Case #" << i+1 << ": " << k << endl;
	}

	fs.close ();
	fs_out.close ();
}
