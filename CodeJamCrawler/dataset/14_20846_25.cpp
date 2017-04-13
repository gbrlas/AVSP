#include <iostream>
using namespace std;
int main(void) {
 long cases, actual, i, j, cards[2][4][4], answer[2], candidates;
 long first_candidate;
 cin >> cases;
 for(actual=1;actual<=cases;actual++) {
  cout << "Case #" << actual << ": ";
  candidates=0;
  first_candidate=-1;
  cin >> answer[0];
//  cout << answer[0] << endl;
  for(i=0;i<4;i++) {
   cin >> cards[0][i][0] >> cards[0][i][1] >> cards[0][i][2] >> cards[0][i][3];
//   cout << cards[0][i][0] << cards[0][i][1] << cards[0][i][2] << cards[0][i][3]<<endl;
  }
  cin >> answer[1];
//  cout << answer[1] << endl;
  for(i=0;i<4;i++) {
   cin >> cards[1][i][0] >> cards[1][i][1] >> cards[1][i][2] >> cards[1][i][3];
//   cout << cards[1][i][0] << cards[1][i][1] << cards[1][i][2] << cards[1][i][3]<<endl;
  }
  for(i=0;i<4;i++) {
   for(j=0;j<4;j++) {
    if(cards[0][answer[0]-1][i]==cards[1][answer[1]-1][j]) {
     if(candidates==0) {
      candidates++;
      first_candidate=cards[0][answer[0]-1][i];
//      cout << "First candidate: " << first_candidate << endl;
     } else {
//      cout << "Other candidate!" << endl;
      candidates++; break;
     }
    }
   }
   if(candidates>1) break;
  }
  if(candidates==0) {
   cout << "Volunteer cheated!" << endl;
  } else if(candidates==1) {
   cout << first_candidate << endl;
  } else {
   cout << "Bad magician!" << endl;
  }
 }
 return(0);
}
