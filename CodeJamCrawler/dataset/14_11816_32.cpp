#include <vector>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
 
#define SLOVA 26  
#define CANTIDAD 10
#define LEN 20
int root;
int indice_nodos=0;
 
struct node {
   char flag;
   int p[SLOVA];
   void clear()
    {
        memset( p, -1, sizeof p );
         flag = 0;
    }
};
 
node dict[CANTIDAD*LEN];//diccionario
//cantidad de nodos posibles
 
int new_node() {
   dict[indice_nodos].clear();
   //limpia el nodo que se ta creando
   return indice_nodos++;
}

void insertar_palabra(char buff[LEN+1])
{   
  int t=root;
       
      for( char *c = buff; *c; ++c )//recorre todas las letras de la palabra
      {
         if( dict[t].p[*c-'A'] == -1 )//si no existe un nodo empezando en "t", que tenga como adyacente a la letra "*c-a" entonces
            dict[t].p[*c-'A'] = new_node();//crea nuevo nodo
            
            t= dict[t].p[*c-'A'];//aqui se va al nuevo nodo
   
      }
      dict[t].flag = 1;
}

char arr[30][LEN+1];
int NN,MM;
int  go(vector <int> indi) {
   indice_nodos=0;//para cada llamada del arbol tiene q inicializarse en 0
   root = new_node();//tendra la raiz
  
  for(int i=0;i<indi.size();i++) {
    insertar_palabra(arr[indi[i]]);
  }
  return indice_nodos;
}
void prt(vector <int> v){
  for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}
int main(){
  int cases;
  scanf("%d",&cases);
  for(int t=1;t<=cases;t++){
    scanf("%d %d",&MM,&NN);
    for(int i=0;i<MM;i++)scanf("%s",arr[i]);
    if(NN == 1){
      vector <int> vv;
      for(int i=0;i<MM;i++)vv.push_back(i);
       cout<<"Case #"<<t<<": ";
       cout<<go(vv)<<" "<<1<<endl;
       continue;
    }
    int maxi = 0, num = 0;
    int bits = 2*MM;
    int lim = (1<<bits);
    for(int i=1;i<lim;i++){
      int mask = i;
      bool fue = false;
      vector < vector <int> > todos(NN);
      for(int j = 0; j< MM; j++){
        int grupo = mask%4;
        if(grupo >= NN) fue = true;
        if(fue)break;
        //cout<<grupo-1<<endl;
        todos[grupo].push_back(j);
        mask/=4;
      }
      if(fue) continue;
      int m1 = 0 ;
      for(int j=0;j<todos.size();j++){
          if(todos[j].size() == 0) fue = true;
          m1+=go(todos[j]);
        }
      if(fue)continue; 
      if(m1>maxi){
          maxi = m1;
          num = 1;
        }
        else if(m1 == maxi)
          num++; 
    }
    cout<<"Case #"<<t<<": ";
    cout<<maxi<<" "<<num<<endl;
  }
  return 0;
}
