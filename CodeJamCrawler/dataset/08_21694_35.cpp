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

int mac[7000],mic[7000];
int mar[7000],mir[7000];
//char a[7000][7000];

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

bool hor[7000][7000];
bool ver[7000][7000];
bool ins[7000][7000];
bool isp[7000][7000];
//int hc[7000][7000];

int main(){
  int _cases; scanf("%d",&_cases);
  for(int _case=1;_case<=_cases;_case++){
    printf("Case #%d:",_case);

    int l;scanf("%d",&l);
    CLEAR(hor);CLEAR(isp);CLEAR(ver);
    REP(i,7000){
      mac[i]=mar[i]=-1;
      mic[i]=mir[i]=10000;
    }
    int x=3500;int y=3500;
    int dir=0;
//    CLEAR(a);
    REP(i,l){
      char s[100];scanf("%s",s);int r;scanf("%d",&r);
      REP(kk,r)
        for(int j=0; s[j];j++){
          if(s[j]=='L')dir=(dir+3)%4;
          else if(s[j]=='R')dir=(dir+1)%4;
          else {x+=dx[dir];y+=dy[dir];
            if(dir==1){
              hor[y-dy[dir]][x-dx[dir]]=true;
            }else if(dir==3){
              hor[y][x]=true;
            }else if(dir==0){
              ver[y][x]=true;
            }else ver[y-dy[dir]][x-dx[dir]]=true;
          }
//          a[y][x]=true;
//          mir[y]=min(mir[y],x);
//          mar[y]=max(mar[y],x);
//          mic[x]=min(mic[x],y);
//          mac[x]=max(mac[x],y);
        }

    }
    CLEAR(isp);
    REP(i,7000){
      bool inside=false;
      REP(j,7000){
        if(hor[j][i]){
          inside=!inside;
        };
        ins[i][j]=inside;
      }

    }
    REP(i,6999){
      int st=0;int en=6999;
      while(st<7000 && !ins[i][st])st++;
      while(en>=0 && !ins[i][en])en--;
      if(st<en){
        for(int j=st+1;j<en;j++)if(!ins[i][j]){isp[i][j]=true;}
      }
    }
    REP(i,6999){
      int st=0,en=6999;
      while(st<7000 && !ins[st][i])st++;
      while(en>=0 && !ins[en][i])en--;
      if(st<en)for(int j=st+1;j<en;j++)if(!ins[j][i])isp[j][i]=true;
    }
    int area=0;
    REP(i,7000)REP(j,7000)if(isp[i][j]){area++;}
//    REP(i,7000)REP(j,7000)if(ins[i][j])printf("ins: %d %d\n",i,j);
    printf(" %d\n",area);




  }
  return 0;
}
