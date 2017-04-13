#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0,a = 0, w, games[100][100], ngames[100];
     double wp[100], owp[100], oowp[100] ,rpi[100];;
     char s[1000], buf[3];//ftiaxto meta
     fin >> k;
     for (int i = 0; i < k; i++)
     {
         fin >> a;
         
         fin.getline(s,a*2);
         for (int j=0; j < a; j++)
         {
             fin.getline(s,a*2);
     
             int counter =0;
             wp[j]=0;
             ngames[j]=0;
             for (int w = 0; w < a; w++)
             {
                 if (s[w]== '.')
                 {
                    games[j][w] = 0;
                 }
                 else
                 {
                     ngames[j]++;
                     games[j][w] = -1;
                     counter++;
                     if (s[w] == '1')
                     {
                        games[j][w]=1;
                        wp[j]=wp[j] + 1;      
                        }
                 }
             }
             wp[j] = wp[j]/counter;
         }//wp ready
         
         for (int j=0; j < a; j++)
         {
             int counter =0;
             owp[j]=0;
             for (int w = 0; w < a; w++)
             {
                 if (games[j][w] != 0)
                 {
                    counter++;
                    if (games[j][w] == 1)
                    {
                       owp[j] = owp[j] + (wp[w]*ngames[w])/(ngames[w]-1);
                    }
                    else
                    {
                        owp[j] = owp[j] + (wp[w]*ngames[w] - 1)/(ngames[w]-1);
                    }
                 }
             }
             owp[j] = owp[j]/counter;
         }
         
         for (int j=0; j < a; j++)
         {
             int counter =0;
             oowp[j]=0;
             for (int w = 0; w < a; w++)
             {
                 if (games[j][w] != 0)
                 {
                    counter++;
                    oowp[j] = oowp[j] + owp[w];
                 }
             }
             oowp[j] = oowp[j]/counter;
         }
         
         for (int j=0; j < a; j++)
         {
             rpi[j] = 0.25 * wp[j] + 0.5 * owp[j] + 0.25 * oowp[j];
         }
         //ta exoume diavasei kai ta valame stous pinakes
         fout << "Case #" << (i+1) << ": " << endl;
         for (int j=0; j < a; j++)
         {
             fout << rpi[j] << endl;
         }
     }
     
}


int main()
{
    solve();
    system("PAUSE");
    return 0;
}
