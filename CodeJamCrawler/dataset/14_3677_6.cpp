#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>
using namespace std;
struct Juri{
           bool test;
           int num;
            };
int main(){
    ofstream out("output.txt");
    ifstream in("input.txt");
    int c=0;
    int i=0,j=0,k=0;
    int T=0,soluzione1=0,soluzione2=0;
    int m[4][4],m1[4][4];
    int risulta=0;
    int sent=0;
    int a=1;
    Juri m2[4][4],m3[4][4];
    in>>T;
   
    for(c=0;c<T;c++){sent=0;
                     //prima parte
                     in>>soluzione1;
                     soluzione1--;
                     for(i=0;i<4;i++)
                                      for(j=0;j<4;j++){//carico matrici
                                                       in>>k;
                                                       m[i][j]=k;
                                                       m2[i][j].num=k;
                                                       k++;
                                                       m2[i][j].test=false;
                                                      }
                     for(i=0;i<4;i++)m2[soluzione1][i].test=true;                                 
                     //seconda parte                  
                     in>>soluzione2;
                     soluzione2--;                                 
                     for(i=0;i<4;i++)
                                     for(j=0;j<4;j++){//carico matrice 2
                                                       in>>k;
                                                       m[i][j]=k;
                                                       m3[i][j].num=k;
                                                       k++;
                                                       m3[i][j].test=false;
                                                      }
                     for(i=0;i<4;i++)m3[soluzione2][i].test=true;
                     for(i=0;i<4;i++)                                  
                     //confronto                                 
                     for(i=0;i<4;i++){
                                      for(j=0;j<4;j++)if(m2[soluzione1][i].num==m3[soluzione2][j].num){
                                                                                                       risulta=m2[soluzione1][i].num;
                                                                                                       sent++;
                                                                                                       }
                                      }
                                                                       
                                                                                      
                                     
    //cout<<sent<<endl;
    if(sent==1){out<<"Case #"<<a<<": ";
                a++;
                out<<risulta;
                   out<<endl;
                   }
    else{out<<"Case #"<<a<<": ";
                a++;
         if(sent==0)out<<"Volunteer cheated!";
         if(sent>1)out<<"Bad magician!";
            out<<endl;
         }
 
}
scanf("\n");
}
