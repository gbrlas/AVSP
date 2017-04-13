#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    FILE* f;
    FILE* g;
    int n,i,j,p=1;
    g=fopen("output.out","w+");
    f=fopen("input.in","r");
    char l[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char t[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    char line[102]; //with '\0'
    if(f==NULL){printf("error of opning input file"); exit(-1);} //opning imput file
    else{
         fscanf(f,"%d",&n);
         line[102]='\n';
         fgets(line,101,f);
         if(n>30) {printf("we have overflow many line :("); goto end;}
         if(f==NULL)printf("error of opnin output file");
         else{
         while(n>0){
                         fgets(line,102,f);
                         for(i=0;i<101;i++){
                                 for(j=0;j<26;j++){
                                 if(line[i]==l[j]){ 
                                 line[i]=t[j]; 
                                 break;}
                                 }
                                 }
                                 if(p<=30){
                                 fprintf(g,"Case #%d: ",p);
                                 fprintf(g,"%s",line);
                                 if(strlen(line)==99){fprintf(g,"\n");}
                                  p++;
                                 }
                                 n--;
                                 
                         }
         }
         }
         fclose(f);
         fclose(g);
         end:
    getch();
    return 0;
    }
