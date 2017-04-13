#include <iostream>
#include <vector>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int gg=0;gg<t;gg++){
    vector <int> izbor(4,0);
    int bv;
    int poz;
    cin >> poz;
    for(int i=1;i<=4;i++){
      if(i==poz){
	for(int j=0;j<4;j++){cin >> izbor[j];}
      } else {
	for(int j=0;j<4;j++){cin >> bv;}
      }
    }
    cin >> poz;
    int st=0;
    int kateri=0;
    for(int i=1;i<=4;i++){
      if(i==poz){
	for(int j=0;j<4;j++){
	  int tren;
	  cin >> tren;
	  for(int k=0;k<4;k++){
	    if(izbor.at(k)==tren){st++;kateri=izbor.at(k);}
	  }
	}
      } else {
	for(int j=0;j<4;j++){cin >> bv;}
      }
    }
  cout << "Case #" << gg+1;
  if(st==0){cout << ": Volunteer cheated!\n";}
  if(st==1){cout << ": " << kateri << '\n';}
  if(st>1){cout << ": Bad magician!\n";}
  }
  return 0;
}