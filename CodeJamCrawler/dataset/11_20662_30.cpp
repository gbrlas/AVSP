#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  int t;  
  int n;
  char r;
  int p;
  int cases_count = 1;
  scanf("%d",&t);
  while(t--){
    queue<pair<char,int> > main;    
    queue<int> o;
    queue<int> b;
    scanf("%d ",&n);
    for(int i=0 ; i<n ; i++){
      scanf(" %c %d ",&r,&p);
      main.push(pair<char,int>(r,p));
      if(r=='O') o.push(p);
      else b.push(p);
    }
    //printf("size: %d\n",main.size());
    int current_o = 1;
    int current_b = 1;
    int segs = 0;
    int diff;
    while(!main.empty()){
      //printf("R:|%c| P:|%d|\n",main.front().first,main.front().second);
      switch(main.front().first){
	case 'O':
	  diff = abs(current_o-main.front().second)+1;
	  current_o = o.front();
	  o.pop();
	  segs += diff;
	  if(b.front()>current_b)
	    current_b = abs(b.front()-current_b)>diff?current_b+diff:b.front();
	  if(b.front()<current_b)
	    current_b = abs(b.front()-current_b)>diff?current_b-diff:b.front();
	  break;
	case 'B':
	  diff = abs(current_b-main.front().second)+1;
	  current_b = b.front(); 
	  b.pop();
	  segs += diff;
	  if(o.front()>current_o)
	    current_o = abs(o.front()-current_o)>diff?current_o+diff:o.front();
	  if(o.front()<current_o)
	    current_o = abs(o.front()-current_o)>diff?current_o-diff:o.front();
      }
      //printf("%d ",diff);
      main.pop();
    }
    printf("Case #%d: %d\n",cases_count++,segs);
  }
  return 0;
}