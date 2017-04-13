#define ll long long 
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <utility>  
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 

using namespace std; 

#define CLEAR(t) memset((t),0,sizeof(t)) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define FORD(i,a,b) for(int i=(a);i>=(b);--i) 
#define REP(i,n) for(int i=0;i<(n);++i) 

char m[300];

void add(string a, string b){
  REP(i,(int)a.size())
    m[a[i]]=b[i];
}

int main(){

  REP(i,300)m[i]='?';
  add("aozq", "yeqz");
  add("ejp mysljylc kd kxveddknmc re jsicpdrysi",
      "our language is impossible to understand");
  add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
      "there are twenty six factorial possibilities");
  add("de kr kd eoya kw aej tysr re ujdr lkgc jv",
      "so it is okay if you want to just give up");
//  for(char i='a';i<='z';i++){
//    printf("%c %c\n",i,m[i]);
//  }
  int Cases; scanf("%d ",&Cases);
  REP(xxxx,Cases){
    printf("Case #%d: ",xxxx+1);
    char s[200];
    gets(s);
    for(int i=0;s[i]==' ' || (s[i]>='a' && s[i]<='z');i++)printf("%c",m[s[i]]);
    printf("\n");
  }
}
