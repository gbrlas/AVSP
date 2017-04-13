#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile;
    ofstream outfile;
    int L,D,N;
    string* lang;
    string test;
    int CaseNum=0;
    int P_Count=0;
    int P_index;
    int T_index=0;
    int length;
    bool poss=false;
    
    infile.open("sample.txt");
    outfile.open("result.txt");
    infile>>L>>D>>N;
    lang = new string[D];
    
    for (int i=0; i<D;i++){
    infile>>lang[i];
    //cout<<lang[i]<<endl;
    }
    
while(CaseNum < N) {
              CaseNum++;
              infile>>test;
              
              cout<<"<<>>"<<test<<endl;
              length = test.length();
              
              for(int i=0; i <D; i++){
              for(P_index=0;P_index < L; P_index++){
                                    if(test[T_index] == '('){
                                           bool P_poss=false;
                                           while(test[T_index] !=')'){
                                                      T_index++;
                                                      if(!P_poss)
                                                      if(test[T_index] == lang[i][P_index]){P_poss=true;}
                                                      }
                                            T_index++;
                                            if(!P_poss){printf("sss %c \n",lang[i][P_index]);poss=false; break;}
                                            else poss=true;
                                            }
                      else{
                           if(lang[i][P_index] != test[T_index]){printf("sss %c \n",lang[i][P_index]);poss=false; break;}
                           else poss=true;
                           T_index++;
                           }
                           }     
                           
                           T_index=0;
                           if(poss){P_Count++;cout<<"::"<<lang[i]<<"::\n";}
                           }
                           
                           outfile<<"Case #"<<CaseNum<<": "<<P_Count<<endl;
                           poss=false;P_Count=0;
                           }
    infile.close();
    outfile.close();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
