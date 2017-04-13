//Mandeep Singh
//mandeep2150@gmail.com

#include <iostream>

using namespace std;

int main(void){
  int t, s, p, n, c, tmp;
  int m[11] = {0,1,2,3,4,5,6,7,8,9,10};
  cin >> t;
  
  for(int count =0; count<t; ++count) {
    c=0;
    cin >> n >> s >> p;
    cout << "Case #" << count+1 << ": ";
    for( int ite=0; ite<n; ++ite ){
      cin >> tmp;
      for( int o=0; o<11-p; o++) {
        if( 3*m[p+o] == tmp || 2*m[p+o] + m[o+p-1] == tmp
           || 2*m[p+o-1] + m[o+p] == tmp ) {
          c++;
          break;
        }
        if(s>0){
          if(m[p-2+o] + m[p+o] + m[p-1+o] == tmp ||
             2*m[p-2+o] + m[p+o] == tmp ||
             m[p-2+o] + 2*m[p+o] == tmp) {
            
             s--;
             c++;
             break;
          }
        }
      }
    }
    cout << c << endl;
  }
  return 0;
}