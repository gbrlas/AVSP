
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;
ifstream infile;
ofstream outfile;

int main(int argc, char *argv[])
{
    
    infile.open("A-small-attempt1.in");
    outfile.open("res.in");
    string Search[10];
    string str = "";
    string currentEng;
    int Queries[100];
    int Value[10];
    int COUNT = 0;
    int Num_Cases = 0, NumCopy = 0, NumSearch = 0, NumSCopy = 0,NumQueries = 0;
    bool init = true;
    infile>>Num_Cases;
//    cout<<Num_Cases;
    NumCopy = Num_Cases;
    while(Num_Cases > 0){
                    Num_Cases--;
                    int Gret = 0;
                    init = true;
                    infile>>NumSearch;
                    NumSCopy = NumSearch;
                    char c = 'z';
                    infile.get(c);
                    c = 'z';
                    str = "";
                    for(int i = 0; i < NumSearch; i++){
                            while(c != '\n' && !infile.eof()){
                            infile.get(c);
                            if(c != '\n' && !infile.eof())
                            str += c;
                            }
                            c = 'z';
                            Search[i] = str;
                            str = "";
//                            cout<<i<<" "<<Search[i]<<endl;
                            }
                            
                    infile>>NumQueries;
                    COUNT = 0;
                    for(int i = 0; i < 10; i++){Value[i] = 100;}
                    infile.get(c);                    
                    
                    for(int i = 0; i < NumQueries; i++){
                            c = 'z';
                            str = "";
                            while(c != '\n' && !infile.eof()){
                            infile.get(c);
                            if(c != '\n' && !infile.eof())
                            str += c;
                            }
                            c = 'z';
                            for(int k =0; k < NumSearch; k ++){
                                    if(Search[k] == str) Queries[i] = k;
                                    }
                              }
                              
                            int n = 0;                 
Evaluate:
                            for(int m = n; m < NumQueries; m++){
                                    if(Value[Queries[m]] == 100){
                                    Value[Queries[m]] = m;
                                    NumSCopy--;}
                                    if(NumSCopy == 0){
                                                COUNT++;
                                                for(int l = 0; l < NumSearch; l++)Value[l] = 100;
                                                n = m;
                                                NumSCopy = NumSearch;
                                                goto Evaluate;
                                                }
                                    }
                                    
/*                                    if(NumSCopy == 0 ){
                                                
                                                currentEng = Search[Gret];
                                                for(int i = 0; i < 10; i++)Value[i] = 100;
                                                NumSCopy = NumSearch;
                                                init = false;                    

                                    
                                    if(!init){
                                      if(str == currentEng){
                                             COUNT++;
                                             int Gret = 0;
                                             for(int u = 0; u < 10; u++)Value[u] = 100;
                                             for(int k = 0; k < NumSearch; k++){
                                                        if(Search[k] == str) Value[k] = i;
                                                }
                                                
                                             for(int k = 0; k < NumSearch; k++){
                                                        if(Value[k] > Gret) Gret = k;
                                                }
                                                currentEng = Search[Gret];
                                                NumSCopy = NumSearch;
                                             }
                                      }
  */                          
                    outfile<<"Case #"<<NumCopy - Num_Cases<<": "<<COUNT<<endl;
                    
                    }
    
    
    
    
    infile.close();
    outfile.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
