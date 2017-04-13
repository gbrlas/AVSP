#include<iostream>
#include<vector>
#include<string.h>
#include<cmath>

using namespace std;
int abs(int a){
  if (a < 0){
    a = a * -1;
  }
  return a;
}

int main(){

  int v;
  int count = 1;
  cin >> v;
  while(v--){
  int buttons;
  char robot;
  int num;
  vector<int> orange;
  vector<int> blue;
  vector<char> moves;
  cin >> buttons;
  for(int i = 0 ; i < buttons; i++){
    cin >> robot >> num;
    moves.push_back(robot);
    if(robot == 'O'){
      orange.push_back(num);
    }
    if(robot == 'B'){
      blue.push_back(num);
    }
  }

  int timeO = 0;
  int timeB = 0;
  int dest = 0;
  int distO;
  int distB;
  int destO;
  int destB;
  int orinO;
  int orinB;
  orinO = 1;
  orinB = 1;
  int indexB = 0;
  int indexO = 0;

  int ans = 0;

  for (int j = 0; j < moves.size(); j++){

    if(indexB < blue.size()){
    destB = blue[indexB];
    distB = abs(destB - orinB);
    }
    destB = destB;
    if(indexO < orange.size()){
    destO = orange[indexO];
    distO = abs(destO - orinO);
    }
    destO = destO;
    
    
    
    if(moves[j] == 'B'){      
      timeB = distB + 1;
      orinB = destB;
      indexB++;
      ans += timeB;
      if(timeB >= distO){
	orinO = destO;
      }else{
	if(orinO <= destO){
	  orinO += timeB;
	}
	else{
	  orinO -= timeB;
	}
      }
    }
    else if(moves[j] == 'O'){
      timeO = distO + 1;
      orinO = destO;
      indexO++;
      ans += timeO;
      if(timeO >= distB){
	orinB = destB;
      }else{
	if(orinB < destB){
	  orinB += timeO;
       }else{
	  orinB -= timeO;
	}
     }
    }
  }
  cout << "Case #"<< count << ": "<<ans << endl;
  count++;
}
  return 0;
}
