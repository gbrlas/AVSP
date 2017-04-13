#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
    int pos;
    char ch;
}MARK;

int find_first_of(vector<char>a, char c){
    for(int i=0;i<a.size();i++){
        if(a[i]==c)
            return i+1;
    }
    return 0;
}

int process(char c, vector<string> sComA, vector<string> sOppA, vector<char> &sRet){
    int n = sRet.size();
    if(n==0)
        sRet.push_back(c);
    else{
        for(int i=0;i<sComA.size();i++){
            string sCom = sComA[i];
            if((c==sCom[0] && sRet[n-1]==sCom[1]) || (c==sCom[1] && sRet[n-1]==sCom[0])){
                sRet[n-1]=sCom[2];
                return 0;
            }
        }
        for(int i=0;i<sOppA.size();i++){
            string sOpp = sOppA[i];
            if((c==sOpp[0] && find_first_of(sRet, sOpp[1])) || (c==sOpp[1] && find_first_of(sRet, sOpp[0]))){
                sRet.clear();
                return 0;
            }
        }        
        sRet.push_back(c);        
    }
    return 0;
}

int main(int argc, char** argv) {
    ifstream inFile;
    ofstream outFile;
    int T, C, D, N;
    
    inFile.open("B-large.in", ifstream::in);
    outFile.open("B-large.out", ifstream::out);
    inFile >> T;
    for (int i = 0; i < T; i++) {
        cout<<i<<endl;
        string strInvoke="123";
        vector<string>strCom; 
        vector<string>strOpp; 
        
        //Input
        inFile>>C;
        for(int j=0;j<C;j++){
            string tmp;
            inFile>>tmp;
            strCom.push_back(tmp);
        }
        inFile>>D;
        for(int j=0;j<D;j++){
            string tmp;
            inFile>>tmp;
            strOpp.push_back(tmp);
        }
        inFile>>N;
        inFile>>strInvoke;
        
        //Process
        vector<char> strRet;        
        for(int j=0; j<N; j++){
            char c = strInvoke[j];
            process(c,strCom,strOpp,strRet);
        }
            
        //Output                
        outFile << "Case #"<<i+1<<": [";
        for(int j=0; j<strRet.size(); j++){
            outFile <<strRet[j];
            if(j<strRet.size()-1)
                outFile<<", ";
        }
        outFile<<"]"<<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}

