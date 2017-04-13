#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//ofstream cout("OUT31.txt");
long long num[501], N;
bool found;

bool areEqual(vector <long long> s1, vector<long long> s2){
    if(s1.size()==0 || s2.size()==0)return false;
    long long sum1, sum2, i;
    sum1 = sum2 = 0;
    for(i=0;i<s1.size();i++)sum1+=s1[i];
    for(i=0;i<s2.size();i++)sum2+=s2[i];
    return (sum1==sum2);
}
bool used[501];

void print(vector <long long> s1, vector<long long> s2){
    long long i;
    for(i=0;i<s1.size()-1;i++)cout << s1[i] << " ";cout << s1[i]<< endl;
    for(i=0;i<s2.size()-1;i++)cout << s2[i] << " ";cout << s2[i]<< endl;
}
void process(long long ind, vector <long long> s1, vector<long long> s2){
    if(found)return;
    if(areEqual(s1,s2)){
        print(s1,s2);
        //getchar();
        found = true;
        return;
    }
    if(ind==N)return;
    vector<long long> t1, t2;
    t1.clear(); t2.clear();
    t1 = s1;
    t2 = s2;
    t1.push_back(num[ind]);
    t2.push_back(num[ind]);
    process(ind+1,t1,s2);
    process(ind+1,s1,t2);
    process(ind+1,s1,s2);
    return;
}

int main(){
    //ifstream cin("DATA31.txt");
    int tests, t = 1;
    cin >> tests;
    //tests = 1;
    vector<long long> a1, a2;
    a1.clear();
    a2.clear();
    while(t<=tests){
        cin >> N;
        memset(used,false,sizeof used);
        for(int i=0;i<N;i++)
            cin >> num[i];
        found = false;
        cout << "Case #" << t << ":" << endl;
        process(0,a1,a2);
        if(!found)cout << "impossible" << endl;
        t++;
    }
    return 0;
}
