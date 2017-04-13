#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream cout("salWarBIG.txt");

    ifstream cin("D-large.in");
    int T,cant;
    double n1;
    int casos = 0;
    cin>>T;

    while (T--){
        cin>>cant;
        vector<double> n(cant);
        vector<double> k(cant);

        for (int i=0; i<cant; i++){
            cin>>n1;
            n[i]=n1;
        }
        for (int i=0; i<cant; i++){
            cin>>n1;
            k[i]=n1;
        }
        sort(n.begin(),n.end());
        sort(k.begin(),k.end());

        map<double,bool> mapa;
        int pk=0,pn=0,pk1=0,pn1=0;
        for (int i=0; i<cant; i++){
            double noe = n[i];
            double menor = -1;
            bool sw = false;
            for (int j=0; j<cant; j++){
                double ken = k[j];
                if (!mapa[ken]&&menor==-1){
                    menor = ken;
                }
                if ((noe-ken)<0 && !mapa[ken]){
                    mapa[ken]=true;
                    pk+=1;
                    sw = true;
                    break;
                }
            }
            if (!sw){
                mapa[menor]=true;
                pn+=1;
            }
        }

        map<double,bool> mapaN;

        for (int i=cant-1; i>=0; i--){
            double ken = k[i];
            double menor = -1;
            bool sw = false;
            for (int j=0; j<cant; j++){
                double noe = n[j];
                if (!mapaN[noe] && menor==-1){
                    menor = noe;
                }
                if ((noe-ken)>0 && !mapaN[noe]){
                    mapaN[noe]=true;
                    pn1+=1;
                    sw = true;
                    break;
                }
            }
            if (!sw){
                mapaN[menor]=true;
                pk1+=1;
            }

        }

        cout<<"Case #"<<++casos<<": "<<pn1<<" "<<pn<<endl;

    }

    return 0;
}
