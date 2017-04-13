/*Author : Iresh Agrawal
Date : 3 April 2012*/
#include <iostream>
#include <fstream>

using namespace std;


int main()
{   
ifstream fin;
ofstream fout;
fin.open("A.txt");
fout.open("A2.txt");
char p[200];
    int T,c=0,j,e;
    fin>>T;
   // fin>>p[0];
 // fin.seekg(-1,ios::cur);
    T++;
    T++;
    while(T--)
    {       c++;
                 
           fin.getline(p,200,'\n');
           if(c==1)        {continue; } 
                        
           fout<<"\nCase #"<<c-1<<": ";
            for(j=0;p[j]!='\0';j++);
            e=j;
            for(j=0;j<e;j++)
            {
                            if(p[j]=='a')         fout<<'y';
                            else if(p[j]=='b')    fout<<'h';
                            else if(p[j]=='c')    fout<<'e';
                            else if(p[j]=='d')    fout<<'s';
                            else if(p[j]=='e')    fout<<'o';
                            else if(p[j]=='f')    fout<<'c';
                            else if(p[j]=='g')    fout<<'v';
                            else if(p[j]=='h')    fout<<'x';
                            else if(p[j]=='i')    fout<<'d';
                            else if(p[j]=='j')    fout<<'u';
                            else if(p[j]=='k')    fout<<'i';
                            else if(p[j]=='l')    fout<<'g';
                            else if(p[j]=='m')    fout<<'l';
                            else if(p[j]=='n')    fout<<'b';
                            else if(p[j]=='o')    fout<<'k';
                            else if(p[j]=='p')    fout<<'r';
                            else if(p[j]=='q')    fout<<'z';
                            else if(p[j]=='r')    fout<<'t';
                            else if(p[j]=='s')    fout<<'n';
                            else if(p[j]=='t')    fout<<'w';
                            else if(p[j]=='u')    fout<<'j';
                            else if(p[j]=='v')    fout<<'p';
                            else if(p[j]=='w')    fout<<'f';
                            else if(p[j]=='x')    fout<<'m';
                            else if(p[j]=='y')    fout<<'a';
                            else if(p[j]=='z')    fout<<'q';
                            else                  fout<<p[j];
                            }
                             
            }
fin.close();
fout.close();            
system("pause"); 
return 0;}
