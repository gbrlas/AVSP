/* 
 * File:   Ugly.cpp
 * Author: root
 *
 * Created on July 27, 2008, 3:37 PM
 */

#include <vector>


#include <cstdlib>
#include <cstdio>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

/*
 * 
 */

string str;
int strLen;
//set <long long> numSet;
vector <long long> numVect;
char signs[20];


void process()
{
    long long i, res, num;
    char lastSign;
    
    lastSign = '+';
    res = 0;
    num = str[0] - '0';
    
    for(i=1;i<strLen;i++)
    {
        if(signs[i] == '.')
        {
            num *= 10;
            num += (str[i] - '0');
        }
        else if(signs[i] == '+'|| signs[i] == '-')
        {
            if(lastSign == '+')
                res += num;
            else if(lastSign == '-')
                res -= num;
            
            num = str[i] - '0';
            lastSign = signs[i];
        }
    }
    
    if(lastSign == '+')
        res += num;
    else if(lastSign == '-')
        res -= num;
    
    //numSet.insert(res);
    numVect.push_back(res);
    
    
    
}


void backtrack(int pos)
{
    if(pos == strLen)
    {
        process();
        return;
    }
    
    signs[pos] = '.';
    backtrack(pos + 1);
    signs[pos] = '+';
    backtrack(pos + 1);
    signs[pos] = '-';
    backtrack(pos + 1);
}


bool isUgly(long long num)
{
    if(!num)
        return true;
    
    if(!(num % 2))
        return true;
    
    if(!(num % 3))
        return true;
    
    if(!(num % 5))
        return true;
    
    if(!(num % 7))
        return true;
    
    return false;
}


int main(int argc, char** argv) {
    
    int cases, caseNo;
    long long res, i;
    //set <long long>::iterator it;
    
    freopen("input.txt","r",stdin);
    freopen("BSoutput.txt","w",stdout);
    
    cin>>cases;
    for(caseNo=1;caseNo<=cases;caseNo++)
    {
        printf("Case #%d: ",caseNo);
        cin>>str;
        strLen = str.length();
        
        //numSet.clear();
        numVect.clear();
        
        signs[0] = '.';
        backtrack(1);      
        
        res = 0;
//        for(it=numSet.begin(); it!=numSet.end(); it++)
//        {
//            printf("%lld ",*it);
//            if(isUgly(*it))
//            {
//                
//                res++;            
//            }
//        }
        for(i=0; i<numVect.size(); i++)
            if(isUgly(numVect[i]))
                res++;
        
        printf("%lld\n",res);
        

        
    }
    
    return (EXIT_SUCCESS);
}

