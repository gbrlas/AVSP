#include "iostream"
#include "fstream"

using namespace::std;

int main()
{
	ifstream input("D-small-attempt0.in");
	ofstream output("D-small.out");

	int t, n, a[1000], i, j;

	input >> t;

	double count;

	for (i = 0; i < t; i++)
	  {
	    count = 0;
	    input >> n;
	    for (j = 0; j < n; j++)
	      {
		input >> a[j];
		if (j != a[j] - 1)
		  count++;
	      }
	    output << "Case #" << i + 1 << ": " << count << endl;
	  }

	return(0);
}
