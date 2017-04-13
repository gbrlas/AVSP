#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main(){
    ofstream cout("salMagic.txt");
    ifstream cin("A-small-attempt0.in");
    int T,r1,r2,n1;
    cin>>T;
    int voy = 0;
    while (T--){
        cin>>r1;
        vector<bool> m(20,false);
        vector<vector<int> > c1(4);
        vector<vector<int> > c2(4);
        for (int i =0; i<4; i++){
            for (int j=0; j<4; j++){
                cin>>n1;
                c1[i].push_back(n1);
            }
        }

        cin>>r2;

        for (int i =0; i<4; i++){
            for (int j=0; j<4; j++){
                cin>>n1;
                c2[i].push_back(n1);
            }
        }
        for (int i=0; i<4; i++){
            m[c1[r1-1][i]]= true;
        }
        bool sw = false;
        int cont = 0;
        int resp = 0;
        for (int i=0; i<4; i++){
            if (m[c2[r2-1][i]]){
                sw = true;
                cont++;
                resp = c2[r2-1][i];
            }
        }
        cout<<"Case #"<<++voy<<": ";
        if (!sw){
            cout<<"Volunteer cheated!"<<endl;
        }else{
            if (cont == 1){
                cout<<resp<<endl;
            }else{
                cout<<"Bad magician!"<<endl;
            }
        }

    }

    return 0;
}
