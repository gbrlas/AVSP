// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

char *ELA,*ELB,*ELC,*OPA,*OPB,*ARR;
int carraylen,oparraylen,arrlen;


string checkcomb(string str)
{
    char searchcomb(char,char);
    char c;
    int flag=0;
    if(str.length()<2)
        return str;
    else
    {
        if(str.length()>2)
            flag=1;

        c=searchcomb(str[0],str[1]);
        if(c!='~')
        {
            str.erase(0,1);
            str[0]=c;
        }
        
        if(flag==1)
        {
            c=searchcomb(str[str.length()-1],str[str.length()-2]);
            if(c!='~')
            {
                str.erase(str.length()-1,1);
                str[str.length()-1]=c;
            }
        }

        return str;
    }
}

char searchcomb(char x,char y)
{
    for(int i=0;i<carraylen;i++)
    {
        if((ELA[i]==x)&&(ELB[i]==y))
            return ELC[i];
        if((ELB[i]==x)&&(ELA[i]==y))
            return ELC[i];
    }
    return '~';
}

string checkopp(string str)
{
    int search(string,char);
    if(str.length()<2)
        return str;
    else
    {
        for(int i=0;i<oparraylen;i++)
        {
            if(search(str,OPA[i])==1)
            {
                if(search(str,OPB[i])==1)
                {
                    str.erase();
                    return str;
                }
            }
        }
        return str;
    }
}

int search(string str,char c)
{
    for(int i=0;i<str.length();i++)
    {
        if(c==str[i])
            return 1;
    }
    return 0;
    
}


int _tmain(int argc, _TCHAR* argv[])
{
	string checkcomb(string);
    string checkopp(string);

    int n;
    string str,tempstr;
    freopen("B-small-attempt0.in","rt",stdin);
	freopen("B-small.out","wt",stdout);


    cin>>n;
    for(int i=0;i<n;i++)
    {
        str.clear();
        tempstr.clear();
        ELA = NULL;
        ELB = NULL;
        ELC = NULL;
        OPA = NULL;
        OPB = NULL;
        cin>>carraylen;
        if(carraylen!=0)
        {
        ELA = new char[carraylen];
        ELB = new char[carraylen];
        ELC = new char[carraylen];
        for(int k=0;k<carraylen;k++)
        {
            cin>>tempstr;
            ELA[k]=tempstr[0];
            ELB[k]=tempstr[1];
            ELC[k]=tempstr[2];
            tempstr.clear();
        }
        }

        cin>>oparraylen;
        if(oparraylen!=0)
        {
            OPA = new char[oparraylen];
            OPB = new char[oparraylen];
            for(int k=0;k<oparraylen;k++)
            {
            cin>>tempstr;
            OPA[k]=tempstr[0];
            OPB[k]=tempstr[1];
            tempstr.clear();
            }
        }

        cin>>arrlen;
        ARR = new char[arrlen];
        cin>>tempstr;
        for(int k=0;k<arrlen;k++)
            ARR[k]=tempstr[k];
        tempstr.clear();

        for(int k=0;k<arrlen;k++)
        {
            str.push_back(ARR[k]);
            str = checkcomb(str);
            str = checkopp(str);
        }

        tempstr.append("[");
        if(str.length()>=1)
        {
        for(int k=0;k<str.length();k++)
        {
            tempstr.push_back(str[k]);
            tempstr.push_back(',');
            tempstr.push_back(' ');
        }
        tempstr.resize(tempstr.length()-2);
        }
        tempstr.push_back(']');
        cout<<"Case #"<<(i+1)<<": "<<tempstr<<endl;

 }
     return 0;
}

