#include <iostream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream iFile;
  ofstream oFile;
  iFile.open(argv[1]);
  oFile.open("result.out");
  
  int iCase, nCase;
  iFile >> nCase;
  for( iCase = 0; iCase != nCase; ++iCase) {
    oFile << "Case #" << iCase+1 << ": ";

    // Solve the problem
    int i, n;
    iFile >> n;
    
    typedef vector<int>* parray;
    parray* rt = new parray[n];
    for(i = 0; i != n; ++i) {
      *(rt+i) = new vector<int>;
      int j;
      for(j = 0; j != n; ++j) {
        char r;
        iFile >> r;
        switch(r) {
        case '1':
          (**(rt+i)).push_back(1);
          break;
        case '0':
          (**(rt+i)).push_back(2);
          break;
        default:
          (**(rt+i)).push_back(3);
          break;
        }
      }
    }

    vector<float> wp, owp, oowp;
    // get wp
    for(i = 0; i != n; ++i) {
      vector<int>::iterator it;
      int p = 0;    // points
      int ng = 0;   // number of games
      for(it = (**(rt+i)).begin(); it != (**(rt+i)).end(); ++it) {
        if (*it == 1) {
          // win
          ++p;
          ++ng;
        }
        else if(*it == 2)
          // lose
          ++ng;
      }
      wp.push_back(float(p)/ng);
    }

    // get owp
    for(i = 0; i != n; ++i) {
      float p = 0;    // points
      int nt = 0;     // number of teams
      int j;
      for(j = 0; j != n; ++j) {
        if ((**(rt+i)).at(j) < 3) {
          // team i,j played
          // get team j's wp throwing out game with i
          int pp = 0;  // points
          int ngg = 0; // number of games
          int k;
          for(k = 0; k != n; ++k) {
            if (k != i) {
              if ((**(rt+j)).at(k) == 1) {
                //win
                ++pp;
                ++ngg;
              }
              else if ((**(rt+j)).at(k) == 2)
                //lose
                ++ngg;
            }
          }
          p += float(pp)/ngg;
          ++nt;
        }
      }
      // i's owp
      owp.push_back(p/nt);
    }


    // get oowp
    for(i = 0; i != n; ++i) {
      float p = 0;    // points
      int nt = 0;     // number of teams
      int j;
      for(j = 0; j != n; ++j) {
        if ((**(rt+i)).at(j) < 3) {
          //team i, j played
          p += owp.at(j);
          ++nt;
        }
      }
      oowp.push_back(p/nt);
    }
    
    oFile << endl;
    oFile.precision(6);
    oFile.setf(ios::fixed, ios::floatfield);
    // get rpi
    for(i = 0; i != n; ++i) {
      float rpi;
      rpi = 0.25*wp.at(i) + 0.5*owp.at(i) + 0.25*oowp.at(i);
      oFile << rpi << endl;
    }
  }
  
  iFile.close();
  oFile.close();
  
  return 0;
}
