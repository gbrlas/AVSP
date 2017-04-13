#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int BUF = 105;


int nCnv, nDel;
string cnv[BUF], del[BUF], str;

void read(){
  cin >> nCnv;
  for(int i=0;i<nCnv;i++) cin >> cnv[i];
  cin >> nDel;
  for(int i=0;i<nDel;i++) cin >> del[i];
  int dummy;
  cin >> dummy >> str;
}


void work(int cases){
  vector<char> cur;

  for(int loop=0;loop<str.size();loop++){
    cur.push_back(str[loop]);
    if(cur.size()<2) continue;

    while(1){
      bool updated = false;
      for(int i=0;i<nCnv;i++)
        if((cnv[i][0]==cur[cur.size()-1] && cnv[i][1]==cur[cur.size()-2]) ||
           (cnv[i][0]==cur[cur.size()-2] && cnv[i][1]==cur[cur.size()-1]) ){
          cur.pop_back();
          cur.pop_back();
          cur.push_back(cnv[i][2]);
          updated = true;
          break;
        }
      if(!updated) break;
    }

    for(int i=0;i<nDel;i++)
      for(int pos1=0;pos1<cur.size();pos1++)
        for(int pos2=pos1+1;pos2<cur.size();pos2++)
          if((del[i][0]==cur[pos1] && del[i][1]==cur[pos2]) ||
             (del[i][0]==cur[pos2] && del[i][1]==cur[pos1]) ){
            cur.clear();
            goto _finish;
          }
  _finish:;
  }

  cout << "Case #" << cases << ": [";
  for(int i=0;i<cur.size();i++){
    if(i) cout << ", ";
    cout << cur[i];
  }
  cout << "]" << endl;
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
