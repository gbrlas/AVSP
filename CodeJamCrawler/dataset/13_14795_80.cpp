#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;
typedef unsigned long long ull;

bool checkKaibun(ull num) {
  ostringstream ss;
  unsigned int compLen;
  string front, back;

  ss << num;
  string sNum = ss.str();
  ss.str("");
  ss.clear(ostringstream::goodbit);

  compLen = sNum.size() / 2;
  if(sNum.size() % 2 == 1) {
    front = sNum.substr(0, compLen);
    back = sNum.substr(compLen + 1, compLen);
  }
  else {
    front = sNum.substr(0, compLen);
    back = sNum.substr(compLen, compLen);
  }

  if(front == back)
    return true;
  else
    return false;
}
void getSquareList(ull A, ull B, vector<ull>& sList) {
  ull sq;
  for(ull i = A; i <=B; i++) {
    sq = sqrt(i);
    if(sq * sq == i && checkKaibun(sq) == true) {
      sList.push_back(i);
    }
  }
  return;
}


#if 0
void getKaibun(ull A, ull B, vector<ull>& kList) {
  unsigned int digiNum = 1;
  ostringstream ss;
  string dat;
  string tmp;
  while(1) {
    dat = "";
    if(digiNum % 2 == 1) { //digiNum is Odd
      if(digiNum == 1) {
        for(ull i = 1; i <=9; i++) {
          klist.push_back(i);
        }
      }
      else {
        vector<string> base;
        for(int j = 0; j <= 9; j++) {
            ss << j;
            base.push_back(ss.str());
            ss.str("");
            ss.clear(ostringstream::goodbit);
        }

        for(int i = 1; i < digiNum; i += 2) {
          for(int j = 0; j <= base.size(); j++) {
            ss << j;
            tmp = ss.str() + dat + ss.str();
            ss.str("");
            ss.clear(ostringstream::goodbit);
            cout << "loop:" << tmp << endl;
          }
        }
        cout << dat << endl;
      }
    }
    else { //digiNum is Even
    }
    if(digiNum == 5)
      break;
    digiNum++;
    cout << digiNum << endl;
  }
  return;
}
#endif

int solve(long long A, long long B) {
  ull num = 0;
  vector<ull> kList;
  getSquareList(A, B, kList);
  for(int i = 0; i < kList.size(); i++)
    if(checkKaibun(kList[i]) == true){
      num++;
      //cout << kList[i] << endl;
    }
  return num;
}

int main() {
    int T;
    long long A, B;
    int tmp;

    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> A >> B;
        int answer = solve(A, B);
        cout << "Case #" << i << ": " << answer << endl;
    }
}
