#include <stdio.h>
#include <math.h> 
#include <iostream>
#include <sstream> 
#include <set> 
#include <map> 
#include <vector> 
#include <list> 
#include <string>
#include <algorithm>

using namespace std;


void PrintResult(int i, int res)
{
		cout<<"Case #"<<i<<": "<<res;
		cout<<"\n";
}

vector<char*> words;
int D, L;

void ReadDictionary()
{
	words.reserve(D);
	for (int i = 0; i < D; ++i) {
		char* word = new char[L];
		for (int j = 0; j < L; ++j) {
			cin >> word[j];
		}
		words.push_back(word);
	}
}

int CalcWord(const string& line, int at, const vector<char*>& win, const int n)
{
   vector<char> chars;
   if (line[at] != '(') {
	   chars.push_back(line[at]);
   }
   else {
	   ++at;
	   while(line[at] != ')') {
		   chars.push_back(line[at]);
		   ++at;
	   }
   }
   ++at;

   const int chsz = chars.size();
   int num = 0;
   for (int i = 0; i < chsz; ++i) {
	   char c = chars[i];
	   vector<char*> wout;
	   const int winsz = win.size();
		for (int j = 0; j < winsz; ++j) {
			if (win[j][n] == c) {
				wout.push_back(win[j]);
			}
		}
		if (wout.size() > 0) {
			num += ((n +1 >= L) ?
				wout.size() //=1
			  : CalcWord(line, at, wout, n+1));
		}
   }
   return num;
}

int CalcWords() 
{
	string line;
	do { 
	   getline(cin,line); 
    } 
    while(line==""); 
	
	return CalcWord(line, 0, words, 0);
}

void Cleanup() {
	for (int i = 0; i < D; ++i) {
		delete [] (words[i]);
	}
}

int main(int argc, char* argv[])
{
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);

	int N;
	cin >> L >> D >> N;

    ReadDictionary();
	for(int i=1;i<=N;++i)
	{
		int res = CalcWords();
		PrintResult(i, res);
	}
	Cleanup();
	return 0;
}
