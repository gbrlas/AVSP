#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string.h>
#include <string>
#include <cmath>
using namespace std;

void solve(){
     int N, S, p;
     int t[100];
     cin >> N >> S >> p;
     for(int i=0; i<N; i++) cin >> t[i];
     sort(t, t+N);
     int result = 0;
     for(int i=0; i<N; i++){
             if (t[i]==0) {if (p==0) result++;}
             else if(t[i]%3 == 0){
                       if(S>0 && t[i]/3+1 >=p){
                              S--;
                              result++;
                              }
                       else if(t[i]/3 >= p){
                            result++;
                            }
                       }
             else if(t[i]%3==1){
                  if(t[i]/3+1 >= p){
                           result++;
                           }
                  }
             else{
                  if(S>0 && t[i]/3+2>=p){
                         S--;
                         result++;
                         }
                  else if(t[i]/3+1>=p) result++;
                  }
             }
     printf("%d", result);
     }

int main(void){
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
            cout << "Case #" << i << ": ";
            solve();
            cout << endl;
            }
    return 0;
    }
