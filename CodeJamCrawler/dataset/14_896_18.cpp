#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string deleteAdjc(string s)
{
    string _s = s;
    for(int i=0;i<_s.size() - 1;i++)
        if(_s[i] == _s[i+1]){
            _s.erase(_s.begin()+i);
            i--;
        }
    return _s;
}

bool isStrIdntcl(string s1,string s2){
    if(s1.size() != s2.size()) return false;
    for(int i=0;i<s1.size();i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

int findResult(string s0,string s1){
    vector<int> v1;
    int k=0;
    for(int i=0;i<s0.size() - 1;i++){
        if(s0[i] != s0[i+1]) {v1.push_back(k + 1); k=0;}
        else{
            k++;
        }
    }
    v1.push_back(k + 1);

    vector<int> v2;
    k=0;
    for(int i=0;i<s1.size() - 1;i++){
        if(s1[i] != s1[i+1]) {v2.push_back(k + 1); k=0;}
        else{
            k++;
        }
    }
    v2.push_back(k + 1);

    int result = 0;
    for(int i=0;i<v1.size();i++){
        result += abs(v1[i] - v2[i]);
    }
    return result;
}

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        int t;
        _if >> t;
        string s[t];
        for(int j=0;j<t;j++) _if >> s[j];

        if(!isStrIdntcl(deleteAdjc(s[0]),deleteAdjc(s[1]))){
            _of << "Case #" << i+1 << ": Fegla Won" << endl;
            continue;
        }

        _of << "Case #" << i+1 << ": " << findResult(s[0],s[1]) << endl;
    }
}
