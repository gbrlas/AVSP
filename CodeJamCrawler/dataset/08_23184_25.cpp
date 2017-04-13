#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int N,S,Q,i,caso=1;
  string* servers;
  string* queries;
  string temp,query;

  cin >> N;
  while (N--){

    cin >> S;
    servers=new string[S];
    getline(cin,temp);
    for(i=0;i<S;++i){
      getline(cin,temp);
      servers[i]=temp;
    }

    cin >> Q;
    queries=new string[Q];
    getline(cin,query);
    for(i=0;i<Q;++i){
      getline(cin,query);
      queries[i]=query;
    }

    int ini=0,num_serv=0,pos;
    while(1){
      int max_pos=-1;
      for(i=0;i<S;++i){
	string* res=find(queries+ini,queries+Q,servers[i]);
	pos=res-queries;
	if(pos>max_pos) max_pos=pos;
      }
      if(max_pos==Q)break;
      else{
	ini=max_pos;
	num_serv++;
      }
    }

    cout << "Case #" << caso << ": " << num_serv << endl;
    caso++;
    delete[] queries;
    delete[] servers;
  }
}
