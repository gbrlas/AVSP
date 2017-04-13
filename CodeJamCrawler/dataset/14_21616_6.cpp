#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
int a[4][4];

void inp() {
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> a[i][j];
}

vector<int> getPos(int ch) {
    ch--;
    vector<int> res;
    for(int i=0;i<4;i++)
        res.push_back(a[ch][i]);
    return res;

}

string result(vector<int> &x, vector<int> &y) {
    int cnt = 0;
    int n;
    for (int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if (x[i]==y[j]) {
                n = x[i];
                cnt++;
            }
    char tmp[4];

    if (cnt == 0)
        return "Volunteer cheated!";
    else if (cnt == 1) {
        sprintf(tmp, "%d", n);
        return tmp;
    }
    else
        return "Bad magician!";
}

int main() {
    int t;
    cin >> t;
    int c = 0;
    while(t--) {
        c++;
        int ch;
        cin >> ch;
        inp();
        vector<int> pos = getPos(ch);
        cin >> ch;
        inp();
        vector<int> nextPos = getPos(ch);
        cout << "Case #" << c << ": "<< result(pos, nextPos) << endl;
    }
}
