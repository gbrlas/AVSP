#include <iostream>
#include <fstream>
#include <string>


using namespace std;

char comb[36][3], opos[28][2], spell[100], s[1000];
int cursize , ncomb, nopos, nspell;

void clears()
{
     for (int i = 0; i < cursize; i++)
     {
         s[i] = '\0';
     }
     cursize = 0;
}

bool oposcheck(char q)
{
     char f;
     for (int i = 0; i < nopos; i++)
     {
         if (opos[i][0] == q)
         {
            f = opos[i][1];
            for (int j = 0; j < cursize; j++)
            {
                if (s[j] == f)
                   return true;
            }
         }
         else if (opos[i][1] == q)
         {
            f = opos[i][0];
            for (int j = 0; j < cursize; j++)
            {
                if (s[j] == f)
                   return true;
            }
         }
     }
     return false;
}

bool combcheck(char q, char f)
{
     for (int i = 0; i < ncomb; i++)
     {
         if (comb[i][0] == q)
         {
            if (comb[i][1] == f)
            {
               s[cursize-2] = comb[i][2];
               s[cursize-1] = '\0';
               cursize--;
               return true;
            }
         }
         else if (comb[i][0] == f)
         {
            if (comb[i][1] == q)
            {
               s[cursize-2] = comb[i][2];
               s[cursize-1] = '\0';
               cursize--;
               return true;
            }
         }
     }
     return false;
}

void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0, w;
     ncomb = 0, nopos = 0, nspell = 0;//n stands for number
     char buf[3];//ftiaxto meta
     fin >> k;
     
     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         cursize = 0;
         ncomb = 0, nopos = 0, nspell = 0;
         fin >> ncomb;
         for (int j = 0; j < ncomb; j++)
         {
             fin >> s;
             comb[j][0] = s[0];
             comb[j][1] = s[1];
             comb[j][2] = s[2];
         }
         fin >> nopos;
         for (int j = 0; j < nopos; j++)
         {
             fin >> s;
             opos[j][0] = s[0];
             opos[j][1] = s[1];
         }
         fin >> nspell;
         fin >> s;
         for (int j = 0; j < nspell; j++)
         {
             spell[j] = s[j];
             s[j] = '\0';
         }
         for (int j = 0; j < nspell; j++)
         {
             if (cursize == 0)
             {
                s[0] = spell[j];
                cursize++;   
             }
             else 
             {
                  s[cursize] = spell[j];
                  cursize++;
                  if (!combcheck(s[cursize-1],s[cursize-2]))
                  {
                     if (oposcheck(s[cursize-1]))
                        clears();
                  }
             }
         }
         fout << "Case #" << (i+1) << ": ";
         fout << "[";
         if (cursize > 0)
         {
            fout << s[0];
            for (int j = 1; j < cursize; j++)
            {
                fout << ", " << s[j];
            }
         }
         fout << "]" << endl;
         
     }     
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
