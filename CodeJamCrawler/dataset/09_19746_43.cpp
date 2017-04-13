#include <stdio.h>
#include <map>
#include <iostream>
#include <sstream>
#include <boost/algorithm/string.hpp>
#include <boost/dynamic_bitset.hpp>

using namespace std;

int main()
{
  int L, D, N;

  cin >> L >> D >> N;

  //cout << "L = " << L << ", D = " << D << ", N = " << N <<  endl;

  string line;
  getline(cin, line);

  map<string, boost::dynamic_bitset<> > a;
  for(int i = 0; i < D; i++){
    getline(cin, line);
    for(int j = 0; j < line.length(); j++){
      std::stringstream ss;
      ss << j;
      string key = line.substr(j, 1) + "_" + ss.str();

      if(a.find(key) == a.end()){
        a[key] = boost::dynamic_bitset<>(D);
      }
      a[key][i] = 1;

      //cout << "key = " << key << endl;
    } 
    //cout << line << endl;
  }

  for(int i = 0; i < N; i++){
    getline(cin, line);
    boost::dynamic_bitset<> total(D);
    total.flip();
    bool or_mode = false;
    boost::dynamic_bitset<> or_total(D);
    int pos = 0;
    bool no_bit = false;
    for(int j = 0; j < line.length(); j++){
      string s = line.substr(j, 1);
      if(s == "("){
        or_mode = true;
        or_total = boost::dynamic_bitset<>(D);
      }else if(s == ")"){
        or_mode = false;
        total &= or_total;
        pos++;
      }else{
        std::stringstream ss;
        ss << pos;
        string key = s + "_" + ss.str();
        //cout << "key in = " << key << endl;

        boost::dynamic_bitset<> * ap = NULL;
        if(a.find(key) != a.end()){
          ap = & a[key];
        }

        if(! or_mode){
          if(ap != NULL){
            total &= (* ap);
          }else{
            no_bit = true;
            break;
          }
          pos++;
        }else{
          if(ap != NULL){
            or_total |= (* ap);
          }
        }
      }
    }
    int bit_count = 0;
    if(! no_bit){
      bit_count = total.count();
    }else{
      //cout << "no bit" << endl;
    }
    cout << "Case #" << (i + 1) << ": " << bit_count << endl;
  } 

  return 1;
}

