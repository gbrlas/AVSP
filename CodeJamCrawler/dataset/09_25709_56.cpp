#include <cstdio>
#include <string>
#include <set>
#include <vector>
using namespace std;

char buf[128], buf2[128];
char tot[128*128];
set<string> ss;
double ans;
int p;

inline int isspace(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

double get_number() {
	char tb[32];
	int tp = 0;
	double s;
	for ( ; isspace(tot[p]) ; p++) ;

	for ( ; isdigit(tot[p]) || tot[p] == '.' ; p++)
		tb[tp++] = tot[p];
	tb[tp] = 0;
	sscanf(tb, "%lf", &s);
	return s;
}

string get_word() {
	char tb[32];
	int tp = 0;
	for ( ; isspace(tot[p]) ; p++) ;
	if (tot[p] == ')') {
		++p;
		return ")";
	} else if (tot[p] == '(') {
		++p;
		return "(";
	}
	for ( ; isspace(tot[p]) == 0 ; p++)
		tb[tp++] = tot[p];
	tb[tp] = 0;
	return (string)tb;
}

void parse(int flg) {
	//assert(buf[p] == '(');
	//printf("p:%d\n",p);
	string sss = get_word();
	//if (sss != "(") printf("ooops %s\n",sss.c_str());
	//printf("dslkgla\n");
	double pro = get_number();
	//printf("pro:%f\n",pro);
	if (flg) ans *= pro;
	string ts;
	if ((ts = get_word()) == ")") {
		//printf("ldslg\n");
		return ;
	}
	//printf("ddd\n");
	if (ss.count(ts)) {
		parse(1&flg);
		parse(0);
		get_word();
	} else {
		parse(0);
		parse(1&flg);
		get_word();
	}
}

int main() {
	freopen("a-small.in","r",stdin);
	freopen("a-small.out","w",stdout);
	int T, ca = 0, L, k, n;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&L);
		gets(buf);
		tot[0] = 0;
		while (L--) {
			gets(buf);
			strcat(tot, buf);
			strcat(tot, " ");
		}
		//printf("tot:%s\n",tot);
		printf("Case #%d:\n",++ca);
		scanf("%d",&n);
		while (n--) {
			scanf("%s",buf);
			scanf("%d",&k);
			ss.clear();
			while (k--) {
				scanf("%s",buf2);
				ss.insert((string)buf2);
			}
			p = 0;
			ans = 1.0;
			parse(1);
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}
