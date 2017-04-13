#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
 
using namespace std;

ifstream fin("A-small.in");
ofstream fout("A-small.out");

char mapping[] = "yhesocvxduiglbkrztnwjpfmaq";

void solve(int cn, vector<string> line) {
    int N = line.size();
    string ans;
    for (int i=0 ; i < N; i++) {
        string word = line[i];
        for(int j = 0; j < word.size(); j++) {
            ans += mapping[word[j]-'a'];
        }
        if (i != N) ans += ' ';
    }
 
    fout << "Case #" << cn << ": " << ans << endl;
}

int main() {

    int CASES;
    fin >> CASES;
    string dummieLine;
    getline(fin, dummieLine);    // New line.
    for (int i=1; i<=CASES; i++) {
        string line; 
        getline(fin, line);
        stringstream ss(line);
        vector<string> text;
        string word;
        while(ss >> word) text.push_back(word);

        solve(i, text);
    }
    return 0;
}

