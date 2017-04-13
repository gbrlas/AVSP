#include "global.h"

map<string, int> feat;
vector< pair<double, pii> > d;
vi names;
string ss;
stringstream iss;
set<int> sf;

void Parse()
{
	int nom = SZ(d); d.resize(SZ(d)+1);
	
	string s;
	iss >> s;
	
	iss >> d[nom].first;
	iss >> s;

	if (s[0] == ')') {
		d[nom].second.first = d.back().second.second = -1;
		names.push_back(-2);
		return;
	}

	if (feat.count(s) == 0)
		feat[s] = SZ(feat);

	names.push_back(feat[s]);
	d[nom].second.first = SZ(d);
	Parse();

	d[nom].second.second = SZ(d);
	Parse();

	iss >> s;
}

double Calc(double prob, int nom)
{
	prob *= d[nom].first;
	if (d[nom].second.first == -1) return prob;
	if (sf.find(names[nom]) != sf.end())
		return Calc(prob, d[nom].second.first);
	return Calc(prob, d[nom].second.second);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tt; cin >> tt;
	For(ttt, 0, tt)
	{
		printf("Case #%d:\n", ttt+1);
		feat.clear(); d.clear(); names.clear();
		int n; string s;
		cin >> n; ss = "";
		For(i, 0, n)
		{
			s = ""; while (!SZ(s)) getline(cin, s);
			ForD(j, SZ(s), 0)
				if (s[j] == ')' || s[j] == '(') {
					s.insert(s.begin()+j+1, ' ');
					s.insert(s.begin()+j, ' ');
				}
			ss += s;
		}
		iss.clear();
		iss << ss;
		Parse();
		cin >> n;
		For(i, 0, n)
		{
			cin >> s; int k; cin >> k;
			sf.clear();
			For(j, 0, k) {
				cin >> s;
				if (feat.count(s))
					sf.insert(feat[s]);
			}
			printf("%.7lf\n", Calc(1., 0));
		}
	}
	return 0;
}