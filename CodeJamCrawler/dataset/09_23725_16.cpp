#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

int posledny(string s){
    int last=0;
    for(int i=0;i<s.size();i++) if(s[i]=='1') last = i;
    return last;
}
int main(){
    int T;
    fin>>T;
    for(int q=0;q<T;q++){
        int N;
        fin>>N;
        vector< string> V(N),M(N); getline(fin,V[0]);
        for(int i=0;i<N;i++) getline(fin,V[i]);
        /*for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) M[j]+=V[i][j];
        */
       /* for(int i=0;i<N;i++) cout<<V[i]<<endl;
        swap(V[0],V[1]);

*/
        int poc=0;
        for(int i=0;i<N;i++){
            int ind=i;
            while( posledny(V[ind]) > i ) ++ind;
            for(int j=ind;j!=i;j--){
                swap(V[j],V[j-1]); poc++;
            }
        }
        fout<<"Case #"<<q+1<<": "<<poc<<endl;
    }
    return 0;
}
