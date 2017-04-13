#include<iostream>
#include<fstream>
#include <string>
#include <stdlib.h>

using namespace std;

class betu {
    public:
        char letter;
        betu* next;
        betu() {
            next=NULL;
        }
        betu(char jel) {
            letter=jel;
            next=NULL;
        }
};

class betusor {
    public:
        betu* head;
        betusor() {
            head=NULL;
        }
        ~betusor() {
            while(head!=NULL) {
                this->pop();
            }
        }
        void push(char betuke) {
            betu* pointer;
            pointer=head;
            if(pointer==NULL) {
                head=new betu(betuke);
            } else {
                while(pointer->next!=NULL) {
                    pointer=pointer->next;
                }
                pointer->next=new betu(betuke);
            }
        }
        void pop() {
            betu* pointer=head;
            head=head->next;
            delete pointer;
        }
        
        bool vanbenne(char keresett) {
            betu* pointer=head;
            while(pointer!=NULL) {
                if(pointer->letter==keresett) {
                    return true;
                }
                pointer=pointer->next;
            }
            return false;
        }

};

int main() {

    int szavakhossza;
    int szotarhossz;
    int teszthossz;
    string* szotar;
    string* tesztek;
    string line;

    ifstream BE("input",ios::in);
        BE>>line;
        szavakhossza=atoi(line.c_str());
        BE>>line;
        szotarhossz=atoi(line.c_str());
        BE>>line;
        teszthossz=atoi(line.c_str());

        szotar=new string[szotarhossz];
        for(int i=0; i<szotarhossz;i++) {
            BE>>szotar[i];
        }
        tesztek=new string[teszthossz];
        for(int i=0; i<teszthossz;i++) {
            BE>>tesztek[i];
        }

    BE.close();
    
    ofstream KI("output.txt");
    betusor* betusorok;
    for(int i=0; i<teszthossz;i++) {
        betusorok=new betusor[szavakhossza];
        int index=0;
        bool zarojelben=false;
        for(int k=0;k<tesztek[i].length();k++) {
            if(tesztek[i][k]=='(') {
                zarojelben=true;
            } else if(tesztek[i][k]==')') {
                zarojelben=false;
                index++;
            } else {
                betusorok[index].push(tesztek[i][k]);
                if(!zarojelben) {
                    index++;
                }
            }
            
        }
        
        int talalt=0;
        for(int z=0;z<szotarhossz;z++) {
            bool megfelel=true;
            for(int j=0;j<szotar[z].length();j++) {
                if(!(betusorok[j].vanbenne(szotar[z][j]))) {
                    megfelel=false;
                    break;
                }
            }
            if(megfelel) {
                talalt++;
            }
        }
        KI<<"Case #"<<i+1<<": "<<talalt<<endl;
        delete [] betusorok;
    }
    KI.close();
    return 0;
}