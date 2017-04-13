#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<iomanip>

using namespace std;
void chtin(char a[100],double x[5],int& n)
{
     int st=0,ctr1=0,ct,i;
     char temp[10];
     for (i=0; a[i]!='\0'; i++)
     {
         if(a[i]==' '|| a[i+1]=='\0')
         {
                    for(ct=0;a[st]!=' ' && a[st]!='\0'; st++)
                    {
                            temp[ct++]=a[st];
                    }
                    temp[ct]='\0';
                    st++;
                    x[ctr1++]=atof(temp);
         }
     }
     n=ctr1;
}        
int main()
{
    char a[100];
    int n,i,y,ans;
    double row[5],inst,C,ctr,F,X,tprev,t,ttemp;
    fstream fin;
    fin.open("C:\\Users\\Tarun Khajuria\\Desktop\\My files @Tarun Khajuria\\Projects\\Ongoing Projects\\Google Code Jam\\Sample test data\\B-small-attempt1.in",ios::in);
    fin.getline(a,20);//Getting the no of instances
    inst=atof(a);
    fstream fout;
    fout.open("C:\\Users\\Tarun Khajuria\\Desktop\\My files @Tarun Khajuria\\Projects\\Ongoing Projects\\Google Code Jam\\Sample test data\\Cookie Cli Output.txt",ios::out);
    for(i=0; i<inst; i++)
    {       t=0;
            y=0;
            tprev=10000;
            fin.getline(a,100);
            chtin(a,row,n);
            C=row[0];
            F=row[1];
            X=row[2];
            do
            {
                   if(y!=0)
                   tprev=t;        
                   t=0;
                   for(ctr=0; ctr<y; ctr++)
                   {
                              ttemp=C/(2+(ctr*F));
                              t+=ttemp;
                   }
                   t+=X/(2+(y*F));                 
                   y++;
            }while(tprev>=t);
            fout<<"Case #"<<i+1<<": "<<setprecision(12)<<tprev<<"\n";          
    }          
    getch();
}
