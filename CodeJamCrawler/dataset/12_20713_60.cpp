#include <cstdlib>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#define PI acos(-1.0)
using namespace std;
int x[2000010];

int main(){
  int A;
  int B;
  int aux;
  int aux_cont;
  int t;
  unsigned long long int cont;
  int count_cases = 1;
  int cases;
  cin>>cases;
  while(cases--){
    cont = 0;
    fill(x,x+2000010,0);
    cin>>A>>B;
    for (int i=A ; i<=B ; i++){
      aux = i;
      if(!x[i]){
        aux_cont = 1;
        t = 1;
        for (int k=0 ; k<floor(log10(i)) ; k++)
          t *= 10;
        for (int j=0 ; j<floor(log10(i)) ; j++){
          aux = aux/10 + (aux%10*t);
          if(!x[aux]&&aux>=A&&aux<=B&&floor(log10(aux))==floor(log10(i))&&aux!=i){
            x[aux]++;
            aux_cont++;
          }
        }
        x[i]++;
        cont += (aux_cont-1)*aux_cont/2;
      }
    }
    cout<<"Case #"<<count_cases++<<": "<<cont<<endl;
  }
  return 0;
}
