//09 google code jame qualification round
//Alien Language
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAXN 5010
int l,n,d,res,curPos;
int mark[15];
string dict[MAXN];
bool splitCharArray[15][30];
string curLine;
string curWord;

void input();
void work();
void splitWord();
void dfs(int s);



int main()
{
    scanf("%d %d %d",&l,&d,&n);
    input();
    work();
    return 0;
}

void work()
{
    int i,j,k;
    for(i=1;i<=n;++i)
    {
        res=0;
        curPos=0;
        cin >> curLine;
        splitWord();
        for(j=0;j<d;++j)    //enumerate each word
        {
            bool flag=true;
            for(k=0;k<l;++k)    //enumerate each char
            {
                int ch=dict[j][k]-'a';
                if(!splitCharArray[k][ch])
                {
                    flag=false;
                    break;
                }
            }   //end for 
            if(flag) ++res;
        }   // end for
        printf("Case #%d: %d\n",i,res);
    }
    return;
}

void splitWord()
{
    int pos,cur;
    char ch;
    memset(splitCharArray,0,sizeof(splitCharArray));
    pos=0;
    cur=0;
    while(pos!=curLine.size())
    {
        if(curLine[pos]=='(')
        {
            ++pos;  //ignore '('
            while(curLine[pos]!=')')
            {
                ch=curLine[pos];
                splitCharArray[cur][ch-'a']=1;
                ++pos;
            }
            ++cur;
        }
        else
        {
            ch=curLine[pos];
            splitCharArray[cur][ch-'a']=1;
            ++cur;
        }
        ++pos;
    }
}

void input()
{
    int i,j;
    string newWord;
    memset(mark,0,sizeof(mark));
    for(i=0;i<d;++i)
    {
        cin >> dict[i];
    }
    return;
}
