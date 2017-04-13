//Vignesh.M
//Vignesh.ase@gmail.com
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int comp(char narr[],char darr[])
{   
//Decipher narr[] into 2d map
char map[100][300]={'\0'};
int i=0,j=0,flag=0;
for(int k=0;narr[k]!='\0';k++)
{
        if(narr[k]=='(')
        {  
           flag=1;
           j=0;
        }
        else if(narr[k]==')')
        {
             flag=0;
             j=0;
             i++;
        }
        else if(flag==1) 
        {
             map[i][j]=narr[k];
             j++;
        }
        else
        {
            map[i][j]=narr[k];
            i++;
            
        } 
}
//Check for Inequality
for(i=0;i<strlen(darr);i++)
{
    flag=0;
    char p;
    p=darr[i];
    for(int q=0;map[i][q]!='\0';q++)
    {
        if(p==map[i][q])
        {
           flag=1;
           break;                       
        }
    }
    if(flag==0) return 0;    
}

return 1;                      
   
}


  

int main()
{
     FILE* fp,*op;
     fp=fopen("A-small-attempt0.in","r+");
     op=fopen("A-small-attempt0.out","r+");
  
     int l,d,n;
     fscanf(fp,"%d %d %d\n",&l,&d,&n);
     printf("\nl:%d d:%d n:%d ",l,d,n);

     int lbrk=0;

     char darr[100][300]={'\0'};
     char narr[100][300]={'\0'};
     for(int i=0;i<d;i++) fscanf(fp,"%s\n",darr[i]);
     for(int i=0;i<n;i++) fscanf(fp,"%s\n",narr[i]);
     cout<<"\nDics:\n";
     for(int i=0;i<d;i++) printf("%s\n",darr[i]);

    
     cout<<"\nNarras:\n";
     for(int i=0;i<n;i++) printf("%s\n",narr[i]);
 
    
     //Consider for individual test cases
     int counter=0,flag=0;
     for(int i=0;i<n;i++)
     {       
             counter=0;
             //Consider each test case separately
             //narr[i]
             //Compare with each of dictionary word and tract counter
             for(int j=0;j<d;j++)
             {
                     //Consider every darr[j] with the given narr[i]         
                     if(comp(narr[i],darr[j])) counter++;
             }
             fprintf(op,"Case #%d: %d\n",i+1,counter);   
     }
 
     
}


