#include<cstdio>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int main(){
  int t;
  int c;
  int d;
  int n;
  char aux1;
  char aux2;
  char aux3;  
  string tmp;
  int case_count = 1;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&c);
    map<string,char> combine;
    map<char,char> opposed;
    queue<char> invoke;
    for(int i=0 ; i<c ; i++){
      scanf(" %c%c%c ",&aux1,&aux2,&aux3);
      tmp = string();      
      tmp += aux1;
      tmp += aux2;
      combine[tmp] = aux3;
      tmp = string();
      tmp += aux2;
      tmp += aux1;
      combine[tmp] = aux3; 
    }
    scanf("%d",&d);
    for(int i=0 ; i<d ; i++){
      scanf(" %c%c ",&aux1,&aux2);
      opposed[aux1] = aux2;
      opposed[aux2] = aux1;
    }
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
      scanf(" %c ",&aux1);
      invoke.push(aux1);
    }
    list<char> mylist;
    list<char> mysortlist;
    while(!invoke.empty()){
      if(mylist.empty()){
	mylist.push_back(invoke.front());
	mysortlist.push_back(invoke.front());
	mysortlist.sort();
      }else{
	tmp = string();
	tmp += mylist.back();
	tmp += invoke.front();
	if(combine[tmp]!=0){
	  mysortlist.erase(lower_bound(mysortlist.begin(),mysortlist.end(),mylist.back()));
	  mylist.pop_back();
	  mylist.push_back(combine[tmp]);
	  mysortlist.push_back(combine[tmp]);
	  mysortlist.sort();	  
	}
	else{
	  mylist.push_back(invoke.front());
	  mysortlist.push_back(invoke.front());
	  mysortlist.sort();
	}
	if(binary_search(mysortlist.begin(),mysortlist.end(),opposed[mylist.back()])){
	  mylist.clear();
	  mysortlist.clear();
	}
      }      
      invoke.pop();
    }
    printf("Case #%d: [",case_count++);
    if(!mylist.empty()){
      list<char>::iterator it = mylist.begin();
      printf("%c",*it);
      it++;
      for( ; it!=mylist.end() ; it++)
	printf(", %c",*it);
    }
    printf("]\n");
  }
  return 0;
}