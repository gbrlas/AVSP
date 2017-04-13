#include <fstream>
using namespace std;

ifstream in("A-small-attempt0.in");
ofstream out("a-small.out");


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