//Bot trust
#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef pair<char,int> Seq;
typedef vector<Seq> SeqVec;

int main()
{
   int T;
   cin >> T;
   for(int n=0; n< T; ++n)
   {
       int k;
       SeqVec butseq;
       cin >> k;
       for(int i=0; i<k; ++i)
       {
           Seq temp;
           cin >> temp.first >> temp.second;  
           butseq.push_back(temp); 
       }
       
       int bcur = 1;
       int ocur = 1;
       Seq onext('O',1), bnext('B',1);
       
       int t=0;
       
       for(int i=0; i< butseq.size(); ++i)
       {
          Seq nowtodo = butseq[i];
          (nowtodo.first == 'B') ? bnext = nowtodo : onext = nowtodo;
          
          for(int j = i+1; j< butseq.size(); ++j)
          {
              if(butseq[j].first != nowtodo.first)
              {
                  (nowtodo.first == 'B') ? onext = butseq[j] : bnext = butseq[j]; 
                  break;              
              }   
          }
              
          while(1)
          {
            ++t;
            bool breakloop =false;
            if(nowtodo.first == 'B')
            {
               if(bcur <  nowtodo.second) ++bcur;
               else if (bcur ==  nowtodo.second)  breakloop = true;
               else  --bcur;        
               
               if(ocur <  onext.second) ++ocur;    
               else if(ocur >  onext.second) --ocur;     
            }
            else
            {
                if(ocur <  nowtodo.second) ++ocur;
                else if(ocur ==  nowtodo.second)  breakloop = true; 
                else --ocur;
                
                if(bcur < bnext.second) ++bcur;
                else if(bcur > bnext.second) --bcur;
            }
            if(breakloop) break;     
          }
       }
       
       cout << "Case #"<<n+1<< ": "<<t<<"\n";       
   } 
}
