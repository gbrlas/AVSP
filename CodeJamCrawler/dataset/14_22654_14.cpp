#include<fstream>
#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>

using namespace std;
//function to convert characters to intergers
int conv(char a[100])
{
    int i,j,temp,num=0,sinum,ctr;
    for(i=0; a[i]!='\0'; i++);
    i--;
    for(j=0;i>=0;i--,j++)
    {            
         temp=((int)a[j])-48;
         sinum=1;
         for(ctr=0;ctr<i;ctr++)
         {
         sinum*=10;
         }    
         num+=(sinum*temp);//Create complete number
    }
    return num;
}

void chtin(char a[100], int x[100],int& n)
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
                    x[ctr1++]=conv(temp);
         }
     }
     n=ctr1;
}        
int main()
{
    char a[100];
    int inst,pre1,pre2,n1,n2,i,x,count,y,ans;
    int row1[100],row2[100];
    fstream fin;
    fin.open("C:\\Users\\Tarun Khajuria\\Desktop\\My files @Tarun Khajuria\\Projects\\Ongoing Projects\\Google Code Jam\\Sample test data\\A-small-attempt1.in",ios::in);
    fin.getline(a,20);//Getting the no of instances
    inst=conv(a);
    fstream fout;
    fout.open("C:\\Users\\Tarun Khajuria\\Desktop\\My files @Tarun Khajuria\\Projects\\Ongoing Projects\\Google Code Jam\\Sample test data\\Magic Trick Output.txt",ios::out);
    for(i=0; i<inst; i++)
    {
            fin.getline(a,10);
            pre1=conv(a);
            for( x=0;x<4; x++ )
            {
                    fin.getline(a,100);
                    if(x==(pre1-1))
                    {
                         chtin(a,row1,n1);
                    }
            }
            fin.getline(a,10);
            pre2=conv(a);
            for( x=0;x<4; x++ )
            {
                    fin.getline(a,100);
                    if(x==(pre2-1))
                    {
                         chtin(a,row2,n2);
                    }
            }
            count=0;
            for(x=0; x<n1; x++)
            {
                     for(y=0;y<n2;y++)
                     {                
                      if(row1[x]==row2[y])
                      {
                      ans=row1[x];
                      count++;
                      }
                     }
            }
            if(count==1)
            {
            fout<<"Case #"<<i+1<<": "<<ans<<"\n";
            }
            else if(count ==0)
            {
            fout<<"Case #"<<i+1<<": "<<"Volunteer cheated!"<<"\n";
            }
            else
            {
            fout<<"Case #"<<i+1<<": "<<"Bad magician!"<<"\n";
            }              
    }          
    getch();
}
