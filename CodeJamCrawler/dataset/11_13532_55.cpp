#include <iostream>
#include <fstream>
#include <string>

#define LearnN 0.1

using namespace std;


void solve()
{
     ifstream fin("input.txt", ios::in);
     ofstream fout("output.txt", ios::out);
     int k = 0,a = 0, *turn, w, *o,*b;
     char s[1000], buf[3];//ftiaxto meta
     fin >> k;
     
     fin.getline(s,1000);
     for (int i = 0; i < k; i++)
     {
         fin >> a;
         turn = new int[a];
         b = new int[a];
         o = new int[a];
         fin.getline(s,a*40);
         
         int l = a,j = 1, ocount=0,bcount=0;
         while (l > 0)
         {
               
               if (s[j] == 'O')
                  turn[a-l] = 0; 
               else 
                  turn[a-l] = 1;
               
               j++;
               j++;
               w=0;
               while (s[j] != ' ' && s[j] != '\0')
               {
                   buf[w] = s[j];
                   w++;
                   j++;  
               }
               int temp = buf[w-1]-48 , temp2 = 10;
               w--;
               while (w > 0)
               {
                     temp = temp + temp2*(buf[w-1]-48);
                     temp2=temp2*10;
                     w--;
               }     
               if (turn[a-l] == 0)
               {
                  o[ocount]=temp;
                  ocount++;
               }
               else 
               {
                  b[bcount]=temp;
                  bcount++;
               }
               j++;
               l--;
         }
         //ta exoume diavasei kai ta valame stous pinakes
         bcount = 0;
         ocount = 0;
         int pos[2] = { 1, 1 }, time[2] = { 0, 0 };
         for (w = 0; w < a; w++)
         {
             if (turn[w] == 0)
             {
                time[0] = time[0] + abs(o[ocount] - pos[0]) + 1;
                pos[0] = o[ocount];
                ocount++;
                if (time[0] <= time[1])
                   time[0] = time[1] + 1;
             }
             else
             {
                time[1] = time[1] + abs(b[bcount] - pos[1]) + 1;
                pos[1] = b[bcount];
                bcount++;
                if (time[1] <= time[0])
                   time[1] = time[0] + 1;
             }
         }
         if (time[0] < time[1])
            time[0] = time[1];
         fout << "Case #" << (i+1) << ": " << time[0] << endl;
         delete o;
         delete b;
         delete turn;
     }
     
}


int main()
{
    solve();
    //system("PAUSE");
    return 0;
}
