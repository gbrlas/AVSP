#include <iostream>
#include <vector>
#include <algorithm>

#define vi vector<int>
#define PB push_back

using namespace std;

int solve(vi location, vector<char> color){
  int size = (int)color.size();
#if 0
  for(int i = 0; i < size; i++){
    cout << location[i] << color[i] << endl;
  }
#endif
  int orangeNow = 1, blueNow = 1, finish = 0, orangeDst = -1, blueDst = -1, time = 0;
  bool flg;
  for(int i = 0; i < size; i++){
    if(color[i] == 'O'){
      orangeDst = location[i];
      break;
    }
  }
  for(int i = 0; i < size; i++){
    if(color[i] == 'B'){
      blueDst = location[i];
      break;
    }
  }
  while(finish < size){
    flg = true;
    if(orangeNow == -1){}
    else if(orangeNow < orangeDst)orangeNow++;
    else if(orangeNow > orangeDst)orangeNow--;
    else {
      if(color[finish] == 'O'){
	finish++;
	flg = false;
	orangeDst = -1;
	for(int i = finish; i < size; i++){
	  if(color[i] == 'O'){
	    orangeDst = location[i];
	    break;
	  }
	}
      }
    }
    if(blueNow == -1){}
    else if(blueNow < blueDst)blueNow++;
    else if(blueNow > blueDst)blueNow--;
    else {
      if(color[finish] == 'B' && flg){
	finish++;
	blueDst = -1;
	for(int i = finish; i < size; i++){
	  if(color[i] == 'B'){
	    blueDst = location[i];
	    break;
	  }
	}
      }
    }
    time++;
  }
  return time;
}

int main(void){
  int T, N, l;
  char c;
  vi location;
  vector<char> color;
  cin >> T;
  for(int i = 0; i < T; ++i){
    location = vi(0);
    color = vector<char>(0);
    cin >> N;
    for(int j = 0; j < N; ++j){
      cin >> c >> l;
      location.PB(l);
      color.PB(c);
    }
    l = solve(location, color);
    cout << "Case #" << (i+1) << ": " << l << endl;
  }
  return 0;
}
