#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  
 ifstream cin ("test.txt");
 ofstream cout ("output.out");
  
 int t;
 cin >> t;
 
 int guess1, guess2;
 int table1[4][4];
 int table2[4][4];
 
 vector<int> pos;
 
 for (int i = 0; i < t; i++) {
   
  pos.clear();
   
  cin >> guess1;
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 4; b++) {
      cin >> table1[a][b];
    }
  }
  
  cin >> guess2;
  for (int a = 0; a < 4; a++) {
    for (int b = 0; b < 4; b++) {
      cin >> table2[a][b];
    }
  }
  
  for (int j = 0; j < 4; j++) {
    for (int k = 0; k < 4; k++) {
      if (table1[guess1-1][j] == table2[guess2-1][k]) {
	pos.push_back(table1[guess1-1][j]);
      }
    }
  }
  
  if (pos.size() == 0) {
    cout << "Case #";
    cout << (i+1);
    cout << ": Volunteer cheated!";
    cout << "\n";
  }
  
  if (pos.size() == 1) {
    cout << "Case #";
    cout << (i+1);
    cout << ": ";
    cout << pos[0];
    cout << "\n";
  }
  
  if (pos.size() > 1) {
    cout << "Case #";
    cout << (i+1);
    cout << ": Bad magician!";
    cout << "\n";
  }
    
 }
   
}

