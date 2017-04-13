#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int t,len,now,temp;
long long ans;
string str;
int map[100];

int calc(char x){
    if (x>='0'&&x<='9') return int(x)-int('0');
    if (x>='a'&&x<='z') return int(x)-int('a')+10;
    if (x>='A'&&x<='Z') return int(x)-int('A')+36;
}

int main(){
    fin>>t;
    for (int o=1;o<=t;o++){
        fin>>str;
        len=str.length();
        memset(map,-1,sizeof(map));
        temp=calc(str[0]);
        map[temp]=1;
        now=0;
        for (int i=1;i<len;i++){
            temp=calc(str[i]);
            if (map[temp]==-1){
                map[temp]=now;
                if (now==0) now=2;
                    else now++;
            }
        }
        if (now==0) now=2;
        long long base=1;
        ans=0;
        for (int i=len-1;i>=0;i--){
            ans+=map[calc(str[i])]*base;
            base=base*now;
        }
        fout<<"Case #"<<o<<": "<<ans<<endl;
    }
    return 0;
}
