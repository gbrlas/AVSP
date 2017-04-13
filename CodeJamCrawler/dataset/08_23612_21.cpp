#define _CRT_SECURE_NO_WARNINGS
/*
#ifdef SPOJ
#define SCANF(s1,s2) scanf(s1, s2)
#define SCANF2(s1,s2,s3) scanf(s1, s2, s3)
#define SCANF3(s1,s2,s3,s4) scanf(s1, s2, s3, s4)
#define SCANF4(s1,s2,s3,s4,s5) scanf(s1, s2, s3, s4, s5)
#define SCANF5(s1,s2,s3,s4,s5, s6) scanf(s1, s2, s3, s4, s5, s6)
#define GETS(s1) gets(s1)
#else
#define SCANF(s1,s2) fscanf(in, s1, s2)
#define SCANF2(s1,s2,s3) fscanf(in, s1, s2, s3)
#define SCANF3(s1,s2,s3,s4) fscanf(in, s1, s2, s3, s4)
#define SCANF4(s1,s2,s3,s4,s5) fscanf(in, s1, s2, s3, s4, s5)
#define SCANF5(s1,s2,s3,s4,s5, s6) fscanf(in, s1, s2, s3, s4, s5, s6)
#define GETS(s1) fgets(s1, 1000000, in)
#endif
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<list>
#include<deque>
#include<vector>
#include<algorithm>
#include<queue>
#include<time.h>
#include<map>
#include<set>
//#include<iterator>

using namespace std;

struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};
map<char*, int, ltstr> ingredients;

char buffer [100010][30];
int child [1010][100];
int deg [1010];
int ing;

int getId (char* s) {
	int id;
	map<char*, int, ltstr>::iterator it = ingredients.find (s);
	if (it != ingredients.end ())
		id = it->second;
	else {
		id = ing++;
		ingredients.insert (make_pair (s, id));
	}
	return id;
}

int bowls (int node) {
	int m [12], i, c, res;
	if (deg [node] == 0)
		return 1;
	for (i = 0; i < deg [node]; i++)
		m [i] = bowls (child [node][i]);
	sort (m, m + deg [node]);
	c = 0;
	res = 1;
	for (i = deg [node] - 1; i >= 0; i--) {
		if (m [i] + c > res)
			res = m [i] + c;
		c++;
	}
	if (res == deg [node])
		res++;
	return res;
}

int main (void) {
	FILE *in, *out;
	in = fopen ("test.in", "r");
	out = fopen ("test.out", "w");
	int n, c, i, j, tCase, id, id2, m, wCount;
	fscanf (in, "%d", &c);
	wCount = 0;
	for (tCase = 1; tCase <= c; tCase++) {
		ing = 0;
		ingredients.clear ();
		fscanf (in, "%d", &n);
		for (i = 0; i < n; i++)
			deg [i] = 0;
		for (i = 0; i < n; i++) {
			fscanf (in, "%s", &buffer [wCount][0]);
			id = getId (&buffer [wCount][0]);
			wCount++;
			fscanf (in, "%d", &m);
			for (j = 0; j < m; j++) {
				fscanf (in, "%s", &buffer [wCount][0]);
				if (buffer [wCount][0] >= 'A' && buffer [wCount][0] <= 'Z') {
					id2 = getId (&buffer [wCount][0]);
					wCount++;
					child [id][deg [id]++] = id2;
				}				
			}
		}
		fprintf (out, "Case #%d: %d\n", tCase, bowls (0));
	}
}



