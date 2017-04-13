//#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void ordenar(char a[100][6], int tam)
{
     int i, j, cambio;
     char aux[6];
     cambio = 1;
     while(cambio)
     {
        cambio = 0;
        for(i = 0; i < tam - 1; i++)
        {
            if(strcmp(a[i],a[i+1]) > 0)
            {
                strcpy(aux,a[i]);  
                strcpy(a[i],a[i+1]);
                strcpy(a[i+1],aux);     
                cambio = 1;
            }
        }                    
     }
}

void sumar(char a[], char s[], int num)
{
    char *hora, *min , aux[6];
    int m, h, d;
    m = 0;
    strcpy(aux,a);
 
    hora =   strtok(aux, ":");
   

    min = strtok(NULL, ":");
    m = atoi(min);
    
    if( (m + num) > 59)
    {
        s[0] = '\0';
        h = atoi(hora);
        h++;
        aux[0] = '\0';
        itoa(h,aux,10);
        if(h < 10)
        {
          strcat(s, "0");  
          strcat(s, aux);  
        }
        else
          strcat(s, aux);
          
        d =  60 - m;
        m = num - d;
        strcat(s, ":");
        itoa(m,min,10);
        if(m < 10)
        {
            strcat(s, "0");  
            strcat(s, min);  
        }
        else
            strcat(s, min);
        strcat(s, "\0");
    }
    else {
        m = m + num;
        itoa(m,min,10);
        s[0] = '\0';
        strcat(s, hora);
        strcat(s, ":");
        if(m < 10)
        {
            strcat(s, "0");  
            strcat(s, min);  
        }
        else
             strcat(s, min);
        strcat(s, "\0");
    }
}


int main(int argc, char *argv[])
{
    ifstream entrada("B-small.in");
    ofstream salida("B-small.out");
    int i, j, k, l, casos, tiempo, na, nb, nta, ntb, entro;
    char tnas[100][6], tnall[100][6], tnbs[100][6], tnbll[100][6];
    char  horallegada[6];
    
    
    entrada >> casos;
    
    for (i = 0; i < casos; i++)
    {
            
        entrada >> tiempo;
        entrada >> na >> nb;
        
        for(j = 0; j < na; j++)
            entrada >> tnas[j] >> tnall[j];
        for(j = 0; j < nb; j++)
            entrada >> tnbs[j] >> tnbll[j];
            
        ordenar(tnas, na);
        ordenar(tnall, na);
        ordenar(tnbs, nb);
        ordenar(tnbll, nb);
        j = k = l = ntb = 0;
        while(j < nb && k < na)
        {
    
               sumar(tnall[k], horallegada, tiempo);
               entro = 0; 
               while(k < na && strcmp(horallegada,tnbs[j]) > 0)
               {
                   entro = 1;
                   k++;
                   if(k < na)
                        sumar(tnall[k], horallegada, tiempo);
                       
               }
               if(k < na)
                {   ntb++; if(entro) l = k; else {k++; l++;}}
               else
                    k = l; 
               j++;              
        }
        
        j = k = l = nta = 0;
        while(j < na && k < nb)
        {
               
               sumar(tnbll[k], horallegada, tiempo);
               entro = 0;
               while(k < nb && strcmp(horallegada,tnas[j]) > 0)
               {
                   entro = 1;
                   k++;
                   if(k < nb)
                        sumar(tnbll[k], horallegada, tiempo);
                   
               }
               if(k < nb)
                {   nta++; if(entro) l = k; else {k++; l++;}}
               else
                    k = l;
            
               j++;               
        }
        
       
        nta = na - nta;
        ntb = nb - ntb;
        salida << "Case #" << (i + 1) << ": " << nta << " " << ntb;
        if(i < (casos - 1))
            salida <<endl;
    }
  
    return 1;
}
