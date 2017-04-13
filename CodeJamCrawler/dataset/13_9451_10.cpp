#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

#define l long
#define ll long long

l findminops(l A, vector<l> msizes, l minop) {
  if (msizes.size() == 1) {
    if (A > msizes[0])
      return minop;
    else {
      return ++minop; // either remove or add
    }
  }
  else {
    for (int j = 0; j < msizes.size(); j++) {
      if (A > msizes[j]) {
	A += msizes[j];
      }
      else {

	if (j == msizes.size()-1) {
	  vector<l> msizes2;
	  for (int k = j; k < msizes.size(); k++)
	    msizes2.push_back(msizes[k]);
	  return findminops(A, msizes2, minop);
	}
	else {

	  if (A == msizes[msizes.size()-1]) {
	    minop++;
	    vector<l> msizes2;
	    for (int k = j; k < msizes.size() - 1; k++)
	      msizes2.push_back(msizes[k]);
	    sort(msizes2.begin(), msizes2.end());
	    j = msizes.size();
	    return findminops(A, msizes2, minop);
	  }
	  else {
	    if ((A-1) > 0) {
	      msizes[msizes.size()-1] = A - 1;
	      minop += 2;
	      vector<l> msizes2;
	      
	      for (int k = j; k < msizes.size(); k++)
		msizes2.push_back(msizes[k]);
	      
	      sort(msizes2.begin(), msizes2.end());
	      j = msizes.size(); // to stop for loop
	      return findminops(A, msizes2, minop);
	    }
	    else {
	      minop++;
	      vector<l> msizes2;
	      for (int k = j; k < msizes.size() - 1; k++)
		msizes2.push_back(msizes[k]);
	      sort(msizes2.begin(), msizes2.end());
	      j = msizes.size();
	      return findminops(A, msizes2, minop);
	    }
	  }

	}
      }
      
    }
    return minop;
  }
}

l findminops2 (l A, vector<l> msizes, l minop) {
  if (msizes.size() == 1) {
    if (A > msizes[0])
      return minop;
    else {
      //cout << "msizes[0] = " << msizes[0] << endl;
      //cout << "minop+1=" << minop+1 << endl;
      return ++minop; // either remove or add
    }
  }
  else {
    for (int j = 0; j < msizes.size(); j++) {
      if (A > msizes[j]) {
	A += msizes[j];
	//cout << "A=" << A << endl;
	//cout << "minop = " << minop << endl;
      }
      else {
	vector<l> msizes2;
	l jj = j;
	for (int k = j; k < msizes.size(); k++)
	  msizes2.push_back(msizes[k]);

	minop++;
	msizes2.push_back(A-1);
	sort(msizes2.begin(), msizes2.end());
	j = msizes.size();
	minop = findminops(A, msizes2, minop);
	/*
	if (minop < (msizes.size() - jj)) {
	  return findminops2(A, msizes2, minop);
	}
	else {
	  minop = msizes.size() - jj;
	  return minop;
	}
	*/

      }
    }
    return minop;
  }
}

l findminops3 (l A, vector<l> msizes, l minop) {
  if (msizes.size() == 1) {
    if (A > msizes[0])
      return minop;
    else {
      //cout << "msizes[0] = " << msizes[0] << endl;
      //cout << "minop+1=" << minop+1 << endl;
      return ++minop; // either remove or add
    }
  }
  else {
    for (int j = 0; j < msizes.size(); j++) {
      if (A > msizes[j]) {
	A += msizes[j];
	//cout << "A=" << A << endl;
	//cout << "minop = " << minop << endl;
      }
      else {
	vector<l> msizes2;
	l jj = j;
	for (int k = j; k < msizes.size(); k++)
	  msizes2.push_back(msizes[k]);

	minop++;
	msizes2.push_back(A-1);
	sort(msizes2.begin(), msizes2.end());
	j = msizes.size();

	if (minop < (msizes.size() - jj)) {
	  return findminops3(A, msizes2, minop);
	}
	else {
	  //minop = msizes.size() - jj;
	  return minop;
	}


      }
    }
    return minop;
  }
}

int main()
{
  int T, i = 0, N;
  l A, msize, minop = 0;
  vector<l> msizes;
  cin >> T;
  while (i++ < T) {
    cin >> A >> N;
    for (int j = 0; j < N; j++) {
      cin >> msize;
      msizes.push_back(msize);
    }
    sort(msizes.begin(), msizes.end());

    if (msizes[0] > A) {
      minop = msizes.size();
      minop = min(findminops(A, msizes, 0), minop);
      minop = min(findminops2(A, msizes, 0), minop);
      minop = min(minop, findminops3(A, msizes, 0));
    }
    else {
      minop = findminops(A, msizes, 0);
      minop = min(minop, findminops2(A, msizes, 0));
      minop = min(minop, findminops3(A, msizes, 0));
    }

    cout << "Case #" << i << ": " << minop << endl;

    minop = 0;
    msizes.clear();

  }
  return 0;
}
