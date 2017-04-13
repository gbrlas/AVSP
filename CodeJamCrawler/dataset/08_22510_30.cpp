#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>
#include <numeric>

using namespace std;
  
#define VAL(u) ((u)-'0')
#define TIME (24*60)

int NA, NB, T;
typedef pair<int,int> pii;
int parse_date(const string& s) {
  return VAL(s[0])*600 + VAL(s[1])*60 + VAL(s[3])*10 +  VAL(s[4]);
}

int arrivalsA[TIME];
int arrivalsB[TIME];
int departuresA[TIME];
int departuresB[TIME];

pii calc() {
  pii best(NA,NB);
  for (int ra = 0 ; ra <= NA ; ++ra) {
    for (int rb = 0 ; rb <= NB ; rb++) {
      // plus rapidement près à partir en premier
      bool ok = true;
      deque<int> readyA(ra, -100);
      deque<int> readyB(rb, -100);
      for (int t = 0 ; t < TIME ; t++) {
	//faire d'abord les arrivées !
	for (int i = 0 ; i < arrivalsA[t] ; i++) {
	  readyA.push_back(t+T);
	}
	for (int i = 0 ; i < arrivalsB[t] ; i++) {
	  readyB.push_back(t+T);
	}
	for (int i = 0 ; i < departuresA[t] ; i++) {
	  if (readyA.empty() || readyA.front() > t) {
	    ok = false; break;
	  }
	  readyA.pop_front();
	}
	for (int i = 0 ; i < departuresB[t] ; i++) {
	  if (readyB.empty() || readyB.front() > t) {
	    ok = false; break;
	  }
	  readyB.pop_front();
	}
      }
      if (ok) {
	if (best.first + best.second > ra + rb)
	  best = make_pair(ra,rb);
      }
    }
  }
  return best;
}

int main() {
  int N;
  cin>>N;
  for (int tt = 0 ; tt < N ; tt++) {
    cin>>T>>NA>>NB;
    fill(arrivalsA, arrivalsA + TIME, 0);
    fill(arrivalsB, arrivalsB + TIME, 0);
    fill(departuresA, departuresA + TIME, 0);
    fill(departuresB, departuresB + TIME, 0);
    cin.ignore();
    for (int a = 0 ; a < NA ; a++) {
      string s;
      getline(cin, s);
      int dep = parse_date(s);
      int arr = parse_date(s.substr(6));
      arrivalsB[arr]++;
      departuresA[dep]++;
    }
    for (int b = 0 ; b < NB ; b++) {
      string s;
      getline(cin, s);
      int dep = parse_date(s);
      int arr = parse_date(s.substr(6));
      arrivalsA[arr]++;
      departuresB[dep]++;
    }
    pii res = calc();
    cout << "Case #"<<tt+1<<": "<< res.first << " "<<res.second << endl;
  }

  return 0;
}
