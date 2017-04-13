#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<queue>
#include<math.h>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<char,char>m1;

void mapping(){
    m1['a']='y';m1['b']='h';m1['c']='e';m1['d']='s';m1['e']='o';
    m1['f']='c';m1['g']='v';m1['h']='x';m1['i']='d';m1['j']='u';
    m1['k']='i';m1['l']='g';m1['m']='l';m1['n']='b';m1['o']='k';
    m1['p']='r';m1['q']='z';m1['r']='t';m1['s']='n';m1['t']='w';
    m1['u']='j';m1['v']='p';m1['w']='f';m1['x']='m';m1['y']='a';
    m1['z']='q';
}

int main()
{

  mapping();
    char input[105];
    int t=0,caseno=0;
    scanf("%d\n",&t);
    while(t--){
        gets(input);
        cout<<"Case #"<<++caseno<<": ";
        int i=0;
        while(input[i]){
            if(input[i]!=' ')
                cout<<m1[input[i]];
            else
                cout<<input[i];
            i++;
        }
        cout<<endl;
    }
	return 0;
}
