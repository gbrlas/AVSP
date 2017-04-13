#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int number;
string keresett="welcome to code jam";

void szamlalo(string szoveg, int num) {
    for(int i=0; i<szoveg.length();i++){
        if(szoveg[i]==keresett[num]) {
            if(num==keresett.length()-1) {
              number++;
            } else {
                szamlalo(szoveg,num+1);
            }
        } else {
            szoveg[i]='0';
        }
    }
}


int main() {
    int feladatszam;
    string sor;

    ifstream BE("input");
    getline(BE,sor);
    feladatszam=atoi(sor.c_str());
    ofstream KI("output.txt");
    for(int i=0; i<feladatszam;i++) {
        getline(BE,sor);
        number=0;
        szamlalo(sor,0);
        KI<<"Case #"<<i+1<<": ";
        KI.width(4);
        KI.fill('0');
        KI<<number<<endl;
    }
    BE.close();
    KI.close();


}