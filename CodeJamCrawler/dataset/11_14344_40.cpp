#include<iostream>
#include<cstdio>
using namespace std;
const int BUF = 105;

int nMan;
char win[BUF][BUF];

void read(){
  cin >> nMan;
  for(int i=0;i<nMan;i++)
    for(int j=0;j<nMan;j++)
      cin >> win[i][j];
}


void work(int cases){
  double WP[BUF], OWP[BUF], OOWP[BUF];

  // WP
  for(int i=0;i<nMan;i++){
    int cntWin = 0, cntMatch = 0;
    for(int j=0;j<nMan;j++){
      cntWin += win[i][j]=='1';
      cntMatch += win[i][j]!='.';
    }
    WP[i] = 1.0*cntWin/cntMatch;
  }

  // OWP
  for(int self=0;self<nMan;self++){
    int cntOpp = 0;
    OWP[self] = 0;
    for(int opp=0;opp<nMan;opp++){
      if(win[self][opp]=='.') continue;
      cntOpp++;
      int cntWin = 0, cntMatch = 0;
      for(int i=0;i<nMan;i++){
        if(i==self) continue;
        cntWin += win[opp][i]=='1';
        cntMatch += win[opp][i]!='.';
      }
      OWP[self] += 1.0*cntWin/cntMatch;
    }
    OWP[self] /= cntOpp;
  }

  // OOWP
  for(int i=0;i<nMan;i++){
    double sumOWP = 0;
    int cntMatch = 0;
    for(int j=0;j<nMan;j++){
      if(win[i][j]!='.'){
        sumOWP += OWP[j];
        cntMatch++;
      }
    }
    OOWP[i] = sumOWP/cntMatch;
  }

  cout << "Case #" << cases << ':' << endl;
  for(int i=0;i<nMan;i++)
    printf("%.10lf\n",WP[i]/4+OWP[i]/2+OOWP[i]/4);
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
