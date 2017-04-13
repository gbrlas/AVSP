#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_LINE_LEN 1024
//#define USE_STDOUT

#ifdef USE_STDOUT
#include <stdlib.h>
#endif

static int readline (FILE *in, char *line, int maxlen)
{
	char c, pos;
	if (!in || !line || maxlen <= 1 || feof (in))
		return 0;

	pos = 0;
	while (c = fgetc (in), !feof (in) && pos < maxlen - 1) {
		if (c == 0x0a)
			break;
		if (c != 0x0d) {
			line [pos] = c;
			pos ++;
		}
	}

	line [pos] = 0;
	return pos < maxlen;
}

static void goTrain(int time, vector<pair<int,int> > &dest, vector<pair<int,int>> &src, int T)
{
	int di, dsz = dest.size();
	int si, ssz = src.size();
	di = 0; si = 0;
	while (true){
		bool have=false;
		for (;di < dsz; di++) {
			if (time <= dest[di].first) {
				time = dest[di].second + T;
				dest.erase (dest.begin()+di);
				dsz--;
				have = true;
				break;
			}
		}
		if (!have) break;
		have=false;
		for (;si < ssz; si++) {
			if (time <= src[si].first) {
				time = src[si].second + T;
				src.erase (src.begin()+si);
				ssz--;
				have = true;
				break;
			}
		}
		if (!have) break;
	}
}

static void solve (FILE *in, FILE *out)
{
	int tests, test;
	char line [MAX_LINE_LEN + 1];

	if (!readline (in, line, MAX_LINE_LEN)) {
		return;
	}

	if (sscanf (line, "%d", &tests) != 1) {
		return;
	}

	test = 1;
	while (test <= tests && readline (in, line, MAX_LINE_LEN)) {
		int resA = 0, resB = 0;
		int T, NA, NB, fh, fm, th, tm;
		vector<pair<int,int>> A2B, B2A;

		sscanf (line, "%d", &T);
		readline (in, line, MAX_LINE_LEN);
		sscanf (line, "%d %d", &NA, &NB);
		while (NA > 0) {
			readline (in, line, MAX_LINE_LEN);
			sscanf (line, "%02d:%02d %02d:%02d", &fh, &fm, &th, &tm);
			A2B.push_back (pair<int,int>(fh*60+fm, th*60+tm));
			NA--;
		}

		while (NB > 0) {
			readline (in, line, MAX_LINE_LEN);
			sscanf (line, "%02d:%02d %02d:%02d", &fh, &fm, &th, &tm);
			B2A.push_back (pair<int,int>(fh*60+fm, th*60+tm));
			NB--;
		}

		sort (A2B.begin(), A2B.end());
		sort (B2A.begin(), B2A.end());

		while (!A2B.empty () && !B2A.empty ()) {
			if (A2B.begin ()->first < B2A.begin()->first) {
				pair<int,int> p = *A2B.begin ();
				A2B.erase (A2B.begin());

				resA++;
				goTrain (p.second+T, B2A, A2B, T);
			} else {
				pair<int,int> p = *B2A.begin ();
				B2A.erase (B2A.begin());

				resB++;
				goTrain (p.second+T, A2B, B2A, T);
			}
		}

		resA+=A2B.size();
		resB+=B2A.size();

		fprintf (out, "Case #%d: %d %d\n", test, resA, resB);
		test++;
	}
}

int main (void)
{
	FILE *out;
	FILE *in = fopen ("data.in", "rb");

	#ifdef USE_STDOUT
		out = stdout;
	#else
		out = fopen ("data.out", "wt");
	#endif

	if (!in) {
		fprintf (stderr, "No input file!\n");
		#ifndef USE_STDOUT
			if (out)
				fclose (out);
		#endif
		return 1;
	}

	if (!out) {
		fprintf (stderr, "Cannot open output file!\n");
		fclose (in);
		return 2;
	}

	solve (in, out);

	fclose (in);
	#ifdef USE_STDOUT
		system ("pause");
	#else
		fclose (out);
	#endif
	return 0;
}
