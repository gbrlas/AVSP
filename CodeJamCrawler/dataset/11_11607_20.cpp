#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;
 
int main()
{
    //int total=0;
    int n,cas;
    int team[100][100];
    ifstream fin;
    char ch;int pl,p[100],play,win,w[100];
    double ow[100],r[100],ooow[100];
    fin.open("A-large.in");
    ofstream fout;
    fout.open("output.in");
    fin>>cas;
    int i,j,k,l;
    int owi;
    double a,oow;
    double o;

    for(i=0;i<cas;i++)
    {
                      fout<<"Case #"<<i+1<<":\n";
        fin>>n;
       // fout<<'\n'<<n;
        for(j=0;j<n;j++)
        {               win=0;
                        play=0;
                        for(k=0;k<n;k++)
                        {
                                        fin>>ch;
                                        if(ch=='.')
                                        team[j][k]=-1;
                                        else
                                        if(ch=='0')
                                        {team[j][k]=0;
                                        play++;
                                        }
                                        else
                                        {team[j][k]=1;
                                        play++;
                                        }
                                        if(team[j][k]==1)
                                        {
                                                         win++;                                                        
                                                         
                                                         }
                                        }
                        w[j]=win;
                        p[j]=play;
                        //fout<<w[j]<<'\n';
                        
                        }              
        for(j=0;j<n;j++)
        {o=0;
                        for(k=0;k<n;k++)
                        {               owi=0;if(k!=j)
                                        {
                                        if((team[j][k]==1)||(team[j][k]==0))
                                        {               //fout<<"yes";
                                                         pl=p[k];
                                                         owi+=w[k];
                                                         if(team[j][k]==0)
                                                         {owi-=1;
                                                         
                                                         }
                                         pl-=1;
                                        // fout<<owi<<'*';
                                         o+=(double)owi/(double)pl;
                                        //fout<<o<<'='<<'\n';                
                                         }
                                         }
                                         
                                        }
                        ow[j]=(double)o/(double)p[j];
                        //fout<<ow[j]<<"   00 \n";
                        }
                      
                      
        for(j=0;j<n;j++)
        {oow=0;
                        for(k=0;k<n;k++)
                        {
                                        if(team[j][k]!=-1)
                                        {
                                                          oow+=ow[k];
                                                          }
                                        }
                        ooow[j]=oow/(double)p[j];
                        a=(double)w[j]/(double)p[j];
                        
                        //fout<<"\np"<<p[j]<<"\t"<<ooow[j]<<"vvv"<<a<<'\n';
                        r[j]=(0.25*a)+(0.5*ow[j])+(0.25*ooow[j]);
                        fout<<setprecision(12)<<r[j]<<"\n";
                        }
                      }
                      ch=getchar();
    }
