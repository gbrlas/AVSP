#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>  //for C++
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <sstream>
//#include <string> for C

using namespace std;

int card[4][4];
int r1[4]; int r2[4];

int answer1, answer2;
string res;

string checkCard(int *r1, int *r2){
    string res;
    int count=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(r1[i]==r2[j]){
                count++;
                stringstream s;
                s<<r1[i];
                s>>res;
            }
        }
    }

    if(count==0)
        res = "Volunteer cheated!";
    else if(count!=1)
        res = "Bad magician!";

    return res;
}

int main()
{
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        for(int j=0; j<2; j++){
            if(j==0)
                cin>>answer1;
            else
                cin>>answer2;
            for(int a=0; a<4; a++)
                for(int b=0; b<4; b++){
                    cin>>card[a][b];
                    if(j==0 && answer1==a+1){
                        r1[b] = card[a][b];
                    }
                    else if(j==1 && answer2==a+1){
                        r2[b] = card[a][b];
                    }
                }
        }

        res = checkCard(r1, r2);

        cout<<"Case #"<<i+1<<": "<<res<<endl;
    }
}
