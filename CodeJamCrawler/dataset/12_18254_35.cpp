/* 
 * File:   main.cpp
 * Author: christopher
 *
 * Created on April 13, 2012, 6:35 PM
 */
             
             
#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () 
{
    string line;
    int x;
    int y; y=0;
    int i; i=0;
    fstream file;
    file.open("A-small-attempt0.in");
    getline(file,line); 
    stringstream ss(line);
    ss >> x;
    getline(file,line); 
    while (i!=x)
    {
        cout << "Case #";
        cout << i+1;
        cout << ": ";
        while(y!=line.length())
        {
            if(line[y]=='y') {line[y]='a';}
            else if (line[y]=='n'){line[y]='b';}
            else if (line[y]=='f'){line[y]='c';}
            else if (line[y]=='i'){line[y]='d';}
            else if (line[y]=='c'){line[y]='e';}
            else if (line[y]=='w'){line[y]='f';}
            else if (line[y]=='l'){line[y]='g';}
            else if (line[y]=='b'){line[y]='h';}
            else if (line[y]=='k'){line[y]='i';}
            else if (line[y]=='u'){line[y]='j';}
            else if (line[y]=='o'){line[y]='k';}
            else if (line[y]=='m'){line[y]='l';}
            else if (line[y]=='x'){line[y]='m';}
            else if (line[y]=='s'){line[y]='n';}
            else if (line[y]=='e'){line[y]='o';}
            else if (line[y]=='v'){line[y]='p';}
            else if (line[y]=='z'){line[y]='q';}
            else if (line[y]=='p'){line[y]='r';}
            else if (line[y]=='d'){line[y]='s';}
            else if (line[y]=='r'){line[y]='t';}
            else if (line[y]=='j'){line[y]='u';}
            else if (line[y]=='g'){line[y]='v';}
            else if (line[y]=='t'){line[y]='w';}
            else if (line[y]=='h'){line[y]='x';}
            else if (line[y]=='a'){line[y]='y';}
            else if (line[y]=='q'){line[y]='z';}
            cout <<line[y];
            y++;
        }
        cout <<'\n';
        getline(file,line);
        i++;
        y=0;
    } 
       return 0;
}

