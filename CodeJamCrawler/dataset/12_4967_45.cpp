// basic file operations
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>

using namespace std;
typedef pair<int, int> result;

result getResult(int credit, vector<int> items);
void writeFile(ofstream &of, int i, string r);

int main()
{
  map<char, char> translate;
  translate['y'] = 'a';
  translate['n'] = 'b';
  translate['f'] = 'c';
  translate['i'] = 'd';
  translate['c'] = 'e';
  translate['w'] = 'f';
  translate['l'] = 'g';
  translate['b'] = 'h';
  translate['k'] = 'i';
  translate['u'] = 'j';
  translate['o'] = 'k';
  translate['m'] = 'l';
  translate['x'] = 'm';
  translate['s'] = 'n';
  translate['e'] = 'o';
  translate['v'] = 'p';
  translate['q'] = 'z';
  translate['p'] = 'r';
  translate['d'] = 's';
  translate['r'] = 't';
  translate['j'] = 'u';
  translate['g'] = 'v';
  translate['t'] = 'w';
  translate['h'] = 'x';
  translate['a'] = 'y';
  translate['z'] = 'q';
  translate[' '] = ' ';

  ifstream inFile("in.txt", ios::in);
  ofstream outFile("out.txt", ios::out);

  string line;
  int total;
  string in;
  string out;

  inFile >> total;
  getline(inFile, in);

  for (int i=0;i<total;i++){
    in.clear();
    out.clear();
    getline(inFile, in);
    for (int j=0;j<in.size();j++){
      out.push_back(translate[in.at(j)]);
    }
    writeFile(outFile, i+1, out);
  }

  inFile.close();
  outFile.close();
  return 0;
}

void writeFile(ofstream &of, int i, string r){
  of<<"Case #"<<i<<": "<<r<<endl;
}

