#include <string>
#include <stack>
#include <iostream>
#include <vector>

using std::string;
using std::stack;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

#define FIRST_ELEMENT 60
#define MAX_ELEMENTS  40
#define EMPTY         60

struct Combine {
  char with;
  char produce;
  Combine(char w=EMPTY, char p=EMPTY) : with(w), produce(p) { }
};

class Problem {
  Combine      combine_with[MAX_ELEMENTS];
  char         opossed_to[MAX_ELEMENTS];
public:
  Problem() {
    for (int i=0; i<MAX_ELEMENTS; ++i) {
      opossed_to[i] = EMPTY;
    }
  }
  Combine getCombineFromChar(char elem) const {
    return combine_with[elem - FIRST_ELEMENT];
  }
  char getOpossedFromChar(char elem) const {
    return opossed_to[elem - FIRST_ELEMENT];
  }
  void setCombineFromChar(char e1, char e2, char p) {
    combine_with[e1-FIRST_ELEMENT] = Combine(e2, p);
    combine_with[e2-FIRST_ELEMENT] = Combine(e1, p);
  }
  void setOpossedFromChar(char e1, char e2) {
    opossed_to[e1-FIRST_ELEMENT] = e2;
    opossed_to[e2-FIRST_ELEMENT] = e1;
  }
};

void computeElementsList(const Problem &data, string invoke, vector<char> &elements_seq) {
  stack<unsigned int> elements_pos[MAX_ELEMENTS];
  
  for (unsigned int i=0; i<invoke.size(); ++i) {
    char elem       = invoke[i];
    char last_elem  = EMPTY;
    if (!elements_seq.empty()) last_elem = elements_seq[elements_seq.size()-1];
    Combine combine = data.getCombineFromChar(elem);
    char    opossed = data.getOpossedFromChar(elem);
    if (last_elem != EMPTY && combine.with == last_elem) {
      
      elements_pos[last_elem-FIRST_ELEMENT].pop();
      elements_seq.pop_back();
      
      elements_pos[combine.produce-FIRST_ELEMENT].push(elements_seq.size());
      elements_seq.push_back(combine.produce);
      
    }
    else if (!elements_pos[opossed-FIRST_ELEMENT].empty()) {
      for (int i=0; i<MAX_ELEMENTS; ++i)
	while(!elements_pos[i].empty()) elements_pos[i].pop();
      elements_seq.clear();
    }
    else {
      elements_pos[elem - FIRST_ELEMENT].push(elements_seq.size());
      elements_seq.push_back(elem);
    }
  }
}

// 5
// 0 0 2 EA
// 1 QRI 0 4 RRQR
// 1 QFT 1 QF 7 FAQFDFQ
// 1 EEZ 1 QE 7 QEEEERA
// 0 1 QW 2 QW

int main() {
  int N;
  cin >> N;
  for (int i=0; i<N; ++i) {
    Problem p;
    int M;
    cin >> M;
    for (int j=0; j<M; ++j) {
      // combines
      string combine;
      cin >> combine;
      p.setCombineFromChar(combine[0], combine[1], combine[2]);
    }
    cin >> M;
    for (int j=0; j<M; ++j) {
      // opossed
      string opossed;
      cin >> opossed;
      p.setOpossedFromChar(opossed[0], opossed[1]);
    }
    cin >> M;
    string invoke;
    cin >> invoke;
    vector<char> elements_seq;
    computeElementsList(p, invoke, elements_seq);
    cout << "Case #" << (i+1) << ": [";
    for (unsigned int j=0; j<elements_seq.size(); ++j) {
      cout << elements_seq[j];
      if (j != elements_seq.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
  }
}
