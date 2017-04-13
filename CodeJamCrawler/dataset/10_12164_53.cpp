//#define _DEB

#ifndef _DEB
	#define inf cin
	#define ouf cout
	#include <iostream>
#else
	#include <fstream>
#endif


long inc_pos(long curpos, long N)
{
	return (curpos + 1) == N ? 0 : curpos + 1;
}


int main()
{
	using namespace std;
#ifdef _DEB
	ifstream inf("input.txt");
	ofstream ouf("output.txt");
#endif

	long i, j, t;
	//Travels
	long R;
	long k, N;
	long g[1000];
	long prise;
	long pos = 0, startpos;
	long people;

	inf >> t;

	for (i = 0; i < t; i++)
	{
		inf >> R >> k >> N;
		for (j = 0; j < N; j++) inf >> g[j];

		prise = 0;
		pos = 0;
		startpos = 0;
		for (j = 0; j < R; j++)
		{
			people = 0;
			startpos = pos;
			while (people + g[pos] <= k)
			{
				people += g[pos];
				pos = inc_pos(pos, N);
				if (pos == startpos) break;
			}

			prise += people;
		}
		ouf << "Case #" << i + 1 << ": " << prise << endl;
	}

#ifdef _DEB
	inf.close();
	ouf.close();
#endif
	return 0;
}
