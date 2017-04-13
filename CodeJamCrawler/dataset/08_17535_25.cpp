#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h> 


using namespace std;

class Caso{
    public:
        string engines[11];
        string testes[101];
        int resposta;
       

};

int str2int (const string &str) {
    stringstream ss(str);
    int n;
    ss >> n;
    return n;
}

main(){
    string strcontengines;
    string strconttestes;
    string strcasos;
    string strengines;
    string strtestes;
    
    int contengines = 0;
    int conttestes = 0;
    int casos = 0;
    int contcasos = 0;
    
    int quantcasos = 0;
    int quantengines = 0;
    int quanttestes= 0 ;
    
    int loopcasos = 0;
    int loopengines = 0;
    int looptestes = 0;
    int maxfundo = 0;
    int j;
    
    int fundoengines[10];
    int numfundo;
    
    ifstream input("A-small-attempt2.IN");
    ofstream output("A-small-attempt2.OUT");
    
    int trocas = 0;
    
    getline(input,strcasos);
    casos = str2int(strcasos);
    
    contcasos = casos;
    
    Caso entrada[21];
    
    while(contcasos > 0){
        
        getline(input,strcontengines);
        contengines = str2int(strcontengines);
        
        quantengines = 0;
        
        while(contengines > 0){
            getline(input,strengines);
            
            entrada[quantcasos].engines[quantengines] = strengines;
            
            quantengines++;
            contengines--;
        }
        
        getline(input,strconttestes);
        conttestes = str2int(strconttestes);
        
        quanttestes = 0;
        
        while(conttestes > 0){
            getline(input,strtestes);
            entrada[quantcasos].testes[quanttestes] = strtestes;
            
            quanttestes++;
            conttestes--;
        }
        
        maxfundo = 0;
        trocas = 0;
        while(maxfundo < quanttestes){
            loopengines = 0;
            while(loopengines < quantengines){
                fundoengines[loopengines] = maxfundo;
                looptestes = maxfundo;
                while((entrada[quantcasos].engines[loopengines] != entrada[quantcasos].testes[looptestes]) && (looptestes < quanttestes)){
                    
                    fundoengines[loopengines]++;
                    looptestes++;
                }
                
                loopengines++;
            }
           
            maxfundo = fundoengines[0];
            for (j = 1; j < quantengines; j += 1)
                if (maxfundo < fundoengines[j]) 
                    maxfundo = fundoengines[j];
                  
            if(maxfundo < quanttestes)
                trocas++;
    
        }
        
        entrada[quantcasos].resposta = trocas;
                
        quantcasos++;
        contcasos--;
    }
    
    while(loopcasos < quantcasos){
        output << "Case #" << loopcasos + 1 << ": " << entrada[loopcasos].resposta;
        loopcasos++;
        if(loopcasos != quantcasos){
            output << endl;
        }
    }
    
    output.close();
    input.close();
    
}
        
        
 


