#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
    long long int t,i,j;
    map<char,char> google;
    scanf("%lld",&t);
    char a[100];
   // strcpy(a,"ejp mysljylc kd kxveddknmc re jsicpdrysi");
    google['a'] = 'y';
    google['b'] = 'h';
    google['c'] = 'e';
    google['d'] = 's';
    google['e'] = 'o';
    google['f'] = 'c';
    google['g'] = 'v';
    google['h'] = 'x';
    google['i'] = 'd';
    google['j'] = 'u';
    google['k'] = 'i';
    google['l'] = 'g';
    google['m'] = 'l';
    google['n'] = 'b';
    google['o'] = 'k';
    google['p'] = 'r';
    google['q'] = 'z';
    google['r'] = 't';
    google['s'] = 'n';
    google['t'] = 'w';
    google['u'] = 'j';
    google['v'] = 'p';
    google['w'] = 'f';
    google['x'] = 'm';
    google['y'] = 'a';
    google['z'] = 'q';
    //google[' '] = ' ';
    for(i=0;i<t+1;i++){
        gets(a);
        if(i!=0)
        cout<<"Case #"<<i<<": ";
        for(j=0;a[j]!='\0';j++){
            if(a[j]!=' ')
            cout<<google[a[j]];
            else
            cout<<a[j];
            }
        if(i!=0)
        cout<<endl;
        }
    return 0;
    }
