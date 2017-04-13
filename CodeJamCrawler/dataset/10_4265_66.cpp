#include <fstream>
using namespace std;

ifstream in("A-large.in");
ofstream out("A-large.out");


int main()
{
	int t, n, k;
	in >> t;
	for (int ii = 0; ii < t; ++ii)
	{
		in >> n >> k;
		bool on = true;
		for (int i = 0; i < n; ++i)
		{
			if (!((1<<i)&k))
			{
				on = false;
				break;
			}
		}

		out << "Case #" << (ii + 1) << ": " << (on ? "ON": "OFF") << '\n';
	}

	return 0;
}