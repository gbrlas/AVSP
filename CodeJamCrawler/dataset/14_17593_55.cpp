#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define CHEATED -1
#define BADMAGICIAN -2


using namespace std;

typedef vector<int> vint;

template<typename T>
string toString(T t) {
    stringstream s;
    s << t;
    return s.str();
}

vint interseccion(vint &v1, vint &v2){
	vint v3;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));

    return v3;
}

int resultado(vint v1, vint v2){
	vint res = interseccion(v1,v2);
	if(res.size() == 0)
		return CHEATED;
	if(res.size() >= 2)
		return BADMAGICIAN;
	else
		return res[0];
}

int main(){
  int casos, row, num;
  vint v1, v2;

  cin >> casos;

  for(int caso = 1; caso <= casos; caso++){
  	v1.clear();
  	v2.clear();

  	//paso 1
    cin >> row;
  	for(int i = 1; i <= 4; i++){
  	  for(int j = 1; j <= 4; j++){
  	  	cin >> num;
  	  	if(i == row)
  	  	  v1.push_back(num);
  	  }
  	}

  	//paso 2
  	cin >> row;
  	for(int i = 1; i <= 4; i++){
  	  for(int j = 1; j <= 4; j++){
  	  	cin >> num;
  	  	if(i == row)
  	  	  v2.push_back(num);
  	  }
  	}

  	int res = resultado(v1,v2);
  	string message;

  	if(res == CHEATED){
  	  message = "Volunteer cheated!";
  	}
  	else if(res == BADMAGICIAN){
  	  message = "Bad magician!";
  	}
  	else{
  	  message = toString(res);
  	}

  	cout << "Case #" << caso << ": " << message << endl;

  }

  return 0;
}
