#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int T,n,caso=1;
  long long int scalar;
  vector<int> v1,v2;

  cin >> T;
  while(T--){
    cin >> n;

    v1.clear();
    v2.clear();
    int temp;
    for(int i=0;i<n;i++){
      cin >> temp;
      v1.push_back(temp);
    }
    for(int i=0;i<n;i++){
      cin >> temp;
      v2.push_back(temp);
    }
    sort(v1.begin(), v1.end() );
    sort(v2.begin(), v2.end() );

    scalar=0;
    for(int i=0,j=n-1;i<n;i++,j--){
      scalar+=v1[i]*v2[j];
    }

    cout << "Case #" << caso << ": " << scalar << endl;
    caso++;
  }
  return 0;
}
