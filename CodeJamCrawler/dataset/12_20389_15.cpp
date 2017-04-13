/**
 * Author: Ashraful Islam Rafi
 * University: Leading University,Sylhet
 * url:   https://code.google.com/codejam/contest/1460488/dashboard
 * problem id: A. Speaking in Tongues
 * complexity: 1st level(string)
 * site: codejam
**/
#include"map"
#include"set"
#include"queue"
#include"cmath"
#include"stack"
#include"ctype.h"
#include"cstdio"
#include"vector"
#include"stdio.h"
#include"cstring"
#include"cstdlib"
#include"string.h"
#include"iostream"
#include"algorithm"
using namespace std;
#define cs "Case "<<++casee<<": "
#define csE "Case "<<++casee<<":\n"
#define sf(t) scanf("%d",&t)
#define sNE(n,e) scanf("%d %d",&N,&E)
#define Inf 1000000000
#define S_N 5000010
#define MST(a, tf) memset(a, tf, sizeof (a))

int main()
{


    map<char,char> M;

    M['a']='y'; M['b']='h';M['c']='e'; M['d']='s'; M['e']='o';M['f']='c';
    M['g']='v'; M['h']='x';M['i']='d'; M['j']='u';M['k']='i';
    M['l']='g'; M['m']='l'; M['n']='b'; M['o']='k';  M['p']='r';
    M['q']='z';M['r']='t'; M['s']='n';M['t']='w';
    M['u']='j'; M['v']='p';M['w']='f';M['x']='m';M['y']='a';M['z']='q';


     // while((ch=getchar())!=EOF)

   char resul,ch,s[110];
   int t;sf(t);int casee=0;
   while(t--)
   {
     while(gets(s))
     {  int x=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {

            if(x==0)
            {
                 cout<<"Case #"<<++casee<<": "; x++;
            }

            if(s[i]==' ') cout<<" ";
            else
            if(M[s[i]]  && M[s[i]]!='0')
            {
                resul=M[s[i]];
                cout<<resul;//<<endl;
            }
        }
        cout<<endl;
     }
   }
}

/**Input

3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv


Output
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up
*/
