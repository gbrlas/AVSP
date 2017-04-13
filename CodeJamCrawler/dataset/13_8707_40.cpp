#include <iostream>
//#include <string>

using namespace std;

char primerjaj(char crke1, char crke2, char crke3, char crke4){
  if(crke1=='T'){crke1=crke2;}
  if(crke2=='T'){crke2=crke3;}
  if(crke3=='T'){crke3=crke4;}
  if(crke4=='T'){crke4=crke1;}
  if(crke1==crke2 && crke3==crke4 && crke1 == crke3 && crke1!='.'){return crke1;}
  return '0';
}

int main(){
  int st;
  cin >> st;
  for(int primer=1;primer < st+1; primer++){
    char tabela[4][4];
    bool tr00=1;
    for(int i=0;i<4;i++){
      cin >> tabela[i];
      if(primerjaj(tabela[i][0],tabela[i][1],tabela[i][2],tabela[i][3])!='0'){cout << "Case #" << primer << ": " << primerjaj(tabela[i][0],tabela[i][1],tabela[i][2],tabela[i][3]) << " won" << endl; tr00=0;}
    }
    for(int i=0;i<4;i++){
      if(primerjaj(tabela[0][i],tabela[1][i],tabela[2][i],tabela[3][i])!='0'){cout << "Case #" << primer << ": " << primerjaj(tabela[0][i],tabela[1][i],tabela[2][i],tabela[3][i]) << " won" << endl; tr00=0;}
    }
    if(primerjaj(tabela[0][3],tabela[1][2],tabela[2][1],tabela[3][0])!='0'){cout << "Case #" << primer << ": " << primerjaj(tabela[0][3],tabela[1][2],tabela[2][1],tabela[3][0]) << " won" << endl; tr00=0;}
    if(primerjaj(tabela[0][0],tabela[1][1],tabela[2][2],tabela[3][3])!='0'){cout << "Case #" << primer << ": " << primerjaj(tabela[0][0],tabela[1][1],tabela[2][2],tabela[3][3]) << " won" << endl; tr00=0;}
    if(tr00){
      bool gr1m=1;
      for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
	  if(tabela[i][j]=='.'){gr1m=0; break; break;}
	}
      }
      if(gr1m){cout << "Case #" << primer << ": Draw" << endl;} else{cout << "Case #" << primer << ": Game has not completed" << endl;}
    }
  }
  return 0;
}