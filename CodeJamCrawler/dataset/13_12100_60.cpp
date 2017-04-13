#include <stdio.h>
#include <map>

using namespace std;
#define MAXN 6
char M[MAXN][MAXN];

int main(){

  
  int T;
  int i,j,k;
  
  scanf("%d",&T);

  for(k = 0; k < T; k++){
    for(i = 0; i < 4; i++)
      scanf("%s", M[i]);
    
    map<char,int> q;
    int qp;
    bool x_won = false;
    bool o_won = false;

    for( i = 0; i < 4; i++){
      q.clear();      
      for( j = 0; j < 4; j++){
        q[M[i][j]]++;
      }
      qp = q['.'];
      if(q['O'] == 4 || (q['O'] == 3 && q['T'] == 1) ){
        o_won = true;
      }
      if(q['X'] == 4 || (q['X'] == 3 && q['T'] == 1) ){
        x_won = true;
      }   
    }
    
    for( j = 0; j < 4; j++){
      q.clear();      
      for( i = 0; i < 4; i++){
        q[M[i][j]]++;
      }
      if(q['O'] == 4 || (q['O'] == 3 && q['T'] == 1) ){
        o_won = true;
      }
      if(q['X'] == 4 || (q['X'] == 3 && q['T'] == 1) ){
        x_won = true;
      }   
    }

      q.clear();      
      for( i = 0; i < 4; i++){
        q[M[i][i]]++;
      }
      if(q['O'] == 4 || (q['O'] == 3 && q['T'] == 1) ){
        o_won = true;
      }
      if(q['X'] == 4 || (q['X'] == 3 && q['T'] == 1) ){
        x_won = true;
      }
      
      q.clear();      
      for( i = 0; i < 4; i++){
        q[M[i][4 - i - 1]]++;
      }
      if(q['O'] == 4 || (q['O'] == 3 && q['T'] == 1) ){
        o_won = true;
      }
      if(q['X'] == 4 || (q['X'] == 3 && q['T'] == 1) ){
        x_won = true;
      }
     
    printf("Case #%d: ",k+1); 
    if(x_won){
      printf("X won\n");
    }
    else if(o_won){
      printf("O won\n");
    }
    else if(qp == 0){
      printf("Draw\n");
    }
    else{
      printf("Game has not completed\n");
    }

  } 

  return 0;
}
