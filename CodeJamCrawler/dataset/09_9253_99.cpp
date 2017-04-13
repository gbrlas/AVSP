#include<iostream>
#include<string>
using namespace std;
const int WORD = 5005, LENG = 20;

int main(){
  int len, nWord, cases;
  string word[WORD];
  
  cin >> len >> nWord >> cases;
  for(int i=0;i<nWord;i++) cin >> word[i];
  
  for(int caze=0;caze<cases;caze++){
    string str, strSeq[LENG];
    cin >> str;
    
    for(int strIdx=0,seqIdx=0;seqIdx<len;seqIdx++){
      if(str[strIdx]=='('){
        int pos = strIdx;
        while(str[pos]!=')') pos++;
        strSeq[seqIdx] = str.substr(strIdx+1,pos-strIdx-1);
        strIdx = pos+1;
      }
      else
        strSeq[seqIdx] = str[strIdx++];
    }
    
    int cnt = 0;
    for(int i=0;i<nWord;i++){
      bool ok = true;
      for(int j=0;j<len;j++)
        if(strSeq[j].find(word[i][j])==string::npos)
          ok = false;
      cnt += ok;
    }
    cout << "Case #" << caze+1 << ": " << cnt << endl;
  }
  
  return 0;
}
