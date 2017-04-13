#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
	#define entrada cin
#else
	#include <fstream>
#endif

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;
	#ifndef ONLINE_JUDGE
		ifstream entrada("entrada.txt");
	#endif

#define MAXLET 128

char combines[MAXLET+1][MAXLET+1];
bool oposes[MAXLET+1][MAXLET+1];

void clearMats(){
    for(int i=0; i<=MAXLET; i++)
        for(int j=0; j<=MAXLET; j++)
            combines[i][j] = oposes[i][j] = 0;
}

void associate(const string &s){
    char a = s[0];
    char b = s[1];
    char c = s[2];
    //cout << a << " combines with " << b << " to give " << c << endl;
    combines[a][b] = combines[b][a] = c;
}

void neglect(const string &s){
    char a = s[0];
    char b = s[1];
    //cout << a << " is oposed to " << b << endl;
    oposes[a][b] = oposes[b][a] = true;
}

int main(int argc, char **argv) {
    
    int T;
    entrada >> T;
    
    vector<char> list;
    
    for(int z=0; z<T; z++){
        clearMats();
        list.clear();
        
        int C;
        entrada >> C;
        
        for(int j=0; j<C; j++){
            string g;
            entrada >> g;
            associate(g);
        }
        
        int D;
        entrada >> D;
        for(int j=0; j<D; j++){
            string g;
            entrada >> g;
            neglect(g);
        }
        
        int N;
        entrada >> N;
        string linea;
        entrada >> linea;
        
        //cout << endl << endl;
        //cout << "N=" << N << " linea=" << linea << endl;
        
        list.push_back(linea[0]);
        
        for(int i=1; i<N; i++){
            char last = list.back();
            char curr = linea[i];
            
            list.push_back(curr);
            
            
            if( combines[last][curr] ){
                //cout << last << " combines with " << curr << endl;
                list.pop_back();
                list.pop_back();
                
                list.push_back(combines[last][curr]);
            }else{
                
                for(int j=0; j<list.size(); j++)
                    if( oposes[list[j]][curr] ){
                        list.clear();
                        break;
                    }
            }
            
        }
        
        cout << "Case #" << (z+1) << ": [";
        if(list.size() > 0)
            cout << list[0];
        for(int i=1; i<list.size(); i++)
            cout << ", " << list[i];
        cout << "]" << endl;
        
    }
    
	#ifndef ONLINE_JUDGE
		entrada.close();
	#endif
	return 0;
}
