#include<iostream>
#include<string>
#include<vector>
using namespace std;

int K;
void rotate(int N, vector<string> &tbl)
{
	for (int i=0; i<N; i++) {
		string s = tbl[i];
		string dot, ndot;
		for (int j=0; j<N; j++)
			if (s[j] == '.')
				dot += s[j];
			else
				ndot += s[j];
		tbl[i] = dot+ndot;
	}
}
bool ok(string s, char c)
{
	if (s.find(string(K, c)) != string::npos)
		return true;
	else
		return false;
}
void checkdiag(int N, vector<string> &tbl, bool &rok, bool &bok)
{
	for (int c=0; c<N; c++) {
		string s;
		int i = 0, j = c;
		for (int l=N-c; l>0; l--) {
			s += tbl[i][j];
			i++; j++;
		}
		if (ok(s, 'R'))
			rok = true;
		if (ok(s, 'B'))
			bok = true;
	}
	for (int r=0; r<N; r++) {
		string s;
		int i = r, j = 0;
		for (int l=N-r; l>0; l--) {
			s += tbl[i][j];
			i++; j++;
		}
		if (ok(s, 'R'))
			rok = true;
		if (ok(s, 'B'))
			bok = true;
	}
}
void getit(int N, int K, vector<string> &tbl)
{
	bool rok = false, bok = false;
	rotate(N, tbl);
	for (int i=0; i<N; i++) {
		if (ok(tbl[i], 'R'))
			rok = true;
		if (ok(tbl[i], 'B'))
			bok = true;
	}
	for (int i=0; i<N; i++) {
		string s;
		for (int j=0; j<N; j++)
			s += tbl[j][i];
		if (ok(s, 'R'))
			rok = true;
		if (ok(s, 'B'))
			bok = true;
	}
	checkdiag(N, tbl, rok, bok);
	vector<string> rtbl = tbl;
	for (int i=0; i<N; i++) for (int j=0; j<N; j++)
		rtbl[i][j] = tbl[j][N-i-1];
	checkdiag(N, rtbl, rok, bok);
	if (rok && bok)
		cout<<"Both"<<endl;
	else if (rok)
		cout<<"Red"<<endl;
	else if (bok)
		cout<<"Blue"<<endl;
	else
		cout<<"Neither"<<endl;
}
int main(void)
{
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
		int N;
		cin>>N; cin>>K;
		vector<string> tbl(N);
		for (int j=0; j<N; j++)
			cin>>tbl[j];
		cout<<"Case #"<<i<<": ";
		getit(N, K, tbl);
	}
}
