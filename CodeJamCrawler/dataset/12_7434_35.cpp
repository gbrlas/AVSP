//Mandeep Singh
//mandeep2150@gmail.com
#include <iostream>

using namespace std;

int main(void) {
  string keyl = "ynficwlbkuomxsevzpdrjgthaq"; 
  string keyu = "YNFICWLBKUOMXSEVZPDRJGTHAQ";
  string decl = "abcdefghijklmnopqrstuvwxyz";
  string decu = "ABCDEFGHIJKLMNOPQRSTUVWXYX";
  int inputs;
  int asciic;
  cin >> inputs;
  string word;
  getline(cin, word);
  for (int count=0; count<inputs; ++count) {
    getline(cin, word);
    cout << "Case #" << count+1 << ": ";
    for (int i =0; i<word.size(); ++i) {
      asciic = static_cast<int>(word[i]);
      if( asciic >= 97 ) {
        cout << decl[keyl.find(word[i])];
      }
      else if( asciic < 59 && asciic > 32 ) {
        cout << decu[keyu.find(word[i])];
      }
      else if( asciic == 32 ) {
        cout << " ";
      }
    }
    cout << endl;
    
  }
}