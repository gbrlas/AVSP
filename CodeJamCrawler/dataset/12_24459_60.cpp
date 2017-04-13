using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    
    int i,len,cases,tc;
    char c;
    string str="yhesocvxduiglbkrztnwjpfmaq";
    string temp;
    scanf("%d",&cases);
    getline(cin,temp);
    tc=0;
    
    while(cases--)
    {
         tc++;
         getline(cin,temp);
         len=temp.length();
         for(i=0;i<len;i++)
         {
              c=temp[i]-'a';
              if(temp[i]>='a' && temp[i]<='z')
                   temp[i]=str[c];
         }
         cout<<"Case #"<<tc<<": "<<temp<<endl;
    }
    return 0;
}
