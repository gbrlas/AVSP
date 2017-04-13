#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <strstream>

using namespace std;

#define MAX_LINE_LEN 1024
//#define USE_STDOUT

#ifdef USE_STDOUT
#include <stdlib.h>
#endif

static bool readline (FILE *in, char *line, int maxlen)
{
	char c, pos;
	if (!in || !line || maxlen <= 1 || feof (in))
		return false;

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

static bool readint (FILE *in, int &num)
{
	char line [MAX_LINE_LEN + 1];
	if (!in) return false;

	if (!readline (in, line, MAX_LINE_LEN)) {
		return false;
	}

	return 1 == sscanf (line, "%d", &num);
}

static void gen_primes (vector<double> &primes)
{
	char *p = (char*)malloc (sizeof(char)*2000000);
	int i;
	memset(p,0,2000000);
	for (i=2; i<2000000;i++){
		for (int j = i + i; j < 2000000; j += i) {
			p[j] = 1;
		}
	}

	for (i = 2; i < 2000000; i++){
		if (!p[i]) {
			primes.push_back (i);
		}
	}
	free (p);
}

static void solve (FILE *in, FILE *out)
{
	int tests, test;
	char line [MAX_LINE_LEN + 1];
	int *arr = (int*)malloc(sizeof(int)*1000000);

	if (!readline (in, line, MAX_LINE_LEN)) {
		return;
	}

	if (sscanf (line, "%d", &tests) != 1) {
		return;
	}

	for (test = 1; test <= tests; test++) {
		int K, i, pos, tot;

		memset (arr, 0, sizeof(int)*1000000);
		readint (in, K);

		pos = K-1;
		for (i=0; i<K; i++) {
			for(int from=i+1;from>0;) {
				pos=pos+1;
				if (pos>=K) pos=0;
				if (arr[pos]==0){
					from--;
					/*if(!from) break;*/
				}
			}
			arr[pos]=i+1;
		}

		fprintf (out, "Case #%d:", test);

		fscanf (in, "%d ", &tot);
		for (i=0; i<tot; i++){
			int idx;
			fscanf (in, "%d ", &idx);
			fprintf (out, " %d", arr[idx-1]);
		}

		fprintf (out, "\n");
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
