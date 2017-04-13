#include<iostream>
#include<fstream>
using namespace std;

string phrase;
string alpha = "abcedrfghijklmnopqrstuvwxyz ";
string coded = "yheostcvxduiglbkrztnwjpfmaq ";

int main(){
    //ifstream fin("DATAa.txt");
    //ofstream fout("DATAout.txt");
    //FILE*out = fopen("DATAout.txt","w");
    int tests,t = 1;
    cin >> tests;
    getline(cin,phrase);
    while(t<=tests){
        getline(cin,phrase);
        printf("Case #%d: ",t);
        for(int i=0;i<phrase.size();i++)
            printf("%c",coded[alpha.find(phrase[i])]);
        printf("\n");
        t++;
    }
    return 0;
}
