#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("a.out");

int N;

double getProb(string &strom, int &ind){
    if(strom[ind] == '(') ind++;
    double res;

    stringstream ss(strom.substr(ind,30));
    ss>>res;
    //cout<<strom<<endl;cout<<ind;
    while(!(strom[ind]>='a' && strom[ind]<='z') && strom[ind] != ')') ind++;

    return res;
}

string getFeature(string &strom, int &ind){
    while(strom[ind]==' ') ind++;
    if(strom[ind] == ')') return "";

    string s;
    while(strom[ind]>='a' && strom[ind]<='z') {
        s+=strom[ind];
        ind++;
    }
    while(strom[ind]==' ') ind++;

    return s;
}

void move(string &strom, int &ind){
    if(strom[ind] == '(') ind++;
    int hlbka = 1;
    while(hlbka!=0){
        if(strom[ind] == '(') ++hlbka;
        if(strom[ind] == ')') --hlbka;
        ind++;
    }
    while(strom[ind]==' ') ind++;
}

int main(){
    fin>>N;
    for(int q=0;q<N;q++){
        int L;
        fin>>L;
        string tree;
        for(int i=0;i<L;i++){
            string s;
            getline(fin,s);
            if(s=="") getline(fin,s);
            tree+=s;
        }
        cout<<tree<<endl;

        fout<<"Case #"<<q+1<<":"<<endl;

        int A,n;
        fin>>A;
        for(int i=0;i<A;i++){
            string meno,s;
            set<string> vlast;

            fin>>meno>>n;
            for(int j=0;j<n;j++){
                fin>>s;
                vlast.insert(s);
            }

            double prav=1;
            int index=0;
            while(index<tree.size()){
                prav *= getProb(tree, index);
                //cout<<prav<<endl;
                string vl = getFeature(tree, index);
                //cout<<"|"<<vl<<"|"<<endl;

                if(vl.size()>0){
                    if( vlast.count(vl)<=0 ) move(tree, index);

                } else break;
            }

            fout<<fixed;
            fout<<setprecision (8) <<prav<<endl;
        }

    }
    return 0;
}
