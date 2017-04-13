#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
#define from(i,s,m) for(int i=s;i<m;i++)

int main() {
    freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small-attempt0.out","wt",stdout);
	int testcases;
    cin >> testcases;
	from(t,0,testcases){
                        int n, po, pb;
                        scanf("%i",&n);
                        int P[n];
                        string R;
                        from(i,0,n) scanf("%s %i", &R[i], &P[i]);
                        int time = 0;
                        po = 1;
                        pb = 1;
                        from(i,0,n){
                                    
                                    if(R[i] == 'O'){
                                            time += abs(po - P[i])+1;
                                            from(j,i+1,n){
                                                if(R[j] == 'B'){
                                                          if(abs(po - P[i]) < abs(P[j]-pb)){
                                                                  if(P[j] > pb) pb = pb + abs(po - P[i])+1;
                                                                  else pb = pb - abs(po - P[i])-1;
                                                                  }
                                                          else pb = P[j];
                                                          break;
                                                          }
                                                }
                                            po = P[i];
                                            }
                                    if(R[i] == 'B'){

                                            time += abs(pb - P[i])+1;
                                            from(j,i+1,n){
                                                if(R[j] == 'O'){
                                                          if(abs(pb - P[i]) < abs(P[j]-po)){
                                                                  if(P[j] > po) po = po + abs(pb - P[i])+1;
                                                                  else po = po - abs(pb - P[i])-1;
                                                                  }
                                                          else po = P[j];
                                                          break;
                                                          }
                                                }
                                            pb = P[i];
                                            }
                                    }
                        cout << "Case #" << t+1 << ": " << time << endl;
                        }
	cin >> testcases;
}
