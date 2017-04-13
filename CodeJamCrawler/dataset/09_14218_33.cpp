#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void clear_dict_table(bool  **tab, int D, int L);
int count_dict_table(bool **tab, int D, int L);

int main(int argc, char *argv[])
{
    
    int L, D, N, let, numwords, tok;
    bool found;
    bool ** dict_table;
    ifstream f;
    ofstream ou;
    string * dict, * cas;
    ou.open("exam.txt");
    f.open("A-large.in");
    numwords = let = 0;
    if (f.is_open() && ou.is_open())
    {
                    
       f >> L >> D >> N;
       
       dict = new string[D];
       cas = new string[N];
       dict_table = (bool **) malloc (D * sizeof(bool *));
       
       for (int row = 0; row < D;row++)
           dict_table[row] = (bool *) malloc(L * sizeof(bool));
           
       //Just to clear the buffer
       getline(f,dict[0]);
       //Read dict
       for (int i=0; i < D;i++)
       {
           getline(f,dict[i]);
           //cout << dict[i] <<endl;
       }
       //Read case
       for (int i=0; i < N;i++)
       {
           getline(f,cas[i]);
           //cout << cas[i] <<endl;
       }
       
       for(int j = 0; j < N; j++) //per case
       {
           int i = 0;    
           numwords = let = 0; 
           clear_dict_table(dict_table, D, L);
           tok = 0;
           
           
           while (tok < L)    
           //for (int i = 0; i < L; i++)
           {
                 
                 found = false;
                 if (cas[j][i] != '(')
                 {
                    //We have a definite token           
                    for (int k=0; k < D;k++)
                    {
                        if (cas[j][i] == dict[k][tok])
                        {
                            //cout << "K and tok and I: "<< k << " " << tok << " " << i << endl;          
                           //Letter found
                           dict_table[k][tok] = true;
                           //found = true;
                           let++;
                        }
                    }
                    tok++; 
                    i++;           
                 }
                 else
                 {
                     while (cas[j][i] != ')')
                     {
                           for (int k=0; k < D;k++)
                           {
                               if (cas[j][i] == dict[k][tok])
                               {
                                  //Letter found
                                  dict_table[k][tok] = true;
                                  found = true;
                                  let++;
                                       
                               }
                           }              
                           i++;
                     }
                     tok++;
                     i++;
                 }
           
           }//end while tok < L
       //if (let == L) numwords++;
       numwords = count_dict_table(dict_table, D, L);
//       cout << "Case #"<< (j+1) << ":"<<numwords << " Let: " << let << endl; 
       cout << "Case #"<< (j+1) << ": "<<numwords << endl;      
       ou << "Case #"<< (j+1) << ": "<<numwords << endl;      
       }//end for j
       
     }               

    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void clear_dict_table(bool **tab, int D, int L)
{
     for (int i = 0; i < D;i++)
         for(int j = 0; j < L; j++)
                 tab[i][j] = false;
}

int count_dict_table(bool **tab, int D, int L)
{
    int i,j, count;
    count = 0;
    for ( i = 0; i < D;i++)
    {
         for(j = 0; j < L; j++)
         {
               //cout << " " << tab[i][j];
                if(tab[i][j] == false)
                   break;
         }
         //cout <<endl;
         if (j == L)
            count++;
    }
    
    return count;
}
