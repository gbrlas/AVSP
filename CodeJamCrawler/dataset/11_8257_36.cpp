#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <limits.h>
#include <set>
#include <map>

using namespace std;

struct custom {
   int node;
   set<int> threat;
   int dist;
};

int main() {
    int TTT; cin >> TTT;
    for (int ZZZ = 1; ZZZ <= TTT; ZZZ++) {
        int P, W; cin >> P >> W;
        
        map<int, vector<int> > adjList;
        for (int i=0; i < W; i++) {
            int x, y;
            char gbg;
            cin >> x >> gbg >> y;
            if (adjList.find(x) != adjList.end()) {
                adjList[x].push_back(y);
            } else {
                vector<int> t;
                t.push_back(y);
                adjList[x] = t;
            }
            if (adjList.find(y) != adjList.end()) {
                adjList[y].push_back(x);
            } else {
                vector<int> t;
                t.push_back(x);
                adjList[y] = t;
            }
        }
        
        vector<int> bestdist;
        int currbest = INT_MAX;
        int currbestthreat = 0;
     
        stack<custom> *q = new stack<custom>;
        custom start;
        start.node = 0;
        set<int> a;
        for (int i=0; i < adjList[0].size(); i++) {
            a.insert(adjList[0][i]);
        }
        a.insert(0);
        start.threat = a;
        start.dist = 1;
        q->push(start);
        
        for (int i=0; i < P; i++) {
            bestdist.push_back(INT_MAX);
        }
        
        while(q->size()) {
            custom n = q->top(); q->pop();
            //cout << n.node << endl;
            if (n.dist > bestdist[n.node]) continue;
            bestdist[n.node] = n.dist;
            for (set<int>::iterator it = n.threat.begin(); it != n.threat.end(); it++) {
                int node = *it;
                if (node == 1) {
                    if (n.dist < currbest || (n.dist == currbest && n.threat.size() - n.dist > currbestthreat)) {
                        currbest = n.dist;
                        currbestthreat = n.threat.size() - n.dist;
                    }
                    break;
                }
                if (n.dist + 1 <= bestdist[node]) {
                    set<int> newthreat(n.threat);                    
                    for (int i=0; i < adjList[node].size(); i++) {
                        newthreat.insert(adjList[node][i]);
                    }
                    custom tmp;
                    tmp.node = node;
                    tmp.threat = newthreat;
                    tmp.dist = n.dist+1;
                    q->push(tmp);
                }
            }
        }
        delete q;
        cout << "Case #" << ZZZ << ": " << currbest - 1 << " " << currbestthreat << endl;
    }
}
