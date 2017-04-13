#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
    ifstream inp("Input.in");
    ofstream outp("Output.out");
    string a="ejp mysljylc kd kxveddknmc re jsicpdrysi";
    string b="our language is impossible to understand";
    int ascii[256];
    for(int i=0; i<256; i++)
        ascii[i]=0;
    for(int i=0; i<a.length(); i++)
        ascii[(int)a[i]]= (int)b[i];
    a="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    b="there are twenty six factorial possibilities";
    for(int i=0; i<a.length(); i++)
        ascii[(int)a[i]]= (int)b[i];
    a="de kr kd eoya kw aej tysr re ujdr lkgc jv";
    b="so it is okay if you want to just give up";
    for(int i=0; i<a.length(); i++)
        ascii[(int)a[i]]= (int)b[i];
    ascii[122]=113;
    ascii[113]=122;
    /*for(int i=0; i<256; i++){
        cout<<i<<" : "<<ascii[i]<<endl;
    }*/
    //verdadero inicio del programa
    int tc;
    string g;
    inp>>tc;
    getline(inp,g);
    for(int TC=1; TC<=tc; TC++){
        getline(inp,g);
        cout<<g;
        string ans="";
        for(int i=0; i<g.length(); i++)
            ans+=(char)(ascii[(int)g[i]]);
        outp<<"Case #"<<TC<<": "<<ans<<"\n";
        cout<<"Case #"<<TC<<": "<<ans<<endl;
    }
    outp.close();
    inp.close();
    system("PAUSE");
    return 0;
}
