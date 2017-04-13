
#include <iostream>
#include <fstream>
#include <istream>

using namespace std;
ifstream infile;
ofstream outfile;

int main(int argc, char *argv[])
{
    
    infile.open("A-large.in");
    outfile.open("resLarge.in");
    string Search[100];
    string str = "";
    string currentEng;
    int Queries[1000];
    int Value[100];
    int COUNT = 0;
    int Num_Cases = 0, NumCopy = 0, NumSearch = 0, NumSCopy = 0,NumQueries = 0;
    infile>>Num_Cases;
    NumCopy = Num_Cases;
    while(Num_Cases > 0){
                    Num_Cases--;
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
                            }
                            
                    infile>>NumQueries;
                    COUNT = 0;
                    for(int i = 0; i < 100; i++){Value[i] = 1001;}
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
                                    if(Value[Queries[m]] == 1001){
                                    Value[Queries[m]] = m;
                                    NumSCopy--;}
                                    if(NumSCopy == 0){
                                                COUNT++;
                                                for(int l = 0; l < NumSearch; l++)Value[l] = 1001;
                                                n = m;
                                                NumSCopy = NumSearch;
                                                goto Evaluate;
                                                }
                                    }
                    outfile<<"Case #"<<NumCopy - Num_Cases<<": "<<COUNT<<endl;
                    
                    }
    
    
    
    
    infile.close();
    outfile.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}
