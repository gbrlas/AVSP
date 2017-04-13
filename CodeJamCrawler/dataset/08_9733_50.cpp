#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <fstream>
#include <iostream.h>

using namespace std;

int main()
{
    int n=0;
    string str,atemp="";
    int s=0,q=0,count=0,k;
    set<string> queryset;
  ifstream file("C:\\A-large.in");


getline( file, str );
n=atoi(str.c_str());
for (int i=0;i<n;i++){
    getline( file, str );

    s=atoi(str.c_str());
     count=0;
      for (int j=0;j<s;j++)
                      getline( file, str );

                            getline( file, str );
                             q=atoi(str.c_str());
                             for (int j=0;j<q;j++){
                                 getline( file, str );
                                 queryset.insert(str);
                                 if(queryset.size()==s){
                                 queryset.clear();
                                 queryset.insert(str);
                                 count++;
                                 }
                             }

    queryset.clear();
    cout<< "Case #"<<(i+1)<<": "<<count<<endl;
}
file.close();
  return 0;
}
