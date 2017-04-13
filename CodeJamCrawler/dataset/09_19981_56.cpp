#include <cstdio>
#include <cctype>
#include <cassert>
#include <string>
#include <sstream>
#include <set>
//#include <sleep>

using namespace std;

//Why am I coding this at 4:44am?

char buff[1000000];
char tree[1000000];

set<string> attributes;

long double recurse(char ** s) {
	while (isspace(**s)) (*s)++;
	double multiplierd;
	sscanf(*s, "%lf", &multiplierd);
	long double multiplier = (long double) multiplierd;
	while (!isspace(**s)) (*s)++;
	while (isspace(**s)) (*s)++;
	if (**s == ')') {(*s)++; return multiplier;}//done

	sscanf(*s, "%s", buff);
	string sbuff(buff);
	while (!isspace(**s)) (*s)++;
	while (isspace(**s)) (*s)++;
	assert(**s == '(');
	(*s)++;
	long double tree1 = recurse(s);
	while (isspace(**s)) (*s)++;
	assert(**s == '(');
	(*s)++;
	long double tree2 = recurse(s);
	while (isspace(**s)) (*s)++;
	assert(**s == ')');
	(*s)++;
	if (attributes.count(sbuff) > 0) {
		return tree1 * multiplier;
	} else {
		return tree2 * multiplier;
	}
}

int main() {
	gets(buff);
	int nc;
	sscanf(buff, "%d", &nc);
	for (int c = 1; c <= nc; c++) {
		gets(buff);
		int nl;
		sscanf(buff, "%d", &nl);
		char * s = buff;
		for (int l = 0; l < nl; l++) {
			gets(s);
			while (*s != '\0') s++;
		}
		int i = 0;
		for (s = buff; *s != '\0'; s++) {
			if (*s != ')' && *s != '(') {
				tree[i++] = *s;
			} else {
				tree[i++] = ' ';
				tree[i++] = *s;
				tree[i++] = ' ';
			}
		}
		tree[i++] = ' ';
		tree[i] = '\0';
		gets(buff);
		int na;
		sscanf(buff, "%d", &na);
		printf("Case #%d:\n", c);
		for (int a = 0; a < na; a++) {
			gets(buff);
			attributes.clear();
			stringstream sin(buff);
			string name;
			sin >> name;
			int nt;
			sin >> nt;
			for (int t = 0; t < nt; t++) {
				string attribute;
				sin >> attribute;
				attributes.insert(attribute);
			}

			char * tp = tree;
			while (*tp != '(') tp++;
			tp++;
			double ans = (double) recurse(&tp);
			printf("%lf\n", ans);
		}
	}
	return 0;
}

