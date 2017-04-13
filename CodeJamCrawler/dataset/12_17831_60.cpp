#include<stdio.h>
#include<conio.h>
#define Taille_Max 1000

main(){
       
       int i,j,k,n;
       char chaine[100];
       
      char T1[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      char T11[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
       
       
       
       FILE *fichier;
       FILE *fichier1;
       fichier=fopen("A-small-attempt.in.txt","r+");
       fichier1=fopen("A-small-attempt.out.txt","w+");
       
       
       
       while(1){
       fscanf(fichier,"%d",&n);
       
       if(n==0)
       exit(0);
      
       
       fgets(chaine,Taille_Max, fichier);   // pour revenir a la ligne
       for(j=0;j<n;j++) {
    
                     
       
       
       
       
       fgets(chaine,Taille_Max, fichier);   // pour lire T1
          
         
       
            
        
     
       
      
       for(i=0;i<strlen(chaine);i++){
                        for(k=0;k<28;k++){ 
                                                  
                        if(chaine[i]==T1[k]){
                        chaine[i]=T11[k];
                        break;
                                          }
                        
                            }
          
        
                       }
       fprintf(fichier1, "Case #%d: %s",j+1,chaine);        //on affiche le resultat    
      
       
       }
       
       
       
       
       n=0;
       }
       
       
       
       
       
       
       getch();
       return 0;
       
       }
