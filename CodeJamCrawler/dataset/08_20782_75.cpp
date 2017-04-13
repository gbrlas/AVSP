#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class trip
{
public:
	int start;
	int end;
};

bool compA (trip T1, trip T2)
{
	return (T1.start < T2.start)?true:false;
}

bool compB (trip T1, trip T2)
{
	return (T1.end < T2.end)?true:false;
}

/* Used for every case on time. */
void everycase (fstream &fs, fstream &fs2, int no)
{
	int turnaround, start_A, start_B;
	vector <trip> T_A, T_B;
	stringstream ss;
	string s;
	getline (fs, s);
	ss << s;
	ss >> turnaround;

	getline (fs, s);
	string sA, sB;
	int x = s.find (' ',0);
	sA = s.substr (0, x);
	sB = s.substr (x + 1, s.size () - x - 1);
	ss.clear ();
	ss << sA;
	ss >> start_A;
	ss.clear ();
	ss << sB;
	ss >> start_B;

	/*Compute the time. */
	for (int i = 0; i < start_A; i++)
	{
		trip T;
		getline (fs, s);
		string s1, s2;
		int x = s.find (' ', 0);
		s1 = s.substr (0, x);
		s2 = s.substr (x + 1, s.size () - x - 1);

		string s11, s12, s21, s22;	
		int h11, h12, h21, h22;
		x = s1.find (':', 0);
		s11 = s1.substr (0, x);
		s12 = s1.substr (x+1, s1.size () - x - 1);
		ss.clear ();
		ss << s11;
		ss >> h11;

		ss.clear ();
		ss << s12;
		ss >> h12;
		T.start = h11 * 60 + h12;

		x = s2.find (":", 0);
		s21 = s2.substr (0, x);
		s22 = s2.substr (x + 1, s2.size () - x - 1);
		ss.clear ();
		ss << s21;
		ss >> h21;
		ss.clear ();
		ss << s22;
		ss >> h22;
		T.end = 60 * h21 + h22 + turnaround;
		T_A.push_back (T);
	}

	for (int i = 0; i < start_B; i++)
	{
		trip T;
		getline (fs, s);
		string s1, s2;
		int x = s.find (' ', 0);
		s1 = s.substr (0, x);
		s2 = s.substr (x + 1, s.size () - x - 1);

		string s11, s12, s21, s22;	
		int h11, h12, h21, h22;
		x = s1.find (':', 0);
		s11 = s1.substr (0, x);
		s12 = s1.substr (x+1, s1.size () - x - 1);
		ss.clear ();
		ss << s11;
		ss >> h11;

		ss.clear ();
		ss << s12;
		ss >> h12;
		T.start = h11 * 60 + h12;

		x = s2.find (":", 0);
		s21 = s2.substr (0, x);
		s22 = s2.substr (x + 1, s2.size () - x - 1);
		ss.clear ();
		ss << s21;
		ss >> h21;
		ss.clear ();
		ss << s22;
		ss >> h22;
		T.end = 60 * h21 + h22 + turnaround;
		T_B.push_back (T);
	}

	vector <trip> T_A1(T_A);
	vector <trip> T_B1 (T_B);

	sort (T_A.begin (), T_A.end (), compA);
	sort (T_B.begin (), T_B.end (), compB);
	sort (T_A1.begin (), T_A1.end (), compB);
	sort (T_B1.begin (), T_B1.end (), compA);

	int min_A = 0, min_B = 0;

	for (int i = 0; i < T_A.size (); i++)
	{
		int num_come = 0, num_out = 0;
		trip T = T_A[i];
		num_out = i + 1;
		for (int j = 0; j < T_B.size () && T_B[j].end <= T.start; j++)
		{
			num_come++;	
		}
		if (min_A + num_come < num_out)
			min_A = num_out-num_come;
	}

	for (int i = 0; i < T_B1.size (); i++)
	{
		int num_come = 0, num_out = 0;
		trip T = T_B1[i];
		num_out = i + 1;
		for (int j = 0; j < T_A1.size () && T_A1[j].end <= T.start; j++)
		{
			num_come++;
		}
		if (min_B + num_come < num_out)
				min_B = num_out - num_come;
	}

	fs2 << "Case #" << no << ": "<<min_A << " "<<min_B << endl;
	
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
	for (int i = 1; i <= num_cases; i++)
	{
		everycase (fs, fs_out, i);
	}

	fs.close ();
	fs_out.close ();
}
