#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char a[1000];
    int t,i,j,len,r;
    cin>>t;
    r=1;
     cin.getline(a,1000,'\n');
    for(j=0;j<t;j++)
    {
        cin.getline(a,1000,'\n');
    int len=strlen(a);
   //cout<<"case#"<<r++<<":";
   cout<<"Case #"<<r++<<": ";
    for(i=0;i<len;i++)
    {
     switch(a[i])
    {


    case ' ':
    cout<<' ';
    break;
    case 'a':

    cout<<'y';
    break;
    case 'b':
    cout<<'h';
    break;
break;

    case 'c':
    cout<<'e';
break;

    case 'd':
    cout<<'s';
break;

    case 'e':
    cout<<'o';
break;

    case 'f':
    cout<<'c';
break;

    case 'g':
    cout<<'v';
break;

    case 'h':
    cout<<'x';
break;

    case 'i':
    cout<<'d';
break;

    case 'j':
    cout<<'u';


break;

    case 'k':
    cout<<'i';
break;

    case 'l':
    cout<<'g';
break;

    case 'm':
    cout<<'l';
break;

    case 'n':
    cout<<'b';
break;

    case 'o':
    cout<<'k';
break;

    case 'p':
    cout<<'r';
break;

    case 'q':
    cout<<'z';
break;

    case 'r':
    cout<<'t';
break;

    case 's':
    cout<<'n';
break;



   case 't':
    cout<<'w';
break;

    case 'u':
    cout<<'j';
break;

    case 'v':
    cout<<'p';
break;

    case 'w':
    cout<<'f';
break;

    case 'x':
    cout<<'m';
break;

    case 'y':
    cout<<'a';
    break;
    case 'z':
    cout<<'q';
break;
default:
break;


     //   cout<<a[i];
    }
    }
   // cout<<"Case #"<<r++<<":";
   /* for(i=0;i<len;i++)
    {
        cout<<a[i];
    }*/

    cout<<"\n";
    }

    return 0;
}
