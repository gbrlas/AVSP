#include<iostream>
#include<set>
#define BUF 1001
using namespace std;

class DSet{
public:
  int pre[BUF];

  DSet(){}
  DSet(int L, int R){
    for(int i=L;i<=R;i++) pre[i] = i;
  }

  int find(int a){
    if(pre[a]==a) return a;
    return pre[a] = find(pre[a]);
  }

  void merge(int a, int b){
    pre[find(a)] = pre[find(b)];
  }
};

int low, up, P;

void read(){
  cin >> low >> up >> P;
}

bool share(int a, int b){
  for(int i=2;i*i<=a;i++)
    if(a%i==0){
      while(a%i==0) a/=i;
      
      if(i>=P && b%i==0)
        return true;
    }
  return a>=P && b%a==0;
}

void work(int cases){
  DSet dset(low,up);

  for(int i=low;i<=up;i++)
    for(int j=i+1;j<=up;j++)
      if(share(i,j))
        dset.merge(i,j);
  
  set<int> S;
  for(int i=low;i<=up;i++)
    S.insert(dset.find(i));

  cout << "Case #" << cases << ": " << S.size() << endl;
}

int main(){
  int cases;
  cin >> cases;

  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }

  return 0;
}
