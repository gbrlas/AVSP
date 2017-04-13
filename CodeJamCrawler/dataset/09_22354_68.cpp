#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define CLEAR(X) memset(X,0,sizeof(X))
#define REP(i,n) for(int i=0;i<(n);i++) 
template <class T> vector<T>parse(string s,const char d=' '){
  vector<T> v; string p; s+=d; int i=0; 
  while(i<(int)s.size())
    if (s[i] == d){stringstream u; u<<p; T t; u>>t; v.push_back(t); p=""; while(i<(int)s.size() && s[i]==d)i++;} else p+=s[i++];   
  return v;
} 

typedef long long ll;
typedef long double ld;

char s[10000];

struct st{
  double w;
  char f[20];
  st *left,*right;
} head;

int k;

bool wt(char c){return c==' '|| c=='\n';}
void skip(){
  while(s[k] && wt(s[k]))k++;
}

char tmp[100];

void getn(char *tmp){  
  while((s[k]>='0' && s[k]<='9')||s[k]=='.'){
    *tmp=s[k];
    k++;tmp++;
  }
  *tmp=0;
}

void getf(char *tmp){
  while((s[k]>='a' && s[k]<='z')){
    *tmp=s[k];
    k++;tmp++;
  }
  *tmp=0;
}

void parse(st* cur){
  skip();
  if(s[k]!='('){cerr<<"zle je "<<k<<endl<<endl;}
  k++;
  skip();
  getn(tmp);
  sscanf(tmp,"%lf",&cur->w);
//  printf("c %lf\n",cur->w);
  skip();
  if(s[k]==')'){
  //  cerr<<"a"<<endl;
    k++;
    return;
  }
  getf(cur->f);
  skip();
//  printf("%s\n",cur->f);
//  printf("%d\n",k);
  cur->left = new st;
  cur->left->left=cur->left->right=NULL;
  parse(cur->left);
  skip();
  cur->right = new st;
  cur->right->left=cur->right->right=NULL;
//  printf("kk %d %c\n",k,s[k]);
  parse(cur->right);
  skip();  
  if(s[k]!=')')cerr<<"ou nou"<<endl;
  k++;
} 

set<string> pr;

double eval(st *cur){
//  printf("w%.9lf\n",cur->w);
  if(!cur->left)return cur->w;
//  printf("%s\n",cur->f);
  if(pr.count(cur->f))return cur->w * eval(cur->left);
  return cur->w * eval(cur->right);
}

int main(){
  int _cases; scanf("%d ",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:\n",_case);
    gets(tmp);
    int l;sscanf(tmp,"%d",&l);
    s[0]=0;
    REP(i,l){
      char tmp[100];
      gets(tmp);
      strcpy(s+strlen(s),tmp);
    }
 //   cerr<<s<<endl;
    head.left=head.right=NULL;
    k=0;
    parse(&head);

    int ans;scanf("%d",&ans);
    REP(i,ans){
      int p;
      scanf("%s %d ",tmp,&p);
      pr.clear();
      REP(j,p){
        scanf("%s ",tmp);
        pr.insert(tmp);
      }
      printf("%.9lf\n",eval(&head));
    }
  }
  cerr<<"ok"<<endl;
  return 0;
}
