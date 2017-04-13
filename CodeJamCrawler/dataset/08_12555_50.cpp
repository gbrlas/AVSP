#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



int main(){
  int n;
  scanf(" %d",&n);
  for(int test=1;test<=n;test++){
    int s,q;
    char linha[200];
    char seen[200];
    string names[200];

    scanf(" %d\n",&s);    
    for(int i=0;i<s;i++){
      gets(linha);
      names[i] = string(linha);
      //printf("[%s]\n",names[i].c_str());
    }
    bzero(seen,sizeof(seen));
    scanf(" %d\n",&q);
    int tot_seen = 0;
    int switches = 0;
    for(int i=0;i<q;i++){
      gets(linha);
      string query(linha);
      //printf("{%s}\n",query.c_str());
      int pos=-1;
      for(int j=0;j<s&&pos==-1;j++){
	if(query == names[j]) pos = j;
      }
      tot_seen += !seen[pos];
      seen[pos] = 1;
      
      if(tot_seen == s){
	switches++;
	bzero(seen,sizeof(seen));
	seen[pos] = 1;
	tot_seen = 1;
      }
    }
    printf("Case #%d: %d\n",test,switches);
  }
  
}
