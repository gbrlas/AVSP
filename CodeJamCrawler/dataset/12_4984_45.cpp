// basic file operations
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <list>
#include <cmath>

using namespace std;
typedef pair<int, int> result;

result getResult(int credit, vector<int> items);
void writeFile(ofstream &of, int i, int r);

int main()
{

  ifstream inFile("in.txt", ios::in);
  ofstream outFile("out.txt", ios::out);

  string line;
  int total;
  int dlen;
  int pairs;
  int a, b, n;

  inFile >> total;

  for (int i=0;i<total;i++){
    pairs = 0;
    a = 0;
    b = 0;
    inFile >> a;
    inFile >> b;
    stringstream sl;
    string ss;
    sl<<a;
    dlen = sl.str().size();
    map<string,int> mp;

    for(int j=a;j<=b;j++){
      // check permutations of j
      stringstream s;
      s<<j;
      ss = s.str();
      for(int k=0;k<dlen-1;k++){
        stringstream sn;
        if(ss.size()>1){
          sn<<ss.substr(ss.size()-1, 1)<<ss.substr(0,ss.size()-1);
        }
        ss = sn.str();
        sn >> n;
        stringstream mk;
        mk<<j<<" "<<ss;

        if(a<=j && j<n && n<=b && mp[mk.str()] == 0){
          pairs++;
          mp[mk.str()]++;
        }

      }
    }

    writeFile(outFile, i+1, pairs);\
  }

  inFile.close();
  outFile.close();
  return 0;
}

void writeFile(ofstream &of, int i, int r){
  of<<"Case #"<<i<<": "<<r<<endl;
}

