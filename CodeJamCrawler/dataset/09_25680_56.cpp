/* 
 * File:   code.cpp
 * Author: dzaric
 *
 */

#include <cmath>
#include <cstdlib>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cctype>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;

int main(int argc, char** argv) {

    int tcases;
    cin>>tcases;
    cin.get();


    for(int tcase=1;tcase<=tcases;tcase++){
        string num;
        getline(cin,num);
        string num2=num;
        bool ok=next_permutation(num2.begin(),num2.end());
        //cout<<num<<" -> "<<num2<<endl;
        string res;
        if(ok){
            res=num2;
        }
        else{
            num2="0"+num2;
            for(int i=0;i<num2.length();i++){
                if(num2[i]!='0'){
                    swap(num2[i],num2[0]);
                    break;
                }
            }
            res=num2;
        }
        //cout<<num<<" -> "<<num2<<endl;
        cout<<"Case #"<<tcase<<": "<<res<<endl;
    }

    return (EXIT_SUCCESS);
}

