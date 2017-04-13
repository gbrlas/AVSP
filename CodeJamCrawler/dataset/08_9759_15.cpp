#include<iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

int main()
{
   long long a,b,c,n=0,s=0,q=0,count=0;
   string str="",buf;
//stringstream ss(str);
//calucating

for(int j=0;j<56;j++)
{j++;
}   


vector <long long> tokens;

    ifstream file("C:\\a.in");
    getline( file, str );
    n=atoi(str.c_str());

        for (int i=0;i<n;i++){
   count=0;
   getline( file, str );
istringstream ss(str);
ss>>a>>b>>c;


/* calulating again */


//code output generating





      getline( file, str );
stringstream ss1(str);

while (ss1 >> buf)
    tokens.push_back(atoi(buf.c_str()));

sort(tokens.rbegin(),tokens.rend());
if(!(a*b<c))
{
for(long long k=0;k<c;k++)
count=count+tokens[k]*((k/b)+1);
}
                                            tokens.clear();


if(!(a*b<c))
        cout<< "Case #"<<(i+1)<<": "<<count<<endl;
else
    cout<< "Case #"<<(i+1)<<": "<<"Impossible"<<endl;
    }
    file.close();
    return 0;
}
