#include<iostream>
#include<queue> 
#include<stack>
#include<list>
#include<iomanip>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<sstream>

using namespace std;


int main(){
    
    int casos, indice =0;
    cin >> casos;
    bool bo = false;
    char tabla[5][5];
    int cont[4]; // x - o - t - empate 
    char variable;
    for(int i =0;i<casos;  i++){
         indice++; 
         bo=false;
         
         for(int j=0; j<4;j++)
            cin >> tabla[j][0] >> tabla[j][1] >> tabla[j][2] >> tabla[j][3];

         
         if(bo == false){
          for(int x = 0; x<4; x++ ){
            if(tabla[x][0]== tabla[x][1] && tabla[x][0]== tabla[x][2] && tabla[x][0]== tabla[x][3] && tabla[x][0] != '.'){
              variable = tabla[x][0];
              bo = true;
               cout <<"Case #"<<indice<<": " << tabla[x][0] <<" won" <<endl;
              break;                 
            }
          }
           
          
         }
         
         
         
         if(bo == false){
          for(int x = 0; x<4; x++ ){
            if(tabla[0][x]== tabla[1][x] && tabla[0][x]== tabla[2][x] && tabla[0][x]== tabla[3][x] && tabla[0][x] != '.'){
              variable = tabla[0][x];
              bo = true;      
             
               cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
                      
            }
          }
            
         }
         
         
         if(bo == false){
          if( tabla[0][0] == tabla[1][1] && tabla[0][0] == tabla[2][2] && tabla[0][0] == tabla[3][3] && tabla[1][1] != '.'){
             variable = tabla[0][0];
           
             cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
             bo = true;  
          }
          
          }
          
          if(bo == false){
            if( tabla[0][3] == tabla[1][2] && tabla[0][3] == tabla[2][1] && tabla[0][3] == tabla[3][0] && tabla[0][3] != '.'){
             variable = tabla[0][3];
             
              bo = true;  
              cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
             }
         
         }
         
   //      for(int x = 0; x<3; x++ ){
     //      for(int y = 0; y<3;y++){
       //       if(tabla[x][y]== tabla[x+1][y] && tabla[x+2][y]== tabla[x][y] && tabla[x+3][y]== tabla[x][y])
         //        variable = tabla[x][y];
               
                    
                   
         //  }
            
       //  }
         
         
         
         
         
         
         
         
          if(bo == false){
          for(int x = 0; x<4; x++ )
            if(  (tabla[x][0]== tabla[x][1] && tabla[x][0]== tabla[x][2] && tabla[x][0] != '.' ) && (tabla[x][3] ==  'T')){
              variable = tabla[x][0];
              bo = true;          
             
              cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
                   
            }
            
         }
         
         
         
         if(bo == false){
          for(int x = 0; x<4; x++ )
            if((tabla[0][x]== tabla[1][x] && tabla[0][x]== tabla[2][x] && tabla[0][x] != '.') && (tabla[3][x] == 'T')){
              variable = tabla[0][x];
              bo = true;   
            
               cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
               break;          
            }
            
         }
         
         
         
          if(bo == false){
          for(int x = 0; x<4; x++ )
            if(  (tabla[x][1]== tabla[x][2] && tabla[x][1]== tabla[x][3] && tabla[x][1] != '.') && (tabla[x][0] ==  'T')){
              variable = tabla[x][1];
              bo = true;   
                     
               cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
               break; 
            }
           
         }
         
         
         
         if(bo == false){
          for(int x = 0; x<4; x++ )
            if((tabla[1][x]== tabla[2][x] && tabla[1][x]== tabla[3][x] && tabla[1][x] != '.') && (tabla[0][x] == 'T')){
              variable = tabla[1][x];
              bo = true;          
                   
              cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
              break;
            }
              
         }
         
         
      
         if(bo == false){
          if( ( tabla[0][0] == tabla[1][1] && tabla[0][0] == tabla[2][2] && ( tabla[3][3] == 'T') && tabla[0][0] != '.' ) || ( tabla[1][1] != '.' && tabla[1][1] == tabla[2][2] && tabla[1][1] == tabla[3][3] && ( tabla[0][0] == 'T') ) ){
             variable = tabla[1][1];
             
              bo=true;
            cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
          }
          
          }
          
          if(bo == false){
            if( ( tabla[0][3] == tabla[1][2] && tabla[0][3] == tabla[2][1] && tabla[3][0]== 'T' && tabla[0][3] != '.') || ( tabla[1][2] != '.' && tabla[1][2] == tabla[2][1] && tabla[1][2] == tabla[3][0] && tabla[0][3]== 'T' )){
             variable = tabla[1][2];
              bo=true;
             
             cout <<"Case #"<<indice<<": " << variable <<" won" <<endl;
             }
         
         }
         
         
         
         
         if(bo == false){
            
              for(int x = 0; x<4; x++ ){
           for(int y = 0; y<3;y++){
              if(tabla[x][y]== '.'){
                             
                  cout <<"Case #"<<indice<<": " << "Game has not completed"<<endl;
                   y = 4;
                   x=4;
                   bo=true;
                  }
                      
           }
            
         }
            
         }
         
         if(bo == false){
                cout <<"Case #"<<indice<<": " << "Draw"<<endl;
               
         }
         
         
         
         
         
         
         
         
    }
    
    
return 0;    
}
