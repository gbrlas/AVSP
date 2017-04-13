#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#define MAX 150
#define DI 1
#define DJ 2
using namespace std;

int mat[MAX][MAX];
char mat2[MAX][MAX];
int I,J,J2;
int ii[4]={-1,0,0,1};
int jj[4]={0,-1,1,0};

void llena2(int i,int j,char &c){
  int ni,nj,mini,minj;
  int l,m;
  //checo 4 ady por minimo
  int min=1000;
//  puts("caca");
  for(l=0;l<4;l++){
    ni=i+ii[l];
    nj=j+jj[l];
    if(ni>=0&&ni<I&&nj>=0&&nj<J){
      if(mat[ni][nj]<mat[i][j]&&mat[ni][nj]<min){
        min=mat[ni][nj];
        mini=ni;
        minj=nj;                    
      }
    }
   }
   //ya teniendo el mayor vemos que pedo
   if(min==1000){
    mat2[i][j]=c;
    c=c+1;
    return ;
   }
   
   if(mat2[mini][minj]==0){
    mat2[i][j]=c;
    llena2(mini,minj,c);
    return;                       
   }
    
   mat2[i][j]=mat2[mini][minj];
   return;  
}

char llena(int i,int j,char &c){
  int ni,nj,mini,minj;
  int l,m;
  //checo 4 ady por minimo
  int min=1000;
//  puts("caca");
  for(l=0;l<4;l++){
    ni=i+ii[l];
    nj=j+jj[l];
    if(ni>=0&&ni<I&&nj>=0&&nj<J){
      if(mat[ni][nj]<mat[i][j]&&mat[ni][nj]<min){
        min=mat[ni][nj];
        mini=ni;
        minj=nj;                    
      }
    }
   }
   //ya teniendo el mayor vemos que pedo
   if(min==1000){
    c=c+1;
    mat2[i][j]=c;
    return c;
   }
   
   if(mat2[mini][minj]==0){
    mat2[i][j]=llena(mini,minj,c);
    return mat2[i][j];                       
   }
    
   mat2[i][j]=mat2[mini][minj];
   return mat2[i][j];  
}

int main(){
 int ncasos,caso=1,i,j;
 char c;
 scanf("%d",&ncasos);
 while(caso<=ncasos){
   printf("Case #%d:\n",caso++);
   scanf("%d %d",&I,&J);


   memset(mat,0,sizeof(mat));
   memset(mat2,0,sizeof(mat2));

   
   for(i=0;i<I;i++)
    for(j=0;j<J;j++)
      scanf("%d",&(mat[i][j]));
//   puts("aqui");   
//   for(i=0;i<I;i++){
//    for(j=0;j<J;j++)
//     cout<<mat[i][j]<<" ";
//     cout<<endl;
//    }

   c='a'-1;
//   puts("aqui");  
   for(i=0;i<I;i++){
//    cout<<i<<" "<<j<<endl;                
    for(j=0;j<J;j++){
//       cout<<i<<" "<<j<<endl;               
       if(mat2[i][j]==0){
         llena(i,j,c);                          
       }
                        
    }                 
   }


   for(i=0;i<I;i++){
    printf("%c",mat2[i][0]);
    for(j=1;j<J;j++)
     printf(" %c",mat2[i][j]);
     puts("");
    }
   
//   for(i=0;i<I;i++)
//    puts(mat2[i]);
 }
    
 return 0;    
}
