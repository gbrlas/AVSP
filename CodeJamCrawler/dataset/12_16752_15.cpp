#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main()
{
    char *fileNameIn="A-small-attempt3.in";
    ifstream in(fileNameIn);
    
    char *fileNameOut="A-small-attempt.out";
    ofstream out(fileNameOut);
    
    string num;
    int t=0;
    getline(in,num);
    
    int numLen=num.length();
    int mi=1;
    for(int i=numLen-1;i>=0;i--)
    {
         t+=mi*(num[i]-'0');
         mi*=10;
    }
    
    int cnt=1;
    
 //   cout<<t<<endl;
    
    while(cnt<=t)
    {
         string input;
         getline(in,input);
         //cout<<input<<endl;system("pause");
         int len=input.length();
         
        // cout<<input<<endl;
         
         string output=""; 
         for(int i=0;i<len;i++)
         {
              if(input[i]!=' ')
              {
                  output+=map[input[i]-'a'];
              }
              else
              {
                  output+=' ';
              }
         }
         out<<"Case #"<<cnt<<": "<<output<<endl;
         
         cnt++;
    }
    //system("pause");
    return 0;
}
