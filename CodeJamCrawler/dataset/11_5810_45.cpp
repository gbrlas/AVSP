#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main () {
    int t;
    cin >> t;
    for (int count = 1; count <= t; ++count) {
        int c,d,n;
        cin >> c;
        map < string , char > com;
        map < string , bool > elim;
        string aux1,aux2;
        char a1,a2;
        while (c--) {
            aux2 = "";
            cin >> aux1;
            a1 = aux1[0];
            a2 = aux1[1];
            aux2 += a2;
            aux2 += a1;
            com[aux1.substr(0,2)] = com[aux2] = aux1[2];                        
        }   
        cin >> d;
        while (d--) {
            aux2 = "";
            cin >> aux1;
            a1 = aux1[0];
            a2 = aux1[1];
            aux2 += a2;
            aux2 += a1;
            elim[aux1.substr(0,2)] = elim[aux2] = true; 
        }
        cin >> n;
        string aux;
        cin >> aux;
        string res = "";
        if (n) 
        res += aux[0];
        for (int i = 1; i < n; ++i) {
            bool test = true;
               res += aux[i];
               while (test) {
                    test = false;
                    if ( res.size() > 1)
                    if (com[res.substr(res.size()-2,2)]) {
                        res[res.size()-2] = com[res.substr(res.size()-2,2)]; 
                        res.erase(res.end()-1); 
                        test = true;
                    }       
                    if ( res.size() > 1)   {
                    for (int i = 0; i < res.size()-1; ++i) {
                        a1 = res[i];
                        string auxil = "";
                        auxil += a1;
                        auxil += res[res.size()-1];       
                    if (elim[auxil]) {
                        res = "";
                        test = false; 
                        break;  
                    }
                }
                }
                    
                }
        }
        cout << "Case #"<<count<<": [";
        if (res.size())
        cout<<res[0];
        for (int j = 1; j < res.size();++j)
        cout<<", "<<res[j];
        cout<<"]"<<endl;
    }   
}
