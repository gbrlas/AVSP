#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#define MAXN 256
#define MAX 1000
#define REM -1
#define S1   1
#define S2   2
using namespace std;

map<char,char> comb[MAXN];
set<char> op[MAXN];
vector<char> ans;
int flag[MAX];
void limpar(){
    int i;
    for(i=0;i<MAXN;i++){
        comb[i].clear();
        op[i].clear();
    }
    ans.clear();
    memset(flag,0,sizeof(flag));

}
int main(){
    int T;
    int N;
    int i,j,k;
    int w;
   cin>>T;
    string a,b,s;
    int C,D;
   // printf("INI ");
    map<char,char>::iterator it1,it2;
    for(k=0;k<T;k++){
        limpar();
        cin>>C;
        for(i=0;i<C;i++){
            cin>>a;
            comb[a[0]].insert(make_pair(a[1],a[2]));
            comb[a[1]].insert(make_pair(a[0],a[2]));
          //  it1=comb[a[0]].find(a[1]);
           // it2=comb[a[1]].find(a[0]);
       //     printf("SZ: %d %d\n",comb[a[1]].size(),comb[a[0]].size());
         //   printf("IN: %c %c %c: %c %c\n",a[0],a[1],a[2],it1->second,it2->second);
        }
        cin>>D;
        for(i=0;i<D;i++){
            cin>>b;
             op[b[0]].insert(b[1]);
             op[b[1]].insert(b[0]);
        }
        cin>>N;
        cin>>s;
       // cout<<N<<" d "<< s<<" e "<< C <<" as "<<D<<endl;
        //int sz=s.size();
        if(N>1){
            for(i=1;i<N;i++){
               // printf("%d %d\n",i,comb[s[i]].empty());
                if(comb[s[i]].find(s[i-1])!= comb[s[i]].end() && flag[i-1]==0){
                //    printf("COMB : %c %c , %c\n",s[i-1],s[i],comb[s[i]][s[i-1]]);
                    flag[i-1]=S1; flag[i]=S2;

                }
                else{
               //     printf("2\n");
                  //int bo=false;
                    for(j=i-1;j>=0;j--){
                      //  printf("J %d\n",j);
                        if(op[s[i]].find(s[j]) != op[s[i]].end() && flag[j]==0){
                            for(w=0;w<=i;w++){
                             //   printf("W %d\n",w);
                                flag[w]=REM;

                            }
                            break;
                        }

                    }
                }
            }
            for(i=0;i<N;i++){
               // printf("Flag %d\n",i);
                if(flag[i]==0){
                    ans.push_back(s[i]);
                  //  printf("ans 1: %c \n",s[i]);
                }
                else if(flag[i]==S1){
                    ans.push_back(comb[s[i]][s[i+1]]);
                 //   printf("ans 2, %d: %c \n",i,comb[s[i]][s[i+1]]);
                }
            }
        }
        else{
            ans.push_back(s[0]);
        }

        printf("Case #%d: [",k+1);
        //printf("SZ %d\n",ans.size());
        int sz=ans.size();
        for(i=0; i < sz-1; i++){
            printf("%c, ",ans[i]);
        }
        if(sz>0)
            printf("%c]\n",ans[ans.size()-1]);
        else
            printf("]\n");




    }
    return 0;



}

