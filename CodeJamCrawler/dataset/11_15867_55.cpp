#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int finder(vector<pair<char,int> > vect, char c){
    vector<pair<char,int> >::iterator it;
    for(it=vect.begin();it!=vect.end();it++){
        if((*it).first==c)
            return int(it-vect.begin());
    }
    return -1;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("bot_trust2.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        vector<pair<char,int> > moves;
        int n,p,posB=1,posO=1,steps=0;
        char r;
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>r>>p;
            moves.push_back(make_pair(r,p));
        }
        int fb=finder(moves,'B');
        int fo=finder(moves,'O');
        while(fb!=-1 || fo!=-1){
            if(fb!=-1){
                if(moves[fb].second>posB)
                    posB++;
                else if(moves[fb].second<posB)
                    posB--;
                else if(moves[fb].second==posB){
                    if(fo==-1 || fo>fb)
                        moves.at(fb).first='X';
                }
            }
            if(fo!=-1){
                if(moves[fo].second>posO)
                    posO++;
                else if(moves[fo].second<posO)
                    posO--;
                else if(moves[fo].second==posO){
                    if(fb==-1 || fb>fo)
                        moves.at(fo).first='X';
                }
            }
            fb=finder(moves,'B');
            fo=finder(moves,'O');
            steps++;
        }
        cout<<"Case #"<<i+1<<": "<<steps<<endl;
    }
    return 0;
}
