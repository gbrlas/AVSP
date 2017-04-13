//#include <stdio.h>
#include <io.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#define L 15
#define D 5000
#define N 500
#define ALPHA 128

int l,d,n;

vector<char>word[D];
vector<char>ptn[L];
char s[L*ALPHA];

void main() {
	ifstream infile("A-large.in.txt");
	streambuf *inbuf = cin.rdbuf(infile.rdbuf());

	ofstream outfile("A-large.out.txt");
	streambuf *outbuf = cout.rdbuf(outfile.rdbuf());

	for (int k = 0; k < L; k++)
		ptn[k].reserve(ALPHA);

	cin>>l>>d>>n;
	for (int i = 0; i < d; i++) {
		cin>>s;
		for (int j = 0; j < strlen(s); j++)
			word[i].push_back(s[j]);
	}
	for (int j = 0; j  < n; j++) {
		for (int t = 0; t < l; t++)
			for (int i = 0; i < ALPHA; i++)
				ptn[t][i] = 0;
		cin>>s;
		int u = 0;
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == '(') {
				while (s[++i]!=')') ptn[u][s[i]] = 1;
				u++;
			}
			else ptn[u++][s[i]] = 1;
		}
			u = 0;
		for (int v = 0; v < d; v++) {
			for (int t = 0; t < l; t++)
				if (ptn[t][word[v][t]]==0) break;
			if (t == l) u++;
		}
		cout<<"Case #"<<j+1<<": "<<u<<endl;
	}
	
	cin.rdbuf(inbuf);
	infile.close();

	cout.rdbuf(outbuf);
	outfile.close();
}