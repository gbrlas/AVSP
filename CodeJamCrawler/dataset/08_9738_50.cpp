#include <iostream.h>
#include <vector>

#include <fstream>
#include <algorithm>
#include <string>
 #include <cstdio>

using namespace std;

int main()
{
    int n,na,nb,ca,cb,s1i,s2i,s3i,s4i,tot;
    vector <pair <int,int> > timea,timeb;
    string str,str1,str2,str3,str4;
    char stra[10],strb[10];
    ifstream file("C:\\B-small-attempt0.in");
    getline( file, str );
    n=atoi(str.c_str());
    for (int i=0;i<n;i++){
        ca=0;
        cb=0;
        getline( file, str );
        tot=atoi(str.c_str());
        getline( file, str );
        sscanf(str.c_str(), "%s%s", stra,strb );
        na= atoi(stra);
        nb= atoi(strb);
        for (int j=0;j<na;j++){
            getline( file, str );
            str1 = str.substr (0,2);
            str2 = str.substr (3,2);
            str3 = str.substr (6,2);
            str4 = str.substr (9,2);
            s1i = atoi(str1.c_str())*60+atoi(str2.c_str());
            timea.push_back(make_pair( s1i, 1 ));
            s2i = atoi(str3.c_str())*60+atoi(str4.c_str())+tot;
            timeb.push_back(make_pair( s2i, -1 ));
        }
        for (int k=0;k<nb;k++){
            getline( file, str );
            str1 = str.substr (0,2);
            str2 = str.substr (3,2);
            str3 = str.substr (6,2);
            str4 = str.substr (9,2);
            s1i = atoi(str1.c_str())*60+atoi(str2.c_str());
            timeb.push_back(make_pair( s1i, 1 ));
            s2i = atoi(str3.c_str())*60+atoi(str4.c_str())+tot;
            timea.push_back(make_pair( s2i, -1 ));
        }
        sort (timea.rbegin(), timea.rend());
        sort (timeb.rbegin(), timeb.rend());
        for (int j=0;j<nb+na;j++){
            ca=timea[j].second + ca;
            cb=timeb[j].second+cb;
            if(ca<0)
                        ca=ca+1;
            if(cb<0)
                        cb=cb+1;
        }
        timea.clear();
        timeb.clear();
        cout<< "Case #"<<(i+1)<<": "<<ca<<" "<<cb<<endl;
    }
    file.close();
    return 0;
}
