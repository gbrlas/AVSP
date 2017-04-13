#include<iostream>
#include<vector>
#include<map>
#define s(n)scanf("%d",&n)
using namespace std;

int dp[505][505];

string s;
int len,words,t;
char s2[10000];
int cs;
map<string,int>m;
int cnt;
int slen;
string v[20];
int ans;

void go(int p,string a)
{
     if(p==len)
     {
       ans++;
       return ;
     }
     for(int i=0;i<v[p].length();i++)
     {
             string tmp = a + "" + v[p][i];
             
             if(m.find(tmp)!=m.end())
             go(p+1,tmp);
     }
      
}

main()
{
      freopen("A-small-attempt1.in","r",stdin);
      freopen("A-small-attempt1.out","w",stdout); 
      ans=0;     
      s(len);s(words);s(t);
      int tt = words;
      while(words-- )
      {
         cin >> s;
         for(int i=0;i<len;i++)
         {
           string tmp = s.substr(0,i+1);
            m[tmp]=++cnt;
         }
      }
      while(t--)
      {
           ans=0;
           scanf("%s",&s2);
           slen=strlen(s2);
           int pos=0;
           for(int i=0;i<slen;i++)
           {
                   v[pos]="";
                   if(s2[i] == '(')
                   {
                     string tmp="";
                     ++i;
                     while(s2[i]!=')')
                     tmp+=s2[i++];

                     v[pos]=tmp;
                     pos++;                   
                   }
                   else
                   v[pos++]+=s2[i];
           }
           
           go(0,"");
           printf("Case #%d: %d\n",++cs,ans);
      }
      //system("pause");
      
}
