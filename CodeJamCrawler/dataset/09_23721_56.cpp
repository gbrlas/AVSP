#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

ifstream fin("B-large.in");
ofstream fout("b.out");

int T;

int main(){
    fin>>T;
    for(int q=0;q<T;q++){

        string c;
        string res="";
        fin>>c;

        bool done=false;
        for(int i=c.size()-1;i>=0;i--){
            int minn=1000, ind=-1;
            for(int j=c.size()-1;j>i;j--){
                if(c[i]<c[j] && minn>c[j]) {
                    minn = c[j];
                    ind = j;
                }
            }
            if(ind != -1){
                res=c.substr(0,i)+char(minn);
                string tmp=c.substr(i,ind-i)+c.substr(ind+1);
                done =true;

                vector<char> cislo;
                for(int i=0;i<tmp.size();i++) cislo.push_back(tmp[i]);
                sort(cislo.begin(),cislo.end());
                for(int i=0;i<cislo.size();i++){
                    res+=cislo[i];
                }
                break;
            }

        }

        if( !done ){
            vector<char> cislo;
            for(int i=0;i<c.size();i++) cislo.push_back(c[i]);
            sort(cislo.begin(),cislo.end());

            res="";
            for(int i=0;i<cislo.size();i++){
                res+=cislo[i];
            }
            if(res[0]!='0'){
                string tmp="0";
                res=res[0]+tmp+res.substr(1);
            } else {
                int ind=0;
                while (res[ind]=='0') ind++;
                res=res.substr(ind)[0]+res.substr(0,ind)+'0'+res.substr(ind).substr(1);
            }
        }

        fout<<"Case #"<<q+1<<": "<<res<<endl;
    }
    return 0;
}
