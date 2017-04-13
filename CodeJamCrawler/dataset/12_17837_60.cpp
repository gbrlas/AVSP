#include<stdio.h>
#include<conio.h>
#define Taille_Max 1000

main(){
       
       int i,j,k,k1,c,n,n1,n2,n3,n4,n5,n6,A,B,N,trouve;
       int T1[100000];
     
       
       FILE *fichier;
       FILE *fichier1;
       fichier=fopen("test.txt","r+");
       fichier1=fopen("test1.txt","w+");
       
       
       
       while(1){
       fscanf(fichier,"%d",&n);
       
       
       
       if(n==0)
       exit(0);
      
       
       
       for(i=0;i<n;i++) {
      // getch();
       fscanf(fichier,"%d%d",&A,&B);
       
       N=A;
       c=0;
     
       
       for(j=0;j<=B-A;j++){
            
            
           
            
            if(N>10 && N<99){
                           
                 n1=(N%10)*10+N/10;
                 if(n1>A && n1<=B && n1>N) c++;
                     
                     }
                 
       
            if(N>100 && N<999){
                           
                 n1=(N%10)*100+N/10;
                 if(n1>A && n1<=B && n1>N) c++;
                 
                 n2=(n1%10)*100+n1/10;
                 if(n2>A && n2<=B && n2>N && n1!=n2) c++;     
                 
                 }
            if(N>1000 && N<9999){
                           
                 n1=(N%10)*1000+N/10;
                 if(n1>A && n1<B && n1>N) c++;
                 
                 n2=(n1%10)*1000+n1/10;
                 if(n2>A && n2<B && n2>N && n1!=n2) c++;     
                 
                 n3=(n2%10)*1000+n2/10;
                 if(n3>A && n3<B && n3>N && n1!=n3 && n2!=n3) c++;
                 }
           // printf("%d  %d  %d\n\n",n1,n2,n3);
            
            if(N>10000&&N<99999){
                           
                 n1=(N%10)*10000+N/10;
                 if(n1>A && n1<B && n1>N) c++;
                 
                 n2=(n1%10)*10000+n1/10;
                 if(n2>A && n2<B && n2>N && n1!=n2) c++;     
                 
                 n3=(n2%10)*10000+n2/10;
                 if(n3>A && n3<B && n3>N && n1!=n3 && n2!=n3) c++; 
                 
                 n4=(n3%10)*10000+n3/10;
                 if(n4>A && n4<B && n4>N && n1!=n4 && n2!=n4 && n3!=n4) c++; 
                 }
                 
            if(N>100000&&N<999999){
                           
                 n1=(N%10)*100000+N/10;
                 if(n1>A && n1<B && n1>N) c++;
                 
                 n2=(n1%10)*100000+n1/10;
                 if(n2>A && n2<B && n2>N && n1!=n2) c++;     
                 
                 n3=(n2%10)*100000+n2/10;
                 if(n3>A && n3<B && n3>N && n1!=n3 && n2!=n3) c++; 
                 
                 n4=(n3%10)*100000+n3/10;
                 if(n4>A && n4<B && n4>N && n1!=n4 && n2!=n4 && n3!=n4) c++; 
                 
                  n5=(n4%10)*100000+n4/10;
                 if(n5>A && n5<B && n5>N && n1!=n5 && n2!=n5 && n3!=n5 && n4!=n5) c++; 
                 }
       
             if(N>1000000&&N<9999999){
                           
                 n1=(N%10)*1000000+N/10;
                 if(n1>A&&n1<B && n1>N) c++;
                 
                 n2=(n1%10)*1000000+n1/10;
                 if(n2>A && n2<B && n2>N && n1!=n2) c++;     
                 
                 n3=(n2%10)*1000000+n2/10;
                 if(n3>A && n3<B && n3>N && n1!=n3 && n2!=n3) c++; 
                 
                 n4=(n3%10)*1000000+n3/10;
                 if(n4>A && n4<B && n4>N && n1!=n4 && n2!=n4 && n3!=n4) c++; 
                 
                 n5=(n4%10)*1000000+n4/10;
                 if(n5>A && n5<B && n5>N && n1!=n5 && n2!=n5 && n3!=n5 && n4!=n5) c++; 
                 
                 n6=(n5%10)*1000000+n5/10;
                 if(n6>A && n6<B && n6>N && n1!=n6 && n2!=n6 && n3!=n6 && n4!=n6 && n5!=n6) c++; 
                 
                 }
       
       
       N++;
      
       }
       

       
        fprintf(fichier1, "Case #%d: %d\n",i+1,c);        //on affiche le resultat
       
       
   
       
       }
       n=0;
       }
       
       
       
       
       getch();
       return 0;
       
       }
