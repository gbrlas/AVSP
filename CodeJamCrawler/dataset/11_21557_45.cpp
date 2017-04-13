/* 
 * File:   main.cpp
 * Author: vvtoan
 *
 * Created on May 7, 2011, 9:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct {
    char bot;
    int pos;
} TARGET;

/*
 * 
 */
vector<TARGET> road;
int cur_posBlue = 0;
int cur_posOrange = 0;
int nextBlue() {    
    for (; cur_posBlue < road.size(); cur_posBlue++) {
        if (road[cur_posBlue].bot == 'B')
            return road[cur_posBlue++].pos;
    }
    return 0;
}

int nextOrange() {    
    for (; cur_posOrange < road.size(); cur_posOrange++) {
        if (road[cur_posOrange].bot == 'O')
            return road[cur_posOrange++].pos;
    }
    return 0;
}

int main(int argc, char** argv) {
    ifstream inFile;
    ofstream outFile;
    int T, N;

    inFile.open("A-small-attempt1.in", ifstream::in);
    outFile.open("A-small1.out", ifstream::out);
    inFile >> T;    
    for (int i = 0; i < T; i++) {
        inFile >> N;
        road.clear();
        cur_posBlue = cur_posOrange = 0;
        for (int j = 0; j < N; j++) {
            TARGET t;
            inFile >> t.bot;
            inFile >> t.pos;
            road.push_back(t);
        }
        int tBlue = nextBlue();
        int tOrange = nextOrange();
        int idx = 0, posO = 1, posB = 1, steps = 0;
        TARGET tNext = road[idx++];
        while (idx <= N) {
            //Orange
            if (tNext.bot == 'O') {
                if (posO == tNext.pos) {
                    tNext = road[idx++];
                    tOrange = nextOrange();
                } else if (posO < tNext.pos)
                    posO++;
                else if (posO > tNext.pos)
                    posO--;
                if (posB < tBlue)
                    posB++;
                else if (posB > tBlue)
                    posB--;
            } else { //Blue
                if (posB == tNext.pos) {
                    tNext = road[idx++];
                    tBlue = nextBlue();
                } else if (posB < tNext.pos)
                    posB++;
                else if (posB > tNext.pos)
                    posB--;
                if (posO < tOrange)
                    posO++;
                else if (posO > tOrange)
                    posO--;
            }
            steps++;
        }
        outFile << "Case #"<<i+1<<": " << steps<<endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}

