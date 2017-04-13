#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int T, i = 0, N, M;
  int lawn[100][100];
  vector<int> V, V_sort;

  cin >> T;
  while (i++ < T) {
    cin >> N >> M;
    int j = 0, k = 0;
    for (j = 0; j < N; ++j) {
      for (k = 0; k < M; ++k)
	cin >> lawn[j][k];
    }

    int quit = 0;
    // if N & M > 2
    if (0) { //((N > 2) && (M > 2)) {
      // check for the solution
      for (j = 1; j < N - 1; j++) {
	V.clear(), V_sort.clear();
	for (k = 1; k < M - 1; k++) {
	  if (N==5 && M==9) cout << "k = " << k << endl;
	  V.push_back(lawn[j][k]);
	  V_sort.push_back(lawn[j][k]);
	}

	sort(V_sort.begin(), V_sort.end());

	if (N==5 && M==9) {
	  cout << "V.size() = " << V.size() << endl;
	  for (int kkk = 0; kkk < V.size(); kkk++) {
	    cout << "V["<<kkk<<"]="<<V[kkk]<<"; V_sort["<<kkk<<"]="<<V_sort[kkk]<<endl;
	  }
	}

	// checking each element
	int ii = 0, num, sum_row = 0, sum_col = 0, rep = 0;
	for (; ii < V.size();) {
	  if (ii > 0) {
	    if (V_sort[ii] == V_sort[ii - 1]) {
	      rep++;
	      if (sum_col == M) {
		ii++;
		continue;
	      }
	    }
	    num = V_sort[ii];
	  }
	  else
	    num = V_sort[ii];
	  
	  // find num position
	  //if ((N == 5) && (M == 9)) cout << "rep = " << rep << endl;
	  int iii = 0, rep_iii = 0;
	  for (; iii < V.size(); iii++) {
	    //cout << "V[" << iii << "] = " << V[iii] << endl;
	    if (num == V[iii]) {
	      if (rep_iii == rep)
		break;
	      else
		rep_iii++;
	    }
	  }
	  //if ((N == 5) && (M == 9)) cout << "iii + 1 = " << iii + 1 << endl;
	  
	  // Check at iii + 1 column in lawn
	  // and also in the row for the
	  // smallest number
	  iii++;
	  
	  //if ((N == 5) && (M == 9)) cout << "num = " << num << "; j = " << j << "; iii = " << iii << endl;
	  
	  sum_col = 0;
	  if (ii == 0) { // smallest element
	    for (int jj = 0; jj < M; jj++) {
	      if (num >= lawn[j][jj]) {
		sum_col++;
		//if ((N == 5) && (M == 9)) cout << "num = " << num << "; lawn[j][jj] = " << lawn[j][jj] << "; sum_col = " << sum_col << endl;
	      }
	    }
	    // //if (sum_row != M) quit = 1;
	  }
	  
	  if ((ii == 0) && (sum_col != M)) {
	    sum_row = 0;
	    for (int jj = 0; jj < N; jj++) {
	      if (num >= lawn[jj][iii]) sum_row++;
	    }
	    if (sum_row != N) quit = 1;
	  }
	  else {
	    if (ii != 0) {
	      sum_row = 0;
	      for (int jj = 0; jj < N; jj++) {
		if (num >= lawn[jj][iii]) {
		  sum_row++;
		  //if ((N == 5) && (M == 9)) cout << "num = " << num << "; lawn[jj][iii] = " << lawn[jj][iii] << "; sum_row = " << sum_row << endl;
		}
	    }
	      if (sum_row != N) quit = 1;
	    }
	  }
	  
	  //if ((N == 5) && (M == 9)) cout << "quit = " << quit << endl;
	  
	  if (quit) break;
	  ii++;
	}
	
	
	if (quit) break; // break for loop and no solution
	
	V.clear();
	V_sort.clear();
	
	//k = 1;
      }
      //-- end if N & M > 2
    }
    else {

      // Check each row
      j = -1;
      while (++j < N) {
	V.clear(), V_sort.clear();
	for (k = 0; k < M; k++) {
	  V.push_back(lawn[j][k]);
	  V_sort.push_back(lawn[j][k]);
	}
	
	sort(V_sort.begin(), V_sort.end());

	/*	
	if (N==3 && M==3) {
	  cout << "V.size() = " << V.size() << endl;
	  for (int kkk = 0; kkk < V.size(); kkk++) {
	    cout << "V["<<kkk<<"]="<<V[kkk]<<"; V_sort["<<kkk<<"]="<<V_sort[kkk]<<endl;
	  }
	}
	*/

	// checking each element
	int ii = 0, num, sum_row = 0, sum_col = 0, rep = 0;
	for (; ii < V.size();) {
	  if (ii > 0) {
	    if (V_sort[ii] == V_sort[ii - 1]) {
	      rep++;
	      if (sum_col == M) {
		ii++;
		continue;
	      }
	    }
	    num = V_sort[ii];
	  }
	  else
	    num = V_sort[ii];
	  
	  //cout << "rep = " << rep << "; num=" << num << endl;

	  // find num position
	  //cout << "rep = " << rep << endl;
	  int iii = 0, rep_iii = 0;
	  for (; iii < V.size(); iii++) {
	    if (num == V[iii]) {
	      if (rep_iii == rep)
		break;
	      else
		rep_iii++;
	    }
	  }
	  //cout << "iii = " << iii << endl;
	  
	  // Check at iii + 1 column in lawn
	  // and also in the row for the
	  // smallest number
	  //iii++;
	  
	  //cout << "num = " << num << "; j = " << j << "; iii = " << iii << endl;
	  
	  sum_col = 0;
	  if (ii == 0) { // smallest element
	    for (int jj = 0; jj < M; jj++) {
	      if (num >= lawn[j][jj]) {
		sum_col++;
		//cout << "num = " << num << "; lawn[j][jj] = " << lawn[j][jj] << "; sum_col = " << sum_col << endl;
	      }
	    }
	    // //if (sum_row != M) quit = 1;
	  }
	  
	  if ((ii == 0) && (sum_col != M)) {
	    sum_row = 0;
	    for (int jj = 0; jj < N; jj++) {
	      if (num >= lawn[jj][iii]) sum_row++;
	    }
	    if (sum_row != N) quit = 1;
	  }
	  else {
	    if (ii != 0) {
	      sum_row = 0;
	      for (int jj = 0; jj < N; jj++) {
		if (num >= lawn[jj][iii]) {
		  sum_row++;
		  //cout << "num = " << num << "; lawn[jj][iii] = " << lawn[jj][iii] << "; sum_row = " << sum_row << endl;
		}
	    }
	      if (sum_row != N) quit = 1;
	    }
	  }
	  
	  //cout << "quit = " << quit << endl;
	  
	  if (quit) break;
	  ii++;
	}
	
	
	if (quit) break; // break for loop and no solution
	
	V.clear();
	V_sort.clear();
	
	//k = 0;

      }


    }


    if (quit) cout << "Case #" << i << ": NO" << endl;
    else cout << "Case #" << i << ": YES" << endl;
  }

  return 0;
}
