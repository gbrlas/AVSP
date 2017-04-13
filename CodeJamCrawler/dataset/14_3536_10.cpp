inline VS split(const string& s, const string& delim) {
	VS v;
	size_t start = 0, end = 0;
	while ((end = s.find(delim, start)) != string::npos) {
		v.push_back(s.substr(start, end - start));
		start = end + delim.length();
	}
	v.push_back(s.substr(start));
	return v;
}
template<class T>
inline T tonum(const string& s) {
	T v;
	istringstream si(s);
	si >> v;
	return v;
}

struct Case {
	int N;
	VS ss;
};

class B {

public:
	Case readCase( ifstream& ifs ) {
		string line;
		Case case_;
		if (getline(ifs, line)) { 
			case_.N = tonum<int>(line);
		}
		if (getline(ifs, line)) { 
			case_.ss = split(line, " ");
		}
		
		return case_;
	}
	
	LL solve( Case case_ ) {
		VS sss;
		FORV(i,case_.ss) {
			if (case_.ss[i].size()<3) {
				sss.pb(case_.ss[i]);
				continue;
			}
			string s = "";
			s += case_.ss[i][0];
			for(int j=1; j<case_.ss[i].size()-1; j++) {
				if (case_.ss[i][j-1]!=case_.ss[i][j] || case_.ss[i][j+1]!=case_.ss[i][j]) s+=case_.ss[i][j];
			}
			s += case_.ss[i][case_.ss[i].size()-1];
			sss.pb(s);
		}
		
		VI perm;
		int mod = 1000000007;
		for (int i = 0; i < case_.N; i++) perm.pb(i);
		int res = 0;
		set<char> chars;
		{
			string s = "";
			FORV(i,perm) {
				s += sss[perm[i]];
			}
			//cout << s << endl;
			int count = 0;
			FORV(i,s) chars.insert(s[i]);
		}
		do {
			string s = "";
			FORV(i,perm) {
				s += sss[perm[i]];
			}
			//cout << s << endl;
			int count = 1;
			for(int i=1; i<s.size(); i++) {
				if (s[i]!=s[i-1]) count++;
			}
			if (count==chars.size()) {
				res++;
				if (res>mod) res-=mod;
			}
			
		} while (next_permutation(ALL(perm)));
		return res;
	}
};
