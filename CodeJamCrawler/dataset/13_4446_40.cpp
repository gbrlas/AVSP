#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
void marcar(bool marcas[]);
int main (){
    ofstream cout("C.txt");
    int T,a,b,cont=0;
    bool mar[1001];
    cin>>T;
    marcar(mar);
    for (int i=1; i<=T; i++){
        cin>>a>>b;
        cont=0;
        for (int j=a; j<=b; j++){
            if (mar[j]){
               cont++;
            }
        }
        cout<<"Case #"<<i<<": "<<cont<<endl;       
    } 

    return 0;
}

void marcar(bool marcas[]){
     
     for (int i=1; i<=1000; i++){
        char numero[12];
        int num=i,j=0,cont=0;
        while (num !=0){
            numero[j++] = num %10;
            num /= 10; 
            cont++;
        }
        bool sw = true;
        for (int k=0, l=cont-1; k<cont; k++,l--){
            if (numero[k]!=numero[l]){
               sw = false;
               break;
            }
        }
        if (!sw){
           marcas[i]=false;
        }else{
              double raiz = sqrt(i);
              int raiz2 = raiz;
              double raiz3 = raiz2;
              if ( raiz3 == raiz ){
                 num = raiz,j=0,cont=0;
                 while (num!=0){
                       numero[j++]= num%10;
                       num/=10;
                       cont++;
                 }
                 sw = true;
                 for (int k=0, l=cont-1; k<cont; k++,l--){
                     if (numero[k]!=numero[l]){
                        sw=false;
                        break;
                     }
                 }
                 if (sw){
                    marcas[i]=true;
                 }else{
                       marcas[i]=false;
                 }
              }else{
                    marcas[i]=false;
              }
        }
     }
     
}
