#include "iostream"
#include "fstream"

using namespace::std;

int main() {

  ifstream in("A-small-attempt0.in");
  ofstream out("A-small.out");

  int i, j, k, t, n;
  double win[100], tot[100], wp[100], owp[100], oowp[100], temp1, temp2;
  double rpi[100], win1, tot1;
  char sch[10][10];
  
  in >> t;

  for (i = 0; i < t; i++) {
    in >> n;
    for (j = 0 ; j < n;j++)
      for (k = 0; k < n;k++)
	in >> sch[j][k];

    for (j = 0 ; j < n;j++) {
      win[j] = 0;
      tot[j] = 0;
      for (k = 0; k < n;k++) {
	if (sch[j][k] == '1') {
	  win[j]++;
	  tot[j]++;
	}
	else if (sch[j][k] == '0')
	  tot[j]++;
      }
    }

    for (j = 0; j < n; j++)
      wp[j] = win[j]/tot[j];

    for (j = 0; j < n; j++) {
      temp1 = 0;
      temp2 = 0;
      for (k = 0; k < n; k++) {
	win1 = win[k];
	tot1 = tot[k];
	if (sch[j][k] == '1') {
	  tot1--;
	}
	else if (sch[j][k] == '0') {
	  tot1--;
	  win1--;
	}

	if (sch[j][k] == '1' || sch[j][k] == '0') {
	  temp1 += (win1/tot1);
	  temp2++;
	}
      }
      owp[j] = temp1/temp2;
    }

    for (j = 0; j < n; j++) {
      temp1 = 0;
      temp2 = 0;
      for (k = 0; k <n; k++)
	if (sch[j][k] == '1' || sch[j][k] == '0') {
	  temp1 += owp[k];
	  temp2++;
	}
      oowp[j] = temp1/temp2;
    }

    out << "Case #" << i + 1 << ":" << endl;

    for (j = 0; j < n; j++) {
      rpi[j] = (0.25 * wp[j]) + (0.5 * owp[j]) + (0.25 * oowp[j]);

      out << rpi[j] << endl;
    }
    
  }

  return(0);
}
