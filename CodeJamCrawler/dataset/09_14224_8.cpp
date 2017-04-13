#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main(int argc, char *argv[])
{
    
    int L, D, T,let, j, tok, num;
    long long * N;
    long long fnum;
    bool found;
    bool ** dict_table;
    int dstat[40]; 
    int dval[40];
    //long long num[30];
    ifstream f;
    ofstream ou;
    string * dict, * cas;
    
    ou.open("exam.txt");
    f.open("A-small-attempt4.in");
    //numwords = let = 0;
    if (f.is_open() && ou.is_open())
    {
                    
       f >> T;
       N = new long long[T];
       dict = new string[T];           
       
       //Just to clear the buffer
       getline(f,dict[0]);
       //Per case
       for (int i=0; i < T;i++)
       {
           long long dig;
           memset (dstat, 0, sizeof(dstat));
           memset (dval, -1, sizeof(dval));
           getline(f,dict[i]);
       
           cout << dict[i] << "- length" << dict[i].length() << endl;
           //check each char
           for (int j = 0; j < dict[i].length(); j++)
           {
               cout << dict[i][j] << "-";
               if (dict[i][j] >= 'a')
                  dstat[dict[i][j] - 'a' + 10]++; 
               else
                  dstat[ dict[i][j] - '0']++;
           }
           cout <<endl;
          
          num = 0;
          //count num of unique chars
          for (int k = 0; k < 36; k++)
              if (dstat[k] > 0)
                 num++;
           cout <<"NUM: " <<num <<endl;      
          //num will be our base
          if (num == 1)
             num++;
          fnum = 0;
          bool next = false;
          int next_val = 1;
          for (int j = 0; j < dict[i].length(); j++)
          {
              int loc;
              long long powe;
              
               if (dict[i][j] >= 'a')
               {
                  loc = dict[i][j] - 'a' + 10;
               }
               else
                  loc = dict[i][j] - '0';
               
                  if (j == 0)            
                     dval[loc]=1;
                  else if (next == false &&dval[loc] == -1)
                  {
                      dval[loc]=0;
                      next = true;
                      next_val++;
                  }
                  else if  (dval[loc] == -1)
                       dval[loc] = next_val++;
                       
               powe =  static_cast<long long>(pow(static_cast<double>(num), (int)(dict[i].length() - j-1)));       
               fnum = fnum + (long long)(dval[loc] * powe);   
           }
                    
           cout << "Case #"<< (i+1) << ": "<<fnum<< endl;
           ou << "Case #"<< (i+1) << ": "<<fnum<< endl;
       }
    
       
       
     }               

    
    system("PAUSE");
    return EXIT_SUCCESS;
}


