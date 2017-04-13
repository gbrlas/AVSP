#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<vector>
#define maxs 40000
using namespace std;

int A, B;
vector <int> p1;
vector <int> p2;
bool found[maxs][maxs];

string toString(int x){
    stringstream ss;
    ss << x;
    string ret;
    ss >> ret;
    return ret;
}

int toInt(string x){
    stringstream ss;
    ss << x;
    int ret;
    ss >> ret;
    return ret;
}

string rotate(string x){
    return x.substr(1,x.size()) + x.substr(0,1);
}

bool findPair(int a, int b){
    if(a==b)return true;
    int m = p1.size();
    for(int i=0;i<m;i++)
        if((p1[i]==a && p2[i]==b) ||  (p2[i]==a && p1[i]==b))
            return true;
    return false;
}
long solve_small(){
    int ret = 0, size, newNum;
    string num;
    for(int i=A ; i<=B ; i++){
        num = toString(i);
        size = num.size() - 1;
        found[i][i] = true;
        while(size--){
            num = rotate(num);
            newNum = toInt(num);
            if(found[i][newNum]==true)continue;
            if(newNum >= A && newNum <= B){
                //p1.push_back(i);
                //p2.push_back(newNum);
                found[i][newNum] = found[newNum][i] = true;
                ret++;
            }
        }
    }
    return ret;
}
long solve(){
    //cout << "Big" << endl;
    int ret = 0, size, newNum;
    string num;
    for(int i=A ; i<=B ; i++){
        num = toString(i);
        size = num.size() - 1;
        while(size--){
            num = rotate(num);
            newNum = toInt(num);
            if(findPair(i,newNum)==true)continue;
            if(newNum >= A && newNum <= B){
                p1.push_back(i);
                p2.push_back(newNum);
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    //ifstream fin("DATAc.txt");
    //FILE*out = fopen("DATAcout.txt","w");
    int tests,t = 1, sol;
    cin >> tests;
    while(t<=tests){
        cin >> A >> B;
        p1.clear();
        p2.clear();
        if(B<maxs){
            sol = solve_small();
            for(int i=0;i<=B;i++)
                for(int j=0;j<=B;j++)
                    found[i][j] = 0;
        }
        else sol = solve();
        printf("Case #%d: %ld\n",t,sol);
        t++;
    }
    return 0;
}
