#include<stdio.h>
#include<conio.h>
#define Taille_Max 1000

main(){
       
       int i,j,k,n,N,S,p,G,c;
      
       
       
       
       FILE *fichier;
       FILE *fichier1;
       fichier=fopen("test.txt","r+");
       fichier1=fopen("test1.txt","w+");
       
       
       
       while(1){
       fscanf(fichier,"%d",&n);
       
       
       if(n==0)
       exit(0);

       for(i=0;i<n;i++) {
       
       c=0;                 
       fscanf(fichier,"%d%d%d",&N,&S,&p);
       
     
       for(j=0;j<N;j++) {
    
                     
         fscanf(fichier,"%d",&G);
         
               
                             
                                                             
                    if(G/3 >=p){
                                c++;
                                continue;         
                                }
                    
                    if(G==0)
                         continue;
                    
                    if( p-G/3 >2)
                         continue;    
                    else{
                         if(G/3+1==p){
                                      if(G%3!=0){
                                                 c++;
                                                 continue;
                                                 }
                                      else{
                                           if(S!=0){
                                                    c++;
                                                    S--;
                                                    continue;
                                                    }
                                           }
                                      
                                      }
                                      
                         if(G/3+2==p){
                                      if(G%3==2 && S!=0){
                                                 c++;S--;
                                                 continue;
                                                 }
                                      }
                         
                         
                         }
                            
          
       
       }
       
       fprintf(fichier1, "Case #%d: %d\n",i+1,c);        //on affiche le resultat    
       
       }
       
       n=0;
       }
       
       
       
       
       
       
       getch();
       return 0;
       
       }
