// basic file operations
#include <iostream>
#include <fstream>
#include <iostream>
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
  int nr;
  int surprise;
  int target;
  int result;
  list<int> scores;


  inFile >> total;

  for (int i=0;i<total;i++){
    scores.clear();
    result = 0;
    inFile >> nr;
    inFile >> surprise;
    inFile >> target;
    for(int j=0;j<nr;j++){
      int r;
      inFile >> r;
      scores.push_back(r);
    }
    for(auto j : scores){
      int a = floor(((float)j-target)/2);
      int d = (j-target) %2;
      if( a >= target -1  && a+a+target+d >= j){
        result++;
      } else if(surprise > 0 && a >= target -2 && a+a+target+d >= j){
        result++;
        surprise--;
      }
    }
    writeFile(outFile, i+1, result);
    cout<<endl;
  }

  inFile.close();
  outFile.close();
  return 0;
}

void writeFile(ofstream &of, int i, int r){
  of<<"Case #"<<i<<": "<<r<<endl;
}

