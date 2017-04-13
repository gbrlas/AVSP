#include <iostream>
#include <fstream>
#include <string>


using namespace std;


void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0,r = 0,c = 0;
     char s[1000], buf[3];//ftiaxto meta
     char pi[50][50];
     fin >> k;
     for (int i = 0; i < k; i++)
     {
         fin >> r;
         fin >> c;
         
         fin.getline(s,c*2);
         for (int j=0; j < r; j++)
         {
             fin.getline(s,c*2);
             for (int w = 0; w < c; w++)
                 pi[j][w] = s[w];
         }
         bool cando = true;
         bool flagc = false;
         bool flagr = false;
         int counter = 0;
         for (int j=0; j < r; j++)
         {
             for (int w = 0; w < c; w++)
             {
                 if (pi[j][w] == '#')
                 {
                    flagc = true;
                    counter++;
                 }
                 else
                 {
                     if (flagc)
                     {
                        flagc = false;
                        if (counter%2 == 1)
                        {
                           cando = false;
                           counter = 0;
                        } 
                     }
                 }
             }
             if (flagc)
             {
                flagc = false;
                if (counter%2 == 1)
                {
                   cando = false;
                   counter = 0;
                } 
             }
             counter = 0;
         }
         
         
         for (int w = 0; w < c; w++)
         {
             for (int j=0; j < r; j++)
             {
                 if (pi[j][w] == '#')
                 {
                    flagr = true;
                    counter++;
                 }
                 else
                 {
                     if (flagr)
                     {
                        flagr = false;
                        if (counter%2 == 1)
                        {
                           cando = false;
                           counter = 0;
                        } 
                     }
                 }
             }
             if (flagr)
             {
                flagr = false;
                if (counter%2 == 1)
                {
                   cando = false;
                   counter = 0;
                } 
             }
             
             counter = 0;
         }
         
         if (cando)
         {
            for (int j=0; j < r; j++)
            {
                for (int w = 0; w < c; w++)
                {
                    if (pi[j][w] == '#')
                    {
                       pi[j][w] = '/';
                       pi[j][w+1] = '\\';
                       pi[j+1][w] = '\\';
                       pi[j+1][w+1] = '/';
                    }
                }
            
            }
         }
         
         
         
         //ta exoume diavasei kai ta valame stous pinakes
         fout << "Case #" << (i+1) << ": " << endl;
         cout << "Case #" << (i+1) << ": " << endl;
         if (cando)
         {
            for (int j=0; j < r; j++)
            {
                for (int w = 0; w < c; w++)
                {
                    fout << pi[j][w];
                    cout << pi[j][w];
              
                }
                fout << endl;
                cout << endl;
            }
         }
         else
         {
             fout << "Impossible" << endl;
             cout << "Impossible" << endl;
         
         }
     }
     
}


int main()
{
    solve();
    system("PAUSE");
    return 0;
}
