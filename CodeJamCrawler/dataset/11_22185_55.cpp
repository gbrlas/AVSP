#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char combine[33][33];
int clear[33][33];

int main(){
  int T;
  scanf("%d", &T);
  for(int test_num = 1; test_num <=T; test_num++){
    int c, d, n;
    scanf("%d", &c);

    for(int i=0; i<33; i++){
      for(int j=0; j<33; j++){
        combine[i][j] = 0;
        clear[i][j] = 0;
      }
    }

    for(int i=0; i<c; i++){
      char str[10];
      scanf("%s", str);
      combine[str[1] - 'A'][str[0] - 'A'] = combine[ str[0]-'A' ][str[1]-'A'] = str[2];
    }
    scanf("%d", &d);
    for(int i=0; i<d; i++){
      char str[10];
      scanf("%s", str);
      clear[str[1]-'A'][str[0]-'A'] = clear[str[0]-'A'][str[1]-'A'] = 1;
    }

    scanf("%d", &n);
    string str;
    char _str[111];
    scanf("%s", _str); str = _str;

    vector <char> list;
    for(int i=0; i<n; i++){
      char pre;
      if(list.empty()){
        list.push_back( str[i] );
      }
      else{
        pre = list.back();
        if( combine[pre-'A'][str[i]-'A'] != 0){
          list.erase(list.begin() + (int)list.size()-1);
          list.push_back( combine[pre-'A'][str[i]-'A'] );
        }
        else{
          bool is_clear = false;
          for(int j=0; j<list.size(); j++){
            if(clear[ list[j] -'A' ][str[i]-'A'] == 1){
              list.clear();
              is_clear = true;
              break;
            }
          }
          if(!is_clear){
            list.push_back( str[i] );
          }
        }
      }
    }
    printf("Case #%d: [", test_num);
    for(int i=0; i<list.size(); i++){
      if(i == list.size() -1)   printf("%c", list[i]);
      else      printf("%c, ", list[i]);
    }
    printf("]\n");
  }
  return 0;
}
