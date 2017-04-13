#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

    int terkepszam;
    string temp;
    int sorszam;
    int oszlopszam;
    int** szamok;
    char** betuk;
    char letter;
    

bool lefolyat(char betu,int ypoz, int xpoz) {
    int minvalue=szamok[ypoz][xpoz];
    int yfinal, xfinal;
    betuk[ypoz][xpoz]=betu;
    if(ypoz+1<sorszam) {
        if(minvalue>=szamok[ypoz+1][xpoz]) {
            minvalue=szamok[ypoz+1][xpoz];
            yfinal=ypoz+1;
            xfinal=xpoz;
        }
    }
    if(xpoz+1<oszlopszam) {
        if(minvalue>=szamok[ypoz][xpoz+1]) {
            minvalue=szamok[ypoz][xpoz+1];
            yfinal=ypoz;
            xfinal=xpoz+1;
        }
    }
    if(xpoz-1>=0) {
        if(minvalue>=szamok[ypoz][xpoz-1]) {
            minvalue=szamok[ypoz][xpoz-1];
            yfinal=ypoz;
            xfinal=xpoz-1;
        }
    }
    if(ypoz-1>=0) {
        if(minvalue>=szamok[ypoz-1][xpoz]) {
            minvalue=szamok[ypoz-1][xpoz];
            yfinal=ypoz-1;
            xfinal=xpoz;
        }
    }
    if(minvalue==szamok[ypoz][xpoz]) {
        return false;
    }
    if(betuk[yfinal][xfinal]=='0') {
        lefolyat(betu,yfinal,xfinal) ;
    } else {
        letter--;
        char atir=betuk[yfinal][xfinal];
        for(int i=0; i<sorszam; i++) {
             for(int k=0; k<oszlopszam; k++) {
                 if(betuk[i][k]==betu) {
                     betuk[i][k]=atir;
                 }
             }

        }
        return false;
    }
    return true;
    
}

int main() {


    ifstream BE("input");
    BE>>temp;
    terkepszam=atoi(temp.c_str());
    ofstream KI("output.txt");
    for(int i=0; i<terkepszam;i++) {
        letter='a';
        BE>>temp;
        sorszam=atoi(temp.c_str());
        BE>>temp;
        oszlopszam=atoi(temp.c_str());

        szamok=new int*[sorszam];
        betuk=new char*[sorszam];
        for(int j=0;j<sorszam;j++) {
            szamok[j]=new int[oszlopszam];
            betuk[j]=new char[oszlopszam];
        }
        for(int j=0;j<sorszam;j++) {
            for(int k=0;k<oszlopszam;k++) {
                betuk[j][k]='0';
                BE>>temp;
                szamok[j][k]=atoi(temp.c_str());
            }
        }
        for(int h=0;h<sorszam;h++) {
             for(int z=0;z<oszlopszam;z++) {
                 if(betuk[h][z]=='0') {
                     lefolyat(letter,h,z);
                     letter++;
                 }
             }
        }
            
        KI<<"Case #"<<i+1<<":"<<endl;
        for(int j=0;j<sorszam;j++) {
            for(int k=0;k<oszlopszam;k++) {
                KI<<betuk[j][k]<<" ";
            }
            KI<<endl;
        }

        for(int j=0;j<sorszam;j++) {
            delete [] szamok[j];
            delete [] betuk[j];
        }
        delete  [] szamok;
        delete [] betuk;
   }


    BE.close();

    
    
    

    return 0;
}