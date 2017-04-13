#include"macro.h"

string permute(vector<int> p, string k) {
	string answer="";

	for(int i=0; i<p.sz; i++) 
		answer=answer+k[p[i]];
	
	return answer;	
}

int compress(string a, int k, char prev) {
	if (k == a.sz) return 0;
	if (a[k] == prev ) return compress(a,k+1,a[k]);
	else return compress(a,k+1,a[k])+1;
}
int solve() {
	string s;
	int k,size;
	vector<int> p;


	scanf("%d",&k);
	for(int i=0; i<k; i++)
		p.push_back(i);


	cin>>s;
	size = s.sz;
	int answer = INT_MAX;


	do {
		string str="";
		for(int g=0; g<	size/k; g++) 
			str= str+ permute(p,s.substr(g*k,k));	
		
		answer = min(answer, compress(str,0,'!'));
	} while(next_permutation(p.begin(), p.end()));

	return answer;
}
int main() {
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	FOR(i,1,t)  {		
		long long answer = solve();				
		cout<<"Case #"<<i<<": "<<answer<<endl;
	}
	return 0;
}
