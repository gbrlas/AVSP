#include<iostream>
#include<vector>
#include<string>
using namespace std;
char temp1[100];
char temp2[2000];
string words[8000];
int L;
int D;
int N;
int soln[20][26];
int main()
{ scanf("%d %d %d",&L,&D,&N);
  for(int i=0;i<D;i++)
  { scanf("%s",temp1);
    string tt=temp1;
    words[i]=tt;
  }
  for(int i=0;i<N;i++)
  { scanf("%s",temp2);
    string str=temp2;
    int len=str.size();
    for(int j=0;j<20;j++)
    for(int k=0;k<26;k++)
    soln[j][k]=0;
    for(int j=0,num=0;j<len;num++,j++)
    if(str[j]=='(')
    { j++;
      while(j<len&&str[j]!=')')
      soln[num][str[j++]-'a']=1;
    }
    else
    soln[num][str[j]-'a']=1;
    int ans=0;
    for(int j=0;j<D;j++)
    { bool exist=true;
      for(int k=0;k<L&&exist;k++)
      if(soln[k][words[j][k]-'a']==0)
      exist=false;
      if(exist)
      ans++;
    }
    printf("Case #%d: %d\n",i+1,ans);
  }
}
