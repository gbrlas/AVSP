/* 
 * File:   main.cpp
 * Author: christopher
 *
 * Created on April 13, 2012, 11:50 PM
 */

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream> 

using namespace std;

int x;//test cases
int out;//output
int m;
string line;
fstream file;
int i;//counter
int j;//score counter
int y;//space finder
int sur;//surpises
int ts;//target score
int s;//current score

int getcases()
{
    
    file.open("B-small-attempt0.in");
    getline(file,line); 
    stringstream ss(line);
    ss >> x;
    return x;
}
int getmax()
{
    getline(file,line);
    stringstream ss(line);
    ss >> out;  
    m = out;
    return out;
}
int getsurprise()
{
    y=line.find(' ');
    line.erase(0,y+1);
    stringstream ss(line);
    ss >> sur;
    return sur;
}
int gettarget()
{
    y=line.find(' ');
    line.erase(0,y+1);
    stringstream ss(line);
    ss >> ts;
    y=line.find(' ');
    line.erase(0,y+1);
    return ts;
}
int getscore()
{
    stringstream ss(line);
    ss >> s;
 
    if(y=line.find(' '))
    {
        line.erase(0,y+1);
    }
    return s;
}
int main() 
{     
    int hs;//lowest possible score without surprise
    int ls;//lowest possible score with surprise
    getcases();//happens once
    i=0;
    while(i!=x)
    {
        getmax();
        getsurprise();
        gettarget();
        
        hs=ts*3-2; ls=ts*3-4;
        j=0;
        while (j!=m)
        {
                getscore();
                if(s>hs-1)
                {
                    out=out;
                }
                else if (s<ls or s==0)
                {
                    out--;
                }
                else if(s>ls-1)
                {
                    sur--;
                    if (sur<0)
                    {
                        out--;
                    }
                }
                j++;
                
                
        }
        cout << "Case #"<< i+1 << ": "<<out<<'\n';
        i++;
    }
    return 0;
}

