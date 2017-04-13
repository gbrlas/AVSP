// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>

using namespace std;


char returnmapped(char c)
{
    if(c=='a')
        return 'y';
    if(c=='b')
        return 'h';
    if(c=='c')
        return 'e';
    if(c=='d')
        return 's';
    if(c=='e')
        return 'o';
    if(c=='f')
        return 'c';
    if(c=='g')
        return 'v';
    if(c=='h')
        return 'x';
    if(c=='i')
        return 'd';
    if(c=='j')
        return 'u';
    if(c=='k')
        return 'i';
    if(c=='l')
        return 'g';
    if(c=='m')
        return 'l';
    if(c=='n')
        return 'b';
    if(c=='o')
        return 'k';
    if(c=='p')
        return 'r';
    if(c=='q')
        return 'z';
    if(c=='r')
        return 't';
    if(c=='s')
        return 'n';
    if(c=='t')
        return 'w';
    if(c=='u')
        return 'j';
    if(c=='v')
        return 'p';
    if(c=='w')
        return 'f';
    if(c=='x')
        return 'm';
    if(c=='y')
        return 'a';
    if(c=='z')
        return 'q';
}
    



int _tmain(int argc, _TCHAR* argv[])
{
	
    int n,i=1,j=0,len=0;
    string str,opstr;
    fstream file;
   
    file.open("A.in", ios::in);
   // freopen("A.in","rt",stdin);
	freopen("A.out","wt",stdout);

   getline(file,str);
   n = atoi(str.c_str());
    
    for(i=1;i<=n;i++)
    {
    getline(file,str);
    len = str.length();
    while(j<len)
    {
        opstr.push_back(returnmapped(str[j++]));
        
    }

    cout<<"Case #"<<i<<": "<<opstr.c_str();
    if(i<n)
        cout<<"\n";
    opstr.clear();
    str.clear();
    j=0;
    }

   
    file.close();
    return 0;
}

