//
//  P1.cpp
//  
//
//  Created by Jun Ma on 4/14/12.
//  Copyright (c) 2012 Michigan Technological University. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <strstream>
#include <string>
#include <cstring>
using namespace std;
char words[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main(){
    string temp;
    getline(cin, temp);
    int t = atoi(temp.c_str());
    string mystr[40];
    for(int i=0; i<t; i++){
        getline(cin, mystr[i]);
        cout<<"Case #"<<i+1<<": ";
        char* mychr = new char[mystr[i].length()];
        strcpy(mychr, mystr[i].c_str());
        for(int j=0; j<mystr[i].length(); j++){
            if(mychr[j]==' ')
                cout<<' ';
            else
                cout<<words[mychr[j]-'a'];
        }
        cout<<endl;
        delete []mychr;
    }
    return 0;
}