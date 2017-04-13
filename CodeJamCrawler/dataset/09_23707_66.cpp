#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("alien.out");

long long L,D,N;
vector< vector<int> > node;
vector<int> fingers;
int pointer;
int node_counter;

int getChild(int uzol, int pismeno){
    if(node[uzol][pismeno] == 0){
        node_counter++;
        node[node_counter].resize(27);
        node[uzol][pismeno] = node_counter;
    }
    return node[uzol][pismeno];
}

void moveOn(string list){
    vector<int> newFingers;
    for(int i=0;i<fingers.size();i++){
        for(int j=0;j<list.size();j++){
            if (node[fingers[i]][list[j]-'a'] != 0) newFingers.push_back(node[fingers[i]][list[j]-'a']);
        }
    }
    fingers.clear();
    fingers=newFingers;
}

int main(){
    fin>>L>>D>>N;
    node.resize(L*D + 7);
    node_counter=1;
    node[1].resize(27);

    string s;
    for(int i=0;i<D;i++){
        fin>>s;
        pointer=1;
        for(int j=0;j<s.size();j++){
            pointer=getChild(pointer, s[j] - 'a');
        }
    }
    for(int i=0;i<N;i++){
        fin>>s;
        int j=0;
        fingers.clear();
        fingers.push_back(1);
        while( j<s.size() ){
            string list;

            if( s[j] == '(' ){
                j++;
                while(s[j] != ')'){
                    list +=s[j];
                    j++;
                }
            } else {
                list = s[j];
            }
            j++;

            moveOn(list);
        }
        fout<<"Case #"<<i+1<<": "<<fingers.size()<<endl;
    }
}
