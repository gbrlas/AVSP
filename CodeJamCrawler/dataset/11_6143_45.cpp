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

int N;
char owner[101];
int button[101];

int pushedButtons;

int currentOrange;
int currentBlue;

int nextDir(char who, int currButton){
    int k = pushedButtons;
    
    while(owner[k] != who and k <= N) k++;
    
    if(k == N) return 0;
    
    if(button[k] > currButton) return +1;
    if(button[k] < currButton) return -1;
    return 0;
}

bool canBePushed(int whichButton, char whichOwner){
    return button[pushedButtons]==whichButton && owner[pushedButtons]==whichOwner;
}

void onePeriod(){
    int ora = nextDir('O', currentOrange);
    int blu = nextDir('B', currentBlue);
    
    //cout << "ora:" << ora << " blu:" << blu << endl;
    //char c; cin>>c;
    
    currentOrange += ora;
    currentBlue += blu;
    #if false
    if(ora != 0)
        cout << "orange moves to " << currentOrange << endl;
    
    if(blu != 0)
        cout << "blue moves to " << currentBlue << endl;
    #endif
    //cout << "currentOrange=" << currentOrange << " currentBlue=" << currentBlue << endl;
    
    bool justPushed = false;
    
    if(ora == 0){
        if( canBePushed(currentOrange, 'O') ){
            pushedButtons++;
            justPushed = true;
            //cout << "orange pushes button " << currentOrange << endl;
        }else{
            //cout << "orange stays at " << currentOrange << endl;
        }
    }
    if(blu == 0 and !justPushed){
        if( canBePushed(currentBlue, 'B') ){
            pushedButtons++;
            //cout << "blue pushes button " << currentBlue << endl;
        }else{
            //cout << "blue stays at " << currentBlue << endl;
        }
    }
    //cout << pushedButtons << " of " << N << endl;
}

int main(int argc, char **argv) {
    
    int T;
    entrada >> T;
    
    for(int k=1; k<=T; k++){
        entrada >> N;
        for(int i=0; i<N; i++)
            entrada >> owner[i] >> button[i];
            //cout << "owner:" << owner << " button:" << button << endl;
        //cout << "----" << endl;
        
        currentOrange = 1;
        currentBlue = 1;
        pushedButtons = 0;
        
        int totalTime = 0;
        
        while(pushedButtons < N){
            onePeriod();
            totalTime++;
        }
        
        cout << "Case #" << k << ": " << totalTime << endl;
    }
    
	return 0;
}
