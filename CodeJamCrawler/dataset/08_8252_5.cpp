#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include<list>
using namespace std;

#define LEN 2048

char buf[LEN];

int comp(int i,int j)
{
    if(i==j)
    return 0;
    else
    if(i<j)
    return -1;
    else
    return 1;
}
int main()
{
    freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
	
	gets(buf);

	int T=atoi(buf);
	

    for(int k=0;k<T;k++)
    {
            	list<int> li1;
	list<int> li2;
    	gets(buf);
        int n=atoi(buf);
        gets(buf);

    	
    	int i=0;
        for(int it=0;it<n;it++)
    	{
            int j=0;
            char tempbuf[1024];
            memset(tempbuf,0,1024);
            while((buf[i]!=' ')&&(buf[i]!='\0')&&(buf[i]!='\n'))
            {
                 tempbuf[j]=buf[i];
                 i++;
                 j++;
                 
            }
            i++;
            li1.push_back(atoi(tempbuf));     
             
        } 
        
        gets(buf);
    	
    	i=0;
        for(int it=0;it<n;it++)
    	{
            int j=0;
            char tempbuf[1024];
            memset(tempbuf,0,1024);
            while((buf[i]!=' ')&&(buf[i]!='\n')&&(buf[i]!='\0'))
            {
                 tempbuf[j]=buf[i];
                 i++;
                 j++;
            }
            i++;
            li2.push_back(atoi(tempbuf));
            
        }
        
        
        li1.sort();
        li2.sort();
        
        long Y=0;
        list<int>::iterator it1=li1.begin();
        list<int>::iterator it2=li2.end();
        
        for(int it=0;it<n;it++)
        {
            it2--;
            Y+=((*it1) * (*it2));
            it1++;
        }
        printf("Case #%d: %ld\n",k+1,Y);
        
    }

    return 0;
}

