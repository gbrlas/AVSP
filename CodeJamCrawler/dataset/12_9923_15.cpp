#include <string>
#include <map>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

map<char,char> M;

M['a']='y';
M['b']='h';
M['c']='e';
M['d']='s';
M['e']='o';
M['f']='c';
M['g']='v';
M['h']='x';
M['i']='d';
M['j']='u';
M['k']='i';
M['l']='g';
M['m']='l';
M['n']='b';
M['o']='k';
M['p']='r';
M['q']='z';
M['r']='t';
M['s']='n';
M['t']='w';
M['u']='j';
M['v']='p';
M['x']='m';
M['y']='a';
M['w']='f';
M['z']='q';

int T;
string line;
getline(cin,line);
sscanf(line.c_str(),"%d",&T);
int i,j,k;


for(i=0;i<T;i++){
    getline(cin,line);
    string out="";
    cout<<"Case #"<<i+1<<": ";
    for(j=0;j<line.size();j++){
        cout<<M[line[j]];
    }
    cout<<endl;

}

return 0;
}
